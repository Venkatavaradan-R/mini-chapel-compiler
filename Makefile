all:
	lex src/lex.l
	yacc -d src/yacc.y --warnings=none
	g++ y.tab.c -ll -w -o chplcompiler	
clean:
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	rm gocompiler

