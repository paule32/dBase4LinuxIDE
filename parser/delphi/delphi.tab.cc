/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "source/parser/delphi/delphi.ypp" /* yacc.c:339  */

// --------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2018 Jens Kallup
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
//#include <stdio.h>
//#include <strings.h>
//#include <stdlib.h>

# include "source/asm/binheader.h"

using namespace std;

using namespace asmjit;
using namespace asmtk;

#include <QDate>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QDebug>

FILE * delphi_output = nullptr;
FILE * delphi_input  = nullptr;

bool delphi_app  = false;
bool delphi_lib  = false;
bool delphi_unit = false;

QMap<QString,bool> proc_body_map;

QString delphi_unit_name;
QString delphi_temp_string;

#undef  yyparse
#undef  yylex

#undef  yychar
#undef  yynerrs
#undef  yylval
#undef  yyerror
#undef  yyset_in
#undef  yyset_out

extern QString delphi_yytext;

#define yychar    delphichar
#define yynerrs   delphinerrs
#define yylval    delphilval
#define yyerror   delphierror
#define yyrestart delphirestart

#define yyset_in  delphiset_in
#define yyset_out delphiset_out

#define yylex     delphilex
#define yyparse   delphiparse

extern void delphiset_in (FILE *);
extern void delphiset_out(FILE *);
extern void delphirestart(FILE *);

extern int  delphilex();
extern int  delphierror(const char*);

#include <QString>
#include <QMessageBox>

extern int line_no;

int delphierror(const char *p)
{
    QMessageBox::warning(
    0,"Error !!!",
    QString("error at line: %1: %2. ")
    .arg(line_no+1)
    .arg(p));
    return line_no;
}


#line 167 "source/parser/delphi/delphi.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "delphi.tab.hh".  */
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
#line 103 "source/parser/delphi/delphi.ypp" /* yacc.c:355  */

  int val; 
  char sym;

#line 330 "source/parser/delphi/delphi.tab.cc" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SOURCE_PARSER_DELPHI_DELPHI_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 345 "source/parser/delphi/delphi.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  154
/* YYNRULES -- Number of rules.  */
#define YYNRULES  479
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  873

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     133,   134,   126,   124,   120,   125,   119,   127,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   123,   118,
     130,   129,   131,     2,   128,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   121,     2,   122,   132,     2,     2,     2,     2,     2,
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
     115,   116,   117
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   134,   135,   139,   139,   143,   143,
     149,   152,   149,   163,   167,   167,   169,   170,   171,   172,
     176,   180,   181,   181,   210,   210,   219,   220,   221,   227,
     228,   231,   232,   235,   236,   240,   241,   245,   246,   247,
     251,   252,   256,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   284,   285,   286,   287,   291,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   307,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   345,   346,   347,   348,   349,   350,   351,
     352,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   374,   375,   376,   377,
     378,   379,   380,   381,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   411,   412,   416,   417,   421,   422,
     426,   427,   428,   429,   433,   438,   442,   443,   444,   458,
     459,   460,   464,   465,   469,   473,   474,   475,   476,   480,
     481,   482,   483,   487,   488,   489,   493,   494,   495,   496,
     500,   504,   508,   512,   513,   514,   515,   519,   520,   524,
     525,   529,   533,   534,   535,   536,   537,   538,   539,   540,
     543,   543,   547,   548,   552,   553,   557,   561,   562,   563,
     566,   566,   566,   569,   570,   572,   573,   574,   577,   578,
     581,   582,   583,   587,   588,   589,   609,   610,   614,   615,
     616,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   711,
     712,   713,   714,   718,   719,   723,   724,   725,   726,   727,
     728,   729,   730,   734,   735,   736,   740,   741,   745,   749,
     750,   751,   755,   759,   763,   764,   768,   769,   773,   774,
     775,   776,   777,   778,   779,   780,   781,   784,   785,   785,
     787,   790,   791,   792,   793,   796,   798,   799,   800,   801,
     802,   803,   806,   809,   810,   811,   812,   816,   817,   821,
     822,   825,   826,   830,   831,   835,   836,   847,   848,   852,
     853,   854,   855,   856,   860,   861,   865,   866,   867,   871,
     872,   876,   877,   881,   882,   883,   887,   888,   892,   896,
     897,   898,   899,   900,   901,   905,   909,   910,   914,   918,
     922,   926,   927,   928,   932,   933,   934,   938,   939,   943,
     944,   948,   949,   950,   951,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   970,   971,   972,
     975,   978,   979,   983,   984,   992,   993,   994,   998,   999,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,  1013,  1013,  1017,
    1021,  1022,  1023,  1024,  1028,  1029,  1032,  1033,  1036,  1037,
    1038,  1039,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,
    1051,  1055,  1059,  1060,  1061,  1062,  1063,  1064,  1068,  1069,
    1073,  1074,  1075,  1079,  1083,  1084,  1088,  1089,  1093,  1097,
    1101,  1102,  1103,  1104,  1108,  1109,  1113,  1117,  1118,  1119,
    1120,  1121,  1122,  1126,  1127,  1128,  1132,  1133,  1134,  1138,
    1142,  1143,  1147,  1148,  1152,  1153,  1154,  1155,  1156,  1157
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_BEGIN_", "_END_", "_IMPLEMENTATION_",
  "_PROGRAM_", "_UNIT_", "_LIBRARY_", "_PACKAGE_", "_USES_", "_IN_",
  "_FILE_", "_NOT_EQUAL_", "_LESSER_THAN_", "_GREATER_THAN_", "_ABSOLUTE_",
  "_NIL_", "_NAME_", "_STRING_", "_NUMBER_", "_STRING_LITTERAL_",
  "_DBL_POINT_", "_ASM_", "_PACKED_", "_ARRAY_", "_OF_", "_SET_",
  "_RECORD_", "_OVERLOAD_", "_ASSIGNMENT_", "_DOT_", "_CASE_",
  "_PROCEDURE_", "_FUNCTION_", "_CLASS_", "_CDECL_", "_PASCAL_",
  "_REGISTER_", "_AT_", "_SAFECALL_", "_STDCALL_", "_DESTRUCTOR_",
  "_CONSTRUCTOR_", "_CONST_", "_VAR_", "_OUT_", "_ABSTRACT_", "_VIRTUAL_",
  "_DYNAMIC_", "_OVERRIDE_", "_REINTRODUCE_", "_MESSAGE_", "_PRIVATE_",
  "_PUBLIC_", "_PROTECTED_", "_PUBLISHED_", "_INITIALIZATION_",
  "_FINALIZATION_", "_TYPE_", "_PROPERTY_", "_DEFAULT_", "_NODEFAULT_",
  "_WRITE_", "_READ_", "_READONLY_", "_WRITEONLY_", "_INDEX_", "_DISPID_",
  "_STORED_", "_THREADVAR_", "_INTERFACE_", "_DISPINTERFACE_", "_DIV_",
  "_MOD_", "_AND_", "_XOR_", "_OR_", "_NOT_", "_SHL_", "_SHR_", "_IF_",
  "_ELSE_", "_THEN_", "_WHILE_", "_FOR_", "_DO_", "_REPEAT_", "_TRY_",
  "_WITH_", "_UNTIL_", "_EXCEPT_", "_FINALLY_", "_RAISE_", "_INHERITED_",
  "_TO_", "_DOWNTO_", "_IMPLEMENTS_", "_ON_", "_IS_", "_EXTENDED_",
  "_DOUBLE_", "_BYTE_", "_WORD_", "_LONGWORD_", "_SMALLINT_", "_INTEGER_",
  "_CARDINAL_", "_SINGLE_", "_CURRENCY_", "_SHORTINT_", "_LONGINT_",
  "_INT64_", "_CHAR_", "_STRINGTYPE_", "_BOOLEAN_", "_FALSE_", "_TRUE_",
  "';'", "'.'", "','", "'['", "']'", "':'", "'+'", "'-'", "'*'", "'/'",
  "'@'", "'='", "'<'", "'>'", "'^'", "'('", "')'", "$accept", "delphi",
  "program", "$@1", "$@2", "unit", "$@3", "$@4", "uses", "unit_interface",
  "$@5", "unit_implementation", "procedure_or_function_decl", "$@6",
  "procedure_forward_decl", "$@7", "unit_end", "initialization", "library",
  "package", "identifier_list", "unit_qualified_identifier", "main_uses",
  "uses_in", "asm", "asm_statement_", "label_", "asm_statement",
  "typed_constant", "simple_expression", "simple_expression_",
  "expression", "constant_expression", "simple_expression__", "term__",
  "factor__", "set_factor", "set_element", "variable_access", "end_access",
  "array_access", "record_access", "function_parameters", "type_name",
  "unit_qualified_type_name", "function_result_type", "string_expression",
  "bloc", "main_declarations", "const_type_var_declarations",
  "procedure_declarations_and_body", "procedure_declaration",
  "composed_instruction", "instruction_list", "instruction",
  "assignment_or_call", "end_assignment", "structured_instruction", "test",
  "if", "case", "case_element", "case_label", "repetition", "while",
  "repeat", "for", "with", "try", "except_block", "inherited_call",
  "raise_statement", "type", "type_0", "keyed_types", "string_type",
  "structure_type", "array_type", "index_type", "record_type",
  "field_list", "common_field", "variant_fields", "tag", "cases",
  "one_case", "set_type", "file_type", "pointer_type", "procedural_type",
  "procedural_type_directives", "calling_directives", "overload_directive",
  "routine_header", "class_methods_header", "class_procedure_method",
  "class_function_method", "constructor_header", "destructor_header",
  "formal_parameters", "formal_parameter", "parameter_name_list",
  "array_or_name_type", "parameter", "var_parameter", "const_parameter",
  "out_parameter", "in_parameter", "method_directives",
  "constant_definitions", "constant_definition", "resource_definitions",
  "resource_definition", "type_definitions", "type_definition", "property",
  "property_type", "property_indexes", "property_index",
  "property_specifiers", "storage_specifier", "storage_nodefault",
  "storage_stored", "storage_default", "variable_declarations", "varname",
  "variable_declaration", "boolean", "absolute", "interface_type",
  "interface_definition", "interface_heritage", "interface_guid",
  "interface_member_list", "interface_directives_", "dispid",
  "class_procedure_", "class_function_", "class_type", "class_reference",
  "class_definition", "ineritance", "class_body",
  "fields_and_procs_section", "protection", "fields_and_procs",
  "class_field", "class_methods", "class_procedure", "class_function",
  "rename_method", "constructor", "destructor", "method_directives_", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
     365,   366,   367,   368,   369,   370,   371,   372,    59,    46,
      44,    91,    93,    58,    43,    45,    42,    47,    64,    61,
      60,    62,    94,    40,    41
};
# endif

