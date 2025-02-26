#pragma once
#include <iostream>
#include <stack>

#include "Symbol.h"
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

    // compute the result of the expression in the given lexer
    int compute();

    // forward
    void forward(Symbole* s, State* e);

    // reduction
    void reduction(int n, Symbole* s, int ruleNumber);

    // forward for an unterminal expression (not moving the head of the lexer)
    void forward_unterminal(Symbole* s, State* e);
 
private:
    // state stack 
    stack<State*> stateStack;
    stack<Symbole*> symbolStack;

    // lexer
    Lexer &lexer;
};