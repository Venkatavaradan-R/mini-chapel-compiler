# mini-chapel-compiler

### Lexing

To compile the raw lexer, Create the lex (.l) file then:

- lex lex.l (Generates lex.yy.c)
- cc lex.yy.c -ll (generates an executable for the lexer)
- ./a.out

~ decide how I wanna do symbol table

~ change lexer from process token accordingly - set yyval.sval (https://github.com/Venkatavaradan-R/mini-chapel-compiler/blob/parse/src/lex.l#L23), insert into table if needed

~ remove the trash functions from the bottom of the lexer

~ check if productions work fully (modify for declarations if necessary)

ICG - parser modifications, function definitions

Code optimization - ???

https://github.com/sanskritip/mini-golang-compiler/blob/main/lex.l

https://github.com/sanskritip/mini-golang-compiler/blob/main/ICG/tac.y

a = 10 + 2;

t0 = 10+2
a=t0;

t0 = 10+5; //
x = t0; //

s o a1 a2 r
0 + 10 5 t0
1 = t0 x

a = 10 + 2

stack

# a

t0

# x

10

- 5

* 2

t0 = 10+5
t1= t0-2
x=t1

- 10 5 t0

* t0 2 t1
  = t1 N x
