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



//
// identifiers and literals
//
%token <pch> TIDENT
%token <pch> TQUERIEDIDENT
%token <pch> INTLITERAL
%token <pch> REALLITERAL
%token <pch> IMAGLITERAL
%token <pch> STRINGLITERAL
%token <pch> BYTESLITERAL
%token <pch> CSTRINGLITERAL
%token <pch> EXTERNCODE


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

%type <b> access_control use_access_control include_access_control
%type <b> opt_prototype
%type <b> opt_throws_error

%type <pt> required_intent_tag opt_intent_tag opt_this_intent_tag

%type <retTag>  opt_ret_tag
%type <aggrTag> class_tag

%type <pch> ident_use ident_def ident_fn_def
%type <pch> internal_type_ident_def reserved_type_ident_use
%type <pch> fn_ident assignop_ident opt_label_ident
%type <pch> implements_type_ident implements_type_error_ident
//%type <pch> opt_string

%type <pblockstmt> program
%type <pblockstmt> toplevel_stmt_ls
%type <pblockstmt> toplevel_stmt
%type <vpch>       pragma_ls

%type <pmodsymbol> module_decl_start
%type <pblockstmt> module_decl_stmt
%type <pblockstmt> include_module_stmt

%type <pblockstmt> block_stmt
%type <pblockstmt> stmt_ls

%type <pimportstmt> import_expr
%type <pblockstmt> use_stmt import_stmt import_ls require_stmt
%type <ponlylist>  renames_ls use_renames_ls opt_only_ls except_ls

%type <pblockstmt> implements_stmt interface_stmt
%type <pcallexpr>  ifc_formal_ls
%type <pdefexpr>   ifc_formal

%type <pblockstmt> class_level_stmt_ls

%type <pblockstmt> stmt
%type <pblockstmt> do_stmt
%type <pblockstmt> if_stmt loop_stmt
%type <pblockstmt> select_stmt assignment_stmt class_level_stmt
%type <pblockstmt> private_decl
%type <pblockstmt> forwarding_stmt
%type <pblockstmt> extern_export_decl_stmt
/*%type <pblockstmt> extern_record_stmt
%type <pblockstmt> extern_export_proc_stmt
%type <pfnsymbol> extern_export_linkage_spec*/
%type <pblockstmt> extern_block_stmt
%type <pblockstmt> return_stmt
%type <pblockstmt> defer_stmt
%type <pblockstmt> try_stmt
%type <pblockstmt> throw_stmt
%type <pblockstmt> catch_stmt_ls
%type <pexpr>      catch_stmt
%type <pdefexpr>   catch_expr

%type <pflagset> var_decl_type

%type <pblockstmt> type_alias_decl_stmt type_alias_decl_stmt_inner fn_decl_stmt class_decl_stmt
%type <pblockstmt> enum_decl_stmt

%type <pblockstmt> var_decl_stmt var_decl_stmt_inner_ls
%type <pblockstmt> var_decl_stmt_inner tuple_var_decl_stmt_inner_ls


%type <pblockstmt> function_body_stmt opt_function_body_stmt

%type <pexpr> when_stmt
%type <pblockstmt> when_stmt_ls

%type <pcallexpr> array_type
%type <pexpr> opt_type opt_ret_type ret_array_type
%type <pexpr> opt_formal_type formal_array_type opt_formal_array_elt_type lambda_decl_expr
%type <penumtype> enum_header
%type <pvecOfDefs> enum_ls

%type <pcallexpr> zippered_iterator
%type <pexpr> call_base_expr call_expr dot_expr
%type <pexpr> lhs_expr
%type <pexpr> unary_op_expr binary_op_expr
%type <pexpr> parenthesized_expr expr actual_expr
%type <pexpr> bool_literal str_bytes_literal literal_expr
%type <pexpr> stmt_level_expr sub_type_level_expr type_level_expr scalar_type
%type <pexpr> lifetime_components_expr
%type <pexpr> lifetime_expr lifetime_ident
%type <lifetimeAndWhere> opt_lifetime_where
%type <pexpr> ident_expr for_expr cond_expr nil_expr io_expr new_expr
%type <pexpr> let_expr ifvar
%type <pexpr> reduce_expr scan_expr reduce_scan_op_expr opt_init_expr
%type <pexpr> opt_init_type var_arg_expr
%type <pexpr> opt_try_expr opt_expr
%type <pexpr> tuple_component tuple_var_decl_component
%type <pdefexpr> formal enum_item
%type <pexpr> query_expr ifc_constraint

