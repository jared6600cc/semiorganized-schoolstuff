#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char *argv[])
{

   if (argc < 2)
   {
      fprintf(stderr, "Please input a csv file name\n");
      exit(1);
   }

   char line[256] =  {0x0};
   char name[10] = {0x0};
   int i, j, k;
   char *tok; //= strtok(NULL, ",");
   char c;

   // file pointer
   FILE *fin;
   printf("the input file name is %s\n",  argv[1]);

   // open file in read mode
   fin = fopen(argv[1], "r");
   if(fin == NULL) 
   {
      perror("Error in opening file %s\n", argv[1]);
      return(-1);
   }
   printf("The location of the pointer is %ld\n", ftell(fin)); 
   
   // let's read one char
   c = getc(fin);

   printf("I got 1 char from the file and it is %c\n", c);

   printf("The location of the pointer is %ld\n", ftell(fin)); 

   // advance the pointer a few char into the file
   printf("Now let's jump 3 chars from the present location\n");
   fseek(fin, 3, SEEK_CUR);

   // see where we are
   printf("The location of the pointer is %ld\n", ftell(fin)); 
   
   // let's read one char
   c = getc(fin);

   printf("I got 1 char from the file and it is %c\n", c);


   // advnace to the end of the file
   fseek(fin, 0, SEEK_END);

   // get the location of the pointer
   printf("The location of the pointer is %ld. This is the number of bytes the file has.\n", ftell(fin)); 

   // let's go back a few chars and read something
   fseek(fin, -4, SEEK_END);

   c = fgetc(fin);
   printf("I got 1 char from the file and it is %c\n", c);
   printf("The location of the pointer is %ld\n", ftell(fin)); 


   // let's get back to the beginning of the file and read tokens
   
   fseek(fin, 0, SEEK_SET); // SEEK_CUR, SEEK_END
   
   int lines = 0;
   
   while(!feof(fin)) // returns no zero when EOF  is reached; zero otherwise
   {
      fgets(line, 255, fin);
         lines++;
   }
   
   // let's see where we are after we read all the lines
   printf("The location of the pointer is %ld\n", ftell(fin)); 
   
   // this is the number of lines we have in the file
   printf("%d lines in this file.\n", lines);

   // let's get back to the beginning of the line and read tokens
   
   fseek(fin, 0, SEEK_SET); // SEEK_CUR, SEEK_END

   // let's see where we are after the fseek statement
   printf("The location of the pointer is %ld\n", ftell(fin)); 
   
   // get the first line (read till you hit EOL character) 
   fgets(line, 255, fin);
  
   // prints the line
   puts(line);
   
   // line is searched until a ',' is found or EOL, the first token
   // which is the string to the left of the ',' is returned. 
   tok = strtok(line, ",");
   
   // print the first token
   printf("1st token: \n");
   puts(tok);
   printf("size of token %d\n", strlen(tok));
   
   
   // to continue search the string "line", we pass the NULL character to strtok
   // because strtok is a static pointer to the initial string so it will continue
   // where it left off, earch for the next ',' and return the string from where it 
   // ended during the first read up to the next ',' 
   tok = strtok(NULL, ",");
   printf("2nd token: \n");
   puts(tok);
   
   
   tok = strtok(NULL, ",");
   printf("3rd token: \n");
   puts(tok);
   printf("size of token %d\n", strlen(tok));
   

   tok = strtok(NULL, ",");
   printf("4th token: \n");
   puts(tok);

   printf("size of token %d\n", strlen(tok));


   // get the 2nd line (read till you hit EOL character) 
   fgets(line, 255, fin);
   tok = strtok(line, ",");

   strcpy(name, tok);
   
   
   tok = strtok(NULL, ",");
   i = atoi(tok);

   tok = strtok(NULL, ","); 
   j = atoi(tok);
   
   tok = strtok(NULL, ",");
   k = atoi(tok);

   printf("%s\n", name);
   printf("%d\n", i);
   printf("%d\n", j);
   printf("%d\n", k);
   
   
   fseek(fin, 0, SEEK_SET);
   
   fgets(line, 255, fin);
   for (tok = strtok(line,","); tok != NULL; tok = strtok(NULL, ","))
   {
      puts(tok);
   }
   
   
   
   fclose(fin);

   return 0;


}
