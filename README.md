# mini-chapel-compiler

### Lexing

To compile the raw lexer, Create the lex (.l) file then:

- lex lex.l (Generates lex.yy.c)
- cc lex.yy.c -ll (generates an executable for the lexer)
- ./a.out

Missing from this version:
"&&" {printf("(%s, AND)\n", yytext);Insert(yytext,yylineno,"AND");}
"||" {printf("(%s, OR)\n", yytext);Insert(yytext,yylineno,"OR");}

{DIGIT}+"."{DIGIT}{+|-}{DIGIT}+"."{DIGIT}+i {yylval.sval = strdup(yytext);printf("(%s, T_COMPLEX)\n", yytext);Insert(yytext,yylineno,"COMPLEX");return T_COMPLEX;}

decide how I wanna do symbol table

change lexer from process token accordingly - set yyval.sval (https://github.com/Venkatavaradan-R/mini-chapel-compiler/blob/parse/src/lex.l#L23), insert into table if needed

remove the trash functions from the bottom of the lexer

check if productions work fully (modify for declarations if necessary)

ICG - parser modifications, function definitions

Code optimization - ???

https://github.com/sanskritip/mini-golang-compiler/blob/main/lex.l

https://github.com/sanskritip/mini-golang-compiler/blob/main/ICG/tac.y
