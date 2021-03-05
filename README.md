# mini-chapel-compiler

### Lexing

To compile the raw lexer, Create the lex (.l) file then:

- lex lex.l (Generates lex.yy.c)
- cc lex.yy.c -ll (generates an executable for the lexer)
- ./a.out