#define YYPACT_NINF -700

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-700)))

#define YYTABLE_NINF -396

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     530,    53,    71,    89,   159,   252,  -700,  -700,  -700,  -700,
     101,  -700,   245,   157,  -700,  -700,   164,   265,    43,  -700,
     245,   582,  -700,   297,   215,   291,    15,   303,   309,   330,
     344,   362,   344,   266,    37,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,   582,   364,   331,   442,
    -700,   265,   269,  -700,   389,   390,  -700,  -700,   295,   296,
     -76,  -700,   335,   236,    47,   324,  -700,  -700,  -700,   723,
     987,  -700,  -700,   434,  -700,   431,   480,  -700,   363,   363,
    -700,   346,   442,   346,   346,   346,   459,   442,  -700,    68,
     182,   243,  -700,  -700,   373,    13,   375,   387,   498,   500,
     925,   490,   925,   344,   501,  -700,   885,   490,   490,   490,
     503,   723,   723,   490,   116,   802,  -700,   346,   346,  -700,
      84,  -700,   493,   200,  -700,   520,   408,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,    52,
    -700,  -700,   523,  -700,   511,   512,    31,   527,   527,  -700,
     626,   502,   116,   442,  -700,   225,  -700,  -700,  -700,  -700,
    -700,  -700,   519,   367,   275,   305,  -700,  -700,   415,   442,
     442,   442,   442,   442,   442,   442,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,  -700,  -700,  -700,
     146,   424,   532,   535,    72,   113,   528,  -700,  -700,   436,
    -700,   421,    -6,   529,   511,   426,   426,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,   542,  -700,  -700,
     432,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,   444,   118,   242,  -700,   441,   445,    93,  -700,  -700,
    -700,  -700,  -700,   -37,   -37,    93,   453,   461,   462,  -700,
    -700,  -700,  -700,   591,   511,   570,   219,   513,   478,   568,
     510,    18,   -29,   363,   363,   563,  -700,   320,   327,   490,
     490,   490,   490,   490,   490,   490,   490,   490,  -700,   346,
     346,   346,   346,  -700,   802,  -700,  -700,   422,  -700,   486,
     489,  -700,  -700,  -700,   575,  -700,  -700,  -700,   723,   605,
     606,  -700,  -700,   494,  -700,   -95,   442,   442,  -700,   346,
     346,   346,   346,   346,   346,   346,   346,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,   123,
     426,  -700,   191,   514,  -700,   515,   925,   442,  -700,  -700,
    -700,  -700,   925,   442,   925,   496,   608,   521,  -700,   497,
    -700,   490,  -700,   490,   490,   490,   490,   490,   490,   490,
     490,   344,   251,   925,  -700,  -700,  -700,   518,  -700,    13,
     511,  -700,   438,   438,  -700,    86,  -700,  -700,  -700,  -700,
     508,  -700,   161,   442,   802,   802,   802,   603,   490,   490,
    -700,   544,   723,   802,   490,   442,   346,   346,   346,   346,
     346,   346,   346,   346,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
     620,  -700,   522,   629,  -700,   590,  -700,  -700,   533,   442,
    -700,  -700,   531,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,   538,   534,   632,   539,   632,   632,   632,   -15,
     537,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,   543,
    -700,   642,   380,  -700,   925,  -700,   619,    93,   548,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,   651,   336,
    -700,  -700,   552,   554,   555,  -700,    93,   553,   545,   656,
     658,   659,   662,   663,  -700,   680,  -700,  -700,   681,    93,
    -700,   925,   668,   669,   205,   670,   674,  -700,  -700,  -700,
    -700,  -700,  -700,     7,   -41,   571,  -700,  -700,  -700,  -700,
     419,  -700,   705,   689,   691,  -700,   610,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,   723,
     442,   566,  -700,  -700,    93,  -700,   679,   578,   579,   580,
     191,  -700,   474,  -700,   442,   442,   686,  -700,   688,  -700,
    -700,   192,  -700,  -700,   344,   344,   344,   344,  -700,  -700,
    -700,   132,    36,   156,   167,   801,  -700,  -700,   584,   609,
       3,   298,  -700,  -700,   186,   197,   442,   442,   723,   717,
     802,   490,   490,   652,   723,  -700,  -700,  -700,   802,   621,
    -700,   625,  -700,   630,  -700,   474,   474,   474,   615,   726,
    -700,   627,  -700,   635,   925,   643,   741,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  1032,
     650,    93,   646,  1032,   660,  1032,   664,   442,  -700,   752,
     116,  -700,  -700,   442,   442,   442,   503,    49,    93,   810,
     654,  -700,   666,  -700,  -700,  -700,  -700,  -700,  -700,   762,
     667,   673,    93,   665,   672,   724,   678,   724,   682,  -700,
    -700,   777,  -700,  -700,   711,   716,   802,  -700,  -700,   181,
     442,  -700,   684,  -700,  -700,  -700,   254,   442,   783,  -700,
      93,   442,  -700,  -700,  -700,  -700,  -700,  -700,   442,   442,
     685,   696,   697,  -700,   700,  1032,   706,    93,  -700,  1032,
    -700,  1032,  -700,  -700,  -700,  -700,   709,  -700,   385,    62,
     813,   255,  -700,  -700,    93,  -700,   699,  -700,  -700,   714,
      93,    93,   718,   721,   722,  -700,   724,  -700,   724,  -700,
     802,   802,  -700,   725,   713,   442,  -700,  -700,  -700,   925,
    -700,   312,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    1032,   727,  -700,  -700,  -700,  -700,   503,   828,    93,   365,
      49,  -700,  -700,   831,   724,   732,   734,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,   442,  -700,
    -700,  1032,   735,   731,  -700,   839,    93,   736,   742,  -700,
     724,   724,   738,  -700,  -700,    93,   758,  -700,  -700,  -700,
    -700,  -700,   749,  -700,    93,    24,  -700,  -700,   766,   767,
     754,  -700,    26,   774,   775,   760,   765,  -700,  -700,   782,
     788,  -700,  -700
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       0,    10,    37,     0,     1,     6,     0,     0,   173,    32,
      37,   173,    11,    40,     0,     0,   321,     0,     0,     0,
     400,     0,   400,     0,   170,   174,   175,   180,   181,   314,
     315,   316,   176,   177,   178,   179,   173,     0,     0,     0,
      38,     0,     0,   358,     0,     0,   317,   318,     0,     0,
       0,   355,     0,     0,   395,     0,   360,   396,    31,   183,
      43,   172,   171,     0,     9,    14,     0,   137,   135,   136,
     134,     0,     0,     0,     0,     0,     0,     0,    41,   103,
     111,   126,   141,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,     0,   397,     0,     0,     0,     0,
       0,   183,   183,     0,   228,   226,   184,     0,     0,   199,
      94,    78,   189,    79,   192,     0,     0,   187,   188,   193,
     200,   201,   194,   210,   211,   212,   195,   196,   197,   198,
      44,    46,    45,    62,    57,    59,    58,    56,    61,    60,
      49,    50,    47,    48,    51,    52,    53,    54,    55,     0,
      68,    63,     0,     7,     0,     0,   313,     0,     0,    16,
       0,     0,     0,     0,   152,     0,   148,   150,   151,   153,
     149,   139,   146,     0,   116,   117,   140,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,   165,   166,
       0,     0,     0,     0,     0,     0,   298,   251,   258,   250,
     249,     0,     0,     0,   279,   301,   303,   252,   248,   247,
     233,   238,   240,   239,   243,   241,   245,   246,   237,   242,
     244,   234,   235,   236,   253,   254,   255,     0,   256,   257,
       0,   232,   231,   259,   260,   265,   266,   267,   268,   261,
     262,     0,    69,   398,   406,     0,   399,     0,   440,   450,
     452,   451,   453,   410,   412,   256,     0,     0,     0,   441,
     442,   444,   445,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,   229,   227,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,     0,   182,   185,    64,    65,     0,    42,    33,
       0,    24,    17,    18,    21,    15,    19,    28,   183,     0,
       0,    12,   155,     0,   156,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   110,   105,
     109,   108,   104,   106,   107,   115,   114,   112,   113,   129,
     130,   131,   132,   133,   127,   128,   167,   168,   359,     0,
       0,   325,     0,     0,   323,     0,     0,     0,   269,   270,
     271,   272,     0,     0,     0,     0,     0,     0,   302,     0,
     300,     0,   356,     0,     0,     0,     0,     0,     0,     0,
       0,   400,     0,     0,   161,   159,   160,   162,   443,     0,
       0,   411,   418,   418,   413,     0,   363,   362,   361,   448,
       0,   449,     0,     0,     0,     0,     0,     0,     0,     0,
     220,     0,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,    96,   100,    99,   102,    95,
      97,    98,   191,    83,    82,    80,    81,   186,    66,    67,
       0,    13,     0,     0,    20,    29,    27,    26,     0,     0,
     157,   147,     0,   125,   124,   122,   123,   121,   120,   118,
     119,   319,     0,     0,     0,   334,     0,     0,     0,     0,
       0,   329,   330,   331,   332,   333,   326,   324,   299,     0,
     273,   276,     0,   297,     0,   278,   280,     0,     0,    76,
      71,    75,    74,    77,    70,    72,    73,   401,     0,   136,
     407,   408,     0,     0,     0,   398,     0,     0,     0,     0,
       0,     0,     0,     0,   421,     0,   419,   420,     0,     0,
     446,     0,     0,     0,     0,     0,     0,   455,   454,   459,
     460,   457,   458,   207,     0,     0,   203,   202,   213,    36,
       0,   214,   183,     0,     0,   218,     0,   230,    93,    92,
      90,    91,    89,    88,    86,    87,    34,    25,    22,   183,
       0,     0,   145,   320,     0,   348,     0,   343,   341,   346,
       0,   327,     0,   264,     0,     0,     0,   282,     0,   281,
     164,     0,   357,   409,   400,   400,   400,   400,   163,   417,
     416,     0,     0,     0,     0,   364,   414,   415,     0,     0,
       0,     0,   461,   462,     0,     0,     0,     0,   183,     0,
       0,     0,     0,     0,   183,   224,   221,   222,     0,     0,
      30,     0,   158,     0,   335,     0,     0,     0,     0,     0,
     338,   339,   277,     0,     0,   284,     0,   307,   308,   309,
     310,   311,   306,   304,   305,   405,   402,   404,   403,   422,
       0,     0,     0,   422,     0,   422,     0,   393,   390,     0,
       0,   378,   380,     0,     0,   391,     0,     0,     0,   375,
       0,   365,   383,   389,   387,   388,   447,   456,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     208,     0,   204,   206,     0,     0,     0,   225,   219,   173,
       0,   322,   344,   342,   347,   328,     0,     0,     0,   274,
       0,     0,   312,   349,   350,   351,   352,   353,     0,     0,
     427,   425,   423,   432,   429,   422,     0,     0,   434,   422,
     433,   422,   394,   379,   377,   376,   381,   392,     0,     0,
       0,     0,   367,   366,     0,   384,     0,   465,   464,     0,
       0,     0,   476,   475,   474,   472,     0,   470,     0,   205,
       0,     0,   215,     0,     0,     0,   336,   337,   340,     0,
     285,     0,   283,   354,   431,   428,   426,   424,   430,   435,
     422,     0,   437,   436,   382,   385,     0,     0,     0,     0,
       0,   369,   368,     0,     0,     0,     0,   479,   478,   477,
     473,   471,   216,   217,    23,   154,   345,   275,     0,   286,
     438,   422,     0,     0,   371,     0,     0,     0,     0,   466,
       0,     0,     0,   439,   386,     0,     0,   373,   370,   469,
     468,   467,     0,   372,     0,     0,   287,   374,   288,     0,
       0,   289,     0,   295,     0,     0,     0,   296,   292,   290,
     293,   291,   294
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,   733,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -146,  -649,   888,   808,   880,  -700,  -700,  -700,    14,   287,
     -55,   -97,   -22,   540,   -49,   -30,  -700,   588,  -111,   -59,
    -700,  -700,  -700,  -490,  -260,  -563,   506,   -20,  -700,   -12,
    -700,  -700,   882,  -106,  -113,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,   -98,  -700,  -700,  -700,  -700,   707,   322,   708,
    -700,  -699,  -644,  -700,  -700,  -700,   710,   712,  -700,  -700,
    -700,  -587,  -662,   755,  -700,  -700,  -700,  -700,  -700,  -202,
     342,   -61,  -134,   452,  -700,  -700,  -700,  -700,  -653,  -700,
    -700,  -700,  -700,  -700,  -700,   524,  -700,  -700,   137,   259,
    -700,  -700,  -700,  -700,   887,   850,   -23,  -700,  -700,  -700,
     687,  -700,  -700,   547,  -645,  -700,  -700,  -700,  -700,  -700,
    -700,  -700,  -700,  -700,  -700,  -700,  -700,  -700,   411,   418,
     343,  -700,  -700,  -648
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    20,    21,     7,    16,    48,   166,    76,
     167,   325,   464,   639,   168,   462,   171,   329,     8,     9,
     385,   289,    18,    24,   119,   160,   161,   162,   261,   120,
     121,   122,   182,    89,   123,    91,    92,   183,    93,   180,
     177,   178,   179,   407,   650,   601,   211,    33,    34,    35,
      36,    37,   124,   125,   126,   127,   308,   128,   129,   130,
     131,   554,   555,   132,   133,   134,   135,   136,   137,   563,
     138,   139,   250,   251,   252,   253,   254,   255,   502,   256,
     386,   387,   599,   656,   792,   856,   257,   258,   259,   260,
     663,   740,   741,    38,    39,    56,    57,    40,    41,   373,
     489,   490,   651,   491,   492,   493,   494,   495,   742,    42,
      61,    43,    53,    44,    66,   534,   689,   690,   761,   691,
     692,   693,   694,   695,    45,    63,    64,   523,   524,   277,
     411,   412,   413,   535,   743,   744,   536,   537,   278,   279,
     280,   281,   282,   283,   284,   421,   422,   548,   549,   550,
     701,   551,   552,   775
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    47,   296,   295,   263,   290,   291,   408,   276,    67,
     285,   286,   287,   375,   664,   415,   292,   600,   320,   176,
     382,   643,   430,   388,   389,   469,    73,    88,   748,   626,
     750,   208,   209,    90,   184,   185,   608,   758,    90,   470,
      69,   628,   319,   773,   319,   773,   262,   100,    54,    55,
      25,   181,   774,   101,   774,   186,   598,   433,   598,   777,
      70,   332,    25,   169,   330,   188,    26,   759,   297,   298,
     315,    10,   316,    27,    28,    29,    30,   629,    26,   189,
     264,   190,   191,   192,   409,    27,    28,    29,    30,    11,
      31,   434,    30,   760,   600,   299,   410,   300,   301,   302,
     799,    32,    31,   590,   802,   404,   803,    12,   746,   431,
     432,   405,   406,    32,   773,   383,   773,    32,   772,   591,
     772,   698,   699,   774,    90,   774,    90,   627,   820,   393,
     821,   394,   395,   396,   293,   294,   372,   210,   420,   769,
      90,    90,    90,    90,    90,    90,    90,   355,   356,   357,
     358,   333,   773,   335,   322,   830,   859,   832,   858,   671,
     864,   774,  -169,   865,   366,   367,   839,   482,   483,   372,
     359,   360,   361,   362,   363,   364,   365,    13,   773,   773,
     317,   600,   807,   303,   801,   808,   843,   774,   774,   772,
     371,   772,   850,   851,   542,   543,   544,   193,   194,   195,
      25,   457,   484,   545,   546,   372,   539,   815,   816,   485,
     452,   860,   600,   304,   305,   306,    26,   397,   866,    15,
     540,   533,   465,    27,    28,    29,    30,   772,   657,   658,
     659,   374,   660,   661,   176,   486,   487,   488,   542,   543,
      31,   481,    77,    78,    79,    80,   372,   398,   399,   400,
     669,    32,    14,   772,   772,    17,   372,   600,   196,   197,
     453,   454,   455,   456,   528,   372,   404,   518,    77,    78,
     519,    80,   405,   406,   673,    19,   309,   310,   498,   618,
     600,   600,    22,    23,   500,   675,   503,    90,    90,   372,
     473,   474,   475,   476,   477,   478,   479,   480,   786,  -169,
     372,   424,   425,    81,   705,   525,   198,   199,    49,    52,
     662,   556,   557,   558,   471,   707,   200,   201,   202,   372,
     565,    58,   203,   204,   311,   312,   564,    59,    90,    81,
     372,   560,   561,    50,    90,    51,   262,   566,   509,   510,
     511,   512,   513,   514,   515,   516,    82,   262,    60,    83,
      84,   339,   340,    85,   103,   499,   104,    86,    87,   334,
     401,   501,    62,    77,    78,    79,    80,   520,   521,   205,
     206,   402,    82,   810,    90,   117,   118,   811,   517,    85,
      65,   343,   344,    86,    87,    68,    90,   568,   569,   570,
     571,   572,   573,   574,   575,    74,   436,   437,    95,   341,
     342,   553,    75,   440,   441,   508,   597,    96,    97,   670,
     672,   674,   676,   567,    98,    99,   522,   699,   700,   703,
      90,   702,   706,   708,    81,   587,   588,   589,   762,   345,
     346,   372,   828,   216,  -395,   829,    77,    78,    79,    80,
     458,   164,   459,   619,   438,   439,   222,   581,   223,   224,
      25,   442,   443,   106,   604,   172,   635,   173,   102,    77,
      78,    79,    80,   633,   165,   163,   787,    82,   174,   175,
     790,   529,   530,   640,    85,    29,    30,   187,    86,    87,
     531,   532,   172,   170,   173,   835,   404,   337,   836,   338,
      31,   207,   405,   406,   212,   174,   175,    81,   533,   649,
     595,    32,   596,   805,   812,   806,   213,    77,    78,    79,
      80,   722,   723,   724,   631,   632,   214,   713,   215,   265,
      81,   288,   711,   307,   313,   718,   314,   318,   717,   319,
     321,    90,   324,   331,   714,   715,     1,     2,     3,     4,
      82,   336,   368,   117,   118,    90,    90,    85,   834,   347,
     369,    86,    87,   370,   376,   384,   729,   377,   641,   372,
     390,   391,   392,    82,   403,   104,    83,    84,    81,   754,
      85,   416,   652,   501,    86,    87,   847,    90,    90,   417,
     418,   665,   666,   667,   668,   853,   444,   445,   446,   447,
     448,   449,   450,   451,   857,   419,   423,   427,   428,   426,
     429,    25,   435,   782,   709,   710,   460,   461,   463,   466,
     467,    82,   505,  -169,   117,   118,   468,    26,    85,   504,
     507,   559,    86,    87,    27,    28,    29,    30,    90,    69,
     327,   541,   496,   497,    90,    90,    90,   526,   576,   506,
     577,    31,   562,    77,    78,    79,    80,   578,   579,    70,
     485,   598,    32,   582,   580,   752,   583,   584,   107,   586,
     592,   755,   756,   757,   594,   593,   602,   822,   823,   603,
     605,    90,   606,   607,   611,   609,   612,   613,    90,   610,
     614,   615,    90,   328,   616,   617,   620,   621,   624,    90,
      90,   827,   625,   636,   630,   637,   638,   644,   784,   783,
     642,   645,   646,   647,    81,   788,   655,   108,    69,   791,
     109,   110,   654,   111,   112,   113,   793,   794,   696,   114,
     115,   712,    77,    78,    79,    80,    69,   697,    70,   348,
     349,   350,   351,   352,   353,   354,    90,   107,   716,   719,
      77,    78,    79,    80,   116,   720,    70,    82,   721,   725,
     117,   118,   726,   732,    85,   107,   727,   728,    86,    87,
     657,   658,   659,   826,   660,   661,   730,   731,   745,   747,
     753,   733,   734,   735,   736,   737,   738,   764,   749,    90,
     766,   779,   751,    81,   765,   767,   108,   634,   770,   109,
     110,   768,   111,   112,   113,   771,   776,   780,   114,   115,
     778,    81,   781,   795,   108,    69,   842,   109,   110,   789,
     111,   112,   113,   785,   796,   797,   114,   115,   798,    77,
      78,    79,    80,   116,   800,    70,    82,   804,   813,   117,
     118,   809,   814,    85,   107,   825,   817,    86,    87,   818,
     819,   116,   662,   824,    82,   831,   833,   117,   118,   838,
     840,    85,   841,   844,   845,    86,    87,   846,   848,    94,
     849,   852,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   677,   678,   679,   680,   681,   682,   683,   684,   685,
      81,   854,   855,   108,   861,   862,   109,   110,   863,   111,
     112,   113,   867,   868,   869,   114,   115,   216,   686,   870,
     871,   326,   217,   218,   219,   220,   872,   686,    46,   221,
     222,   267,   223,   224,    71,   527,    72,   653,   225,   226,
     268,   323,   687,    82,   688,   472,   117,   118,   378,   379,
      85,   380,   648,   381,    86,    87,   585,   216,   269,   270,
     271,   272,   217,   218,   219,   220,   547,   837,   763,   221,
     222,   105,   223,   224,   266,   622,   273,   274,   225,   226,
     538,   414,   623,   227,   704,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,   227,     0,   140,   141,   142,     0,   244,
     245,     0,     0,   246,     0,     0,     0,   247,   275,   249,
       0,     0,     0,     0,     0,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,     0,     0,   246,     0,     0,     0,   247,   248,   249,
     143,   732,   144,   145,   146,   147,   148,   149,   657,   658,
     659,     0,   660,   661,     0,     0,     0,     0,     0,   733,
     734,   735,   736,   737,   738,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     739,     0,     0,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     662
};

