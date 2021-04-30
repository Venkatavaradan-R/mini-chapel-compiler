/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/yacc.y"


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




#line 124 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENT = 258,
    TQUERIEDIDENT = 259,
    INTLITERAL = 260,
    REALLITERAL = 261,
    IMAGLITERAL = 262,
    STRINGLITERAL = 263,
    BYTESLITERAL = 264,
    CSTRINGLITERAL = 265,
    EXTERNCODE = 266,
    TALIGN = 267,
    TAS = 268,
    TATOMIC = 269,
    TBEGIN = 270,
    TBREAK = 271,
    TBOOL = 272,
    TBORROWED = 273,
    TBY = 274,
    TBYTES = 275,
    TCATCH = 276,
    TCLASS = 277,
    TCOBEGIN = 278,
    TCOFORALL = 279,
    TCOMPLEX = 280,
    TCONFIG = 281,
    TCONST = 282,
    TCONTINUE = 283,
    TDEFER = 284,
    TDELETE = 285,
    TDMAPPED = 286,
    TDO = 287,
    TDOMAIN = 288,
    TELSE = 289,
    TENUM = 290,
    TEXCEPT = 291,
    TEXPORT = 292,
    TEXTERN = 293,
    TFALSE = 294,
    TFOR = 295,
    TFORALL = 296,
    TFOREACH = 297,
    TFORWARDING = 298,
    TIF = 299,
    TIMAG = 300,
    TIMPORT = 301,
    TIN = 302,
    TINCLUDE = 303,
    TINDEX = 304,
    TINLINE = 305,
    TINOUT = 306,
    TINT = 307,
    TITER = 308,
    TINITEQUALS = 309,
    TIMPLEMENTS = 310,
    TINTERFACE = 311,
    TLABEL = 312,
    TLAMBDA = 313,
    TLET = 314,
    TLIFETIME = 315,
    TLOCAL = 316,
    TLOCALE = 317,
    TMINUSMINUS = 318,
    TMODULE = 319,
    TNEW = 320,
    TNIL = 321,
    TNOINIT = 322,
    TNONE = 323,
    TNOTHING = 324,
    TON = 325,
    TONLY = 326,
    TOPERATOR = 327,
    TOTHERWISE = 328,
    TOUT = 329,
    TOVERRIDE = 330,
    TOWNED = 331,
    TPARAM = 332,
    TPLUSPLUS = 333,
    TPRAGMA = 334,
    TPRIMITIVE = 335,
    TPRIVATE = 336,
    TPROC = 337,
    TPROTOTYPE = 338,
    TPUBLIC = 339,
    TREAL = 340,
    TRECORD = 341,
    TREDUCE = 342,
    TREF = 343,
    TREQUIRE = 344,
    TRETURN = 345,
    TSCAN = 346,
    TSELECT = 347,
    TSERIAL = 348,
    TSHARED = 349,
    TSINGLE = 350,
    TSPARSE = 351,
    TSTRING = 352,
    TSUBDOMAIN = 353,
    TSYNC = 354,
    TTHEN = 355,
    TTHIS = 356,
    TTHROW = 357,
    TTHROWS = 358,
    TTRUE = 359,
    TTRY = 360,
    TTRYBANG = 361,
    TTYPE = 362,
    TUINT = 363,
    TUNDERSCORE = 364,
    TUNION = 365,
    TUNMANAGED = 366,
    TUSE = 367,
    TVAR = 368,
    TVOID = 369,
    TWHEN = 370,
    TWHERE = 371,
    TWHILE = 372,
    TWITH = 373,
    TYIELD = 374,
    TZIP = 375,
    TALIAS = 376,
    TAND = 377,
    TASSIGN = 378,
    TASSIGNBAND = 379,
    TASSIGNBOR = 380,
    TASSIGNBXOR = 381,
    TASSIGNDIVIDE = 382,
    TASSIGNEXP = 383,
    TASSIGNLAND = 384,
    TASSIGNLOR = 385,
    TASSIGNMINUS = 386,
    TASSIGNMOD = 387,
    TASSIGNMULTIPLY = 388,
    TASSIGNPLUS = 389,
    TASSIGNREDUCE = 390,
    TASSIGNSL = 391,
    TASSIGNSR = 392,
    TBANG = 393,
    TBAND = 394,
    TBNOT = 395,
    TBOR = 396,
    TBXOR = 397,
    TCOLON = 398,
    TCOMMA = 399,
    TDIVIDE = 400,
    TDOT = 401,
    TDOTDOT = 402,
    TDOTDOTDOT = 403,
    TEQUAL = 404,
    TEXP = 405,
    TGREATER = 406,
    TGREATEREQUAL = 407,
    THASH = 408,
    TIO = 409,
    TLESS = 410,
    TLESSEQUAL = 411,
    TMINUS = 412,
    TMOD = 413,
    TNOTEQUAL = 414,
    TOR = 415,
    TPLUS = 416,
    TQUESTION = 417,
    TSEMI = 418,
    TSHIFTLEFT = 419,
    TSHIFTRIGHT = 420,
    TSTAR = 421,
    TSWAP = 422,
    TLCBR = 423,
    TRCBR = 424,
    TLP = 425,
    TRP = 426,
    TLSBR = 427,
    TRSBR = 428,
    TNOELSE = 429,
    TDOTDOTOPENHIGH = 430,
    TUPLUS = 431,
    TUMINUS = 432,
    TLNOT = 433
  };
