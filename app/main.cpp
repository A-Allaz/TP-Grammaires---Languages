#include <iostream>
#include "Lexer.h"
#include "Automate.h"



int main(void) {
   // string chaine("(1)");
   // string chaine("(1+5)*3");
   // hard example
   // string chaine("(1+5)*3+2*3");
   // way harder with big numbers
   string chaine("123*(7*7+4)+6");

   Lexer lexer(chaine);

   Automate automate(lexer);

   try {
      automate.compute();
   } catch (const std::invalid_argument& e) {
      cout << "Chain refused" << endl;
   }
   return 0;
}

