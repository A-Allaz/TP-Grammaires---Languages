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
      string flux; // input string to analyse
      int head; // current position in the input string
      Symbole * buffer; // last symbol read
};