static const yytype_int16 yycheck[] =
{
      49,    21,   115,   114,   102,   111,   112,   267,   106,    32,
     107,   108,   109,   215,   601,   275,   113,   507,   164,    78,
      26,   584,     4,   225,   226,   120,    46,    49,   673,    22,
     675,    18,    19,    82,    83,    84,   526,   686,    87,   134,
       3,    82,    18,   705,    18,   707,   101,   123,    33,    34,
      19,    81,   705,   129,   707,    85,    32,    86,    32,   707,
      23,   172,    19,    75,   170,    87,    35,    18,   117,   118,
      18,    18,    20,    42,    43,    44,    45,   118,    35,    11,
     103,    13,    14,    15,   121,    42,    43,    44,    45,    18,
      59,   120,    45,    44,   584,    11,   133,    13,    14,    15,
     745,    70,    59,   118,   749,    12,   751,    18,   671,    91,
      92,    18,    19,    70,   776,   121,   778,    70,   705,   134,
     707,   118,   119,   776,   173,   778,   175,   120,   776,    11,
     778,    13,    14,    15,    18,    19,   133,   124,   284,   702,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   173,   814,   175,   166,   800,   855,   806,   134,   123,
     134,   814,   119,   862,    18,    19,   814,   369,   370,   133,
     200,   201,   202,   203,   204,   205,   206,    18,   840,   841,
     128,   671,   120,    99,   747,   123,   831,   840,   841,   776,
     118,   778,   840,   841,    33,    34,    35,   129,   130,   131,
      19,   314,    11,    42,    43,   133,   120,   770,   771,    18,
     307,   855,   702,   129,   130,   131,    35,    99,   862,   118,
     134,    60,   328,    42,    43,    44,    45,   814,    36,    37,
      38,   118,    40,    41,   293,    44,    45,    46,    33,    34,
      59,   118,    17,    18,    19,    20,   133,   129,   130,   131,
     118,    70,     0,   840,   841,    10,   133,   747,    76,    77,
     309,   310,   311,   312,   410,   133,    12,    16,    17,    18,
      19,    20,    18,    19,   118,   118,    76,    77,   376,   539,
     770,   771,   118,    18,   382,   118,   384,   336,   337,   133,
     339,   340,   341,   342,   343,   344,   345,   346,    44,   118,
     133,    82,    83,    78,   118,   403,   124,   125,    11,    18,
     118,   424,   425,   426,   336,   118,    73,    74,    75,   133,
     433,    18,    79,    80,   124,   125,   432,    18,   377,    78,
     133,   428,   429,   118,   383,   120,   391,   434,   393,   394,
     395,   396,   397,   398,   399,   400,   121,   402,    18,   124,
     125,    76,    77,   128,   118,   377,   120,   132,   133,   134,
     118,   383,    18,    17,    18,    19,    20,   116,   117,   126,
     127,   129,   121,   118,   423,   124,   125,   122,   401,   128,
      18,    76,    77,   132,   133,   119,   435,   436,   437,   438,
     439,   440,   441,   442,   443,    31,    76,    77,   129,   124,
     125,   423,    71,    76,    77,   391,   504,    18,    18,   611,
     612,   613,   614,   435,   119,   119,   402,   119,   620,   621,
     469,   123,   624,   625,    78,   486,   487,   488,   688,   124,
     125,   133,   120,    12,     3,   123,    17,    18,    19,    20,
      18,    10,    20,   541,   124,   125,    25,   469,    27,    28,
      19,   124,   125,   129,   118,   119,   562,   121,   123,    17,
      18,    19,    20,   560,    33,    31,   726,   121,   132,   133,
     730,    33,    34,   579,   128,    44,    45,    18,   132,   133,
      42,    43,   119,     3,   121,   120,    12,   120,   123,   122,
      59,   118,    18,    19,   119,   132,   133,    78,    60,    25,
     120,    70,   122,   118,   764,   120,   119,    17,    18,    19,
      20,   645,   646,   647,    95,    96,    18,   630,    18,    18,
      78,    18,   628,    30,     4,   638,   118,     4,   634,    18,
      18,   580,     5,    31,   631,   632,     6,     7,     8,     9,
     121,    22,   118,   124,   125,   594,   595,   128,   808,   134,
      18,   132,   133,    18,    26,    26,   654,   121,   580,   133,
      18,   129,   118,   121,   123,   120,   124,   125,    78,   680,
     128,   118,   594,   595,   132,   133,   836,   626,   627,   118,
     118,   604,   605,   606,   607,   845,   299,   300,   301,   302,
     303,   304,   305,   306,   854,     4,    26,   119,    30,    86,
      90,    19,    39,   716,   626,   627,   120,   118,    33,     4,
       4,   121,     4,    31,   124,   125,   122,    35,   128,   123,
     123,    18,   132,   133,    42,    43,    44,    45,   677,     3,
       4,   123,   118,   118,   683,   684,   685,   119,    18,   118,
     118,    59,    98,    17,    18,    19,    20,    18,    58,    23,
      18,    32,    70,   122,   121,   677,   118,   123,    32,   120,
     123,   683,   684,   685,    22,   122,   118,   780,   781,    18,
     118,   720,   118,   118,    18,   122,    18,    18,   727,   134,
      18,    18,   731,    57,     4,     4,    18,    18,    18,   738,
     739,   789,    18,     4,   123,     4,    86,    18,   720,   719,
     134,   123,   123,   123,    78,   727,    18,    81,     3,   731,
      84,    85,    26,    87,    88,    89,   738,   739,   134,    93,
      94,     4,    17,    18,    19,    20,     3,   118,    23,   189,
     190,   191,   192,   193,   194,   195,   785,    32,    86,   118,
      17,    18,    19,    20,   118,   120,    23,   121,   118,   134,
     124,   125,    26,    29,   128,    32,   129,   122,   132,   133,
      36,    37,    38,   785,    40,    41,   123,    26,   118,   123,
      18,    47,    48,    49,    50,    51,    52,   123,   118,   828,
      18,     4,   118,    78,   118,   118,    81,    82,   123,    84,
      85,   118,    87,    88,    89,   123,   118,    86,    93,    94,
     118,    78,    86,   118,    81,     3,   828,    84,    85,    26,
      87,    88,    89,   129,   118,   118,    93,    94,   118,    17,
      18,    19,    20,   118,   118,    23,   121,   118,   129,   124,
     125,    18,   118,   128,    32,   122,   118,   132,   133,   118,
     118,   118,   118,   118,   121,   118,    18,   124,   125,    18,
     118,   128,   118,   118,   123,   132,   133,    18,   122,    51,
     118,   123,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      78,   123,   133,    81,   118,   118,    84,    85,   134,    87,
      88,    89,   118,   118,   134,    93,    94,    12,    97,   134,
     118,   168,    17,    18,    19,    20,   118,    97,    20,    24,
      25,    26,    27,    28,    34,   409,    34,   595,    33,    34,
      35,   166,   121,   121,   123,   337,   124,   125,   221,   221,
     128,   221,   590,   221,   132,   133,   484,    12,    53,    54,
      55,    56,    17,    18,    19,    20,   422,   810,   689,    24,
      25,    64,    27,    28,   104,   544,    71,    72,    33,    34,
     413,   274,   544,    78,   621,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    78,    -1,    18,    19,    20,    -1,   124,
     125,    -1,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,    -1,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      73,    29,    75,    76,    77,    78,    79,    80,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     6,     7,     8,     9,   136,   137,   140,   153,   154,
      18,    18,    18,    18,     0,   118,   141,    10,   157,   118,
     138,   139,   118,    18,   158,    19,    35,    42,    43,    44,
      45,    59,    70,   182,   183,   184,   185,   186,   228,   229,
     232,   233,   244,   246,   248,   259,   157,   182,   142,    11,
     118,   120,    18,   247,    33,    34,   230,   231,    18,    18,
      18,   245,    18,   260,   261,    18,   249,   261,   119,     3,
      23,   159,   187,   182,    31,    71,   144,    17,    18,    19,
      20,    78,   121,   124,   125,   128,   132,   133,   167,   168,
     169,   170,   171,   173,   158,   129,    18,    18,   119,   119,
     123,   129,   123,   118,   120,   259,   129,    32,    81,    84,
      85,    87,    88,    89,    93,    94,   118,   124,   125,   159,
     164,   165,   166,   169,   187,   188,   189,   190,   192,   193,
     194,   195,   198,   199,   200,   201,   202,   203,   205,   206,
      18,    19,    20,    73,    75,    76,    77,    78,    79,    80,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     160,   161,   162,    31,    10,    33,   143,   145,   149,   184,
       3,   151,   119,   121,   132,   133,   174,   175,   176,   177,
     174,   170,   167,   172,   169,   169,   170,    18,   167,    11,
      13,    14,    15,   129,   130,   131,    76,    77,   124,   125,
      73,    74,    75,    79,    80,   126,   127,   118,    18,    19,
     124,   181,   119,   119,    18,    18,    12,    17,    18,    19,
      20,    24,    25,    27,    28,    33,    34,    78,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   124,   125,   128,   132,   133,   134,
     207,   208,   209,   210,   211,   212,   214,   221,   222,   223,
     224,   163,   165,   207,   261,    18,   260,    26,    35,    53,
      54,    55,    56,    71,    72,   133,   207,   264,   273,   274,
     275,   276,   277,   278,   279,   166,   166,   166,    18,   156,
     188,   188,   166,    18,    19,   173,   189,   169,   169,    11,
      13,    14,    15,    99,   129,   130,   131,    30,   191,    76,
      77,   124,   125,     4,   118,    18,    20,   128,     4,    18,
     155,    18,   184,   228,     5,   146,   146,     4,    57,   152,
     188,    31,   173,   167,   134,   167,    22,   120,   122,    76,
      77,   124,   125,    76,    77,   124,   125,   134,   168,   168,
     168,   168,   168,   168,   168,   169,   169,   169,   169,   170,
     170,   170,   170,   170,   170,   170,    18,    19,   118,    18,
      18,   118,   133,   234,   118,   234,    26,   121,   212,   214,
     221,   222,    26,   121,    26,   155,   215,   216,   234,   234,
      18,   129,   118,    11,    13,    14,    15,    99,   129,   130,
     131,   118,   129,   123,    12,    18,    19,   178,   179,   121,
     133,   265,   266,   267,   265,   179,   118,   118,   118,     4,
     155,   280,   281,    26,    82,    83,    86,   119,    30,    90,
       4,    91,    92,    86,   120,    39,    76,    77,   124,   125,
      76,    77,   124,   125,   164,   164,   164,   164,   164,   164,
     164,   164,   166,   169,   169,   169,   169,   189,    18,    20,
     120,   118,   150,    33,   147,   188,     4,     4,   122,   120,
     134,   167,   172,   169,   169,   169,   169,   169,   169,   169,
     169,   118,   234,   234,    11,    18,    44,    45,    46,   235,
     236,   238,   239,   240,   241,   242,   118,   118,   207,   167,
     207,   167,   213,   207,   123,     4,   118,   123,   163,   165,
     165,   165,   165,   165,   165,   165,   165,   261,    16,    19,
     116,   117,   163,   262,   263,   207,   119,   181,   155,    33,
      34,    42,    43,    60,   250,   268,   271,   272,   268,   120,
     134,   123,    33,    34,    35,    42,    43,   250,   282,   283,
     284,   286,   287,   167,   196,   197,   189,   189,   189,    18,
     166,   166,    98,   204,   188,   189,   166,   167,   169,   169,
     169,   169,   169,   169,   169,   169,    18,   118,    18,    58,
     121,   167,   122,   118,   123,   238,   120,   236,   236,   236,
     118,   134,   123,   122,    22,   120,   122,   207,    32,   217,
     178,   180,   118,    18,   118,   118,   118,   118,   178,   122,
     134,    18,    18,    18,    18,    18,     4,     4,   179,   207,
      18,    18,   283,   284,    18,    18,    22,   120,    82,   118,
     123,    95,    96,   166,    82,   188,     4,     4,    86,   148,
     188,   167,   134,   180,    18,   123,   123,   123,   235,    25,
     179,   237,   167,   213,    26,    18,   218,    36,    37,    38,
      40,    41,   118,   225,   226,   261,   261,   261,   261,   118,
     234,   123,   234,   118,   234,   118,   234,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    97,   121,   123,   251,
     252,   254,   255,   256,   257,   258,   134,   118,   118,   119,
     234,   285,   123,   234,   285,   118,   234,   118,   234,   167,
     167,   188,     4,   189,   166,   166,    86,   188,   189,   118,
     120,   118,   237,   237,   237,   134,    26,   129,   122,   207,
     123,    26,    29,    47,    48,    49,    50,    51,    52,    68,
     226,   227,   243,   269,   270,   118,   180,   123,   269,   118,
     269,   118,   167,    18,   173,   167,   167,   167,   156,    18,
      44,   253,   179,   254,   123,   118,    18,   118,   118,   180,
     123,   123,   226,   227,   243,   288,   118,   288,   118,     4,
      86,    86,   189,   182,   167,   129,    44,   179,   167,    26,
     179,   167,   219,   167,   167,   118,   118,   118,   118,   269,
     118,   180,   269,   269,   118,   118,   120,   120,   123,    18,
     118,   122,   179,   129,   118,   180,   180,   118,   118,   118,
     288,   288,   189,   189,   118,   122,   167,   207,   120,   123,
     269,   118,   156,    18,   179,   120,   123,   253,    18,   288,
     118,   118,   167,   269,   118,   123,    18,   179,   122,   118,
     288,   288,   123,   179,   123,   133,   220,   179,   134,   216,
     217,   118,   118,   134,   134,   216,   217,   118,   118,   134,
     134,   118,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   135,   136,   136,   136,   136,   138,   137,   139,   137,
     141,   142,   140,   143,   145,   144,   144,   144,   144,   144,
     146,   147,   148,   147,   150,   149,   151,   151,   151,   152,
     152,   153,   154,   155,   155,   156,   156,   157,   157,   157,
     158,   158,   159,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   161,   161,   161,   161,   162,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   164,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   169,   169,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   174,   174,   175,   176,   177,   177,   177,   178,
     178,   178,   179,   179,   180,   181,   181,   181,   181,   182,
     182,   182,   182,   183,   183,   183,   184,   184,   184,   184,
     185,   186,   187,   188,   188,   188,   188,   189,   189,   190,
     190,   191,   192,   192,   192,   192,   192,   192,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   197,   197,   197,
     198,   198,   198,   199,   200,   201,   201,   201,   202,   202,
     203,   203,   203,   204,   204,   204,   205,   205,   206,   206,
     206,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   209,
     209,   209,   209,   210,   210,   211,   211,   211,   211,   211,
     211,   211,   211,   212,   212,   212,   213,   213,   214,   215,
     215,   215,   216,   217,   218,   218,   219,   219,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   221,   222,   222,
     223,   224,   224,   224,   224,   225,   226,   226,   226,   226,
     226,   226,   227,   228,   228,   228,   228,   229,   229,   230,
     230,   231,   231,   232,   232,   233,   233,   234,   234,   235,
     235,   235,   235,   235,   236,   236,   237,   237,   237,   238,
     238,   239,   239,   240,   240,   240,   241,   241,   242,   243,
     243,   243,   243,   243,   243,   244,   245,   245,   246,   247,
     248,   249,   249,   249,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   255,   255,   255,
     256,   257,   257,   258,   258,   259,   259,   259,   260,   260,
     261,   261,   261,   261,   261,   261,   261,   262,   262,   263,
     264,   264,   264,   264,   265,   265,   266,   267,   268,   268,
     268,   268,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   270,   271,   271,   271,   271,   271,   271,   272,   272,
     273,   273,   273,   274,   275,   275,   276,   276,   277,   278,
     279,   279,   279,   279,   280,   280,   281,   282,   282,   282,
     282,   282,   282,   283,   283,   283,   284,   284,   284,   285,
     286,   286,   287,   287,   288,   288,   288,   288,   288,   288
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     0,     7,     0,     6,
       0,     0,     8,     3,     0,     3,     2,     3,     3,     3,
       2,     0,     0,     6,     0,     4,     3,     3,     2,     2,
       4,     5,     3,     1,     3,     1,     3,     0,     3,     5,
       1,     3,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     2,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     2,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     3,     3,     5,     1,     3,     2,     2,
       1,     1,     1,     1,     8,     2,     2,     3,     5,     1,
       1,     1,     1,     3,     1,     1,     1,     2,     2,     0,
       1,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     1,     2,     3,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     6,     7,     3,     1,     3,     3,
       1,     1,     1,     4,     4,     7,     8,     8,     4,     6,
       3,     5,     5,     1,     2,     3,     1,     2,     1,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     6,     8,     1,     3,     3,     0,
       2,     3,     3,     4,     1,     3,     2,     5,     2,     3,
       5,     6,     5,     5,     6,     3,     4,     3,     1,     3,
       2,     1,     2,     1,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     2,     2,     5,
       6,     0,     8,     5,     6,     5,     6,     3,     5,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       5,     2,     4,     2,     4,     6,     2,     4,     2,     1,
       1,     1,     1,     1,     2,     2,     4,     6,     2,     4,
       2,     4,     4,     4,     2,     3,     4,     2,     3,     3,
       5,     3,     5,     4,     6,     0,     2,     2,     1,     2,
       1,     2,     3,     1,     2,     3,     5,     1,     1,     1,
       1,     1,     2,     1,     2,     0,     2,     3,     3,     3,
       0,     5,     7,     7,     7,     7,     3,     1,     1,     2,
       1,     2,     1,     2,     3,     3,     3,     3,     0,     1,
       1,     1,     0,     1,     2,     1,     2,     1,     2,     1,
       2,     2,     4,     4,     4,     5,     5,     5,     6,     7,
       1,     1,     1,     2,     1,     1,     3,     5,     2,     2,
       1,     1,     1,     1,     2,     2,     4,     1,     1,     1,
       1,     2,     2,     3,     4,     4,     6,     7,     7,     5,
       4,     5,     4,     5,     1,     1,     1,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 6:
#line 139 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
	}
