#include <iostream>
#include "../headers/Lexer.h"
#include "../headers/Automate.h"



int main(void) {
   string chaine("(1+34)*123");
   cout << "Analyse de : " << chaine << endl;


   Automate *a = new Automate(chaine);
   a->start();


   return 0;

}

