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

Tokens:

// TFOR - for loop
TIDENT
TIN - access specifier 'in'
TINTLITERAL
TDOTDOT - .. in stuff like 1..10
TLCBR - open curly bracket (left)
TIDENT
TLPAREN
TIDENT
TRPAREN
TSEMI
TRCBR - close curly bracket (right)
