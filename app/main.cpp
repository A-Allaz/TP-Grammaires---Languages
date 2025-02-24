#include <iostream>
#include "Lexer.h"
#include "Automate.h"



int main(void) {
   string chaine("1+3");
   // string chaine("(1+34)*123");

   Lexer lexer(chaine);

   Automate automate(lexer);

   automate.start(); // start the automate to verify the string

   return 0;
}

