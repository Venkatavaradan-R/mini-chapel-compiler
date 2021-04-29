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
%token  TIDENT
%token  TQUERIEDIDENT
%token  INTLITERAL
%token  REALLITERAL
%token  IMAGLITERAL
%token  STRINGLITERAL
%token BYTESLITERAL
%token CSTRINGLITERAL
%token EXTERNCODE


//
// keywords (alphabetical)
//
%token TALIGN TAS TATOMIC
%token TBEGIN TBREAK TBOOL TBORROWED TBY TBYTES
%token TCATCH TCLASS TCOBEGIN TCOFORALL TCOMPLEX TCONFIG TCONST TCONTINUE
%token TDEFER TDELETE TDMAPPED TDO TDOMAIN
%token TELSE TENUM TEXCEPT TEXPORT TEXTERN
%token TFALSE TFOR TFORALL TFOREACH TFORWARDING
%token TIF TIMAG TIMPORT TIN TINCLUDE
%token TINDEX TINLINE TINOUT TINT TITER TINITEQUALS
%token TIMPLEMENTS TINTERFACE
%token TLABEL TLAMBDA TLET TLIFETIME TLOCAL TLOCALE
%token TMINUSMINUS TMODULE
%token TNEW TNIL TNOINIT TNONE TNOTHING
%token TON TONLY TOPERATOR TOTHERWISE TOUT TOVERRIDE TOWNED
%token TPARAM TPLUSPLUS TPRAGMA TPRIMITIVE TPRIVATE TPROC TPROTOTYPE TPUBLIC
%token TREAL TRECORD TREDUCE TREF TREQUIRE TRETURN
%token TSCAN TSELECT TSERIAL TSHARED TSINGLE TSPARSE TSTRING TSUBDOMAIN TSYNC
%token TTHEN TTHIS TTHROW TTHROWS TTRUE TTRY TTRYBANG TTYPE
%token TUINT TUNDERSCORE TUNION TUNMANAGED TUSE
%token TVAR TVOID
%token TWHEN TWHERE TWHILE TWITH
%token TYIELD
%token TZIP



//
// operators and punctuation (alphabetical)
//
%token TALIAS TAND TASSIGN TASSIGNBAND TASSIGNBOR TASSIGNBXOR TASSIGNDIVIDE
%token TASSIGNEXP TASSIGNLAND TASSIGNLOR TASSIGNMINUS TASSIGNMOD
%token TASSIGNMULTIPLY TASSIGNPLUS TASSIGNREDUCE TASSIGNSL TASSIGNSR
%token TBANG TBAND TBNOT TBOR TBXOR
%token TCOLON TCOMMA
%token TDIVIDE TDOT TDOTDOT TDOTDOTDOT
%token TEQUAL TEXP TGREATER
%token TGREATEREQUAL
%token THASH
%token TIO
%token TLESS
%token TLESSEQUAL
%token TMINUS TMOD
%token TNOTEQUAL
%token TOR
%token TPLUS
%token TQUESTION
%token TSEMI TSHIFTLEFT TSHIFTRIGHT TSTAR TSWAP

//
// braces
//
%token TLCBR TRCBR TLP TRP TLSBR TRSBR

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












%type  assignop_ident

//%type  opt_string

%type <pblockstmt> program
%type <pblockstmt> toplevel_stmt_ls
%type <pblockstmt> toplevel_stmt
%type <vpch>       pragma_ls





%type <pblockstmt> block_stmt



%type <pblockstmt> require_stmt








%type <pblockstmt> stmt


%type <pblockstmt> assignment_stmt



/*%type <pblockstmt> extern_record_stmt
%type <pblockstmt> extern_export_proc_stmt
%type <pfnsymbol> extern_export_linkage_spec*/


































%type <pexpr> bool_literal str_bytes_literal literal_expr








%type <pexpr> opt_try_expr


%type <pexpr> query_expr
















%% 


program:
  toplevel_stmt_ls                     {;}
;

// 'toplevel_stmt_ls' is 'stmt_ls' plus resetTempID()
toplevel_stmt_ls:
                                       {;}
| toplevel_stmt_ls toplevel_stmt       {;}
;

stmt_ls:
  toplevel_stmt                        {;}
| stmt_ls toplevel_stmt                {;}
;

// %type <pblockstmt> toplevel_stmt
toplevel_stmt:
   stmt
|  pragma_ls stmt                      {;}
;



// Sequence of pragmas
pragma_ls:
  TPRAGMA STRINGLITERAL                {;}
| pragma_ls TPRAGMA STRINGLITERAL      {;}
;

// %type <pblockstmt> stmt
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
| expr TCOLON expr
    {;}

;

literal_expr:
  bool_literal
| str_bytes_literal
| INTLITERAL            { ;   }
| REALLITERAL           { ; }
| IMAGLITERAL           { ;  }
| TNONE                 { ; }
| TLCBR expr_ls TRCBR   { ;}


;

str_bytes_literal:
  STRINGLITERAL   { ; }
| BYTESLITERAL    { ;}
;

bool_literal:
  TFALSE { ;}
| TTRUE  {; }
;


assignment_stmt:
  lhs_expr assignop_ident opt_try_expr TSEMI
    { ; }

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