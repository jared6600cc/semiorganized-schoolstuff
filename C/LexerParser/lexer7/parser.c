/***************************************************************
  Jared Bumgardner
  parser.c
  Project 1

  Contains recursive descent parser logic.
***************************************************************/
#include "parser.h"
#include "parseTree.h"

int lineno;     // Line number counter
int lookahead;      // Next token from lexical analyzer

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
        printf("Syntax Error: Given %d, lookahead %d\n", given, lookahead);
        exitWithError(lineno, "Mismatched lookahead");
        exit(-1);
    }
}

/* assignStmt: Match an assignment statement of the form "ID = <expression>;" */
void assignStmt(){
    match(ID);
    strcat(unparenthesizedStmt, idLexeme[idLexemeCount]);
    if(lookup(idLexeme[idLexemeCount]) == -1){
       char message[MAXIDLENGTH*2];
       sprintf(message, "Undefined variable %s\n", idLexeme[idLexemeCount]);
       exitWithError(lineno, message);
    } else {
        result = idLexeme[idLexemeCount];
    }
    if(lookahead != '='){
        perror("ERROR: Unexpected data\n");
        printf("\n***Program is illegal***\n");
        exit(-1);
    } else {
        strcat(unparenthesizedStmt, "=");
        match('=');
        expr();
        match(';');
    }
}

/* expr: Match an expression of the form "<term> (+ || -) <term> (+ || -) ... etc" */
void expr(){
    term();
    while(lookahead == '+' || lookahead == '-'){
            if(lookahead == '+'){
                    strcat(unparenthesizedStmt, "+");
            }
            if(lookahead == '-'){
                    strcat(unparenthesizedStmt, "-");
            }
//            sprintf(lookaheadString, "%c", lookahead);
 //           printf("%d", lookahead);
//            strcat(parenthesizedStatement, lookaheadString);
//            parseTreeOperator(lookahead);
        match(lookahead);
        term();
    }
}

/* term: Match a term of the form "<factor> (* || /) <factor> (* || /) ... etc" */
void term(){
    factor();
    while(lookahead == '*' || lookahead == '/'){
//            parseTreeOperator(lookahead);
        if(lookahead == '*'){
                strcat(unparenthesizedStmt, "*");
        }
        if(lookahead == '/'){
                strcat(unparenthesizedStmt, "/");
        }
        match(lookahead);
        factor();
    }
}

/* factor: Match a factor of the form "<ID>, <NUM>, or (<expression>)" */
void factor(){
    if(lookahead == ID){
        match(ID);
        strcat(unparenthesizedStmt, idLexeme[idLexemeCount]);
//        parseTreeTerminal(idLexeme[idLexemeCount]);
    } else if(lookahead == NUM){
        match(NUM);
        strcat(unparenthesizedStmt, numLexeme[numLexemeCount]);
//        parseTreeTerminal(numLexeme[numLexemeCount]);
    } else if(lookahead == '('){
              strcat(unparenthesizedStmt, "(");
        match('(');
//        parseTreeOpenBracket();
        expr();
        strcat(unparenthesizedStmt, ")");
        match(')');
//        parseTreeCloseBracket();
    } else {
        perror("ERROR in factor()\n");
    }
}

/* intDecls: Match a factor of the form <varDeclaration><varDecls> || empty */
void intDecls(){
    while(lookahead == INT){
        intDeclaration();
    }
}

/* intDeclaration: Match a factor of the form "int <ID> = <NUM>;" OR "int <ID>;" */
void intDeclaration(){
    match(INT);
    if((insert(idLexeme[idLexemeCount], ID)) < 0){// previously defined in symTable
        char message[MAXIDLENGTH*2];
        sprintf(message, "Illegal redefinition <%s>\n", idLexeme[idLexemeCount]);
        exitWithError(lineno, message);
    }

    match(ID);
    while(lookahead == ','){
        match(',');
        if((insert(idLexeme[idLexemeCount], ID)) < 0){// previously defined in symTable
        char message[MAXIDLENGTH*2];
        sprintf(message, "Illegal redefinition <%s>\n", idLexeme[idLexemeCount]);
        exitWithError(lineno, message);
    }
        match(ID);
    }
    match(';');
}

/* Lexical Analysis */
/* Parse: Parses through specified file */
void parse(){
    lineno = 1;
    lookahead = lexan();
    match(BEGIN);                 // Beginning
    intDecls();
    while(lookahead != END)
    {
        initParseTree();                            // PARSE TREE CALL
        assignStmt();               // Middle
        postOrderPrint();
        printf("\n");
    }
    match(END);                   // End
    match('.');

  // Check for unexpected data at end of program
  if(lookahead != DONE){
    exitWithError(lineno, "Unexpected data after 'end.' of program");
  }
}

void process(){
	initSymTable();
	parse();
//	printSymTable();
}


/* Lexan: Provides lexical analysis capabilities. Returns an integer value representing a type or a char value. */
int lexan(){
    char ch;        // char buffer (read from file)
    char newID[MAXIDLENGTH];    // new ID buffer
    char newNum[MAXIDLENGTH];   // new number buffer
    int type;       // tokentype to be returned

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
            strcpy(numLexeme[idLexemeCount], newNum);
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
                    if(!isalnum(ch)){
                        exitWithError(lineno, "Underscore at end of ID");
                    }
                    ungetc(ch, fp);
                } else {
                    ungetc(ch, fp);
                    break;
                }
                i++;
            }
            strcpy(idLexeme[idLexemeCount], newID);

            // Get type of string
            type = lookup(newID);
            if(type == NOT_FOUND){
//                insert(newID, ID);
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
