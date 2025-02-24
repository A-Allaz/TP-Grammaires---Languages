#pragma once
#include <iostream>
using namespace std;

#include "Automate.h"
#include "Symbole.h"

class Automate;

// abstract class
class State {
    public:
        State(string name) : name(name) {};
        virtual ~State();
        void print() const; // debugging the state

        virtual bool transition (Automate &automate, Symbole* s) = 0; // pure

    protected:
        string name;
};

class State0 : public State {
    public:
        State0(string name);
        virtual ~State0();
        virtual bool transition (Automate &automate, Symbole* s);

        

    
};

class State1 : public State {
    public:
        State1(string name);
        virtual ~State1();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State2 : public State {
    public:
        State2(string name);
        virtual ~State2();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State3 : public State {
    public:
        State3(string name);
        virtual ~State3();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State4 : public State {
    public:
        State4(string name);
        virtual ~State4();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State5 : public State {
    public:
        State5(string name);
        virtual ~State5();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State6 : public State {
    public:
        State6(string name);
        virtual ~State6();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State7 : public State {
    public:
        State7(string name);
        virtual ~State7();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State8 : public State {
    public:
        State8(string name);
        virtual ~State8();
        virtual bool transition (Automate &automate, Symbole* s);
};

class State9 : public State {
    public:
        State9(string name);
        virtual ~State9();
        virtual bool transition (Automate &automate, Symbole* s);
};