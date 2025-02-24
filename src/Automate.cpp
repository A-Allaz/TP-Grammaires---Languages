#include "../headers/Automate.h"

#include <iostream>
using namespace std;

// constructor
Automate::Automate(string flux)
{
    this->lexer = new Lexer(flux);
    State0 *depart = new State0();
    stateStack.push(depart);
}

// start the automate
void Automate::start(){
    bool prochainEtat = true;

    while (prochainEtat) {
      Symbole *s = lexer->Consulter();
      lexer->Avancer();
      prochainEtat = stateStack.top()->transition(*this, s);
      afficherStacks();
    }
    if (*symbolStack.top() != ERREUR) {
  
      int resultat = symbolStack.top()->getValue();
      cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
    } else {
      cout << "Syntaxe non reconnu : caractere invalide" << endl;
    }
}

// decalage
void Automate::decalage(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.decalage()" << endl;}
    // add the state and the symbol to the stack
    stateStack.push(e);
    symbolStack.push(s);
    // move the head forward
    lexer->Avancer();
    afficherStacks();

}

// reduction
void Automate::reduction(int n, Symbole *s, int ruleNumber){
    if(DEBUG){cout << "Automate.reduction()" << endl;}
    // initialize variables
    int value;
    Symbole* first;
    Symbole* op;
    Symbole* second;
    Symbole* expr;
    Symbole* closePar;


    first = symbolStack.top();
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
            expr = symbolStack.top();
            symbolStack.pop();
            closePar = symbolStack.top();
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
    afficherStacks();
    
}

//
void Automate::transition_simple(Symbole *s, State *e){
    if(DEBUG){cout << "Automate.transition_simple()" << endl;}
    symbolStack.push(s);
    stateStack.push(e);
    afficherStacks();
}

void Automate::afficherStacks() {
    cout << "Contenu de stateStack: ";
    stack<State*> tempStateStack = stateStack;
    while (!tempStateStack.empty()) {
        cout << tempStateStack.top() << " ";
        tempStateStack.pop();
    }
    cout << endl;

    cout << "Contenu de symbolStack: ";
    stack<Symbole*> tempSymbolStack = symbolStack;
    while (!tempSymbolStack.empty()) {
        cout << tempSymbolStack.top() << " ";
        tempSymbolStack.pop();
    }
    cout << endl;
}