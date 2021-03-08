%{
#include <bits/stdc++.h>
#include "y.tab.h"
using namespace std;
#include "src/SymbolTable.h"
int yylex();
extern FILE *yyin;
extern int yylineno;
//Error Handling
void yyerror (const char *s) {fprintf (stderr, "\033[0;31mLine:%d | %s\n\033[0m\n",yylineno, s);} 
vector <string> lhs;
vector <string> rhs;
%}

%start StartFile


%define parse.error verbose


%union {
     char *nt;
     char *sval;
}

%token <sval> T_REQUIRE T_DEFAULT T_CONST T_WRITELN T_EXTERN
%token <sval> T_ELSE T_FOR T_COFORALL T_COBEGIN T_IF T_VAR T_VAR_TYPE
%token <sval> T_BOOL_CONST T_NIL_VAL T_IDENTIFIER T_STRING
%token <sval> T_INCREMENT T_DECREMENT 
%token <sval> T_INTEGER T_REAL T_IMAG

%left <sval> T_ADD T_MINUS T_MULTIPLY T_DIVIDE T_MOD
%right <sval> T_ASSIGN T_AND T_NOT
%right <sval> T_COLON
%left <sval> T_LAND T_LOR T_EQL T_NEQ T_LEQ T_GEQ T_SEMICOLON
%left <sval> T_GTR T_LSR T_LEFTPARANTHESES T_RIGHTPARANTHESES T_LEFTBRACE T_RIGHTBRACE T_LEFTBRACKET T_RIGHTBRACKET T_COMMA T_PERIOD

%type <nt> StartFile Expression 
%type <nt> Block StatementList Statement SimpleStmt 
%type <nt> EmptyStmt IncDecStmt 
%type <nt> Assignment Declaration ConstDecl VarSpec
%type <nt> TopLevelDecl TopLevelDeclList
%type <nt> ForStmt ForClause
%type <nt> Condition UnaryExpr PrimaryExpr
%type <nt> TypeAssertion ExpressionList 
%type <nt> Operand Literal BasicLit OperandName IfStmt
%type <nt> RequireClause PackageName
%type <nt> TypeName


%% 

StartFile:
    RequireClause TopLevelDeclList Block{;}
	| Block{;}
	| RequireClause Block {;}
	;

Block:
	T_LEFTBRACE OPENB StatementList CLOSEB T_RIGHTBRACE{;}
	/*empty*/{;}
	; 

OPENB:
	/*empty*/{;}
	;
	
CLOSEB:
	/*empty*/{;}
	;

StatementList:
    StatementList Statement T_SEMICOLON {;}
    | Statement T_SEMICOLON {;}
	;

Statement:
	Declaration {;}
	| SimpleStmt {;}
	| Block {;}
	| IfStmt {;}
	| ForStmt {;} 
	;

SimpleStmt:
	EmptyStmt {;}
	| IncDecStmt {;}
	| Assignment {;} 
	| WriteStmt {;}
	;

WriteStmt:
	T_WRITELN{;}
	;

EmptyStmt:
	/*empty*/{;}
	;

IncDecStmt:
	Expression T_INCREMENT {;}
	|Expression T_DECREMENT {;}
	;

Assignment:
	ExpressionList assign_op ExpressionList {;}
	;

Declaration:
	VarDecl {;}
	| ConstDecl{;}
	;

VarDecl:
		T_VAR VarSpec T_COLON BasicLit {;}
		;

VarSpec:
		IdentifierList{;}
		;

ConstDecl:
		T_CONST VarSpec T_COLON BasicLit {;}
		;







IdentifierList:
		T_IDENTIFIER IdentifierLIST {;}
		| T_IDENTIFIER {;}
		;
	
IdentifierLIST:	IdentifierLIST T_COMMA T_IDENTIFIER {;}
		| T_COMMA T_IDENTIFIER {;}
		;

TopLevelDeclList:
    TopLevelDeclList T_SEMICOLON /*here colon*/ TopLevelDecl  {;}
    | TopLevelDecl  {;}
	;

TopLevelDecl:
	Declaration {;}	
	;

Type:
	TypeName {;}
	;

TypeName:
	T_IDENTIFIER {;}
	| T_VAR_TYPE {;}
	;

