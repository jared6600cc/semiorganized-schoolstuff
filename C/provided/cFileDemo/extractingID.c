#include <stdio.h>
#include <string.h>
#include <ctype.h> // for isalnum()

#define idLen 50

int main () {
  char idLexeme[idLen]; 
  char st[idLen] = "hello5&";
  int i = 0;
  while(isalnum(st[i]))
  {
    idLexeme[i] = st[i];
    i++;
  }
  idLexeme[i] = '\0'; // MUST place null terminator at end of string
  printf("the id is %s\n",idLexeme);
   
   return(0);
}