#line 2158 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 140 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        delphi_app = true;
	}
#line 2166 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 143 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
	}
#line 2173 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 144 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
	}
#line 2180 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        delphi_unit_name = delphi_yytext;
        delphi_unit = true;
	}
#line 2189 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        delphi_unit = true ;
        delphi_app  = false;
        delphi_lib  = false;
        
        QMessageBox::information(0,"info","zexzer");
	}
#line 2201 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
	}
#line 2208 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { QMessageBox::information(0,"info2","interface");
    }
#line 2215 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 180 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2221 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        delphi_temp_string = delphi_yytext;
        fprintf(delphi_output,"section .text\n");
        fprintf(delphi_output,"global %s\n",delphi_yytext.toLatin1().data());
        fprintf(delphi_output,"%s:\n"      ,delphi_yytext.toLatin1().data());
    }
#line 2232 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        QMessageBox::information(0,delphi_temp_string,"endproc");
        bool found = false;
        QMap<QString, bool>::const_iterator i = proc_body_map.constBegin();
        while (i != proc_body_map.constEnd()) {
            if (i.key() == delphi_temp_string
            && (i.value() == false)) {
                proc_body_map[i.key()] = true;
                found = true;
                break;
            }
            ++i;
        }
        if (!found) {
            QMessageBox::critical(0,
            "Internal Error",
            "Compiler Error - procedure missing.");
            YYABORT;
        }
        fprintf(delphi_output,"\tret\n");
    }
