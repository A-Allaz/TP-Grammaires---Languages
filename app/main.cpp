#include <iostream>
#include "../headers/Lexer.h"
#include "../headers/Automate.h"



int main(void) {
   cout << DEBUG << endl;

   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
   return 0;

   // string chaine("1+3");
   // string chaine("(1+34)*123");

   // Lexer l(chaine);

   // Automate();

   // return 0;

}
