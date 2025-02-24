#include "../headers/State.h"
#include <iostream>
using namespace std;
#include "../headers/Symbole.h"


State::State() {}
State::~State() {}

State::State(std::string n) {
    // Implémentation du constructeur
    this->name = n;
}


State0::State0() : State("State 0") {}

State1::State1() : State("State 1") {}

State2::State2() : State("State 2") {}

State3::State3() : State("State 3") {}

State4::State4() : State("State 4") {}

State5::State5() : State("State 5") {}

State6::State6() : State("State 6") {}

State7::State7() : State("State 7") {}

State8::State8() : State("State 8") {}

State9::State9() : State("State 9") {}

bool State0::transition (Automate &automate, Symbole* s) {
    if(DEBUG){cout << "State0.transition()" << endl;}
    switch (*s) {
        case INT: // val
            automate.decalage(s, new State3);
        case OPENPAR: // open paranthesis
            automate.decalage(s, new State2);
        case EXPR: // expression
            automate.transition_simple(s, new State1);
            // how to detect an expression ?
        default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return true;


    }

      
    return false;
}

bool State1::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State1.transition()" << endl;}
    switch(*s){
        case PLUS: // plus symbol
            automate.decalage(s, new State4);
        case MULT: // multiplication symbol
            automate.decalage(s, new State5);
        case FIN: // end of text
            // Accept (how do we accept ?)
            return true;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State2::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State2.transition()" << endl;}
    switch(*s){
        case PLUS:
            automate.decalage(s, new State3);
        case OPENPAR:
            automate.decalage(s, new State2);
        case EXPR:
            automate.transition_simple(s, new State6);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State3::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State3.transition()" << endl;}
    switch(*s){
        case PLUS:
            automate.reduction(1, s, 5);
        case MULT:
            automate.reduction(1, s, 5);
        case CLOSEPAR:
            automate.reduction(1, s, 5);
        case FIN:
            automate.reduction(1, s, 5);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State4::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State4.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3);
        case OPENPAR:
            automate.decalage(s, new State2);
        case EXPR:
            automate.transition_simple(s, new State7);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State5::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State5.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3);
            break;
        case OPENPAR:
            automate.decalage(s, new State2);
        case EXPR:
            automate.transition_simple(s, new State8);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State6::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State6.transition()" << endl;}
    switch(*s){
        case PLUS: // plus symbol
            automate.decalage(s, new State4);
        case MULT: // multiplication symbol
            automate.decalage(s, new State5);
        case CLOSEPAR:
            automate.decalage(s, new State9);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State7::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State7.transition()" << endl;}
    switch(*s){
        case PLUS: // E -> E + E
            automate.reduction(3, s, 2);
        case MULT:
            automate.decalage(s, new State5);
        case CLOSEPAR: // E -> E + E
            automate.reduction(3, s, 2);
        case FIN: // E -> E + E
            automate.reduction(3, s, 2);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State8::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State8.transition()" << endl;}
    switch(*s){
        case PLUS: // E -> E * E
            automate.reduction(3, s, 3);
        case MULT: // E -> E * E
            automate.reduction(3, s, 3);
        case CLOSEPAR: // E -> E * E
            automate.reduction(3, s, 3);
        case FIN: // E -> E * E
            automate.reduction(3, s, 3);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}

bool State9::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State9.transition()" << endl;}
    switch(*s){
        case PLUS: // E -> ( E )
            automate.reduction(3, s, 4);
        case MULT: // E -> ( E )
            automate.reduction(3, s, 4);
        case CLOSEPAR: // E -> ( E )
            automate.reduction(3, s, 4);
        case FIN: // E -> ( E )
            automate.reduction(3, s, 4);
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return true;
    }
    return false;
}


int State::state() { return -1; }

int State0::state() { return 0; }

int State1::state() { return 1; }

int State2::state() { return 2; }

int State3::state() { return 3; }

int State4::state() { return 4; }

int State5::state() { return 5; }

int State6::state() { return 6; }

int State7::state() { return 7; }

int State8::state() { return 8; }

int State9::state() { return 9; }