#endif
/* Tokens.  */
#define TIDENT 258
#define TQUERIEDIDENT 259
#define INTLITERAL 260
#define REALLITERAL 261
#define IMAGLITERAL 262
#define STRINGLITERAL 263
#define BYTESLITERAL 264
#define CSTRINGLITERAL 265
#define EXTERNCODE 266
#define TALIGN 267
#define TAS 268
#define TATOMIC 269
#define TBEGIN 270
#define TBREAK 271
#define TBOOL 272
#define TBORROWED 273
#define TBY 274
#define TBYTES 275
#define TCATCH 276
#define TCLASS 277
#define TCOBEGIN 278
#define TCOFORALL 279
#define TCOMPLEX 280
#define TCONFIG 281
#define TCONST 282
#define TCONTINUE 283
#define TDEFER 284
#define TDELETE 285
#define TDMAPPED 286
#define TDO 287
#define TDOMAIN 288
#define TELSE 289
#define TENUM 290
#define TEXCEPT 291
#define TEXPORT 292
#define TEXTERN 293
#define TFALSE 294
#define TFOR 295
#define TFORALL 296
#define TFOREACH 297
#define TFORWARDING 298
#define TIF 299
#define TIMAG 300
#define TIMPORT 301
#define TIN 302
#define TINCLUDE 303
#define TINDEX 304
#define TINLINE 305
#define TINOUT 306
#define TINT 307
#define TITER 308
#define TINITEQUALS 309
#define TIMPLEMENTS 310
#define TINTERFACE 311
#define TLABEL 312
#define TLAMBDA 313
#define TLET 314
#define TLIFETIME 315
#define TLOCAL 316
#define TLOCALE 317
#define TMINUSMINUS 318
#define TMODULE 319
#define TNEW 320
#define TNIL 321
#define TNOINIT 322
#define TNONE 323
#define TNOTHING 324
#define TON 325
#define TONLY 326
#define TOPERATOR 327
#define TOTHERWISE 328
#define TOUT 329
#define TOVERRIDE 330
#define TOWNED 331
#define TPARAM 332
#define TPLUSPLUS 333
#define TPRAGMA 334
#define TPRIMITIVE 335
#define TPRIVATE 336
#define TPROC 337
#define TPROTOTYPE 338
#define TPUBLIC 339
#define TREAL 340
#define TRECORD 341
#define TREDUCE 342
#define TREF 343
#define TREQUIRE 344
#define TRETURN 345
#define TSCAN 346
#define TSELECT 347
#define TSERIAL 348
#define TSHARED 349
#define TSINGLE 350
#define TSPARSE 351
#define TSTRING 352
#define TSUBDOMAIN 353
#define TSYNC 354
#define TTHEN 355
#define TTHIS 356
#define TTHROW 357
#define TTHROWS 358
#define TTRUE 359
#define TTRY 360
#define TTRYBANG 361
#define TTYPE 362
#define TUINT 363
#define TUNDERSCORE 364
#define TUNION 365
#define TUNMANAGED 366
#define TUSE 367
#define TVAR 368
#define TVOID 369
#define TWHEN 370
#define TWHERE 371
#define TWHILE 372
#define TWITH 373
#define TYIELD 374
#define TZIP 375
#define TALIAS 376
#define TAND 377
#define TASSIGN 378
#define TASSIGNBAND 379
#define TASSIGNBOR 380
#define TASSIGNBXOR 381
#define TASSIGNDIVIDE 382
#define TASSIGNEXP 383
#define TASSIGNLAND 384
#define TASSIGNLOR 385
#define TASSIGNMINUS 386
#define TASSIGNMOD 387
#define TASSIGNMULTIPLY 388
#define TASSIGNPLUS 389
#define TASSIGNREDUCE 390
#define TASSIGNSL 391
#define TASSIGNSR 392
#define TBANG 393
#define TBAND 394
#define TBNOT 395
#define TBOR 396
#define TBXOR 397
#define TCOLON 398
#define TCOMMA 399
#define TDIVIDE 400
#define TDOT 401
#define TDOTDOT 402
#define TDOTDOTDOT 403
#define TEQUAL 404
#define TEXP 405
#define TGREATER 406
#define TGREATEREQUAL 407
#define THASH 408
#define TIO 409
#define TLESS 410
#define TLESSEQUAL 411
#define TMINUS 412
#define TMOD 413
#define TNOTEQUAL 414
#define TOR 415
#define TPLUS 416
#define TQUESTION 417
#define TSEMI 418
#define TSHIFTLEFT 419
#define TSHIFTRIGHT 420
#define TSTAR 421
#define TSWAP 422
#define TLCBR 423
#define TRCBR 424
#define TLP 425
#define TRP 426
#define TLSBR 427
#define TRSBR 428
#define TNOELSE 429
#define TDOTDOTOPENHIGH 430
#define TUPLUS 431
#define TUMINUS 432
#define TLNOT 433

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "src/yacc.y"

     char *nt;
     char *sval;

