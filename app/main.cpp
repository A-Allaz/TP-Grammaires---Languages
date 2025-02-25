#include <iostream>
#include "Lexer.h"
#include "Automate.h"



int main(void) {
   string chainToVerify;
   cout << "Enter a chain: ";
   cin >> chainToVerify;
   Lexer lexer(chainToVerify);

   Automate automate(lexer);

   try {
      automate.compute();
   } catch (const std::invalid_argument& e) {
      cout << "Chain refused" << endl;
   }
   return 0;
}

