#include "Symbol.h"
#include <iostream>

void Symbole::print() {
   cout<<labels[ident];
}

void Entier::print() {
   Symbole::print();
   cout<<"("<<valeur<<")";
}

void Expr::print() {
   Symbole::print();
   cout<<"("<<valeur<<")";
}

