#include <iostream>
#include "Lexer.h"
#include "Automate.h"



int main(void) {
   // ask the user to enter an input chain
   string chainToVerify;
   cout << "Enter a chain: ";
   cin >> chainToVerify;

   // create a lexer with the chain to verify
   Lexer lexer(chainToVerify);

   // create an automate with the lexer
   Automate automate(lexer);

   // start the automate and compute the result
   try {
      automate.compute();
   } catch (const std::invalid_argument& e) {
      cout << "Chain refused" << endl;
   }
   return 0;
}

