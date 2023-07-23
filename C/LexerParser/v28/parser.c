/***************************************************************
  Jared Bumgardner
  parser.c
  Project 1

  Contains recursive descent parser logic.
***************************************************************/
#include "parser.h"


/* exitWithError: Prints illegal program summary & exits with a negative value */
void exitWithError(int errorLineNo, char * errorMessage){
    printf("\n***Program is illegal***");
    printf("\nLine %d contains error: %s.\n", errorLineNo, errorMessage);
    exit(-1);
}


/* Match:  Match given tokenType with the lookahead. Or not. */
void match(int given){
    if(lookahead == given){
        lookahead = lexan();
    } else {
        // Syntax error detected
        exitWithError(lineno, "Mismatched lookahead");
        exit(-1);
    }
}

/* assignStmt: Match an assignment statement of the form "ID = <expression>;" */
void assignStmt(){
    match(ID);
    if(lookahead != '='){
        perror("ERROR: Unexpected data\n");
        printf("\n***Program is illegal***\n");
        exit(-1);
    } else {
        match('=');
        expr();
        match(';');
    }
}

/* expr: Match an expression of the form "<term> (+ || -) <term> (+ || -) ... etc" */
void expr(){
    term();
    while(lookahead == '+' || lookahead == '-'){
        match(lookahead);
        term();
    }
}

/* term: Match a term of the form "<factor> (* || /) <factor> (* || /) ... etc" */
void term(){
    factor();
    while(lookahead == '*' || lookahead == '/'){
        match(lookahead);
        factor();
    }
}

/* factor: Match a factor of the form "<ID>, <NUM>, or (<expression>)" */
void factor(){
    if(lookahead == ID){
        match(ID);
    } else if(lookahead == NUM){
        match(NUM);
    } else if(lookahead == '('){
        match('(');
        expr();
        match(')');
    } else {
        perror("ERROR in factor()\n");
    }
}
