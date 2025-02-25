#include "State.h"
#include "Automate.h"

// Abtract class State
State::~State() {};
void State::print() const {
    cout << name << endl;
}


// State 0
State0::State0(string name) : State(name) {};
State0::~State0() {};
bool State0::transition (Automate &automate, Symbole* s) {
    if(DEBUG){cout << "State0.transition()" << endl;}
    switch (*s) {
        case INT: // val
            automate.decalage(s, new State3("State 3"));
            break;
        case OPENPAR: // open paranthesis
            automate.decalage(s, new State2("State 2"));
            break;
        case EXPR:
            automate.transition_simple(s, new State1("State 1"));
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}


// State 1
State1::State1(string name) : State(name) {};
State1::~State1() {};

bool State1::transition(Automate &automate, Symbole* s){
    if(DEBUG){cout << "State1.transition()" << endl;}
    switch(*s){
        case PLUS: // plus symbol
            automate.decalage(s, new State4("State 4"));
            break;
        case MULT: // multiplication symbol
            automate.decalage(s, new State5("State 5"));
            break;
        case FIN: // end of text (its the only time when we return true)
            return true;
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 2
State2::State2(string name) : State(name) {};
State2::~State2() {};
bool State2::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State2.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3("State 3"));
            break;
        case OPENPAR:
            automate.decalage(s, new State2("State 2"));
            break;
        case EXPR:
            automate.transition_simple(s, new State6("State 6"));
            break;
        
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 3
State3::State3(string name) : State(name) {};
State3::~State3() {};
bool State3::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State3.transition()" << endl;}
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(1, s, 5); // E -> val donc n=1
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 4
State4::State4(string name) : State(name) {};
State4::~State4() {};
bool State4::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State4.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3("State 3"));
            break;
        case OPENPAR:
            automate.decalage(s, new State2("State 2"));
            break;
        case EXPR:
            automate.transition_simple(s, new State7("State 7"));
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 5
State5::State5(string name) : State(name) {};
State5::~State5() {};
bool State5::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State5.transition()" << endl;}
    switch(*s){
        case INT:
            automate.decalage(s, new State3("State 3"));
            break;
        case OPENPAR:
            automate.decalage(s, new State2("State 2"));
            break;
        case EXPR:
            automate.transition_simple(s, new State8("State 8"));
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 6
State6::State6(string name) : State(name) {};
State6::~State6() {};

bool State6::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State6.transition()" << endl;}
    switch(*s){
        case PLUS: // plus symbol
            automate.decalage(s, new State4("State 4"));
            break;
        case MULT: // multiplication symbol
            automate.decalage(s, new State5("State 5"));
            break;
        case CLOSEPAR:
            automate.decalage(s, new State9("State 9"));
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 7
State7::State7(string name) : State(name) {};
State7::~State7() {};

bool State7::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State7.transition()" << endl;}
    switch(*s){
        case PLUS: // E -> E + E
            automate.reduction(3, s, 2);
            break;
        case MULT:
            automate.decalage(s, new State5("State 5"));
            break;
        case CLOSEPAR: // E -> E + E
            automate.reduction(3, s, 2);
            break;
        case FIN: // E -> E + E
            automate.reduction(3, s, 2);
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 8
State8::State8(string name) : State(name) {};
State8::~State8() {};

bool State8::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State8.transition()" << endl;}
    switch(*s){
        case PLUS: // E -> E * E
            automate.reduction(3, s, 3);
            break;
        case MULT: // E -> E * E
            automate.reduction(3, s, 3);
            break;
        case CLOSEPAR: // E -> E * E
            automate.reduction(3, s, 3);
            break;
        case FIN: // E -> E * E
            automate.reduction(3, s, 3);
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}

// State 9
State9::State9(string name) : State(name) {};
State9::~State9() {};

bool State9::transition(Automate &automate, Symbole * s){
    if(DEBUG){cout << "State9.transition()" << endl;}
    switch(*s){
        case PLUS: // E -> ( E )
            automate.reduction(3, s, 4);
            break;
        case MULT: // E -> ( E )
            automate.reduction(3, s, 4);
            break;
        case CLOSEPAR: // E -> ( E )
            automate.reduction(3, s, 4);
            break;
        case FIN: // E -> ( E )
            automate.reduction(3, s, 4);
            break;
        default: 
            // error
            string message = "Invalid symbol: ";
            message += Etiquettes[*s].c_str();
            throw std::invalid_argument(message);
    }
    return false;
}