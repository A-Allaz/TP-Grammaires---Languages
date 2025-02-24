#include "Automate.h"
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
    Symbole* first;
    Symbole* op;
    Symbole* second;
    // read the top


    Symbole* first = symbolStack.top();
    symbolStack.pop();
    
    // rules 
    switch (ruleNumber) {
        case 2:
            // E -> E + E
            op = symbolStack.top();
            symbolStack.pop();
            second = symbolStack.top();
            symbolStack.pop();
            value = ((Expr*) first)->getValue() + ((Expr*) second)->getValue();

            symbolStack.push(new Expr(value));
            cout << "E -> E + E" << endl;
            cout << "Value: " << value << endl;

            // delete symbols
            delete first;
            delete op;
            delete second;
            break;
        case 3:
            // E -> E * E
            op = symbolStack.top();
            symbolStack.pop();
            second = symbolStack.top();
            symbolStack.pop();
            value = ((Expr*) first)->getValue() * ((Expr*) second)->getValue();

            symbolStack.push(new Expr(value));
            cout << "E -> E * E" << endl;
            cout << "Value: " << value << endl;

            // delete symbols
            delete first;
            delete op;
            delete second;

            break;
        case 4:
            // E -> (E)
            // get the expression in the parenthesis
            // we don’t have to compute anything here
            Symbole* expr = symbolStack.top();
            symbolStack.pop();
            Symbole* closePar = symbolStack.top();
            symbolStack.pop();

            symbolStack.push((Expr*) expr);

            // delete symbols
            delete first;
            delete expr;
            delete closePar;
            
            break;
        case 5:
            // E -> val
            symbolStack.push((Expr*) first);
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

    // transition 
    currentState = stateStack.top();
    currentState->transition(*this, s);
    
}

//
void Automate::transition_simple(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.transition_simple()" << endl;}
    symbolStack.push(s);
    stateStack.push(e);
}