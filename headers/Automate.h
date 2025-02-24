#pragma once
#include <iostream>
#include <stack>

#include "Symbole.h"
#include "State.h"
#include "Lexer.h"

using namespace std;

class Automate {
public:
    // Constructor
    Automate(Lexer &lexer);

    // Destructor
    ~Automate();

    // start the automate
    void start();

    // decalage
    void decalage(Symbole* s, State* e);

    // reduction
    void reduction(int n, Symbole* s, int ruleNumber);
    // n est la taille de la règle de réduction
    //
    void transition_simple(Symbole* s, State* e);
 
private:
    // state stack 
    stack<State*> stateStack;
    stack<Symbole*> symbolStack;

    // lexer
    Lexer &lexer;
};