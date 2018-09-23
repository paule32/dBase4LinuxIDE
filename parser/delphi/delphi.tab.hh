/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_SOURCE_PARSER_DELPHI_DELPHI_TAB_HH_INCLUDED
# define YY_YY_SOURCE_PARSER_DELPHI_DELPHI_TAB_HH_INCLUDED
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
    _BEGIN_ = 258,
    _END_ = 259,
    _IMPLEMENTATION_ = 260,
    _PROGRAM_ = 261,
    _UNIT_ = 262,
    _LIBRARY_ = 263,
    _PACKAGE_ = 264,
    _USES_ = 265,
    _IN_ = 266,
    _FILE_ = 267,
    _NOT_EQUAL_ = 268,
    _LESSER_THAN_ = 269,
    _GREATER_THAN_ = 270,
    _ABSOLUTE_ = 271,
    _NIL_ = 272,
    _NAME_ = 273,
    _STRING_ = 274,
    _NUMBER_ = 275,
    _STRING_LITTERAL_ = 276,
    _DBL_POINT_ = 277,
    _ASM_ = 278,
    _PACKED_ = 279,
    _ARRAY_ = 280,
    _OF_ = 281,
    _SET_ = 282,
    _RECORD_ = 283,
    _OVERLOAD_ = 284,
    _ASSIGNMENT_ = 285,
    _DOT_ = 286,
    _CASE_ = 287,
    _PROCEDURE_ = 288,
    _FUNCTION_ = 289,
    _CLASS_ = 290,
    _CDECL_ = 291,
    _PASCAL_ = 292,
    _REGISTER_ = 293,
    _AT_ = 294,
    _SAFECALL_ = 295,
    _STDCALL_ = 296,
    _DESTRUCTOR_ = 297,
    _CONSTRUCTOR_ = 298,
    _CONST_ = 299,
    _VAR_ = 300,
    _OUT_ = 301,
    _ABSTRACT_ = 302,
    _VIRTUAL_ = 303,
    _DYNAMIC_ = 304,
    _OVERRIDE_ = 305,
    _REINTRODUCE_ = 306,
    _MESSAGE_ = 307,
    _PRIVATE_ = 308,
    _PUBLIC_ = 309,
    _PROTECTED_ = 310,
    _PUBLISHED_ = 311,
    _INITIALIZATION_ = 312,
    _FINALIZATION_ = 313,
    _TYPE_ = 314,
    _PROPERTY_ = 315,
    _DEFAULT_ = 316,
    _NODEFAULT_ = 317,
    _WRITE_ = 318,
    _READ_ = 319,
    _READONLY_ = 320,
    _WRITEONLY_ = 321,
    _INDEX_ = 322,
    _DISPID_ = 323,
    _STORED_ = 324,
    _THREADVAR_ = 325,
    _INTERFACE_ = 326,
    _DISPINTERFACE_ = 327,
    _DIV_ = 328,
    _MOD_ = 329,
    _AND_ = 330,
    _XOR_ = 331,
    _OR_ = 332,
    _NOT_ = 333,
    _SHL_ = 334,
    _SHR_ = 335,
    _IF_ = 336,
    _ELSE_ = 337,
    _THEN_ = 338,
    _WHILE_ = 339,
    _FOR_ = 340,
    _DO_ = 341,
    _REPEAT_ = 342,
    _TRY_ = 343,
    _WITH_ = 344,
    _UNTIL_ = 345,
    _EXCEPT_ = 346,
    _FINALLY_ = 347,
    _RAISE_ = 348,
    _INHERITED_ = 349,
    _TO_ = 350,
    _DOWNTO_ = 351,
    _IMPLEMENTS_ = 352,
    _ON_ = 353,
    _IS_ = 354,
    _EXTENDED_ = 355,
    _DOUBLE_ = 356,
    _BYTE_ = 357,
    _WORD_ = 358,
    _LONGWORD_ = 359,
    _SMALLINT_ = 360,
    _INTEGER_ = 361,
    _CARDINAL_ = 362,
    _SINGLE_ = 363,
    _CURRENCY_ = 364,
    _SHORTINT_ = 365,
    _LONGINT_ = 366,
    _INT64_ = 367,
    _CHAR_ = 368,
    _STRINGTYPE_ = 369,
    _BOOLEAN_ = 370,
    _FALSE_ = 371,
    _TRUE_ = 372
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 103 "source/parser/delphi/delphi.ypp" /* yacc.c:1909  */

  int val; 
  char sym;

#line 177 "source/parser/delphi/delphi.tab.hh" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SOURCE_PARSER_DELPHI_DELPHI_TAB_HH_INCLUDED  */
