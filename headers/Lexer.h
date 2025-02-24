#pragma once // include only once

#include <iostream>
#include <string>
#include "Symbole.h"

using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }

      Symbole * Consulter();
      void Avancer();

   protected:
      string flux; // flux d'entrée à lire
      int tete; // caractère courant
      Symbole * tampon; // dernier symbole lu
};
