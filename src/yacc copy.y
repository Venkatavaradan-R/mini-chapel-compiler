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

%union {
     char *nt;
     char *sval;
}

%token <sval> T_REQUIRE T_CONTINUE T_DEFAULT
%token <sval> T_ELSE T_FOR T_COFORALL T_COBEGIN T_IF T_VAR T_VAR_TYPE
%token <sval> T_BOOL_CONST T_NIL_VAL T_IDENTIFIER T_STRING
%token <sval> T_INCREMENT T_DECREMENT 
%token <sval> T_INTEGER T_REAL T_IMAG T_COMPLEX

%left <sval> T_ADD T_MINUS T_MULTIPLY T_DIVIDE T_MOD
%right <sval> T_ASSIGN T_AND T_NOT
%right <sval> T_COLON
%left <sval> T_LAND T_LOR T_EQL T_NEQ T_LEQ T_GEQ T_SEMICOLON
%left <sval> T_GTR T_LSR T_LEFTPARANTHESES T_RIGHTPARANTHESES T_LEFTBRACE T_RIGHTBRACE T_LEFTBRACKET T_RIGHTBRACKET T_COMMA T_PERIOD

%type <nt> StartFile Expression 
%type <nt> Block StatementList Statement SimpleStmt 
%type <nt> EmptyStmt IncDecStmt 
%type <nt> Assignment Declaration ConstDecl VarSpec
%type <nt> Signature Result Parameters ParameterList ParameterDecl
%type <nt> ConstSpec TopLevelDecl TopLevelDeclList
%type <nt> ReturnStmt BreakStmt ContinueStmt
%type <nt> FunctionDecl FunctionName TypeList
%type <nt> Function FunctionBody FunctionCall ForStmt ForClause ArgumentList
%type <nt> Condition UnaryExpr PrimaryExpr
%type <nt> TypeAssertion ExpressionList 
%type <nt> Operand Literal BasicLit OperandName ImportSpec IfStmt
%type <nt> ImportPath
%type <nt> PackageClause PackageName ImportDecl ImportDeclList ImportSpecList
%type <nt> TypeName
%% 

StartFile:
    PackageClause ImportDeclList TopLevelDeclList {;};

Block:
	T_LEFTBRACE OPENB StatementList CLOSEB T_RIGHTBRACE{;}
	/*empty*/{;}; 

OPENB:
	/*empty*/{;};
	
CLOSEB:
	/*empty*/{;};

StatementList:
    StatementList Statement T_SEMICOLON {;}
    | Statement T_SEMICOLON {;}
	| StatementList Statement {;}
    | Statement;}
	;

Statement:
	Declaration {;}
	| SimpleStmt {;}
	| ReturnStmt {;}
	| BreakStmt {;}
	| ContinueStmt {;}
	| Block {;}
	| IfStmt {;}
	| ForStmt {;} 
	| FunctionCall {;} 
	;

SimpleStmt:
	EmptyStmt {;}
	| IncDecStmt {;}
	| Assignment {;} 
	;

EmptyStmt:
	/*empty*/{;}
	;

IncDecStmt:
	Expression T_INCREMENT {;}
	| Expression T_DECREMENT {;}
	;

Assignment:
	ExpressionList assign_op ExpressionList {;}
	;

Declaration:
	ConstDecl {;}
	|VarDecl {;}
	;

VarDecl:
		T_VAR VarSpec {;}
		;

VarSpec:
		IdentifierList Type T_ASSIGN ExpressionList {;}
		| IdentifierList Type {;}
		;

ConstDecl:
		T_CONST ConstSpec {;}
		;

ConstSpec:
		T_IDENTIFIER Type T_ASSIGN Expression {;}
		| T_IDENTIFIER Type {;}
		;

FunctionDecl:
		T_FUNC FunctionName Function  {;}
		| T_FUNC FunctionName Signature {;}
		;

FunctionName:
		T_IDENTIFIER {;}
		;

Function:
		Signature FunctionBody {;}
		;

FunctionBody:		
		Block {;}
		;

FunctionCall:	
		PrimaryExpr T_LEFTPARANTHESES ArgumentList T_RIGHTPARANTHESES {;}
		;		

ArgumentList:	
		ArgumentList T_COMMA Arguments {;}
		| Arguments {;}
		| /*empty*/{;}
		;

//Accounts for function call as Arguement can remove that part if need :)
Arguments:	PrimaryExpr {;}//{printf("------------");}
		| FunctionCall {;}
		;

Signature:
	Parameters {;}
	| Parameters Result {;}
	;

Result:
	T_LEFTPARANTHESES TypeList T_RIGHTPARANTHESES {;}
	| Type  {;}
	;

Parameters:
	T_LEFTPARANTHESES T_RIGHTPARANTHESES {;}//printf("gor T_func with no arguments");}
	| T_LEFTPARANTHESES ParameterList T_RIGHTPARANTHESES {;}
	|T_LEFTPARANTHESES ParameterList T_COMMA T_RIGHTPARANTHESES {;}
	; 

ParameterList:
	ParameterDecl {;}
	|ParameterList T_COMMA ParameterDecl {;}
	;

ParameterDecl:
	IdentifierList Type {;}
	| IdentifierList T_ELLIPSIS  Type {;}
	| T_ELLIPSIS Type {;}
	;

TypeList:
    TypeList T_COMMA Type {;}
    | Type {;}
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
	| FunctionDecl {;}
	;

Type:
	TypeName {;}
	|TypeLit {;}
	;

TypeName:
	T_IDENTIFIER {;}
	| T_VAR_TYPE {;}
	;

TypeLit:
	FunctionType {;}
	;

FunctionType:
	T_FUNC Signature {;}
	;

Operand:
	Literal {;}
	| OperandName {;}
	| T_LEFTPARANTHESES Expression T_RIGHTPARANTHESES {;}
	;

OperandName:
	T_IDENTIFIER {;}
	;

ReturnStmt:
	T_RETURN Expression {;}
	| T_RETURN {;}
	;

BreakStmt:
	T_BREAK {;}
	;

ContinueStmt:
	T_CONTINUE {;}
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
		;
Literal:
	BasicLit {;}
	| FunctionLit {;}
	;

BasicLit:
	T_INTEGER {;}
	| T_FLOAT {;}
	| T_STRING {;}
	| T_BYTE {;}
	;

FunctionLit:
	T_FUNC Function {;}
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

PackageClause:
	/*PACKAGE*/T_PACKAGE PackageName {;}
	;

PackageName:
	T_IDENTIFIER {;}|
	T_STRING {;}	|
	T_STRING T_SEMICOLON {;}
	;
	
ImportDeclList:
      ImportDeclList ImportDecl  {;}//{ printf("got import list 1");}
    | ImportDecl  {;}//{ printf("got import list 2"); }
    | /*empty*/ {;}//{ printf("got import list 3");}
	;

ImportDecl:
	T_IMPORT ImportSpec {;}//{printf("got imports 1");}
	| T_IMPORT T_LEFTPARANTHESES ImportSpecList  T_RIGHTPARANTHESES {;}//{printf("got imports 2");}
	;

ImportSpecList:
	ImportSpecList ImportSpec {;}
	| ImportSpec {;}
	;
ImportSpec:
	 T_PERIOD ImportPath {;}
	| PackageName ImportPath {;}
	| PackageName {;};

ImportPath:
	T_STRING {;}|
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