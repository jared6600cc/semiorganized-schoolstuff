#include<stdio.h>
#include"fileOps.h"

int main()
{
  demoFileIO();
}
 
 
 void demoFileIO()
 {
   FILE * fp;
   char ch;
   fp = fopen("text.txt","r");
   while((ch = fgetc(fp)) != EOF)
     printf("%c",ch);
   fclose(fp);
   
   fp = fopen("text.txt","r");
   ch = fgetc(fp);
   printf("The first character in the file: %c\n",ch);
   ungetc(ch,fp);
   ch = fgetc(fp);
   printf("After ungetc, the next character: %c\n",ch); 
 }
 