%type <pcallexpr> new_maybe_decorated
%type <pcallexpr> opt_inherit simple_expr_ls expr_ls assoc_expr_ls tuple_expr_ls
%type <pcallexpr> opt_actual_ls actual_ls
%type <pcallexpr> opt_task_intent_ls task_intent_ls task_intent_clause
%type <pcallexpr> forall_intent_clause forall_intent_ls

%type <pfnsymbol> fn_decl_stmt_inner formal_ls opt_formal_ls req_formal_ls
%type <pfnsymbol> formal_ls_inner
%type <pexpr> fn_decl_receiver_expr
%type <procIterOp> proc_iter_or_op
%type <pfnsymbol> linkage_spec
%type <pShadowVar> intent_expr
%type <pShadowVarPref> shadow_var_prefix


%% 


program:
  toplevel_stmt_ls                     { yyblock = $$; }
;

// 'toplevel_stmt_ls' is 'stmt_ls' plus resetTempID()
toplevel_stmt_ls:
                                       { $$ = new BlockStmt(); resetTempID(); }
| toplevel_stmt_ls toplevel_stmt       { $1->appendChapelStmt($2); context->generatedStmt = $1; resetTempID(); }
;


// %type <pblockstmt> toplevel_stmt
toplevel_stmt:
   stmt
|  pragma_ls stmt                      { $$ = buildPragmaStmt( $1, $2 ); }
;



// Sequence of pragmas
pragma_ls:
  TPRAGMA STRINGLITERAL                { $$ = new Vec<const char*>(); $$->add(astr($2)); }
| pragma_ls TPRAGMA STRINGLITERAL      { $1->add(astr($3)); }
;

// %type <pblockstmt> stmt
stmt:
block_stmt
| require_stmt
| assignment_stmt
;


block_stmt:
  TLCBR         TRCBR                  { $$ = new BlockStmt(); }
| TLCBR stmt_ls TRCBR                  { $$ = $2;              }
| TLCBR error   TRCBR                  { $$ = buildErrorStandin(); }
;

require_stmt:
  TREQUIRE expr_ls TSEMI               { $$ = buildRequireStmt($2); }
;

expr_ls:
  expr                       { $$ = new CallExpr(PRIM_ACTUALS_LIST, $1); }
| query_expr                 { $$ = new CallExpr(PRIM_ACTUALS_LIST, $1); }
| expr_ls TCOMMA expr        { $1->insertAtTail($3); }
| expr_ls TCOMMA query_expr  { $1->insertAtTail($3); }
;

query_expr:
  TQUERIEDIDENT       { $$ = buildQueriedExpr($1); }
;


/* exprs represent valid values and types. Any expression with a valid
   type also has a valid value as types can appear on the rhs during
   type-aliasing.  Hence, type_level_expr must be a subset of expr. */
expr:
  literal_expr
| expr TCOLON expr
    { $$ = createCast($1, $3); }

;

literal_expr:
  bool_literal
| str_bytes_literal
| INTLITERAL            { $$ = buildIntLiteral($1, yyfilename, chplLineno);    }
| REALLITERAL           { $$ = buildRealLiteral($1);   }
| IMAGLITERAL           { $$ = buildImagLiteral($1);   }
| TNONE                 { $$ = new SymExpr(gNone); }
| TLCBR expr_ls TRCBR   { $$ = new CallExpr("chpl__buildDomainExpr", $2,
                                            new SymExpr(gTrue)); }


;

str_bytes_literal:
  STRINGLITERAL   { $$ = buildStringLiteral($1); }
| BYTESLITERAL    { $$ = buildBytesLiteral($1); }
;

bool_literal:
  TFALSE { $$ = new SymExpr(gFalse); }
| TTRUE  { $$ = new SymExpr(gTrue); }
;


assignment_stmt:
  lhs_expr assignop_ident opt_try_expr TSEMI
    { $$ = buildAssignment($1, $3, $2);   }

| lhs_expr TASSIGN         TNOINIT TSEMI
    { $$ = buildAssignment($1, new SymExpr(gNoInit), "="); }
;

assignop_ident:
  TASSIGN        { $$ = "="; }
| TASSIGNPLUS    { $$ = "+="; }
| TASSIGNMINUS   { $$ = "-="; }
| TASSIGNMULTIPLY { $$ = "*="; }
| TASSIGNDIVIDE  { $$ = "/="; }
| TASSIGNMOD     { $$ = "%="; }
| TASSIGNEXP     { $$ = "**="; }
| TASSIGNBAND    { $$ = "&="; }
| TASSIGNBOR     { $$ = "|="; }
| TASSIGNBXOR    { $$ = "^="; }
| TASSIGNSR      { $$ = ">>="; }
| TASSIGNSL      { $$ = "<<="; }
;


opt_try_expr:
  TTRY expr       { $$ = tryExpr($2); }
| expr            { $$ = $1; }
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