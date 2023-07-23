/***************************************************************
  Jared Bumgardner
  parser.c
  Project 2

  Contains recursive descent parser logic.
  Also contains a Stack ADT implementation.
***************************************************************/
#include "parser.h"

int lineno;                         // Line number counter
int lookahead;                      // Next token from lexical analyzer
int currRegister;                   // Current register for printing low level code
char result[MAXIDLENGTH];           // Holds the left hand side of an expression
char expression[256];               // Holds the an expression read from the program
char postExpression[256];           // Represents expression in postFix format
char * registers[MAXLEXEMECOUNT];   // For generating register code


/* CHARACTER STACK ADT */
char array[STACKMAX];               // FiFo Array

// charStackPeek(): Returns the element at the top of the charStack as a char.
char charStackPeek(){
    char returnVal;
    if(top < 0){
        printf("ERROR: Cannot peek on empty stack\n");
        returnVal = '\0';
    } else {
        returnVal = array[top];
    }
    return returnVal;
}

// charStackPush(char newC): Pushes newC onto the top of the stack.
void charStackPush(char newC){
    if(top == STACKMAX-1){
        printf("ERROR: Push failed / stack full\n");
    } else {
        top++;
        array[top] = newC;
    }
}

// charStackPop(): Removes the top element from the stack and returns it.
char charStackPop(){
    char returnVal;
    if(top < 0){
        printf("ERROR: Cannot pop an empty stack\n");
        returnVal = '\0';
    } else {
        returnVal = array[top];
        top--;
    }
    return returnVal;
}

// charStackIsEmpty(): Returns 1(true) if the stack is empty; returns 0(false) otherwise
int charStackIsEmpty(){
    if(top <= 0)
        return 1;
    else
        return 0;
}

// charStackInit(int size): Initializes stack parameters
void charStackInit(int size){
    top = -1;
}



/* PARSER */
// getOperatorPrecedence(char op): Gets precedence/rank of operation op & return it.
int getOperatorPrecedence(char op){
    int returnVal = -1;
    switch(op){
    case '*': case '/':                    // M&D: Mult & Div
        returnVal = 2;
        break;
    case '+': case '-':
        returnVal = 1;                   // A&S: Add & Subtr
        break;
    }
    return returnVal;
}

// infixToPostfix(): Converts saved expression from infix notation to postfix notation & prints to console.
void infixToPostfix(){
    char c, x, z;
    memset(postExpression, '\0', strlen(postExpression));
    for(int i=0; expression[i] != '\0'; i++){
        c = expression[i];
        if(getOperatorPrecedence(c) > 0){
            // c is an operator
            while((top != -1) && (getOperatorPrecedence(charStackPeek()) >= getOperatorPrecedence(c))){
                z = charStackPop();
                strncat(postExpression, &z, 1);
                strcat(postExpression, ", ");
            }
            charStackPush(c);
        } else if(c == ')'){
            x = charStackPop();
            while(x != '('){
                if(x != ')' && x != ')'){
                    strncat(postExpression, &x, 1);
                    strcat(postExpression, ", ");
                }
                x = charStackPop();
            }
        } else if(c == '('){
            charStackPush(c);
        } else {
            // c is an operand
            strncat(postExpression, &c, 1);
            if(isalnum(expression[i+1]) == 0 && expression[i+1] != '_'){    // add delim?
                strcat(postExpression, ", ");
            }
        }
    }
    while(charStackIsEmpty() == 0){
            c = charStackPop();
            if(c != ')' && c != ')'){
                strncat(postExpression, &c, 1);
                strcat(postExpression, ", ");
            }
    }
    printf("***POSTFIX: [%s]***\n", postExpression);
}

// exitWithError(..): Prints illegal program summary & exits with a negative value
void exitWithError(int errorLineNo, char * errorMessage){
    printf("***Program is illegal***\n");
    printf("***Line %d contains error: %s.***\n", errorLineNo-1, errorMessage);
    exit(-1);
}

// match(int given):  Match given tokenType with the lookahead.
void match(int given){
    if(lookahead == given){
        lookahead = lexan();
    } else {
        // Syntax error detected
        exitWithError(lineno, "Mismatched lookahead");
    }
}

// assignStmt(): Match an assignment statement of the form "ID = <expression>;"
void assignStmt(){
    match(ID);
    strcpy(result, idLexeme[idLexemeCount]);
    if(lookup(idLexeme[idLexemeCount]) == -1){
       char message[MAXIDLENGTH*2];
       sprintf(message, "Undefined variable %s\n", idLexeme[idLexemeCount]);
       exitWithError(lineno, message);
    }
    if(lookahead != '='){
        exitWithError(lineno, "Unexpected data");
    } else {
        match('=');
        expr();
        match(';');
    }
}

// expr(): Match an expression of the form "<term> (+ || -) <term> (+ || -) ... etc"
void expr(){
    term();
    while(lookahead == '+' || lookahead == '-'){
        char s[16];
        sprintf(s, "%c", lookahead);
        strcat(expression, s);
        int operation = lookahead;
        match(lookahead);
        term();
        printf("R%d = R%d %c R%d\n", currRegister-2, currRegister-2, operation, currRegister-1);
        currRegister--;
    }
}

// term(): Match a term of the form "<factor> (* || /) <factor> (* || /) ... etc"
void term(){
    factor();
    while(lookahead == '*' || lookahead == '/'){
        char s[16];
        sprintf(s, "%c", lookahead);
        strcat(expression, s);
        int operation = lookahead;
        match(lookahead);
        factor();
        printf("R%d = R%d %c R%d\n", currRegister-2, currRegister-2, operation, currRegister-1);
        currRegister--;
    }
}

// factor(): Match a factor of the form "<ID>, <NUM>, or (<expression>)"
void factor(){
    if(lookahead == ID){
        match(ID);
        printf("R%d = %s\n", currRegister, idLexeme[idLexemeCount]);
        registers[currRegister] = idLexeme[idLexemeCount];
        currRegister++;
        strcat(expression, idLexeme[idLexemeCount]);
        if((insert(idLexeme[idLexemeCount], ID)) > 0){
            char message[MAXIDLENGTH*2];
            sprintf(message, "Variable <%s> used but not declared", idLexeme[idLexemeCount]);
            exitWithError(lineno, message);
        }
    } else if(lookahead == NUM){
        match(NUM);
        printf("R%d = %s\n", currRegister, numLexeme[numLexemeCount]);
        registers[currRegister] = numLexeme[numLexemeCount];
        currRegister++;
        strcat(expression, numLexeme[numLexemeCount]);
    } else if(lookahead == '('){
        match('(');
        strcat(expression, "(");
        expr();
        match(')');
        strcat(expression, ")");
    } else {
	exitWithError(lineno, "Unexpected data in factor");
    }
}

// intDecls(): Match a factor of the form <varDeclaration><varDecls> || empty
void intDecls(){
    while(lookahead == INT){
        intDeclaration();
    }
}

// intDeclaration(): Match a factor of the form "int <ID> = <NUM>;" OR "int <ID>;"
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
// parse(): Parses through specified file
void parse(){
    lineno = 1;
    currRegister = 0;

    lookahead = lexan();
    match(BEGIN);                 // Beginning
    intDecls();
    while(lookahead != END)
    {
        assignStmt();               // Middle
        printf("%s = R%d\n", result, currRegister-1);
        infixToPostfix();
        memset(expression, '\0', strlen(expression));
        currRegister = 0;
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
}


// lexan(): Provides lexical analysis capabilities. Returns an integer value representing a type or a char value.
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
