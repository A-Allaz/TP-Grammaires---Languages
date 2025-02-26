#include "Symbol.h"
#include <iostream>

// print the symbol given
void Symbole::print() {
   cout<<labels[ident];
}

// print the INT symbol
void Entier::print() {
   Symbole::print();
   cout<<"("<<valeur<<")";
}

// print the EXPR symbol (same as INT)
void Expr::print() {
   Symbole::print();
   cout<<"("<<valeur<<")";
}