#line 537 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   579

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  179
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

#define YYUNDEFTOK  2
#define YYMAXUTOK   433


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   195,   195,   199,   200,   205,   206,   207,   213,   214,
     215,   219,   223,   225,   229,   230,   231,   235,   236,   240,
     246,   247,   252,   253,   254,   255,   256,   257,   258,   259,
     264,   265,   270,   276,   277,   278,   279,   280,   283,   288,
     289,   290,   294,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   324,   325,   326,   332,   333,   338,   339,   340,
     345,   346,   347,   351,   352,   357,   361,   362,   363,   364,
     368,   374,   375,   376,   382,   383,   384,   385,   386,   387,
     388,   394,   395,   399,   400,   405,   412,   416,   417,   421,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   455,   456
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "TQUERIEDIDENT", "INTLITERAL",
  "REALLITERAL", "IMAGLITERAL", "STRINGLITERAL", "BYTESLITERAL",
  "CSTRINGLITERAL", "EXTERNCODE", "TALIGN", "TAS", "TATOMIC", "TBEGIN",
  "TBREAK", "TBOOL", "TBORROWED", "TBY", "TBYTES", "TCATCH", "TCLASS",
  "TCOBEGIN", "TCOFORALL", "TCOMPLEX", "TCONFIG", "TCONST", "TCONTINUE",
  "TDEFER", "TDELETE", "TDMAPPED", "TDO", "TDOMAIN", "TELSE", "TENUM",
  "TEXCEPT", "TEXPORT", "TEXTERN", "TFALSE", "TFOR", "TFORALL", "TFOREACH",
  "TFORWARDING", "TIF", "TIMAG", "TIMPORT", "TIN", "TINCLUDE", "TINDEX",
  "TINLINE", "TINOUT", "TINT", "TITER", "TINITEQUALS", "TIMPLEMENTS",
  "TINTERFACE", "TLABEL", "TLAMBDA", "TLET", "TLIFETIME", "TLOCAL",
  "TLOCALE", "TMINUSMINUS", "TMODULE", "TNEW", "TNIL", "TNOINIT", "TNONE",
  "TNOTHING", "TON", "TONLY", "TOPERATOR", "TOTHERWISE", "TOUT",
  "TOVERRIDE", "TOWNED", "TPARAM", "TPLUSPLUS", "TPRAGMA", "TPRIMITIVE",
  "TPRIVATE", "TPROC", "TPROTOTYPE", "TPUBLIC", "TREAL", "TRECORD",
  "TREDUCE", "TREF", "TREQUIRE", "TRETURN", "TSCAN", "TSELECT", "TSERIAL",
  "TSHARED", "TSINGLE", "TSPARSE", "TSTRING", "TSUBDOMAIN", "TSYNC",
  "TTHEN", "TTHIS", "TTHROW", "TTHROWS", "TTRUE", "TTRY", "TTRYBANG",
  "TTYPE", "TUINT", "TUNDERSCORE", "TUNION", "TUNMANAGED", "TUSE", "TVAR",
  "TVOID", "TWHEN", "TWHERE", "TWHILE", "TWITH", "TYIELD", "TZIP",
  "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND", "TASSIGNBOR", "TASSIGNBXOR",
  "TASSIGNDIVIDE", "TASSIGNEXP", "TASSIGNLAND", "TASSIGNLOR",
  "TASSIGNMINUS", "TASSIGNMOD", "TASSIGNMULTIPLY", "TASSIGNPLUS",
  "TASSIGNREDUCE", "TASSIGNSL", "TASSIGNSR", "TBANG", "TBAND", "TBNOT",
  "TBOR", "TBXOR", "TCOLON", "TCOMMA", "TDIVIDE", "TDOT", "TDOTDOT",
  "TDOTDOTDOT", "TEQUAL", "TEXP", "TGREATER", "TGREATEREQUAL", "THASH",
  "TIO", "TLESS", "TLESSEQUAL", "TMINUS", "TMOD", "TNOTEQUAL", "TOR",
  "TPLUS", "TQUESTION", "TSEMI", "TSHIFTLEFT", "TSHIFTRIGHT", "TSTAR",
  "TSWAP", "TLCBR", "TRCBR", "TLP", "TRP", "TLSBR", "TRSBR", "TNOELSE",
  "TDOTDOTOPENHIGH", "TUPLUS", "TUMINUS", "TLNOT", "$accept", "program",
  "toplevel_stmt_ls", "toplevel_stmt", "class_level_stmt", "private_decl",
  "var_decl_stmt", "var_decl_type", "var_decl_stmt_inner_ls",
  "var_decl_stmt_inner", "ident_def", "internal_type_ident_def",
  "opt_type", "type_level_expr", "sub_type_level_expr", "nil_expr",
  "unary_op_expr", "binary_op_expr", "binary_op", "opt_init_expr",
  "pragma_ls", "stmt", "block_stmt", "stmt_ls", "require_stmt", "expr_ls",
  "query_expr", "expr", "literal_expr", "str_bytes_literal",
  "bool_literal", "assignment_stmt", "lhs_expr", "ident_expr", "ident_use",
  "scalar_type", "assignop_ident", "opt_try_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433
};
# endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -143,    17,   373,  -143,  -143,  -143,  -143,  -143,   -20,  -143,
    -143,  -143,  -143,  -143,  -143,    10,   -23,  -143,   118,  -143,
    -143,  -143,  -143,  -143,    -1,  -143,  -143,  -143,  -143,   452,
     411,  -143,  -143,  -143,  -143,   115,  -143,  -143,  -143,   452,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   326,
    -143,  -143,   326,   326,  -143,   326,   118,  -143,  -143,  -143,
    -143,  -143,  -115,  -143,   412,  -143,  -143,  -143,  -143,  -142,
    -143,  -143,    20,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -114,  -143,  -108,  -143,    31,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
     192,  -111,  -130,  -130,   412,  -129,  -138,   118,  -143,  -143,
    -143,  -143,  -143,   326,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   326,
    -143,  -143,  -143,   452,  -143,   326,   -81,  -143,   326,   412,
    -120,  -143,  -143,  -143,   412,  -143,   412,  -143,  -122,   412,
     259,  -143,   412,  -143,  -143,   412
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    99,   100,   107,   106,     0,    15,
     101,   105,   102,   109,    14,     0,     0,   104,     0,   108,
     103,    16,   110,     8,     0,     4,     6,     9,    11,     0,
       0,     5,    67,    68,    69,     0,    96,    97,    98,     0,
      65,    10,    80,    86,    87,    88,    91,    92,    93,     0,
      38,    89,     0,     0,    94,     0,     0,    82,    32,    33,
      35,    36,     0,    77,    76,    81,    85,    84,    34,     0,
      70,    73,     0,    20,    22,    28,    27,    26,    23,    25,
      29,    24,     0,    17,    30,    21,     0,     7,   111,   118,
     119,   120,   115,   117,   113,   116,   114,   112,   122,   121,
       0,     0,    39,    40,    37,    41,     0,     0,    75,    59,
      56,    57,    58,     0,    46,    50,    61,    55,    53,    54,
      52,    44,    49,    51,    60,    43,    47,    48,    45,     0,
      72,    71,    74,     0,    13,     0,    62,    66,     0,   124,
       0,    12,    90,    79,    78,    83,    42,    18,    82,     0,
       0,    19,   123,    95,    63,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,   -12,  -143,    34,  -143,    45,    19,   -74,
    -143,  -143,  -143,   -73,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,    36,  -143,  -143,  -143,     5,   -43,   -44,  -143,  -143,
    -143,  -143,     8,  -143,  -143,  -143,  -143,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    27,    28,    29,    82,    83,
      84,    85,   136,    57,    58,    59,    60,    61,   129,   151,
      30,    31,    32,    72,    33,    62,    63,    64,    65,    66,
      67,    34,    68,    36,    37,    38,   100,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,   -31,     4,     8,     9,   102,   107,     9,   103,   104,
      35,   105,    71,   113,   113,   114,     5,     3,    40,     6,
     116,   116,   -31,     4,     7,     8,     9,   130,   122,   107,
     133,   142,    35,   133,    10,   135,   128,     5,    35,   137,
       6,   -31,   150,   153,    11,     7,     8,     9,   108,   134,
      41,    12,   141,    39,    14,    10,   139,    14,   101,   147,
     132,   106,   148,   144,   143,    11,    87,     0,    13,   145,
       0,     0,    12,     0,     0,     0,    14,     0,    15,     0,
      35,     0,     0,    16,    17,   146,     0,     0,    18,    13,
      21,   149,     0,    21,   152,     0,    19,    14,     0,    15,
       0,     0,     0,     0,    16,    17,   155,    20,     0,    18,
       0,     0,    21,    22,     0,     0,     0,    19,     0,     0,
       0,     4,    42,    43,    44,    45,    46,    47,    20,     0,
       0,     0,     0,    21,    22,     5,     0,     0,     6,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,    48,     0,     0,
       0,     0,    23,    11,     0,     0,     0,    24,    70,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,    23,    50,     0,    51,    13,    24,   131,
       0,     0,     0,     0,     0,     4,    52,    43,    44,    45,
      46,    47,     0,    17,     0,     0,     0,     0,     0,     5,
       0,     0,     6,    53,     0,    19,     0,     7,     0,     0,
       0,     0,    54,     0,     0,     0,    20,    10,     0,     0,
       0,    48,    22,     0,     0,     0,     0,    11,    88,    89,
      90,    91,    92,    93,    12,     0,    94,    95,    96,    97,
       0,    98,    99,     0,     0,    49,    55,     0,    50,     0,
      51,    13,     4,     0,    43,    44,    45,    46,    47,     0,
      52,     0,     0,     0,     0,     0,     5,    17,     0,     6,
       0,     0,     0,     0,     7,     0,    56,    53,     0,    19,
       0,     0,     0,     0,    10,     0,    54,   138,    48,     0,
      20,     0,     0,     0,    11,     0,    22,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,    50,   154,    51,    13,     4,
      55,    43,    44,    45,    46,    47,     0,    52,     0,     0,
       0,     0,     0,     5,    17,     0,     6,     0,     0,     0,
       0,     7,     0,     0,    53,     0,    19,     0,     0,     0,
      56,    10,     0,    54,     0,    48,     0,    20,     0,     0,
       0,    11,     0,    22,     0,     0,     4,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       5,     0,    50,     6,    51,    13,     0,    55,     7,     8,
       9,     0,     0,     0,    52,     0,     0,     0,    10,     0,
       0,    17,     0,     0,     4,     0,     0,     0,    11,     0,
       0,    53,     0,    19,     0,    12,     0,    56,     5,     0,
      54,     6,     0,     0,    20,     0,     7,     0,     0,     0,
      22,     0,    13,     0,     0,     0,    10,     0,     0,     0,
      14,     0,    15,     0,     0,    73,    11,    16,    17,     0,
       0,     0,    18,    12,    55,     0,     0,     0,     0,    74,
      19,     0,    75,     0,     0,     0,     0,    76,     0,     0,
      13,    20,     0,     0,     0,     0,    21,    22,     0,     0,
      86,     0,     0,     0,    56,     0,    17,    77,     0,     0,
      18,     0,     0,     0,    78,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,    23,    79,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,    80,
       0,   110,     0,   111,   112,   113,     0,   114,     0,     0,
      81,   115,   116,   117,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,     0,     0,   126,   127,   128,    24
};

