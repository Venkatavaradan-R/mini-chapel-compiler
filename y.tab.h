/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 21 "src/yacc.y"

     char *nt;
     char *sval;

#line 418 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
