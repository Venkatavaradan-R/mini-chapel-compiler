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
    T_REQUIRE = 258,
    T_DEFAULT = 259,
    T_CONST = 260,
    T_WRITELN = 261,
    T_EXTERN = 262,
    T_ELSE = 263,
    T_FOR = 264,
    T_COFORALL = 265,
    T_COBEGIN = 266,
    T_IF = 267,
    T_VAR = 268,
    T_VAR_TYPE = 269,
    T_BOOL_CONST = 270,
    T_NIL_VAL = 271,
    T_IDENTIFIER = 272,
    T_STRING = 273,
    T_INCREMENT = 274,
    T_DECREMENT = 275,
    T_INTEGER = 276,
    T_REAL = 277,
    T_IMAG = 278,
    T_ADD = 279,
    T_MINUS = 280,
    T_MULTIPLY = 281,
    T_DIVIDE = 282,
    T_MOD = 283,
    T_ASSIGN = 284,
    T_AND = 285,
    T_NOT = 286,
    T_COLON = 287,
    T_LAND = 288,
    T_LOR = 289,
    T_EQL = 290,
    T_NEQ = 291,
    T_LEQ = 292,
    T_GEQ = 293,
    T_SEMICOLON = 294,
    T_GTR = 295,
    T_LSR = 296,
    T_LEFTPARANTHESES = 297,
    T_RIGHTPARANTHESES = 298,
    T_LEFTBRACE = 299,
    T_RIGHTBRACE = 300,
    T_LEFTBRACKET = 301,
    T_RIGHTBRACKET = 302,
    T_COMMA = 303,
    T_PERIOD = 304
  };
#endif
/* Tokens.  */
#define T_REQUIRE 258
#define T_DEFAULT 259
#define T_CONST 260
#define T_WRITELN 261
#define T_EXTERN 262
#define T_ELSE 263
#define T_FOR 264
#define T_COFORALL 265
#define T_COBEGIN 266
#define T_IF 267
#define T_VAR 268
#define T_VAR_TYPE 269
#define T_BOOL_CONST 270
#define T_NIL_VAL 271
#define T_IDENTIFIER 272
#define T_STRING 273
#define T_INCREMENT 274
#define T_DECREMENT 275
#define T_INTEGER 276
#define T_REAL 277
#define T_IMAG 278
#define T_ADD 279
#define T_MINUS 280
#define T_MULTIPLY 281
#define T_DIVIDE 282
#define T_MOD 283
#define T_ASSIGN 284
#define T_AND 285
#define T_NOT 286
#define T_COLON 287
#define T_LAND 288
#define T_LOR 289
#define T_EQL 290
#define T_NEQ 291
#define T_LEQ 292
#define T_GEQ 293
#define T_SEMICOLON 294
#define T_GTR 295
#define T_LSR 296
#define T_LEFTPARANTHESES 297
#define T_RIGHTPARANTHESES 298
#define T_LEFTBRACE 299
#define T_RIGHTBRACE 300
#define T_LEFTBRACKET 301
#define T_RIGHTBRACKET 302
#define T_COMMA 303
#define T_PERIOD 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "src/yacc.y"

     char *nt;
     char *sval;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