#line 2258 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        delphi_temp_string = delphi_yytext;
    }
#line 2266 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 212 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        QMessageBox::information(0,"info","eine prpoc");
        proc_body_map.insert(delphi_temp_string,false);
	}
#line 2275 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    {
        QMessageBox::information(0,"info","ender");
	}
#line 2283 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 245 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2289 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 260 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2295 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 480 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2301 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 487 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2307 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 512 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2313 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 749 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2319 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 313:
#line 809 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2325 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 375:
#line 955 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2331 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 395:
#line 992 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2337 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 400:
#line 1003 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /*empty */ }
#line 2343 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 418:
#line 1036 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2349 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;

  case 422:
#line 1043 "source/parser/delphi/delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2355 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
    break;


#line 2359 "source/parser/delphi/delphi.tab.cc" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1160 "source/parser/delphi/delphi.ypp" /* yacc.c:1906  */

//-- FUNCTION DEFINITIONS ---------------------------------
static int delphi_closer(int val)
{
    if (delphi_input != nullptr) {
        fclose(delphi_input);
        delphi_input  = nullptr;
    }
    return val;
}

#if 0
static void emitCaller(X86Emitter * e)
{
    e->push(x86::ebp);
    e->mov (x86::ebp, x86::esp);
    e->sub (x86::esp, 4);
    
    e->add (x86::esp, 4);
    e->leave();
    e->ret();
}
#endif

