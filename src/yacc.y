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
| TCONST      {; }
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
  TIDENT                   { ; }
| internal_type_ident_def  { ; }
;

internal_type_ident_def:

  TBOOL      {; }
| TINT       { ; }
| TUINT      { ; }
| TREAL      { ; }
| TIMAG      { ; }
| TCOMPLEX   { ; }
| TBYTES     {; }
| TSTRING    { ; }
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
  expr TPLUS expr          { ; }
| expr TMINUS expr         { ; }
| expr TSTAR expr          { ; }
| expr TDIVIDE expr        { ; }
| expr TSHIFTLEFT expr     { ; }
| expr TSHIFTRIGHT expr    { ; }
| expr TMOD expr           { ; }
| expr TEQUAL expr         { ; }
| expr TNOTEQUAL expr      { ; }
| expr TLESSEQUAL expr     { ; }
| expr TGREATEREQUAL expr  { ; }
| expr TLESS expr          { ; }
| expr TGREATER expr       { ; }
| expr TBAND expr          { ; }
| expr TBOR expr           { ; }
| expr TBXOR expr          { ; }
| expr TAND expr           { ; }
| expr TOR  expr           {; }
| expr TEXP expr           {; }
;
     


opt_init_expr:
                        { ;}
| TASSIGN TNOINIT       { ; }
| TASSIGN expr  {;}
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
  TQUERIEDIDENT       { ;}
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
| INTLITERAL            {;}
| REALLITERAL           {;}
| IMAGLITERAL           {;}
| TNONE                 {;}
| TLCBR expr_ls TRCBR   {;}


;

str_bytes_literal:
  STRINGLITERAL   {;}
| BYTESLITERAL    {;}
;

bool_literal:
  TFALSE {;}
| TTRUE  {;}
;


assignment_stmt:
  lhs_expr assignop_ident opt_try_expr TSEMI
    {;}

| lhs_expr TASSIGN         TNOINIT TSEMI
    { ; }
;


lhs_expr:
  ident_expr {;}
;

ident_expr:
  ident_use      {; }
| scalar_type    { ; }
;

ident_use:
  TIDENT                   { ;}
;

scalar_type:
  TBOOL    { ;}
| TENUM    { ; }
| TINT     { ; }
| TUINT    { ;}
| TREAL    { ; }
| TIMAG    { ; }
| TCOMPLEX { ; }
| TBYTES   { ; }
| TSTRING  { ; }
| TNOTHING { ; }
| TVOID    { ; }
;

assignop_ident:
  TASSIGN        {;}
| TASSIGNPLUS    {;}
| TASSIGNMINUS   {;}
| TASSIGNMULTIPLY {;}
| TASSIGNDIVIDE  {;}
| TASSIGNMOD     {;}
| TASSIGNEXP     {;}
| TASSIGNBAND    {;}
| TASSIGNBOR     {;}
| TASSIGNBXOR    {;}
| TASSIGNSR      {;}
| TASSIGNSL      {;}
;


opt_try_expr:
  TTRY expr       { ;}
| expr            { ; }
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


	return 0;
}