%{
	#include <stdio.h>
    #include<string.h>
    #include "src/SymbolTable.h"
    #include "y.tab.h"    /* token codes from the parser */  
    int yylex();
    void yyerror (char *s);

%}
%option nounput yylineno


bit              [0-1]
octDigit         [0-7]
digit            [0-9]
hexDigit         [0-9a-fA-F]

letter           [_a-zA-Z]

ident            {letter}({letter}|{digit}|"$")*
queriedIdent     \?{ident}

binaryLiteral    0[bB]{bit}(_|{bit})*
octalLiteral     0[oO]{octDigit}(_|{octDigit})*
decimalLiteral   {digit}(_|{digit})*
hexLiteral       0[xX]{hexDigit}(_|{hexDigit})*
intLiteral       {binaryLiteral}|{octalLiteral}|{decimalLiteral}|{hexLiteral}

digitsOrSeps     {digit}(_|{digit})*
exponent         [Ee][\+\-]?{digitsOrSeps}
floatLiteral1    {digitsOrSeps}?"."{digitsOrSeps}({exponent})?
floatLiteral2    {digitsOrSeps}"."{exponent}
floatLiteral3    {digitsOrSeps}{exponent}

/* hex float literals, have decimal exponents indicating the power of 2 */
hexDigitsOrSeps  {hexDigit}(_|{hexDigit})*
hexDecExponent   [Pp][\+\-]?{digitsOrSeps}
floatLiteral4    0[xX]{hexDigitsOrSeps}?"."{hexDigitsOrSeps}({hexDecExponent})?
floatLiteral5    0[xX]{hexDigitsOrSeps}"."{hexDecExponent}
floatLiteral6    0[xX]{hexDigitsOrSeps}{hexDecExponent}

decFloatLiteral  {floatLiteral1}|{floatLiteral2}|{floatLiteral3}
hexFloatLiteral  {floatLiteral4}|{floatLiteral5}|{floatLiteral6}

floatLiteral     {decFloatLiteral}|{hexFloatLiteral}


%%






align            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TALIGN"); return TALIGN;}

begin            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBEGIN"); return TBEGIN;}
bool             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBOOL"); return TBOOL;}
break            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBREAK"); return TBREAK;}
by               {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBY"); return TBY;}
class            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TCLASS"); return TCLASS;}
const            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TCONST"); return TCONST;}
do               {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TDO"); return TDO;}
else             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TELSE"); return TELSE;}
for              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TFOR"); return TFOR;}
forall           {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TFORALL"); return TFORALL;}
foreach          {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TFOREACH"); return TFOREACH;}
true             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TTRUE"); return TTRUE;}
false            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TFALSE"); return TFALSE;}
if               {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TIF"); return TIF;}
import           {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TIMPORT"); return TIMPORT;}
in               {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TIN"); return TIN;}
include          {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TINCLUDE"); return TINCLUDE;}
int              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TINT"); return TINT;}
iter             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TITER"); return TITER;}
local            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TLOCAL"); return TLOCAL;}
param            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TPARAM"); return TPARAM;}
private          {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TPRIVATE"); return TPRIVATE;}
public           {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TPUBLIC"); return TPUBLIC;}
return           {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TRETURN"); return TRETURN;}
scan             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSCAN"); return TSCAN;}
select           {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSELECT"); return TSELECT;}
string           {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSTRING"); return TSTRING;}
then             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TTHEN"); return TTHEN;}
this             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TTHIS"); return TTHIS;}
void             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TVOID"); return TVOID;}
var              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TVAR"); return TVAR;}
none             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TNONE"); return TNONE;}
when             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TWHEN"); return TWHEN;}
where            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TWHERE"); return TWHERE;}
while            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TWHILE"); return TWHILE;}

try              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TTRY"); return TTRY;}

"_"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TUNDERSCORE"); return TUNDERSCORE;}

"="              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGN"); return TASSIGN;}
"+="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNPLUS"); return TASSIGNPLUS;}
"-="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNMINUS"); return TASSIGNMINUS;}
"*="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNMULTIPLY"); return TASSIGNMULTIPLY;}
"/="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNDIVIDE"); return TASSIGNDIVIDE;}
"**="            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNEXP"); return TASSIGNEXP;}
"%="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNMOD"); return TASSIGNMOD;}
"&="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNBAND"); return TASSIGNBAND;}
"|="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNBOR"); return TASSIGNBOR;}
"^="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNBXOR"); return TASSIGNBXOR;}
"&&="            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNLAND"); return TASSIGNLAND;}
"||="            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNLOR"); return TASSIGNLOR;}
"<<="            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNSL"); return TASSIGNSL;}
">>="            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TASSIGNSR"); return TASSIGNSR;}
"=>"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TALIAS"); return TALIAS;}

"<=>"            {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSWAP"); return TSWAP;}

"#"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"THASH"); return THASH;}
".."             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TDOTDOT"); return TDOTDOT;}
"&&"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TAND"); return TAND;}
"||"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TOR"); return TOR;}
"!"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBANG"); return TBANG;}

"&"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBAND"); return TBAND;}
"|"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBOR"); return TBOR;}
"^"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBXOR"); return TBXOR;}
"~"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TBNOT"); return TBNOT;}

"<<"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSHIFTLEFT"); return TSHIFTLEFT;}
">>"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSHIFTRIGHT"); return TSHIFTRIGHT;}

"=="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TEQUAL"); return TEQUAL;}
"!="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TNOTEQUAL"); return TNOTEQUAL;}
"<="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TLESSEQUAL"); return TLESSEQUAL;}
">="             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TGREATEREQUAL"); return TGREATEREQUAL;}
"<"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TLESS"); return TLESS;}
">"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TGREATER"); return TGREATER;}

"+"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TPLUS"); return TPLUS;}
"-"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TMINUS"); return TMINUS;}
"*"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSTAR"); return TSTAR;}
"/"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TDIVIDE"); return TDIVIDE;}
"%"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TMOD"); return TMOD;}
"--"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TMINUSMINUS"); return TMINUSMINUS;}
"++"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TPLUSPLUS"); return TPLUSPLUS;}
"**"             {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TEXP"); return TEXP;}
":"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TCOLON"); return TCOLON;}
";"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TSEMI"); return TSEMI;}
","              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TCOMMA"); return TCOMMA;}
"."              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TDOT"); return TDOT;}
"("              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TLP"); return TLP;}
")"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TRP"); return TRP;}
"["              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TLSBR"); return TLSBR;}
"]"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TRSBR"); return TRSBR;}
<INITIAL>"{"     {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TLCBR"); return TLCBR;}
"}"              {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TRCBR"); return TRCBR;}

"//".*\n         {yylval.sval = strdup(yytext); }  


{intLiteral}     {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"INTLITERAL"); return INTLITERAL;}
{floatLiteral}   {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"REALLITERAL"); return REALLITERAL;}

{intLiteral}i    {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"IMAGLITERAL"); return IMAGLITERAL;}
{floatLiteral}i  {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"IMAGLITERAL"); return IMAGLITERAL;}









{ident}          {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TIDENT"); return TIDENT;}  
{queriedIdent}   {yylval.sval = strdup(yytext); Insert(yytext,yylineno,"TQUERIEDIDENT"); return TQUERIEDIDENT;}

\n               {yylval.sval = strdup(yytext);  } 

[ \t\r\f]        ;
.                ;

%%


#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>

int yywrap()
{
    printf("Input Exhausted!\n");
    return 1;
}