Operand:
	Literal {;}
	| OperandName {;}
	| T_LEFTPARANTHESES Expression T_RIGHTPARANTHESES {;}
	;

OperandName:
	T_IDENTIFIER {;}
	;



IfStmt:
	T_IF Expression Block {;}//{printf("T_IF case 1");}
	|T_IF Expression Block T_ELSE IfStmt {;}//{printf("T_IF case 5");}
	|T_IF Expression Block T_ELSE  Block {;}//{printf("T_IF case 6");}
	|T_IF SimpleStmt T_SEMICOLON Expression Block {;}//{printf("T_IF case 2");}
	|T_IF SimpleStmt T_SEMICOLON Expression Block T_ELSE IfStmt  {;}//{printf("T_IF case 3");}
	|T_IF SimpleStmt T_SEMICOLON Expression Block T_ELSE  Block {;}//{printf("T_IF case 4");}
	;

ForStmt:
	T_FOR Condition Block {;}
	|T_FOR ForClause Block {;}
	;
Condition:
	Expression {;}
	;
ForClause:
	SimpleStmt T_SEMICOLON Condition T_SEMICOLON SimpleStmt {;}
	;


ExpressionList:
		ExpressionList T_COMMA Expression {;}
		| Expression {;}
		| T_INTEGER {;}
		| T_REAL {;}
		| T_IMAG {;}
		;
Literal:
	BasicLit {;}
	;

BasicLit:
	T_VAR_TYPE {;}
	;


PrimaryExpr:
	Operand {;}
	|PrimaryExpr Selector {;}
	|PrimaryExpr Index {;}
	|PrimaryExpr TypeAssertion {;}
	;

Selector:
	T_PERIOD T_IDENTIFIER {;}
	;
Index:	
	T_LEFTBRACKET Expression T_RIGHTBRACKET {;}
	;
TypeAssertion:
	T_PERIOD T_LEFTPARANTHESES Type T_RIGHTPARANTHESES {;}
	;
Expression:
    Expression1 {;}
	;
Expression1:
    Expression1 T_LOR Expression2 {;}
    | Expression2 {;}
	;
Expression2:
    Expression2 T_LAND Expression3 {;}
    | Expression3 {;}
	;
Expression3:
    Expression3 rel_op Expression4 {;}
    | Expression4 {;}
	;
Expression4:
    Expression4 add_op Expression5 {;}
    | Expression5 {;}
	;
Expression5:
    Expression5 mul_op PrimaryExpr {;}
    | UnaryExpr {}
	;
UnaryExpr:
	PrimaryExpr {;}
	| unary_op PrimaryExpr {;}
	//UnaryExpr {;}
	;

//ops using tokens
/*
binary_op:
	T_LOR {;}
	| T_LAND {;}
	| rel_op {;}
	| add_op {;}
	| mul_op {;}
	;*/
rel_op:
	T_EQL {;}
	| T_NEQ {;}
	| T_LSR {;}
	| T_LEQ {;}
	| T_GTR {;}
	| T_GEQ {;}
	;

add_op:
	T_ADD {;}
	| T_MINUS {;}
	;

mul_op:
	T_MULTIPLY {;}
	| T_DIVIDE {;}
	| T_MOD {;}
	| T_AND {;}
	;

unary_op:
	T_ADD {;}
	| T_MINUS {;}
	| T_NOT {;}
	| T_MULTIPLY {;}
	| T_AND {;}
	;

assign_op:
	  T_ASSIGN {;}
	  ;

RequireClause:
	/*PACKAGE*/T_REQUIRE PackageName {;}
	;

PackageName:
	T_STRING T_SEMICOLON {;}
	;
	

	
%%

int main (int argc, char** argv) {	
	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("Symbol Table after Lexical Analysis: \n");
	Display();
	reverse(lhs.begin(),lhs.end());
	reverse(rhs.begin(),rhs.end());
    FILE *fptr;
    fptr = fopen("grammar_output.txt", "w+");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
	else{
		for(int i=0;i<lhs.size();i++){
			fprintf(fptr, "%s -> %s \n", lhs[i].c_str(),rhs[i].c_str());
	}
	}
	fclose(fptr);
	return 0;
}