int delphimain(QString file)
{
    line_no = 1;
    int res = 0;
    
    if (file.length() < 1) {
        QMessageBox::information(0,
            "Warning",
            "parser file can't be open");
        return 0;
    }


    if (delphi_input == nullptr) {
        delphi_input  = fopen(file.toLatin1().data(), "r");
    }
    else {
        fclose(delphi_input);
        delphi_input  = nullptr;
    }

    delphi_input = fopen(file.toLatin1().data(), "r");
    delphiset_in(delphi_input);


#if 0
    // write code
    {
        JitRuntime rt;
        CodeHolder code;
               
        code.init(rt.getCodeInfo());
        X86Compiler cc(&code);
        
        
        cc.nop();
        
        // parse source
        delphirestart(delphi_input);
        res = delphiparse();

        emitCaller(cc.asEmitter());
        
        cc.nop();
        cc.finalize();
        
        CodeBuffer &buffer = code.getSectionEntry(0)->getBuffer();
    
        // save code ...
        const std::string filename = "pasout.$$$";
    
        binwriter out(filename);
        out.write(reinterpret_cast<char*>(
        buffer.getData()),
        buffer.getLength());
        
        out.close();

        // write header test
//        writer_header(
//        buffer.getLength(),
//        buffer.getData() );
    }
#endif

    // all ok ?
    bool found = true;
    QMap<QString, bool>::const_iterator i = proc_body_map.constBegin();
    while (i != proc_body_map.constEnd()) {
        if (i.key()   == delphi_temp_string
        && (i.value() == true)) {
            found = true;
            break;
        }
        found = false;
        ++i;
    }
    if (found == false) {
        QMessageBox::critical(0,
        "Internal Error",
        "Compiler Error - procedure missing.");
        return delphi_closer(line_no);
    }

    if (delphi_input != nullptr) {
        fclose(delphi_input);
        delphi_input  = nullptr;
    }
    
    return res;
}
