#include "../headers/Lexer.h"
#include <iostream>

Symbole * Lexer::Consulter() {
   if(DEBUG){cout << "Lexer.Consulter()" << endl;}
   if (!tampon) {

      if ((long unsigned int)tete==flux.length())
         tampon = new Symbole(FIN);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') { // check if the character is a number
                  int resultat = flux[tete]-'0'; // convert the character to an integer
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') { // read 1824 as 1824
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat); // give the total integer to the tampon
               }
               else {
                  tampon = new Symbole(ERREUR); // if not a number or a ending character, it's an error
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   if(DEBUG){cout << "Lexer.Avancer()" << endl;}
   tampon = nullptr;
}
