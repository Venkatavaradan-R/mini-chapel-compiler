%{

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int yylex();

extern FILE *yyin;
extern int yylineno;

void yyerror (const char *s) {fprintf (stderr, "\033[0;31mLine:%d | %s\n\033[0m\n",yylineno, s);} 

//Quadraple Structure
  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  //Quadraples data structure
  quad q[100];
  //Top of stack
  int top=-1;


//quadraple functions
void push();
void pushi(char * i);
void codegen();
void codegen_assign();
void codegen_incdec(int o);
void printStack();
void printQuadraples();


//Optimization functions
// void constantPropagation(int index, quad arr[100]);
// int checkForDigits(char *ch);
// char* compute(char *x, char *y, char *op);
// void constantFolding(quad arr[100]);
// void copyPropagation(quad arr[100]);
// void DCE(quad arr[100]);



%}

%start program


%define parse.error verbose


%union {
     char *nt;
     char *sval;
}



//
// identifiers and literals
//
%token <sval>  TIDENT
%token <sval>  TQUERIEDIDENT
%token <sval>  INTLITERAL
%token <sval>  REALLITERAL
%token <sval>  IMAGLITERAL
%token <sval>  STRINGLITERAL
%token <sval> BYTESLITERAL
%token <sval> CSTRINGLITERAL
%token <sval> EXTERNCODE


//
// keywords (alphabetical)
//
%token <sval> TALIGN TAS TATOMIC
%token <sval> TBEGIN TBREAK TBOOL TBORROWED TBY TBYTES
%token <sval> TCATCH TCLASS TCOBEGIN TCOFORALL TCOMPLEX TCONFIG TCONST TCONTINUE
%token <sval> TDEFER TDELETE TDMAPPED TDO TDOMAIN
%token <sval> TELSE TENUM TEXCEPT TEXPORT TEXTERN
%token <sval> TFALSE TFOR TFORALL TFOREACH TFORWARDING
%token <sval> TIF TIMAG TIMPORT TIN TINCLUDE
%token <sval> TINDEX TINLINE TINOUT TINT TITER TINITEQUALS
%token <sval> TIMPLEMENTS TINTERFACE
%token <sval> TLABEL TLAMBDA TLET TLIFETIME TLOCAL TLOCALE
%token <sval> TMINUSMINUS TMODULE
%token <sval> TNEW TNIL TNOINIT TNONE TNOTHING
%token <sval> TON TONLY TOPERATOR TOTHERWISE TOUT TOVERRIDE TOWNED
%token <sval> TPARAM TPLUSPLUS TPRAGMA TPRIMITIVE TPRIVATE TPROC TPROTOTYPE TPUBLIC
%token <sval> TREAL TRECORD TREDUCE TREF TREQUIRE TRETURN
%token <sval> TSCAN TSELECT TSERIAL TSHARED TSINGLE TSPARSE TSTRING TSUBDOMAIN TSYNC
%token <sval> TTHEN TTHIS TTHROW TTHROWS TTRUE TTRY TTRYBANG TTYPE
%token <sval> TUINT TUNDERSCORE TUNION TUNMANAGED TUSE
%token <sval> TVAR TVOID
%token <sval> TWHEN TWHERE TWHILE TWITH
%token <sval> TYIELD
%token <sval> TZIP



//
// operators and punctuation (alphabetical)
//

%token <sval> TALIAS TAND TASSIGN TASSIGNBAND TASSIGNBOR TASSIGNBXOR TASSIGNDIVIDE
%token <sval> TASSIGNEXP TASSIGNLAND TASSIGNLOR TASSIGNMINUS TASSIGNMOD
%token <sval> TASSIGNMULTIPLY TASSIGNPLUS TASSIGNREDUCE TASSIGNSL TASSIGNSR
%token <sval> TBANG TBAND TBNOT TBOR TBXOR
%token <sval> TCOLON TCOMMA
%token <sval> TDIVIDE TDOT TDOTDOT TDOTDOTDOT
%token <sval> TEQUAL TEXP TGREATER
%token <sval> TGREATEREQUAL
%token <sval> THASH
%token <sval> TIO
%token <sval> TLESS
%token <sval> TLESSEQUAL
%token <sval> TMINUS TMOD
%token <sval> TNOTEQUAL
%token <sval> TOR
%token <sval> TPLUS
%token <sval> TQUESTION
%token <sval> TSEMI TSHIFTLEFT TSHIFTRIGHT TSTAR TSWAP

//
// braces
//

%token <sval> TLCBR TRCBR TLP TRP TLSBR TRSBR

//
// keywords, operators, and punctuation that requires precedence
//

%left TNOELSE
%left TELSE
%left TCOMMA
%left TFOR TFORALL TFOREACH TIF TATOMIC TSYNC TSINGLE

// %left TOWNED TUNMANAGED TSHARED
%left TIN
%left TALIGN TBY THASH
%left TOR
%left TAND
%left TEQUAL TNOTEQUAL
%left TLESSEQUAL TGREATEREQUAL TLESS TGREATER
%left TDOTDOT TDOTDOTOPENHIGH

