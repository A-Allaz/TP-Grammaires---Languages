#include "Automate.h"
#include "State.h"
#include "Symbol.h"
#include "Lexer.h"

// constructor
Automate::Automate(Lexer &lexer): 
    lexer(lexer)
{
    // initialize stacks
    stateStack = stack<State*>();
    symbolStack = stack<Symbole*>();

    // initialize the first state
    stateStack.push(new State0("state0"));

}

// destructor
Automate::~Automate(){
    // be sure all the stacks are freed
    if(DEBUG){cout << "Automate.~Automate()" << endl;}
    // delete all states
    while (!stateStack.empty()) {
        delete stateStack.top();
        stateStack.pop();
    }

    // delete all symbols
    while (!symbolStack.empty()) {
        delete symbolStack.top();
        symbolStack.pop();
    }
}


// start the automate
void Automate::start(){
    if(DEBUG){cout << "Automate.start()" << endl;}

    // start the automate
    State* currentState = stateStack.top();
    while (!currentState->transition(*this, lexer.getSymbol())) {
        // apply the transition for the state above the stack
        currentState = stateStack.top();
    }
    
    // if we are here the chain is accpted and well formated
    cout << "Chain accepted" << endl;
}

int Automate::compute() {
    start();
    // print the result
    cout << "Result: " << ((Expr*) symbolStack.top())->getValue() << endl;
    // return the result
    return ((Expr*) symbolStack.top())->getValue();
}



// forward
void Automate::forward(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.forward()" << endl;}
    // add the state and the symbol to the stack
    stateStack.push(e);
    symbolStack.push(s);

    // move the head forward
    lexer.MoveHeadForward();
}

// reduction
void Automate::reduction(int n, Symbole *s, int ruleNumber){
    if(DEBUG){cout << "Automate.reduction()" << endl;}

    // initialize variables
    int value; // computed value of the reduction if add mult or parenthesis
    Expr* exprAftReduction = nullptr; // expression after reduction, contains the value
    
    // read the symbol on the top of the stack
    Symbole* currentSymbol = symbolStack.top();
    symbolStack.pop();
    
    // rules 
    switch (ruleNumber) {
        case 2:
            // E -> E + E
            // delete the operator
            delete symbolStack.top();
            symbolStack.pop();
            
            // store the first value
            value = ((Expr*) currentSymbol)->getValue();
            // delete the first value
            delete currentSymbol;
            
            // get the second value
            currentSymbol = symbolStack.top();
            symbolStack.pop();

            // add the second value
            value += ((Expr*) currentSymbol)->getValue();
            // delete the second value
            delete currentSymbol;

            // put the result on the stack
            exprAftReduction = new Expr(value);
            break;

        case 3:
            // E -> E * E
            // delete the operator
            delete symbolStack.top();
            symbolStack.pop();

            // store the first value
            value = ((Expr*) currentSymbol)->getValue();
            // delete the first expression
            delete currentSymbol;
            
            // get the second expression
            currentSymbol = symbolStack.top();
            symbolStack.pop();

            // multiply by the second value
            value *= ((Expr*) currentSymbol)->getValue();
            // delete the second expression
            delete currentSymbol;

            // compute the new expression containing the result (value)
            exprAftReduction = new Expr(value);
            break;
        case 4:
            // E -> (E)
            // delete the opening parenthesis
            delete currentSymbol;
            // get the expression
            currentSymbol = symbolStack.top();
            symbolStack.pop();

            // delete the closing parenthesis
            delete symbolStack.top();
            symbolStack.pop();

            // create a new expression with the value of the expression
            exprAftReduction = new Expr(((Expr*) currentSymbol)->getValue());        
            break;
        case 5:
            // E -> val
            // create a new expression with the value of the expression
            exprAftReduction = new Expr(((Expr*) currentSymbol)->getValue());        
            break;
        default:
            break;

        
    }

    // pop n states from state stack
    for (int i = 0; i < n; i++) {
        delete stateStack.top();
        stateStack.pop();
    }

    // get the current state at the top of the stack
    State* currentState = stateStack.top();
    
    // launching transition with expression on the top
    // it is going to perform a forward for non terminal symbols
    currentSymbol = symbolStack.top();
    currentState->transition(*this, exprAftReduction);
}

//
void Automate::forward_unterminal(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.forward_unterminal()" << endl;}
    // add the state and the symbol to the stack
    symbolStack.push(s);
    stateStack.push(e);
    // do not move the head forward
}