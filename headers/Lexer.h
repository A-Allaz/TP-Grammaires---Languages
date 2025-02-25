#pragma once // include only once

#include <iostream>
#include <string>
#include "Symbol.h"

using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), head(0), buffer(nullptr) { }
      ~Lexer() { }

      Symbole * getSymbol();
      void MoveHeadForward();

   protected:
      string flux; // flux d'entrée à lire
      int head; // caractère courant
      Symbole * buffer; // dernier symbole lu
};