// These are not currently supported, though we've discussed adding them
//%left TDOTDOTOPENLOW TDOTDOTOPENBOTH

%left TPLUS TMINUS
%left TBOR
%left TBXOR
%left TBAND
%left TSHIFTLEFT TSHIFTRIGHT
%right TUPLUS TUMINUS
%left TSTAR TDIVIDE TMOD
%right TBNOT TLNOT
%left TREDUCE TSCAN TDMAPPED
%right TEXP
%left TCOLON
%right TBORROWED TOWNED TUNMANAGED TSHARED
%left TQUESTION TBANG
%right TNEW
%left TDOT TLP TRSBR TLCBR
%nonassoc TPRAGMA

%type <sval>  assignop_ident

%type <sval>  program
%type <sval>  toplevel_stmt_ls
%type <sval>  toplevel_stmt
%type <sval>        pragma_ls
%type <sval>  block_stmt
%type <sval>  require_stmt
%type <sval>  stmt
%type <sval>  assignment_stmt
%type <sval>  bool_literal str_bytes_literal literal_expr
%type <sval>  opt_try_expr
%type <sval>  query_expr

%% 


program:
  toplevel_stmt_ls                     {;}
;

toplevel_stmt_ls:
                                       {;}
| toplevel_stmt_ls toplevel_stmt       {;}
;


toplevel_stmt:
  stmt                                {;}
| class_level_stmt                    {;}
| pragma_ls stmt                      {;}
;



class_level_stmt:
  TSEMI                 { ; }
| private_decl
| TPUBLIC private_decl  { ; }
;

private_decl:
var_decl_stmt
;

var_decl_stmt:
  TCONFIG var_decl_type var_decl_stmt_inner_ls TSEMI

| var_decl_type var_decl_stmt_inner_ls TSEMI
;

var_decl_type:
  TPARAM      { ; }
| TCONST      { ; }
| TVAR        { ; }
;

var_decl_stmt_inner_ls:
  var_decl_stmt_inner
| var_decl_stmt_inner_ls TCOMMA var_decl_stmt_inner
;

var_decl_stmt_inner:
  ident_def opt_type opt_init_expr


;

ident_def:
  TIDENT                   { push(); }
| internal_type_ident_def  { ; }
;

internal_type_ident_def:

  TBOOL      { push(); }
| TINT       { push(); }
| TUINT      { push(); }
| TREAL      { push(); }
| TIMAG      { push(); }
| TCOMPLEX   { push(); }
| TBYTES     { push(); }
| TSTRING    { push(); }
;


opt_type:
                          { ; }
| TCOLON type_level_expr  { ; }
;


type_level_expr:
  sub_type_level_expr
    { ; }

;

sub_type_level_expr:
  nil_expr
| lhs_expr   
| unary_op_expr            
| binary_op_expr                    
| TSINGLE expr

nil_expr:
  TNIL      {; }
;

unary_op_expr:

TMINUSMINUS expr %prec TUMINUS  { ; }
| TPLUSPLUS expr %prec TUPLUS     { ; }
| TBANG expr %prec TLNOT          { ; }
;

binary_op_expr:
  expr binary_op expr          { codegen(); }
;

binary_op:

TPLUS              { push(); }
|  TMINUS          { push(); }
|  TSTAR           { push(); }
|  TDIVIDE         { push(); }
|  TSHIFTLEFT      { push(); }
|  TSHIFTRIGHT     { push(); }
|  TMOD            { push(); }
|  TEQUAL          { push(); }
|  TNOTEQUAL       { push(); }
|  TLESSEQUAL      { push(); }
|  TGREATEREQUAL   { push(); }
|  TLESS           { push(); }
|  TGREATER        { push(); }
|  TBAND           { push(); }
|  TBOR            { push(); }
|  TBXOR           { push(); }
|  TAND            { push(); }
|  TOR             { push(); }
|  TEXP            { push(); }
;




opt_init_expr:
                        { ; }
| TASSIGN TNOINIT       { ; }
| TASSIGN expr  { codegen_assign(); }
;


// Sequence of pragmas
pragma_ls:
  TPRAGMA STRINGLITERAL                {;}
| pragma_ls TPRAGMA STRINGLITERAL      {;}
;

// %type <sval> stmt
stmt:
block_stmt
| require_stmt
| assignment_stmt
;


block_stmt:
  TLCBR         TRCBR                  {;}
| TLCBR stmt_ls TRCBR                  {;}
| TLCBR error   TRCBR                  {;}
;

stmt_ls:
  toplevel_stmt                        {;}
| stmt_ls toplevel_stmt                {;}
;


require_stmt:
  TREQUIRE expr_ls TSEMI               {;}
;

expr_ls:
  expr                       {;}
| query_expr                 {;}
| expr_ls TCOMMA expr        {;}
| expr_ls TCOMMA query_expr  {;}
;

query_expr:
  TQUERIEDIDENT       {push();}
;



expr:
  literal_expr
| type_level_expr
| expr TCOLON expr
    {;}

