#include "State.h"


// State 0
State0::State0(string name) : State(name) {};
State0::~State0() {};
bool State0::transition (Automate &automate, Symbole* s) {
    if(DEBUG){cout << "State0.transition()" << endl;}
    switch (*s) {
        case INT: // val
            automate.decalage(s, new State3("State 3"));
        case OPENPAR: // open paranthesis
            automate.decalage(s, new State2("State 2"));
        case EXPR: // expression
            automate.transition_simple(s, new State1("State 1"));
            // how to detect an expression ?
        default:
        return true;


    }

      
    return false;
}

bool State1::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State1.transition()" << endl;}
    switch(*s){
        case PLUS: // plus symbol
            automate.decalage(s, new State4("State 4"));
        case MULT: // multiplication symbol
            automate.decalage(s, new State5("State 5"));
        case FIN: // end of text
            // Accept (how do we accept ?)
            return true;
        default:
            return true;
    }
    return false;
}

bool State2::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State2.transition()" << endl;}
    switch(*s){
        case PLUS:
            automate.decalage(s, new State3("State 3"));
        case OPENPAR:
            automate.decalage(s, new State2("State 2"));
        case EXPR:
            automate.transition_simple(s, new State6("State 6"));
        default:
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
            return true;
    }
    return false;
}

bool State4::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State4.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3("State 3"));
        case OPENPAR:
            automate.decalage(s, new State2("State 2"));
        case EXPR:
            automate.transition_simple(s, new State7("State 7"));
        default:
            return true;
    }
    return false;
}

bool State5::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State5.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3("State 3"));
            break;
        case OPENPAR:
            automate.decalage(s, new State2("State 2"));
        case EXPR:
            automate.transition_simple(s, new State8("State 8"));
        default:
            return true;
    }
    return false;
}

bool State6::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State6.transition()" << endl;}
    switch(*s){
        case PLUS: // plus symbol
            automate.decalage(s, new State4("State 4"));
        case MULT: // multiplication symbol
            automate.decalage(s, new State5("State 5"));
        case CLOSEPAR:
            automate.decalage(s, new State9("State 9"));
        default:
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
            automate.decalage(s, new State5("State 5"));
        case CLOSEPAR: // E -> E + E
            automate.reduction(3, s, 2);
        case FIN: // E -> E + E
            automate.reduction(3, s, 2);
        default:
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
            return true;
    }
    return false;
}