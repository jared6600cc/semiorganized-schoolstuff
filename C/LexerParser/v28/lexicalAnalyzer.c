/***************************************************************
  Jared Bumgardner
  lexicalAnalyzer.c
  Project 1

  Contains lexical analysis logic.
***************************************************************/
#include "lexicalAnalyzer.h"

/* Parse: Parses through specified file */
void parse(){
    lineno = 1;
    lookahead = lexan();
    match(BEGIN);                 // Beginning
    while(lookahead != END)
    {
        assignStmt();               // Middle
    }
    match(END);                   // End
    match('.');

  // Check for unexpected data at end of program
  if(lookahead != DONE){
    exitWithError(lineno, "Unexpected data after 'end.' of program");
  }
}


/* Lexan: Provides lexical analysis capabilities. Returns an integer value representing a type or a char value. */
int lexan(){
    char ch;        // char buffer (read from file)
    int type = 0;   // ID Type
    char newID[MAXIDLENGTH];    // new ID buffer
    char newNum[MAXIDLENGTH];   // new number buffer

    while(1){
        ch = fgetc(fp);
        if(ch == ' ' || ch == '\t'){}
        else if(ch == '\n'){
            lineno++;
        } else if(ch == '~'){
            // Consume entire comment
            while(fgetc(fp) != '\n'){}
        } else if(isdigit(ch)){
            memset(newNum, '\0', sizeof(newNum));
            newNum[0] = ch;
            int i = 1;
            while(1){
                    // Get entire number
                ch = fgetc(fp);
                if(isdigit(ch)){
                    newNum[i] = ch;
                } else {
                    ungetc(ch, fp);
                    break;
                }
                i++;
            }
            return NUM;
        } else if(isalpha(ch)){
            memset(newID, '\0', sizeof(newID));
            newID[0] = ch;
            int i = 1;
            // Read in entire string
            while(1){
                ch = fgetc(fp);
                if(isalpha(ch) || isdigit(ch)){
                    newID[i] = ch;
                } else if(ch == '_'){
                    newID[i] = ch;
                    //Check for consecutive underscores
                    ch = fgetc(fp);
                    if(ch == '_'){
                        exitWithError(lineno, "Consecutive underscores in ID");
                    }
                    if(!isalpha(ch) || !isdigit(ch)){
                        exitWithError(lineno, "Underscore at end of ID");
                    }
                    ungetc(ch, fp);
                } else {
                    ungetc(ch, fp);
                    break;
                }
                i++;
            }

            // Get type of string
            type = lookup(newID);
            if(type == NOT_FOUND){
                insert(newID, ID);
                return ID;
            } else {
                return type;
            }
        } else if(ch == EOF){
            return DONE;
        } else {
            return ch;
        }
    }
}