static const yytype_int16 yycheck[] =
{
       1,   123,     3,    26,    27,    49,   144,    27,    52,    53,
       2,    55,    24,   143,   143,   145,    17,     0,     8,    20,
     150,   150,   144,     3,    25,    26,    27,   169,   158,   144,
     144,   169,    24,   144,    35,   143,   166,    17,    30,     8,
      20,   163,   123,   163,    45,    25,    26,    27,   163,   163,
      16,    52,   163,     8,    77,    35,   100,    77,    39,   133,
      72,    56,   135,   107,   107,    45,    30,    -1,    69,   113,
      -1,    -1,    52,    -1,    -1,    -1,    77,    -1,    79,    -1,
      72,    -1,    -1,    84,    85,   129,    -1,    -1,    89,    69,
     113,   135,    -1,   113,   138,    -1,    97,    77,    -1,    79,
      -1,    -1,    -1,    -1,    84,    85,   150,   108,    -1,    89,
      -1,    -1,   113,   114,    -1,    -1,    -1,    97,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,   108,    -1,
      -1,    -1,    -1,   113,   114,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,   163,    45,    -1,    -1,    -1,   168,   169,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,   163,    66,    -1,    68,    69,   168,   169,
      -1,    -1,    -1,    -1,    -1,     3,    78,     5,     6,     7,
       8,     9,    -1,    85,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    95,    -1,    97,    -1,    25,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,   108,    35,    -1,    -1,
      -1,    39,   114,    -1,    -1,    -1,    -1,    45,   123,   124,
     125,   126,   127,   128,    52,    -1,   131,   132,   133,   134,
      -1,   136,   137,    -1,    -1,    63,   138,    -1,    66,    -1,
      68,    69,     3,    -1,     5,     6,     7,     8,     9,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    17,    85,    -1,    20,
      -1,    -1,    -1,    -1,    25,    -1,   168,    95,    -1,    97,
      -1,    -1,    -1,    -1,    35,    -1,   104,   105,    39,    -1,
     108,    -1,    -1,    -1,    45,    -1,   114,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    66,    67,    68,    69,     3,
     138,     5,     6,     7,     8,     9,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    17,    85,    -1,    20,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    95,    -1,    97,    -1,    -1,    -1,
     168,    35,    -1,   104,    -1,    39,    -1,   108,    -1,    -1,
      -1,    45,    -1,   114,    -1,    -1,     3,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      17,    -1,    66,    20,    68,    69,    -1,   138,    25,    26,
      27,    -1,    -1,    -1,    78,    -1,    -1,    -1,    35,    -1,
      -1,    85,    -1,    -1,     3,    -1,    -1,    -1,    45,    -1,
      -1,    95,    -1,    97,    -1,    52,    -1,   168,    17,    -1,
     104,    20,    -1,    -1,   108,    -1,    25,    -1,    -1,    -1,
     114,    -1,    69,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      77,    -1,    79,    -1,    -1,     3,    45,    84,    85,    -1,
      -1,    -1,    89,    52,   138,    -1,    -1,    -1,    -1,    17,
      97,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      69,   108,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,
      79,    -1,    -1,    -1,   168,    -1,    85,    45,    -1,    -1,
      89,    -1,    -1,    -1,    52,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,   163,    85,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,   139,    -1,   141,   142,   143,    -1,   145,    -1,    -1,
     108,   149,   150,   151,   152,    -1,    -1,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,   164,   165,   166,   168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   180,   181,     0,     3,    17,    20,    25,    26,    27,
      35,    45,    52,    69,    77,    79,    84,    85,    89,    97,
     108,   113,   114,   163,   168,   182,   183,   184,   185,   186,
     199,   200,   201,   203,   210,   211,   212,   213,   214,   186,
       8,   184,     4,     5,     6,     7,     8,     9,    39,    63,
      66,    68,    78,    95,   104,   138,   168,   192,   193,   194,
     195,   196,   204,   205,   206,   207,   208,   209,   211,     1,
     169,   182,   202,     3,    17,    20,    25,    45,    52,    85,
      97,   108,   187,   188,   189,   190,    79,   200,   123,   124,
     125,   126,   127,   128,   131,   132,   133,   134,   136,   137,
     215,   187,   206,   206,   206,   206,   204,   144,   163,   122,
     139,   141,   142,   143,   145,   149,   150,   151,   152,   155,
     156,   157,   158,   159,   160,   161,   164,   165,   166,   197,
     169,   169,   182,   144,   163,   143,   191,     8,   105,   206,
     216,   163,   169,   205,   206,   206,   206,   188,   192,   206,
     123,   198,   206,   163,    67,   206
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   179,   180,   181,   181,   182,   182,   182,   183,   183,
     183,   184,   185,   185,   186,   186,   186,   187,   187,   188,
     189,   189,   190,   190,   190,   190,   190,   190,   190,   190,
     191,   191,   192,   193,   193,   193,   193,   193,   194,   195,
     195,   195,   196,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   198,   198,   198,   199,   199,   200,   200,   200,
     201,   201,   201,   202,   202,   203,   204,   204,   204,   204,
     205,   206,   206,   206,   207,   207,   207,   207,   207,   207,
     207,   208,   208,   209,   209,   210,   211,   212,   212,   213,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   216
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     2,     1,     1,
       2,     1,     4,     3,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     2,     1,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     2,     2,     3,     1,     1,     1,
       2,     3,     3,     1,     2,     3,     1,     1,     3,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 195 "src/yacc.y"
                                       {;}
#line 1971 "y.tab.c"
    break;

  case 3:
#line 199 "src/yacc.y"
                                       {;}
#line 1977 "y.tab.c"
    break;

  case 4:
#line 200 "src/yacc.y"
                                       {;}
#line 1983 "y.tab.c"
    break;

  case 5:
#line 205 "src/yacc.y"
                                      {;}
#line 1989 "y.tab.c"
    break;

  case 6:
#line 206 "src/yacc.y"
                                      {;}
#line 1995 "y.tab.c"
    break;

  case 7:
#line 207 "src/yacc.y"
                                      {;}
#line 2001 "y.tab.c"
    break;

  case 8:
#line 213 "src/yacc.y"
                        { ; }
#line 2007 "y.tab.c"
    break;

  case 10:
#line 215 "src/yacc.y"
                        { ; }
#line 2013 "y.tab.c"
    break;

  case 14:
#line 229 "src/yacc.y"
              { ; }
#line 2019 "y.tab.c"
    break;

  case 15:
#line 230 "src/yacc.y"
              { ; }
#line 2025 "y.tab.c"
    break;

  case 16:
#line 231 "src/yacc.y"
              { ; }
#line 2031 "y.tab.c"
    break;

  case 20:
#line 246 "src/yacc.y"
                           { push(); }
#line 2037 "y.tab.c"
    break;

  case 21:
#line 247 "src/yacc.y"
                           { ; }
#line 2043 "y.tab.c"
    break;

  case 22:
#line 252 "src/yacc.y"
             { push(); }
#line 2049 "y.tab.c"
    break;

  case 23:
#line 253 "src/yacc.y"
             { push(); }
#line 2055 "y.tab.c"
    break;

  case 24:
#line 254 "src/yacc.y"
             { push(); }
#line 2061 "y.tab.c"
    break;

  case 25:
#line 255 "src/yacc.y"
             { push(); }
#line 2067 "y.tab.c"
    break;

  case 26:
#line 256 "src/yacc.y"
             { push(); }
#line 2073 "y.tab.c"
    break;

  case 27:
#line 257 "src/yacc.y"
             { push(); }
#line 2079 "y.tab.c"
    break;

  case 28:
#line 258 "src/yacc.y"
             { push(); }
#line 2085 "y.tab.c"
    break;

  case 29:
#line 259 "src/yacc.y"
             { push(); }
#line 2091 "y.tab.c"
    break;

  case 30:
#line 264 "src/yacc.y"
                          { ; }
#line 2097 "y.tab.c"
    break;

  case 31:
#line 265 "src/yacc.y"
                          { ; }
#line 2103 "y.tab.c"
    break;

  case 32:
#line 271 "src/yacc.y"
    { ; }
#line 2109 "y.tab.c"
    break;

  case 38:
#line 283 "src/yacc.y"
            {; }
#line 2115 "y.tab.c"
    break;

  case 39:
#line 288 "src/yacc.y"
                                { ; }
#line 2121 "y.tab.c"
    break;

  case 40:
#line 289 "src/yacc.y"
                                  { ; }
#line 2127 "y.tab.c"
    break;

  case 41:
#line 290 "src/yacc.y"
                                  { ; }
#line 2133 "y.tab.c"
    break;

  case 42:
#line 294 "src/yacc.y"
                               { codegen(); }
#line 2139 "y.tab.c"
    break;

  case 43:
#line 299 "src/yacc.y"
                   { push(); }
#line 2145 "y.tab.c"
    break;

  case 44:
#line 300 "src/yacc.y"
                   { push(); }
#line 2151 "y.tab.c"
    break;

  case 45:
#line 301 "src/yacc.y"
                   { push(); }
#line 2157 "y.tab.c"
    break;

  case 46:
#line 302 "src/yacc.y"
                   { push(); }
#line 2163 "y.tab.c"
    break;

  case 47:
#line 303 "src/yacc.y"
                   { push(); }
#line 2169 "y.tab.c"
    break;

  case 48:
#line 304 "src/yacc.y"
                   { push(); }
#line 2175 "y.tab.c"
    break;

  case 49:
#line 305 "src/yacc.y"
                   { push(); }
#line 2181 "y.tab.c"
    break;

  case 50:
#line 306 "src/yacc.y"
                   { push(); }
#line 2187 "y.tab.c"
    break;

  case 51:
#line 307 "src/yacc.y"
                   { push(); }
#line 2193 "y.tab.c"
    break;

  case 52:
#line 308 "src/yacc.y"
                   { push(); }
#line 2199 "y.tab.c"
    break;

  case 53:
#line 309 "src/yacc.y"
                   { push(); }
#line 2205 "y.tab.c"
    break;

  case 54:
#line 310 "src/yacc.y"
                   { push(); }
#line 2211 "y.tab.c"
    break;

  case 55:
#line 311 "src/yacc.y"
                   { push(); }
#line 2217 "y.tab.c"
    break;

  case 56:
#line 312 "src/yacc.y"
                   { push(); }
#line 2223 "y.tab.c"
    break;

  case 57:
#line 313 "src/yacc.y"
                   { push(); }
#line 2229 "y.tab.c"
    break;

  case 58:
#line 314 "src/yacc.y"
                   { push(); }
#line 2235 "y.tab.c"
    break;

  case 59:
#line 315 "src/yacc.y"
                   { push(); }
#line 2241 "y.tab.c"
    break;

  case 60:
#line 316 "src/yacc.y"
                   { push(); }
#line 2247 "y.tab.c"
    break;

  case 61:
#line 317 "src/yacc.y"
                   { push(); }
#line 2253 "y.tab.c"
    break;

  case 62:
#line 324 "src/yacc.y"
                        { ; }
#line 2259 "y.tab.c"
    break;

  case 63:
#line 325 "src/yacc.y"
                        { ; }
#line 2265 "y.tab.c"
    break;

  case 64:
#line 326 "src/yacc.y"
                { codegen_assign(); }
#line 2271 "y.tab.c"
    break;

  case 65:
#line 332 "src/yacc.y"
                                       {;}
#line 2277 "y.tab.c"
    break;

  case 66:
#line 333 "src/yacc.y"
                                       {;}
#line 2283 "y.tab.c"
    break;

  case 70:
#line 345 "src/yacc.y"
                                       {;}
#line 2289 "y.tab.c"
    break;

  case 71:
#line 346 "src/yacc.y"
                                       {;}
#line 2295 "y.tab.c"
    break;

  case 72:
#line 347 "src/yacc.y"
                                       {;}
#line 2301 "y.tab.c"
    break;

  case 73:
#line 351 "src/yacc.y"
                                       {;}
#line 2307 "y.tab.c"
    break;

  case 74:
#line 352 "src/yacc.y"
                                       {;}
#line 2313 "y.tab.c"
    break;

  case 75:
#line 357 "src/yacc.y"
                                       {;}
#line 2319 "y.tab.c"
    break;

  case 76:
#line 361 "src/yacc.y"
                             {;}
#line 2325 "y.tab.c"
    break;

  case 77:
#line 362 "src/yacc.y"
                             {;}
#line 2331 "y.tab.c"
    break;

  case 78:
#line 363 "src/yacc.y"
                             {;}
#line 2337 "y.tab.c"
    break;

  case 79:
#line 364 "src/yacc.y"
                             {;}
#line 2343 "y.tab.c"
    break;

  case 80:
#line 368 "src/yacc.y"
                      {push();}
#line 2349 "y.tab.c"
    break;

  case 83:
#line 377 "src/yacc.y"
    {;}
#line 2355 "y.tab.c"
    break;

  case 86:
#line 384 "src/yacc.y"
                        {push();}
#line 2361 "y.tab.c"
    break;

  case 87:
#line 385 "src/yacc.y"
                        {push();}
#line 2367 "y.tab.c"
    break;

  case 88:
#line 386 "src/yacc.y"
                        {push();}
#line 2373 "y.tab.c"
    break;

  case 89:
#line 387 "src/yacc.y"
                        {;}
#line 2379 "y.tab.c"
    break;

  case 90:
#line 388 "src/yacc.y"
                        {;}
#line 2385 "y.tab.c"
    break;

  case 91:
#line 394 "src/yacc.y"
                  {push();}
#line 2391 "y.tab.c"
    break;

  case 92:
#line 395 "src/yacc.y"
                  {push();}
#line 2397 "y.tab.c"
    break;

  case 93:
#line 399 "src/yacc.y"
         {push();}
#line 2403 "y.tab.c"
    break;

  case 94:
#line 400 "src/yacc.y"
         {push();}
#line 2409 "y.tab.c"
    break;

  case 95:
#line 406 "src/yacc.y"
    {codegen_assign();}
#line 2415 "y.tab.c"
    break;

  case 96:
#line 412 "src/yacc.y"
             {;}
#line 2421 "y.tab.c"
    break;

  case 97:
#line 416 "src/yacc.y"
                 {; }
#line 2427 "y.tab.c"
    break;

  case 98:
#line 417 "src/yacc.y"
                 { ; }
#line 2433 "y.tab.c"
    break;

  case 99:
#line 421 "src/yacc.y"
                           { push();}
#line 2439 "y.tab.c"
    break;

  case 100:
#line 425 "src/yacc.y"
           { push();}
#line 2445 "y.tab.c"
    break;

  case 101:
#line 426 "src/yacc.y"
           { push();}
#line 2451 "y.tab.c"
    break;

  case 102:
#line 427 "src/yacc.y"
           { push();}
#line 2457 "y.tab.c"
    break;

  case 103:
#line 428 "src/yacc.y"
           { push();}
#line 2463 "y.tab.c"
    break;

  case 104:
#line 429 "src/yacc.y"
           { push();}
#line 2469 "y.tab.c"
    break;

  case 105:
#line 430 "src/yacc.y"
           { push();}
#line 2475 "y.tab.c"
    break;

  case 106:
#line 431 "src/yacc.y"
           { push();}
#line 2481 "y.tab.c"
    break;

  case 107:
#line 432 "src/yacc.y"
           { push();}
#line 2487 "y.tab.c"
    break;

  case 108:
#line 433 "src/yacc.y"
           { push();}
#line 2493 "y.tab.c"
    break;

  case 109:
#line 434 "src/yacc.y"
           { push();}
#line 2499 "y.tab.c"
    break;

  case 110:
#line 435 "src/yacc.y"
           { push();}
#line 2505 "y.tab.c"
    break;

  case 111:
#line 439 "src/yacc.y"
                 {push();}
#line 2511 "y.tab.c"
    break;

  case 112:
#line 440 "src/yacc.y"
                 {push();}
#line 2517 "y.tab.c"
    break;

  case 113:
#line 441 "src/yacc.y"
                 {push();}
#line 2523 "y.tab.c"
    break;

  case 114:
#line 442 "src/yacc.y"
                  {push();}
#line 2529 "y.tab.c"
    break;

  case 115:
#line 443 "src/yacc.y"
                 {push();}
#line 2535 "y.tab.c"
    break;

  case 116:
#line 444 "src/yacc.y"
                 {push();}
#line 2541 "y.tab.c"
    break;

  case 117:
#line 445 "src/yacc.y"
                 {push();}
#line 2547 "y.tab.c"
    break;

  case 118:
#line 446 "src/yacc.y"
                 {push();}
#line 2553 "y.tab.c"
    break;

  case 119:
#line 447 "src/yacc.y"
                 {push();}
#line 2559 "y.tab.c"
    break;

  case 120:
#line 448 "src/yacc.y"
                 {push();}
#line 2565 "y.tab.c"
    break;

  case 121:
#line 449 "src/yacc.y"
                 {push();}
#line 2571 "y.tab.c"
    break;

  case 122:
#line 450 "src/yacc.y"
                 {push();}
#line 2577 "y.tab.c"
    break;

  case 123:
#line 455 "src/yacc.y"
                  { ;}
#line 2583 "y.tab.c"
    break;

  case 124:
#line 456 "src/yacc.y"
                  { ; }
#line 2589 "y.tab.c"
    break;


#line 2593 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 467 "src/yacc.y"


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
