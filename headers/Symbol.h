#pragma once // include only once

#include <string>
using namespace std;

#define DEBUG false

enum Identificators { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string labels[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };


class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void print();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void print();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(int v) : Symbole(EXPR), valeur(v) { }
      ~Expr() { }
      virtual void print();
      int getValue() { return valeur; }

   protected:
      int valeur;
};