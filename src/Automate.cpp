#include "Automate.h"
#include "State.h"
#include "Symbole.h"
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

    // start the automate by the first transition of the first state
    State* currentState = stateStack.top();
    while (!currentState->transition(*this, lexer.Consulter())) {
        // apply the transition for the state above the stack
        currentState = stateStack.top();
    }
   
}

// decalage
void Automate::decalage(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.decalage()" << endl;}
    // add the state and the symbol to the stack
    stateStack.push(e);
    symbolStack.push(s);
    // move the head forward
    lexer.Avancer();

}

// reduction
void Automate::reduction(int n, Symbole *s, int ruleNumber){
    if(DEBUG){cout << "Automate.reduction()" << endl;}
    // initialize variables
    int value;
    Symbole* currentSymbol;
    // read the top


    currentSymbol= symbolStack.top();
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
            symbolStack.push(new Expr(value));
            cout << "E -> E + E" << endl;
            cout << "Value: " << value << endl;
            break;

        case 3:
            // E -> E * E
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

            // multiply the second value
            value *= ((Expr*) currentSymbol)->getValue();
            // delete the second value
            delete currentSymbol;

            // put the result on the stack
            symbolStack.push(new Expr(value));
            cout << "E -> E * E" << endl;
            cout << "Value: " << value << endl;

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

            // put back the expression on the stack
            symbolStack.push(currentSymbol);
            
            break;
        case 5:
            // E -> val
            symbolStack.push(currentSymbol);
            cout << "E -> val" << endl;
            
            break;
        default:
            break;

        
    }

    State* currentState;
    // pop n states from state stack
    for (int i = 0; i < n; i++) {
        currentState = stateStack.top();
        stateStack.pop();
        delete currentState;
    }

    // simple transition from the top of the stack
    currentState = stateStack.top();
    transition_simple(s, currentState); 
    
    
}

//
void Automate::transition_simple(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.transition_simple()" << endl;}
    symbolStack.push(s);
    stateStack.push(e);
}