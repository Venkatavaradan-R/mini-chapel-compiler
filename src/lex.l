
%{
	#include <stdio.h>
    #include<string.h>
    #include "src/SymbolTable.h"
    #include "y.tab.h"    /* token codes from the parser */  
    int yylex();
    void yyerror (char *s);


    static int  processIdentifier(yyscan_t scanner, bool queried);
    static int  processToken(yyscan_t scanner, int t);
    static void processWhitespace(yyscan_t scanner);
    static void processInvalidToken(yyscan_t scanner);
    static int  processSingleLineComment(yyscan_t scanner);

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
align            return processToken(yyscanner, TALIGN);
begin            return processToken(yyscanner, TBEGIN);
bool             return processToken(yyscanner, TBOOL);
break            return processToken(yyscanner, TBREAK);
by               return processToken(yyscanner, TBY);
class            return processToken(yyscanner, TCLASS);
const            return processToken(yyscanner, TCONST);
do               return processToken(yyscanner, TDO);
else             return processToken(yyscanner, TELSE);
for              return processToken(yyscanner, TFOR);
forall           return processToken(yyscanner, TFORALL);
foreach          return processToken(yyscanner, TFOREACH);
false            return processToken(yyscanner, TFALSE);
if               return processToken(yyscanner, TIF);
import           return processToken(yyscanner, TIMPORT);
in               return processToken(yyscanner, TIN);
include          return processToken(yyscanner, TINCLUDE);
int              return processToken(yyscanner, TINT);
iter             return processToken(yyscanner, TITER);
local            return processToken(yyscanner, TLOCAL);
param            return processToken(yyscanner, TPARAM);
private          return processToken(yyscanner, TPRIVATE);
public           return processToken(yyscanner, TPUBLIC);
return           return processToken(yyscanner, TRETURN);
scan             return processToken(yyscanner, TSCAN);
select           return processToken(yyscanner, TSELECT);
string           return processToken(yyscanner, TSTRING);
then             return processToken(yyscanner, TTHEN);
this             return processToken(yyscanner, TTHIS);
void             return processToken(yyscanner, TVOID);
none             return processToken(yyscanner, TNONE);
when             return processToken(yyscanner, TWHEN);
where            return processToken(yyscanner, TWHERE);
while            return processToken(yyscanner, TWHILE);

try              return processToken(yyscanner, TTRY);

"_"              return processToken(yyscanner, TUNDERSCORE);

"="              return processToken(yyscanner, TASSIGN);
"+="             return processToken(yyscanner, TASSIGNPLUS);
"-="             return processToken(yyscanner, TASSIGNMINUS);
"*="             return processToken(yyscanner, TASSIGNMULTIPLY);
"/="             return processToken(yyscanner, TASSIGNDIVIDE);
"**="            return processToken(yyscanner, TASSIGNEXP);
"%="             return processToken(yyscanner, TASSIGNMOD);
"&="             return processToken(yyscanner, TASSIGNBAND);
"|="             return processToken(yyscanner, TASSIGNBOR);
"^="             return processToken(yyscanner, TASSIGNBXOR);
"&&="            return processToken(yyscanner, TASSIGNLAND);
"||="            return processToken(yyscanner, TASSIGNLOR);
"<<="            return processToken(yyscanner, TASSIGNSL);
">>="            return processToken(yyscanner, TASSIGNSR);
"=>"             return processToken(yyscanner, TALIAS);

"<=>"            return processToken(yyscanner, TSWAP);

"#"              return processToken(yyscanner, THASH);
".."             return processToken(yyscanner, TDOTDOT);
"&&"             return processToken(yyscanner, TAND);
"||"             return processToken(yyscanner, TOR);
"!"              return processToken(yyscanner, TBANG);

"&"              return processToken(yyscanner, TBAND);
"|"              return processToken(yyscanner, TBOR);
"^"              return processToken(yyscanner, TBXOR);
"~"              return processToken(yyscanner, TBNOT);

"<<"             return processToken(yyscanner, TSHIFTLEFT);
">>"             return processToken(yyscanner, TSHIFTRIGHT);

"=="             return processToken(yyscanner, TEQUAL);
"!="             return processToken(yyscanner, TNOTEQUAL);
"<="             return processToken(yyscanner, TLESSEQUAL);
">="             return processToken(yyscanner, TGREATEREQUAL);
"<"              return processToken(yyscanner, TLESS);
">"              return processToken(yyscanner, TGREATER);

"+"              return processToken(yyscanner, TPLUS);
"-"              return processToken(yyscanner, TMINUS);
"*"              return processToken(yyscanner, TSTAR);
"/"              return processToken(yyscanner, TDIVIDE);
"%"              return processToken(yyscanner, TMOD);
"--"             return processToken(yyscanner, TMINUSMINUS);
"++"             return processToken(yyscanner, TPLUSPLUS);
"**"             return processToken(yyscanner, TEXP);
":"              return processToken(yyscanner, TCOLON);
";"              return processToken(yyscanner, TSEMI);
","              return processToken(yyscanner, TCOMMA);
"."              return processToken(yyscanner, TDOT);
"("              return processToken(yyscanner, TLP);
")"              return processToken(yyscanner, TRP);
"["              return processToken(yyscanner, TLSBR);
"]"              return processToken(yyscanner, TRSBR);
<INITIAL>"{"     return processToken(yyscanner, TLCBR);
"}"              return processToken(yyscanner, TRCBR);

"//"             return processSingleLineComment(yyscanner);

{intLiteral}     return processToken(yyscanner, INTLITERAL);
{floatLiteral}   return processToken(yyscanner, REALLITERAL);

{intLiteral}i    return processToken(yyscanner, IMAGLITERAL);
{floatLiteral}i  return processToken(yyscanner, IMAGLITERAL);

{ident}          return processIdentifier(yyscanner, false);
{queriedIdent}   return processIdentifier(yyscanner, true);

\n               return processNewline(yyscanner);

[ \t\r\f]        processWhitespace(yyscanner);
.                processInvalidToken(yyscanner);

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

static int processToken(yyscan_t scanner, int t) {
  YYSTYPE* yyLval = yyget_lval(scanner);

  countToken(yyget_text(scanner));

  yyLval->pch = yyget_text(scanner);

  if (captureTokens) {
    if (t == TASSIGN ||
        t == TDOTDOTDOT) {
      captureString.push_back(' ');
    }

    if (t != TLCBR) {
      captureString.append(yyget_text(scanner));
    }

    if (t == TCOMMA  ||
        t == TPARAM  ||
        t == TZIP    ||
        t == TTYPE   ||
        t == TCONST  ||
        t == TIN     ||
        t == TINOUT  ||
        t == TOUT    ||
        t == TREF    ||
        t == TCOLON  ||
        t == TASSIGN ||
        t == TRSBR ||
        t == TBORROWED ||
        t == TUNMANAGED ||
        t == TOWNED ||
        t == TSHARED) {
      captureString.push_back(' ');
    }
  }

  // If the stack has a value then we must be in externmode.
  // Return to INITIAL
  if (yy_has_state(scanner) == true) {
    yy_pop_state(scanner);
  }

  return t;
}

static void processInvalidToken(yyscan_t scanner) {
  ParserContext context(scanner);
  YYLTYPE*      yyLloc = yyget_lloc(scanner);

  yyerror(yyLloc, &context, "Invalid token");
}


int processNewline(yyscan_t scanner) {
  YYLTYPE* yyLloc = yyget_lloc(scanner);

  chplLineno++;

  yyLloc->first_column = 0;
  yyLloc->last_column  = 0;

  yyLloc->first_line   = chplLineno;
  yyLloc->last_line    = chplLineno;

  countNewline();

  return YYLEX_NEWLINE;
}


static int processSingleLineComment(yyscan_t scanner) {
  YYSTYPE* yyLval = yyget_lval(scanner);
  int      c      = 0;

  newString();
  countCommentLine();

  // Read until the end of the line
  while ((c = getNextYYChar(scanner)) != '\n' && c != 0) {
    addChar(c);
  }

  countSingleLineComment(stringBuffer.c_str());

  if (c != 0) {
    processNewline(scanner);
  }

  yyLval->pch = astr(stringBuffer);

  return YYLEX_SINGLE_LINE_COMMENT;
}