;

literal_expr:
  bool_literal
| str_bytes_literal
| INTLITERAL            {push();}
| REALLITERAL           {push();}
| IMAGLITERAL           {push();}
| TNONE                 {;}
| TLCBR expr_ls TRCBR   {;}


;

str_bytes_literal:
  STRINGLITERAL   {push();}
| BYTESLITERAL    {push();}
;

bool_literal:
  TFALSE {push();}
| TTRUE  {push();}
;


assignment_stmt:
  lhs_expr assignop_ident opt_try_expr TSEMI
    {codegen_assign();}

;


lhs_expr:
  ident_expr {;}
;

ident_expr:
  ident_use      {; }
| scalar_type    { ; }
;

ident_use:
  TIDENT                   { push();}
;

scalar_type:
  TBOOL    { push();}
| TENUM    { push();}
| TINT     { push();}
| TUINT    { push();}
| TREAL    { push();}
| TIMAG    { push();}
| TCOMPLEX { push();}
| TBYTES   { push();}
| TSTRING  { push();}
| TNOTHING { push();}
| TVOID    { push();}
;

assignop_ident:
  TASSIGN        {push();}
| TASSIGNPLUS    {push();}
| TASSIGNMINUS   {push();}
| TASSIGNMULTIPLY {push();}
| TASSIGNDIVIDE  {push();}
| TASSIGNMOD     {push();}
| TASSIGNEXP     {push();}
| TASSIGNBAND    {push();}
| TASSIGNBOR     {push();}
| TASSIGNBXOR    {push();}
| TASSIGNSR      {push();}
| TASSIGNSL      {push();}
;


opt_try_expr:
  TTRY expr       { ;}
| expr            { ; }
;








	
%%

#include "lex.yy.c"
#include<ctype.h>
#include<fstream>
//Stack
char st[100][100];
char i_[2]="0";
//Temporary variable counter
int temp_i=0;
//Char string to store temporary varoable number
char tmp_i[3];
char temp[2]="t";
//Array for labels
int label[20];
//Label number counter
int lnum=0;
//Top of label stack
int ltop=0;
//Label counter for loop
int l_for=0;
//Output tac file
ofstream fo;



int main (int argc, char** argv) {	
	printf("Inside main\n");

	FILE * fp= fopen(argv[1], "r");
	yyin = fp;

	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");

	yyparse ( );

	printf("\n\033[0;32mLexing completed.\033[0m\n\n");
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");

  printf("---------------------ICG in the form of Quadruples-------------------------\n\n");
    printQuadraples();


	return 0;
}


//Print top of stack
void printStack()
{
    cout << "Stack Top " << st[top] <<" "<<st[top-1]<<" "<<st[top-2]<<" "<<st[top-3]<<endl;
}
//Pushing to stack using yytext
void push()
{
    cout << "Pushed to stack : "<<yytext<<endl;
    strcpy(st[++top],yytext);
    printStack();
}


void codegen()
{   //Intermediate operation assigned to temporary variable
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //Quad creation (eq. T = a + c)
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    //Writing into output tac file
    fo << temp <<" = "<<st[top-2]<<" "<<st[top-1]<<" "<<st[top]<<endl;
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //Pop 3 elements from stack (eq. a + c)
    top-=2;
    //Pushing temporary variable to stack
    strcpy(st[top],temp);
    temp_i++;
}

void codegen_assign()
{  
    //Assignment operation (eg. b = T2 )
    //T2 < = < b 
    //Writing into output tac file
    fo << st[top-2] <<" = "<<st[top]<<endl;
    printf("%s = %s\n",st[top-2],st[top]);
    //Quad creation
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-2]);
    quadlen++;
    //Pop elements from stack
    top-=3;
}

//Pushing to stack by passing value
void pushi(char * i)
{
    cout << "Pushed to stack : "<<i<<endl;
    strcpy(st[++top],i);
}


//Only for identifiers
void codegen_incdec(int o){
    //Check if increment or decrement
    if(o)
        pushi("+");
    else
        pushi("-");
    // Push one to stack
    pushi("1");
    // Get identifier at position top-2 which has to be incremented
    char tempi[31];
    strcpy(tempi,st[top-2]);
    //quad generation like Tx = a + 1
    codegen();
    pushi("=");
    cout<<"hello "<<st[top]<<" "<<st[top-1]<<" "<<st[top-2]<<endl;
    //Pushing temporary variable to top of stack and identifier downwards so Tx=a+1 and a=Tx
    pushi(st[top-1]);
    cout<<"hello "<<st[top]<<" "<<st[top-1]<<" "<<st[top-2]<<endl;
    strcpy(st[top-2],tempi);
    //Quad genreation for a = Tx
    codegen_assign();
}

//Print Quadraples
void printQuadraples()
{
    for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
    printf("Operator \t | Arg1 \t | Arg2 \t | Result \n");
    for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
    int i;
    for(i=0;i<quadlen;i++)
    {
        printf("%-8s \t | %-8s \t | %-8s \t | %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
	for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
}