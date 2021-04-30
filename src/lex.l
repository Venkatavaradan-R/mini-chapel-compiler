%{
	#include <stdio.h>
    #include<string.h>
    // #include "src/SymbolTable.h"
    #include "y.tab.h"    /* token codes from the parser */  
    int yylex();
    void yyerror (char *s);

%}
%option nounput yylineno noinput

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






align            {yylval.sval = strdup(yytext); return TALIGN;}

begin            {yylval.sval = strdup(yytext); return TBEGIN;}
bool             {yylval.sval = strdup(yytext); return TBOOL;}
break            {yylval.sval = strdup(yytext); return TBREAK;}
by               {yylval.sval = strdup(yytext); return TBY;}
class            {yylval.sval = strdup(yytext); return TCLASS;}
const            {yylval.sval = strdup(yytext); return TCONST;}
do               {yylval.sval = strdup(yytext); return TDO;}
else             {yylval.sval = strdup(yytext); return TELSE;}
for              {yylval.sval = strdup(yytext); return TFOR;}
forall           {yylval.sval = strdup(yytext); return TFORALL;}
foreach          {yylval.sval = strdup(yytext); return TFOREACH;}
true             {yylval.sval = strdup(yytext); return TTRUE;}
false            {yylval.sval = strdup(yytext); return TFALSE;}
if               {yylval.sval = strdup(yytext); return TIF;}
import           {yylval.sval = strdup(yytext); return TIMPORT;}
in               {yylval.sval = strdup(yytext); return TIN;}
include          {yylval.sval = strdup(yytext); return TINCLUDE;}
int              {yylval.sval = strdup(yytext); return TINT;}
iter             {yylval.sval = strdup(yytext); return TITER;}
local            {yylval.sval = strdup(yytext); return TLOCAL;}
param            {yylval.sval = strdup(yytext); return TPARAM;}
private          {yylval.sval = strdup(yytext); return TPRIVATE;}
public           {yylval.sval = strdup(yytext); return TPUBLIC;}
return           {yylval.sval = strdup(yytext); return TRETURN;}
scan             {yylval.sval = strdup(yytext); return TSCAN;}
select           {yylval.sval = strdup(yytext); return TSELECT;}
string           {yylval.sval = strdup(yytext); return TSTRING;}
then             {yylval.sval = strdup(yytext); return TTHEN;}
this             {yylval.sval = strdup(yytext); return TTHIS;}
void             {yylval.sval = strdup(yytext); return TVOID;}
var              {yylval.sval = strdup(yytext); return TVAR;}
none             {yylval.sval = strdup(yytext); return TNONE;}
when             {yylval.sval = strdup(yytext); return TWHEN;}
where            {yylval.sval = strdup(yytext); return TWHERE;}
while            {yylval.sval = strdup(yytext); return TWHILE;}

try              {yylval.sval = strdup(yytext); return TTRY;}

"_"              {yylval.sval = strdup(yytext); return TUNDERSCORE;}

"="              {yylval.sval = strdup(yytext); return TASSIGN;}
"+="             {yylval.sval = strdup(yytext); return TASSIGNPLUS;}
"-="             {yylval.sval = strdup(yytext); return TASSIGNMINUS;}
"*="             {yylval.sval = strdup(yytext); return TASSIGNMULTIPLY;}
"/="             {yylval.sval = strdup(yytext); return TASSIGNDIVIDE;}
"**="            {yylval.sval = strdup(yytext); return TASSIGNEXP;}
"%="             {yylval.sval = strdup(yytext); return TASSIGNMOD;}
"&="             {yylval.sval = strdup(yytext); return TASSIGNBAND;}
"|="             {yylval.sval = strdup(yytext); return TASSIGNBOR;}
"^="             {yylval.sval = strdup(yytext); return TASSIGNBXOR;}
"&&="            {yylval.sval = strdup(yytext); return TASSIGNLAND;}
"||="            {yylval.sval = strdup(yytext); return TASSIGNLOR;}
"<<="            {yylval.sval = strdup(yytext); return TASSIGNSL;}
">>="            {yylval.sval = strdup(yytext); return TASSIGNSR;}
"=>"             {yylval.sval = strdup(yytext); return TALIAS;}

"<=>"            {yylval.sval = strdup(yytext); return TSWAP;}

"#"              {yylval.sval = strdup(yytext);  return THASH;}
".."             {yylval.sval = strdup(yytext);  return TDOTDOT;}
"&&"             {yylval.sval = strdup(yytext);  return TAND;}
"||"             {yylval.sval = strdup(yytext);  return TOR;}
"!"              {yylval.sval = strdup(yytext);  return TBANG;}

"&"              {yylval.sval = strdup(yytext); return TBAND;}
"|"              {yylval.sval = strdup(yytext);  return TBOR;}
"^"              {yylval.sval = strdup(yytext);  return TBXOR;}
"~"              {yylval.sval = strdup(yytext);  return TBNOT;}

"<<"             {yylval.sval = strdup(yytext);  return TSHIFTLEFT;}
">>"             {yylval.sval = strdup(yytext);  return TSHIFTRIGHT;}

"=="             {yylval.sval = strdup(yytext);  return TEQUAL;}
"!="             {yylval.sval = strdup(yytext);  return TNOTEQUAL;}
"<="             {yylval.sval = strdup(yytext);  return TLESSEQUAL;}
">="             {yylval.sval = strdup(yytext);  return TGREATEREQUAL;}
"<"              {yylval.sval = strdup(yytext);  return TLESS;}
">"              {yylval.sval = strdup(yytext);  return TGREATER;}

"+"              {yylval.sval = strdup(yytext);  return TPLUS;}
"-"              {yylval.sval = strdup(yytext);  return TMINUS;}
"*"              {yylval.sval = strdup(yytext);  return TSTAR;}
"/"              {yylval.sval = strdup(yytext);  return TDIVIDE;}
"%"              {yylval.sval = strdup(yytext);  return TMOD;}
"--"             {yylval.sval = strdup(yytext);  return TMINUSMINUS;}
"++"             {yylval.sval = strdup(yytext);  return TPLUSPLUS;}
"**"             {yylval.sval = strdup(yytext);  return TEXP;}
":"              {yylval.sval = strdup(yytext);  return TCOLON;}
";"              {yylval.sval = strdup(yytext);  return TSEMI;}
","              {yylval.sval = strdup(yytext);  return TCOMMA;}
"."              {yylval.sval = strdup(yytext);  return TDOT;}
"("              {yylval.sval = strdup(yytext);  return TLP;}
")"              {yylval.sval = strdup(yytext);  return TRP;}
"["              {yylval.sval = strdup(yytext);  return TLSBR;}
"]"              {yylval.sval = strdup(yytext);  return TRSBR;}
<INITIAL>"{"     {yylval.sval = strdup(yytext);  return TLCBR;}
"}"              {yylval.sval = strdup(yytext);  return TRCBR;}

"//".*\n         {yylval.sval = strdup(yytext); }  


{intLiteral}     {yylval.sval = strdup(yytext);  return INTLITERAL;}
{floatLiteral}   {yylval.sval = strdup(yytext);  return REALLITERAL;}

{intLiteral}i    {yylval.sval = strdup(yytext);  return IMAGLITERAL;}
{floatLiteral}i  {yylval.sval = strdup(yytext);  return IMAGLITERAL;}



{ident}          {yylval.sval = strdup(yytext);  return TIDENT;}  
{queriedIdent}   {yylval.sval = strdup(yytext);  return TQUERIEDIDENT;}

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







