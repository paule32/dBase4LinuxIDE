#include <QString>
#include <QMessageBox>

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
#line 1 "delphi.ypp" /* yacc.c:339  */

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
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#ifdef NO_IDE
#else
# include <QString>
# include <QMessageBox>
#endif

#undef  yylex
#undef  yyparse
#define yylex   delphilex
#define yyparse delphiparse

extern int line_no;
extern void delphiset_in(FILE *);

//-- Lexer prototype required by bison, aka getNextToken()
int delphilex(void);
int yyerror(const char *p) {
#ifdef NO_IDE
    printf("error at %d line: %s\n",line_no,p);
#else
    QMessageBox::warning(
    0,"Error !!!",
    QString("error at line: %1: %2. ")
    .arg(line_no+1)
    .arg(p));
#endif
    return line_no;
}

#line 110 "delphi.tab.cpp" /* yacc.c:339  */

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
   by #include "delphi.tab.hpp".  */
#ifndef YY_YY_DELPHI_TAB_HPP_INCLUDED
# define YY_YY_DELPHI_TAB_HPP_INCLUDED
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
#line 46 "delphi.ypp" /* yacc.c:355  */

  int val; 
  char sym;

#line 273 "delphi.tab.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int delphiparse (void);

#endif /* !YY_YY_DELPHI_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 288 "delphi.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   1186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  145
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  858

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
       0,    74,    74,    74,    74,    74,    77,    78,    82,    86,
      90,    91,    92,    93,    97,    98,   102,   103,   107,   108,
     111,   112,   115,   116,   120,   121,   125,   126,   127,   131,
     132,   136,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   164,   165,   166,   167,   171,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   187,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   225,   226,   227,   228,   229,   230,   231,   232,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   254,   255,   256,   257,   258,
     259,   260,   261,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   291,   292,   296,   297,   301,   302,   306,
     307,   308,   309,   313,   318,   322,   323,   324,   338,   339,
     340,   344,   345,   349,   353,   354,   355,   356,   360,   361,
     362,   363,   367,   368,   369,   373,   374,   375,   376,   380,
     384,   388,   392,   393,   394,   395,   399,   400,   404,   405,
     409,   413,   414,   415,   416,   417,   418,   419,   420,   423,
     423,   427,   428,   432,   433,   437,   441,   442,   443,   446,
     446,   446,   449,   450,   452,   453,   454,   457,   458,   461,
     462,   463,   467,   468,   469,   489,   490,   494,   495,   496,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   591,   592,
     593,   594,   598,   599,   603,   604,   605,   606,   607,   608,
     609,   610,   614,   615,   616,   620,   621,   625,   629,   630,
     631,   635,   639,   643,   644,   648,   649,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   664,   665,   665,   667,
     670,   671,   672,   673,   676,   678,   679,   680,   681,   682,
     683,   686,   689,   690,   691,   695,   696,   700,   701,   704,
     705,   709,   710,   714,   715,   726,   727,   731,   732,   733,
     734,   735,   739,   740,   744,   745,   746,   750,   751,   755,
     756,   760,   761,   762,   766,   767,   771,   775,   776,   777,
     778,   779,   780,   784,   788,   789,   793,   797,   801,   805,
     806,   807,   811,   812,   813,   817,   818,   822,   823,   827,
     828,   829,   830,   834,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   849,   850,   851,   854,   857,
     858,   862,   863,   871,   872,   873,   877,   878,   882,   883,
     884,   885,   886,   887,   888,   892,   892,   896,   900,   901,
     902,   903,   907,   908,   911,   912,   915,   916,   917,   918,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   934,
     938,   939,   940,   941,   942,   943,   947,   948,   952,   953,
     954,   958,   962,   963,   967,   968,   972,   976,   980,   981,
     982,   983,   987,   988,   992,   996,   997,   998,   999,  1000,
    1001,  1005,  1006,  1007,  1011,  1012,  1013,  1017,  1021,  1022,
    1026,  1027,  1031,  1032,  1033,  1034,  1035,  1036
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
  "program", "unit", "uses", "unit_interface", "unit_implementation",
  "unit_end", "initialization", "library", "package", "identifier_list",
  "unit_qualified_identifier", "main_uses", "uses_in", "asm",
  "asm_statement_", "label_", "asm_statement", "typed_constant",
  "simple_expression", "simple_expression_", "expression",
  "constant_expression", "simple_expression__", "term__", "factor__",
  "set_factor", "set_element", "variable_access", "end_access",
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

#define YYPACT_NINF -710

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-710)))

#define YYTABLE_NINF -159

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     441,    50,   111,   138,   152,   200,  -710,  -710,  -710,  -710,
     -55,   113,   279,   198,  -710,   689,   254,   326,   369,  -710,
     347,   264,   371,   381,   392,   404,   408,   404,  1093,   413,
      74,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  1088,   451,   450,   305,   350,   333,  -710,   447,
     448,  -710,  -710,   355,   358,   184,  -710,   357,   309,    57,
     349,  -710,  -710,   453,  -710,   763,   968,  -710,  -710,   464,
     195,  -710,  -710,  1088,   486,   376,  -710,   326,  -710,    35,
     372,   373,   475,   480,   800,   614,   800,   404,   484,  -710,
     925,  -710,  -710,   284,   284,  -710,   614,    41,   614,   614,
     485,   763,   763,   614,   293,   842,  -710,   376,    41,    41,
      41,   489,   376,  -710,    34,  -710,   469,    19,   148,  -710,
    -710,  -710,   506,   393,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,    58,  -710,  -710,   508,
     402,   399,  -710,  -710,   195,  -710,   595,   405,    41,    41,
    -710,    76,   132,   407,  -710,  -710,   320,   409,   505,   510,
     -15,    14,   507,  -710,  -710,   410,  -710,   124,     4,   512,
     464,   401,   401,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,   514,  -710,  -710,   422,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,   418,    59,    83,
    -710,   430,   436,   290,  -710,  -710,  -710,  -710,  -710,   -66,
     -66,   290,   440,   442,   443,  -710,  -710,  -710,  -710,   555,
     464,   293,   376,  -710,   362,  -710,  -710,  -710,  -710,  -710,
     538,  -710,   295,   479,   452,   536,   482,    32,   -21,   284,
     284,   534,  -710,   553,   316,   143,   156,  -710,  -710,   456,
     614,   614,   614,   614,   614,   614,   614,   614,   614,  -710,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,  -710,   842,  -710,  -710,   433,  -710,   558,  -710,  -710,
     763,   573,   583,  -710,   159,   176,   376,   376,   376,   376,
     376,   376,   376,    41,    41,    41,    41,  -710,  -710,  -710,
    -710,    27,   401,  -710,   346,   483,  -710,   487,   800,   376,
    -710,  -710,  -710,  -710,   800,   376,   800,   470,   593,   488,
    -710,   477,  -710,   614,  -710,   614,   614,   614,   614,   614,
     614,   614,   614,   404,   343,   800,  -710,  -710,  -710,   497,
    -710,    35,   464,  -710,   364,   364,  -710,   -34,  -710,  -710,
    -710,  -710,   499,  -710,   341,  -710,   501,  -710,   -22,   376,
     842,   842,   842,   584,   614,   614,  -710,   509,   763,   842,
     614,   376,   376,   376,  -710,    41,    41,    41,    41,    41,
      41,    41,    41,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,   561,  -710,
    -710,    41,    41,    41,    41,    41,    41,    41,    41,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,   517,   502,   608,   516,   608,   608,   608,   -72,   518,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,   515,  -710,
     617,   335,  -710,   800,  -710,   598,   290,   522,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,   625,    21,  -710,
    -710,   526,   527,   528,  -710,   290,   525,   520,   630,   633,
     637,   638,   640,  -710,   655,  -710,  -710,   656,   290,  -710,
     800,   643,   644,   397,   645,   648,  -710,  -710,  -710,  -710,
    -710,  -710,   548,   376,  -710,    -3,   -47,   547,  -710,  -710,
    -710,  -710,   496,  -710,   683,   667,   668,  -710,   588,  -710,
    -710,   556,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
     763,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
     290,  -710,   657,   554,   562,   564,   346,  -710,   390,  -710,
     376,   376,   670,  -710,   663,  -710,  -710,    43,  -710,  -710,
     404,   404,   404,   404,  -710,  -710,  -710,    63,    45,   140,
     144,   954,  -710,  -710,   559,   576,    92,   153,  -710,  -710,
     160,   170,   376,   563,   376,   376,   763,   694,   842,   614,
     614,   618,   763,  -710,  -710,  -710,   842,  -710,  -710,   589,
    -710,   390,   390,   390,   575,   685,  -710,   585,  -710,   590,
     800,   594,   692,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  1031,   603,   290,   599,  1031,
     607,  1031,   611,   376,  -710,   708,   293,  -710,  -710,   376,
     376,   376,   485,    48,   290,   481,   613,  -710,   612,  -710,
    -710,  -710,  -710,  -710,  -710,   722,   623,   626,   290,   620,
     622,  1068,   631,  1068,   632,   634,  -710,  -710,  -710,   747,
    -710,  -710,   669,   671,   842,  -710,  -710,  -710,   624,  -710,
    -710,  -710,    38,   376,   730,  -710,   290,   376,  -710,  -710,
    -710,  -710,  -710,  -710,   376,   376,   642,   651,   660,  -710,
     661,  1031,   666,   290,  -710,  1031,  -710,  1031,  -710,  -710,
    -710,  -710,   676,  -710,   352,   146,   740,   -12,  -710,  -710,
     290,  -710,   646,  -710,  -710,   678,   290,   290,   679,   680,
     681,  -710,  1068,  -710,  1068,   376,  -710,   842,   842,  -710,
     376,  -710,  -710,  -710,   800,  -710,   233,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  1031,   682,  -710,  -710,  -710,
    -710,   485,   744,   290,   235,    48,  -710,  -710,   745,  1068,
     684,   687,  -710,  -710,  -710,  -710,  -710,   652,  -710,  -710,
    -710,  -710,   376,  -710,  -710,  1031,   688,   650,  -710,   767,
     290,   691,   696,  -710,  1068,  1068,  -710,   686,  -710,  -710,
     290,   698,  -710,  -710,  -710,  -710,  -710,   677,  -710,   290,
      -4,  -710,  -710,   704,   705,   695,  -710,     7,   712,   713,
     701,   702,  -710,  -710,   714,   719,  -710,  -710
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       0,     0,    26,     0,     1,    26,     0,     0,   162,    21,
       0,   309,     0,     0,     0,   388,     0,   388,   162,     0,
     159,   163,   164,   169,   170,   302,   303,   304,   165,   166,
     167,   168,   383,     0,    29,     0,     0,     0,   346,     0,
       0,   305,   306,     0,     0,     0,   343,     0,     0,   383,
       0,   348,   384,     0,     7,   172,    32,   161,   160,     0,
     383,    10,    13,   162,     0,     0,    27,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,   388,     0,   385,
       0,     6,   126,   124,   125,   123,     0,     0,     0,     0,
       0,   172,   172,     0,   217,   215,   173,     0,     0,     0,
       0,     0,     0,   188,    83,    67,   178,    68,   115,   130,
     127,   181,     0,     0,   176,   177,   182,   189,   190,   183,
     199,   200,   201,   184,   185,   186,   187,    33,    35,    34,
      51,    46,    48,    47,    45,    50,    49,    38,    39,    36,
      37,    40,    41,    42,    43,    44,     0,    57,    52,     0,
      22,     0,    11,    12,   162,    14,   172,     0,     0,     0,
      30,    92,   100,     0,   154,   155,     0,     0,     0,     0,
       0,     0,   287,   240,   247,   239,   238,     0,     0,     0,
     268,   290,   292,   241,   237,   236,   222,   227,   229,   228,
     232,   230,   234,   235,   226,   231,   233,   223,   224,   225,
     242,   243,   244,     0,   245,   246,     0,   221,   220,   248,
     249,   254,   255,   256,   257,   250,   251,     0,    58,   386,
     394,     0,   387,     0,   428,   438,   440,   439,   441,   398,
     400,   245,     0,     0,     0,   429,   430,   432,   433,     0,
       0,     0,     0,   141,     0,   137,   139,   140,   142,   138,
       0,   128,     0,     0,    24,     0,     0,     0,     0,     0,
       0,   218,   216,   135,     0,    73,    74,   129,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   174,    53,    54,     0,    31,     0,     9,    15,
     172,     0,     0,     8,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,   156,   157,
     347,     0,     0,   313,     0,     0,   311,     0,     0,     0,
     258,   259,   260,   261,     0,     0,     0,     0,     0,     0,
     291,     0,   289,     0,   344,     0,     0,     0,     0,     0,
       0,     0,     0,   388,     0,     0,   150,   148,   149,   151,
     431,     0,     0,   399,   406,   406,   401,     0,   351,   350,
     349,   436,     0,   437,     0,   144,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,   209,     0,   172,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,   132,    90,    85,    89,    88,    91,    84,
      86,    87,   180,    72,    71,    69,    70,   118,   119,   120,
     121,   122,   116,   117,   175,    55,    56,    23,    18,    17,
      16,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      94,    98,    97,    93,    95,    96,   104,   103,   101,   102,
     307,     0,     0,     0,   322,     0,     0,     0,     0,     0,
     317,   318,   319,   320,   321,   314,   312,   288,     0,   262,
     265,     0,   286,     0,   267,   269,     0,     0,    65,    60,
      64,    63,    66,    59,    61,    62,   389,     0,   125,   395,
     396,     0,     0,     0,   386,     0,     0,     0,     0,     0,
       0,     0,     0,   409,     0,   407,   408,     0,     0,   434,
       0,     0,     0,     0,     0,     0,   443,   442,   447,   448,
     445,   446,     0,     0,   146,   196,     0,     0,   192,   191,
     202,    25,     0,   203,   172,     0,     0,   207,     0,   219,
     136,     0,    82,    81,    79,    80,    78,    77,    75,    76,
     172,   114,   113,   111,   112,   110,   109,   107,   108,   308,
       0,   336,     0,   331,   329,   334,     0,   315,     0,   253,
       0,     0,     0,   271,     0,   270,   153,     0,   345,   397,
     388,   388,   388,   388,   152,   405,   404,     0,     0,     0,
       0,   352,   402,   403,     0,     0,     0,     0,   449,   450,
       0,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,     0,   172,   213,   210,   211,     0,   134,    19,     0,
     323,     0,     0,     0,     0,     0,   326,   327,   266,     0,
       0,   273,     0,   296,   297,   298,   299,   300,   295,   293,
     294,   393,   390,   392,   391,   410,     0,     0,     0,   410,
       0,   410,     0,   381,   378,     0,     0,   366,   368,     0,
       0,   379,     0,     0,     0,   363,     0,   353,   371,   377,
     375,   376,   435,   444,   451,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   198,   197,     0,
     193,   195,     0,     0,     0,   214,   208,   310,   332,   330,
     335,   316,     0,     0,     0,   263,     0,     0,   301,   337,
     338,   339,   340,   341,     0,     0,   415,   413,   411,   420,
     417,   410,     0,     0,   422,   410,   421,   410,   382,   367,
     365,   364,   369,   380,     0,     0,     0,     0,   355,   354,
       0,   372,     0,   453,   452,     0,     0,     0,   464,   463,
     462,   460,     0,   458,     0,     0,   194,     0,     0,   204,
       0,   324,   325,   328,     0,   274,     0,   272,   342,   419,
     416,   414,   412,   418,   423,   410,     0,   425,   424,   370,
     373,     0,     0,     0,     0,     0,   357,   356,     0,     0,
       0,     0,   467,   466,   465,   461,   459,     0,   205,   206,
     333,   264,     0,   275,   426,   410,     0,     0,   359,     0,
       0,     0,     0,   454,     0,     0,   143,     0,   427,   374,
       0,     0,   361,   358,   457,   456,   455,     0,   360,     0,
       0,   276,   362,   277,     0,     0,   278,     0,   284,     0,
       0,     0,   285,   281,   279,   282,   280,   283
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -710,  -710,  -710,  -710,   753,  -710,  -710,  -710,  -710,  -710,
    -710,   -57,  -654,   788,   761,   809,  -710,  -710,  -710,  -140,
     299,   -10,   -90,   -60,   471,   -75,    24,  -710,   437,  -103,
     -82,  -710,  -710,  -710,  -462,  -231,  -553,   472,   278,   -50,
      -1,  -710,  -710,   812,   -81,  -100,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,   -83,  -710,  -710,  -710,  -710,   659,   268,
     690,  -710,  -709,  -656,  -710,  -710,  -710,   693,   699,  -710,
    -710,  -710,  -565,  -653,    46,  -710,  -710,  -710,  -710,  -710,
    -165,   277,   -80,  -213,   391,  -710,  -710,  -710,  -710,  -649,
    -710,  -710,  -710,  -710,  -710,  -710,   474,  -710,  -710,    60,
     188,  -710,  -710,  -710,  -710,   805,   778,   -23,  -710,  -710,
    -710,   627,  -710,  -710,   493,  -630,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,   348,
     353,   262,  -710,  -710,  -642
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    70,    43,    74,   167,   311,     8,
       9,   347,   265,    18,    45,   113,   157,   158,   159,   227,
     114,   115,   116,   273,   171,   117,   118,   119,   274,   120,
     259,   256,   257,   258,   369,   636,   587,   177,    29,    30,
      31,    32,    33,   121,   122,   123,   124,   289,   125,   126,
     127,   128,   536,   537,   129,   130,   131,   132,   133,   134,
     545,   135,   136,   216,   217,   218,   219,   220,   221,   481,
     222,   348,   349,   585,   642,   777,   841,   223,   224,   225,
     226,   649,   726,   727,    34,    35,    51,    52,    36,    37,
     335,   468,   469,   637,   470,   471,   472,   473,   474,   728,
      38,    56,    39,    48,    40,    61,   513,   675,   676,   747,
     677,   678,   679,   680,   681,    41,    58,    59,   502,   503,
     243,   373,   374,   375,   514,   729,   730,   515,   516,   244,
     245,   246,   247,   248,   249,   250,   383,   384,   527,   528,
     529,   687,   530,   531,   761
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     172,   271,   370,   229,    62,   272,   260,   242,   262,   263,
     377,   255,   161,   268,   160,   170,   337,   629,   744,   614,
     266,   267,   650,   165,   586,   160,   350,   351,   584,   734,
     344,   736,   172,   275,   276,   616,   396,   172,   759,   584,
     759,    71,   760,   594,   760,   280,   576,   281,   282,   283,
     366,   763,   279,   174,   175,   371,   367,   368,    92,    93,
      94,    95,   577,    15,   230,   399,   745,   372,    10,   162,
     355,   617,   356,   357,   358,   228,   303,    65,   304,   643,
     644,   645,   771,   646,   647,   312,   518,   316,    72,   317,
     318,   319,   746,   314,   315,   290,   291,    66,   533,   400,
     519,   784,    25,   333,   732,   787,   795,   788,   586,   759,
     796,   759,   534,   760,   309,   760,   163,   615,   334,    97,
     805,   261,   806,   397,   398,   345,   758,    27,   758,    11,
     843,   844,   336,   284,   277,   755,   182,   816,   850,   590,
     251,   849,   252,   292,   293,   460,   759,   334,   385,   188,
     760,   189,   190,   253,   254,   814,    12,   823,   359,   176,
     334,   648,   107,   285,   286,   287,   461,   462,   657,   110,
      13,   759,   759,   111,   112,   760,   760,   172,   334,   172,
     786,   655,   835,   836,   845,   828,   305,   255,   360,   361,
     362,   851,   386,   382,   388,   586,   334,   758,   422,   758,
      14,   363,   434,   800,   801,   320,   321,   322,   323,   324,
     684,   685,   364,   487,    20,   423,   424,   425,   426,   405,
     406,   294,   295,   296,   501,   334,   586,   297,   298,   438,
      21,    16,   409,   410,   758,   441,   442,    22,    23,    24,
      25,   172,   172,   172,   172,   172,   172,   172,   456,   457,
     458,   459,   445,   446,    26,   477,   325,   326,   659,   758,
     758,   479,   661,   482,   172,    27,   792,   407,   408,   793,
     172,   586,   685,   334,   299,   300,   688,   334,   691,   478,
     411,   412,   504,   443,   444,   480,   334,   604,   693,    17,
     538,   539,   540,   334,   586,   586,    46,    49,    50,   547,
     447,   448,   366,   334,   542,   543,    63,    84,   367,   368,
     548,   269,   270,    85,   172,   507,    19,   546,   427,   428,
     429,   430,   431,   432,   433,    42,   172,   172,   172,   535,
     552,   553,   554,   555,   556,   557,   558,   559,   328,   329,
     496,   549,   550,   228,    44,   488,   489,   490,   491,   492,
     493,   494,   495,   812,   228,   819,   813,   463,   820,   497,
      92,    93,   498,    95,   464,    47,   561,   562,   563,   564,
     565,   566,   567,   568,   521,   522,   523,   390,   391,    92,
      93,    94,    95,   524,   525,   573,   574,   575,    20,    53,
     465,   466,   467,    92,    93,    94,    95,   508,   509,    54,
     583,   512,   366,   251,    21,   252,   510,   511,   367,   368,
      55,    22,    23,    24,    25,   635,   253,   254,   708,   709,
     710,    97,    57,    76,   512,    77,    60,    87,    26,    88,
     521,   522,   656,   658,   660,   662,   403,   605,   404,    27,
      97,   686,   689,   748,    64,   692,   694,     1,     2,     3,
       4,   435,   621,   436,    97,   581,    73,   582,   172,   499,
     500,    75,    79,   623,   107,    80,    81,   108,   109,    78,
     790,   110,   791,   613,    82,   111,   112,    83,    90,   628,
      86,   772,   160,   107,    91,   775,   168,   169,  -158,   166,
     110,   178,   179,   180,   111,   112,   387,   107,   181,   288,
     168,   169,   231,   264,   110,   172,   172,   278,   111,   112,
     301,   302,   306,    92,    93,    94,    95,   308,   701,   797,
     638,   480,   307,   331,   313,   327,   706,   330,   332,   702,
     703,   339,   352,   338,   334,   699,   354,   172,   346,   172,
     172,   705,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   353,   695,   365,   697,   698,    88,   715,   378,   381,
     379,   380,   818,   740,   389,   392,   394,   651,   652,   653,
     654,   393,   395,   401,    97,   402,   437,   439,   672,   414,
     415,   416,   417,   418,   419,   420,   421,   440,   172,   832,
     413,   619,   620,   483,   172,   172,   172,   484,    65,   838,
     486,   475,   541,   738,   769,   476,   485,   544,   842,   741,
     742,   743,    92,    93,    94,    95,   505,   107,    66,   560,
     108,   109,   520,   532,   110,   570,   464,    96,   111,   112,
     584,    92,    93,    94,    95,   569,   572,   579,   172,   580,
     588,   578,   172,   589,   591,   592,   593,   595,   597,   172,
     172,   598,   310,   773,   596,   599,   600,   776,   601,   602,
     603,   606,   607,   610,   778,   779,   611,   808,   809,   612,
     618,   624,   625,    97,   626,   630,    98,   631,   627,    99,
     100,   641,   101,   102,   103,   632,    65,   633,   104,   105,
     172,   811,    97,   682,   683,   172,   640,   696,   700,    17,
      92,    93,    94,    95,   704,   807,    66,   707,    20,   711,
     810,   712,   714,   106,   713,    96,   107,   716,   717,   108,
     109,   731,   733,   110,    21,   735,   739,   111,   112,   737,
     751,    22,    23,    24,    25,   107,   750,   172,   108,   109,
     752,   753,   110,   756,   754,   757,   111,   112,    26,   762,
     764,   766,   827,   770,   765,   767,   774,   768,   794,    27,
     780,    97,   817,   822,    98,   622,    65,    99,   100,   781,
     101,   102,   103,   830,   826,   798,   104,   105,   782,   783,
      92,    93,    94,    95,   785,   831,    66,   449,   450,   451,
     452,   453,   454,   455,   789,    96,   799,   802,   803,   804,
     815,   106,   824,    28,   107,   825,   829,   108,   109,   837,
     840,   110,   182,   833,   834,   111,   112,   183,   184,   185,
     186,   839,   846,   847,   187,   188,   164,   189,   190,   848,
     852,   853,   856,   191,   192,   854,   855,   857,   173,    67,
     551,    97,    68,   506,    98,    65,   340,    99,   100,   639,
     101,   102,   103,   634,   571,   821,   104,   105,   526,    92,
      93,    94,    95,   749,    89,    66,   232,   376,   517,   690,
       0,   608,     0,     0,    96,     0,   609,   341,   193,     0,
     342,   106,     0,     0,   107,     0,   343,   108,   109,     0,
       0,   110,     0,     0,     0,   111,   112,     0,     0,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,     0,
      97,     0,     0,    98,   210,   211,    99,   100,   212,   101,
     102,   103,   213,   214,   215,   104,   105,   182,     0,     0,
       0,     0,   183,   184,   185,   186,     0,     0,     0,   187,
     188,   233,   189,   190,     0,     0,     0,     0,   191,   192,
     234,     0,     0,   107,     0,     0,   108,   109,     0,     0,
     110,     0,     0,     0,   111,   112,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,   239,   240,     0,     0,
       0,     0,     0,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   663,   664,   665,   666,   667,
     668,   669,   670,   671,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   140,     0,   141,   142,   143,   144,   145,   146,   210,
     211,   672,     0,   212,     0,     0,     0,   213,   241,   215,
     718,     0,     0,     0,     0,     0,     0,   643,   644,   645,
       0,   646,   647,     0,     0,   673,     0,   674,   719,   720,
     721,   722,   723,   724,     0,     0,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   718,    69,   725,
       0,     0,     0,     0,   643,   644,   645,    20,   646,   647,
       0,     0,    20,     0,     0,   719,   720,   721,   722,   723,
     724,     0,     0,    21,  -158,     0,     0,     0,    21,     0,
      22,    23,    24,    25,     0,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,   648,
       0,     0,    26,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   648
};

static const yytype_int16 yycheck[] =
{
      75,   104,   233,    86,    27,   105,    96,    90,    98,    99,
     241,    93,    69,   103,    18,    75,   181,   570,   672,    22,
     101,   102,   587,    73,   486,    18,   191,   192,    32,   659,
      26,   661,   107,   108,   109,    82,     4,   112,   691,    32,
     693,    42,   691,   505,   693,    11,   118,    13,    14,    15,
      12,   693,   112,    18,    19,   121,    18,    19,    17,    18,
      19,    20,   134,   118,    87,    86,    18,   133,    18,    70,
      11,   118,    13,    14,    15,    85,    18,     3,    20,    36,
      37,    38,    44,    40,    41,   166,   120,    11,    42,    13,
      14,    15,    44,   168,   169,    76,    77,    23,   120,   120,
     134,   731,    45,   118,   657,   735,   118,   737,   570,   762,
     122,   764,   134,   762,   164,   764,    70,   120,   133,    78,
     762,    97,   764,    91,    92,   121,   691,    70,   693,    18,
     134,   840,   118,    99,   110,   688,    12,   791,   847,   118,
     119,   134,   121,   124,   125,   118,   799,   133,   251,    25,
     799,    27,    28,   132,   133,   785,    18,   799,    99,   124,
     133,   118,   121,   129,   130,   131,   331,   332,   123,   128,
      18,   824,   825,   132,   133,   824,   825,   252,   133,   254,
     733,   118,   824,   825,   840,   815,   128,   269,   129,   130,
     131,   847,   252,   250,   254,   657,   133,   762,   288,   764,
       0,   118,   302,   756,   757,   129,   130,   131,    76,    77,
     118,   119,   129,   353,    19,   290,   291,   292,   293,    76,
      77,    73,    74,    75,   364,   133,   688,    79,    80,   310,
      35,   118,    76,    77,   799,    76,    77,    42,    43,    44,
      45,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,    76,    77,    59,   338,   124,   125,   118,   824,
     825,   344,   118,   346,   339,    70,   120,   124,   125,   123,
     345,   733,   119,   133,   126,   127,   123,   133,   118,   339,
     124,   125,   365,   124,   125,   345,   133,   518,   118,    10,
     390,   391,   392,   133,   756,   757,    18,    33,    34,   399,
     124,   125,    12,   133,   394,   395,    28,   123,    18,    19,
     400,    18,    19,   129,   389,   372,   118,   398,   294,   295,
     296,   297,   298,   299,   300,    71,   401,   402,   403,   389,
     405,   406,   407,   408,   409,   410,   411,   412,    18,    19,
     363,   401,   402,   353,    18,   355,   356,   357,   358,   359,
     360,   361,   362,   120,   364,   120,   123,    11,   123,    16,
      17,    18,    19,    20,    18,    18,   441,   442,   443,   444,
     445,   446,   447,   448,    33,    34,    35,    82,    83,    17,
      18,    19,    20,    42,    43,   465,   466,   467,    19,    18,
      44,    45,    46,    17,    18,    19,    20,    33,    34,    18,
     483,    60,    12,   119,    35,   121,    42,    43,    18,    19,
      18,    42,    43,    44,    45,    25,   132,   133,   631,   632,
     633,    78,    18,   118,    60,   120,    18,   118,    59,   120,
      33,    34,   597,   598,   599,   600,   120,   520,   122,    70,
      78,   606,   607,   674,    31,   610,   611,     6,     7,     8,
       9,    18,   542,    20,    78,   120,     5,   122,   533,   116,
     117,    11,   129,   544,   121,    18,    18,   124,   125,   119,
     118,   128,   120,   533,   119,   132,   133,   119,   129,   560,
     123,   712,    18,   121,    31,   716,   124,   125,   119,     3,
     128,   119,   119,    18,   132,   133,   134,   121,    18,    30,
     124,   125,    18,    18,   128,   580,   581,    18,   132,   133,
       4,   118,     4,    17,    18,    19,    20,   118,   618,   750,
     580,   581,   120,    18,   119,   118,   626,   118,    18,   619,
     620,   121,    18,    26,   133,   616,   118,   612,    26,   614,
     615,   622,    61,    62,    63,    64,    65,    66,    67,    68,
      69,   129,   612,   123,   614,   615,   120,   640,   118,     4,
     118,   118,   793,   666,    26,    86,    30,   590,   591,   592,
     593,   119,    90,    39,    78,    22,    18,     4,    97,   280,
     281,   282,   283,   284,   285,   286,   287,     4,   663,   820,
     134,    95,    96,   123,   669,   670,   671,     4,     3,   830,
     123,   118,    18,   663,   704,   118,   118,    98,   839,   669,
     670,   671,    17,    18,    19,    20,   119,   121,    23,    58,
     124,   125,   123,   122,   128,   123,    18,    32,   132,   133,
      32,    17,    18,    19,    20,   118,   120,   122,   713,    22,
     118,   123,   717,    18,   118,   118,   118,   122,    18,   724,
     725,    18,    57,   713,   134,    18,    18,   717,    18,     4,
       4,    18,    18,    18,   724,   725,    18,   767,   768,   121,
     123,     4,     4,    78,    86,    18,    81,   123,   122,    84,
      85,    18,    87,    88,    89,   123,     3,   123,    93,    94,
     765,   774,    78,   134,   118,   770,    26,   134,     4,    10,
      17,    18,    19,    20,    86,   765,    23,   118,    19,   134,
     770,    26,   122,   118,   129,    32,   121,   123,    26,   124,
     125,   118,   123,   128,    35,   118,    18,   132,   133,   118,
     118,    42,    43,    44,    45,   121,   123,   812,   124,   125,
      18,   118,   128,   123,   118,   123,   132,   133,    59,   118,
     118,     4,   812,   129,   120,    86,    26,    86,    18,    70,
     118,    78,    18,    18,    81,    82,     3,    84,    85,   118,
      87,    88,    89,   123,   122,   129,    93,    94,   118,   118,
      17,    18,    19,    20,   118,    18,    23,   316,   317,   318,
     319,   320,   321,   322,   118,    32,   118,   118,   118,   118,
     118,   118,   118,    15,   121,   118,   118,   124,   125,   123,
     133,   128,    12,   122,   118,   132,   133,    17,    18,    19,
      20,   123,   118,   118,    24,    25,    73,    27,    28,   134,
     118,   118,   118,    33,    34,   134,   134,   118,    77,    30,
     403,    78,    30,   371,    81,     3,   187,    84,    85,   581,
      87,    88,    89,   576,   463,   795,    93,    94,   384,    17,
      18,    19,    20,   675,    59,    23,    88,   240,   375,   607,
      -1,   523,    -1,    -1,    32,    -1,   523,   187,    78,    -1,
     187,   118,    -1,    -1,   121,    -1,   187,   124,   125,    -1,
      -1,   128,    -1,    -1,    -1,   132,   133,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    81,   124,   125,    84,    85,   128,    87,
      88,    89,   132,   133,   134,    93,    94,    12,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    -1,   121,    -1,    -1,   124,   125,    -1,    -1,
     128,    -1,    -1,    -1,   132,   133,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    73,    -1,    75,    76,    77,    78,    79,    80,   124,
     125,    97,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    -1,   121,    -1,   123,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    29,    10,    68,
      -1,    -1,    -1,    -1,    36,    37,    38,    19,    40,    41,
      -1,    -1,    19,    -1,    -1,    47,    48,    49,    50,    51,
      52,    -1,    -1,    35,    31,    -1,    -1,    -1,    35,    -1,
      42,    43,    44,    45,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,   118,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     6,     7,     8,     9,   136,   137,   138,   144,   145,
      18,    18,    18,    18,     0,   118,   118,    10,   148,   118,
      19,    35,    42,    43,    44,    45,    59,    70,   148,   173,
     174,   175,   176,   177,   219,   220,   223,   224,   235,   237,
     239,   250,    71,   140,    18,   149,   173,    18,   238,    33,
      34,   221,   222,    18,    18,    18,   236,    18,   251,   252,
      18,   240,   252,   173,    31,     3,    23,   150,   178,    10,
     139,   175,   219,     5,   141,    11,   118,   120,   119,   129,
      18,    18,   119,   119,   123,   129,   123,   118,   120,   250,
     129,    31,    17,    18,    19,    20,    32,    78,    81,    84,
      85,    87,    88,    89,    93,    94,   118,   121,   124,   125,
     128,   132,   133,   150,   155,   156,   157,   160,   161,   162,
     164,   178,   179,   180,   181,   183,   184,   185,   186,   189,
     190,   191,   192,   193,   194,   196,   197,    18,    19,    20,
      73,    75,    76,    77,    78,    79,    80,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   151,   152,   153,
      18,   146,   175,   219,   139,   174,     3,   142,   124,   125,
     158,   159,   160,   149,    18,    19,   124,   172,   119,   119,
      18,    18,    12,    17,    18,    19,    20,    24,    25,    27,
      28,    33,    34,    78,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     124,   125,   128,   132,   133,   134,   198,   199,   200,   201,
     202,   203,   205,   212,   213,   214,   215,   154,   156,   198,
     252,    18,   251,    26,    35,    53,    54,    55,    56,    71,
      72,   133,   198,   255,   264,   265,   266,   267,   268,   269,
     270,   119,   121,   132,   133,   165,   166,   167,   168,   165,
     157,   161,   157,   157,    18,   147,   179,   179,   157,    18,
      19,   164,   180,   158,   163,   160,   160,   161,    18,   158,
      11,    13,    14,    15,    99,   129,   130,   131,    30,   182,
      76,    77,   124,   125,    73,    74,    75,    79,    80,   126,
     127,     4,   118,    18,    20,   128,     4,   120,   118,   174,
      57,   143,   179,   119,   160,   160,    11,    13,    14,    15,
     129,   130,   131,    76,    77,   124,   125,   118,    18,    19,
     118,    18,    18,   118,   133,   225,   118,   225,    26,   121,
     203,   205,   212,   213,    26,   121,    26,   146,   206,   207,
     225,   225,    18,   129,   118,    11,    13,    14,    15,    99,
     129,   130,   131,   118,   129,   123,    12,    18,    19,   169,
     170,   121,   133,   256,   257,   258,   256,   170,   118,   118,
     118,     4,   146,   271,   272,   164,   158,   134,   158,    26,
      82,    83,    86,   119,    30,    90,     4,    91,    92,    86,
     120,    39,    22,   120,   122,    76,    77,   124,   125,    76,
      77,   124,   125,   134,   155,   155,   155,   155,   155,   155,
     155,   155,   157,   160,   160,   160,   160,   161,   161,   161,
     161,   161,   161,   161,   180,    18,    20,    18,   179,     4,
       4,    76,    77,   124,   125,    76,    77,   124,   125,   159,
     159,   159,   159,   159,   159,   159,   160,   160,   160,   160,
     118,   225,   225,    11,    18,    44,    45,    46,   226,   227,
     229,   230,   231,   232,   233,   118,   118,   198,   158,   198,
     158,   204,   198,   123,     4,   118,   123,   154,   156,   156,
     156,   156,   156,   156,   156,   156,   252,    16,    19,   116,
     117,   154,   253,   254,   198,   119,   172,   146,    33,    34,
      42,    43,    60,   241,   259,   262,   263,   259,   120,   134,
     123,    33,    34,    35,    42,    43,   241,   273,   274,   275,
     277,   278,   122,   120,   134,   158,   187,   188,   180,   180,
     180,    18,   157,   157,    98,   195,   179,   180,   157,   158,
     158,   163,   160,   160,   160,   160,   160,   160,   160,   160,
      58,   160,   160,   160,   160,   160,   160,   160,   160,   118,
     123,   229,   120,   227,   227,   227,   118,   134,   123,   122,
      22,   120,   122,   198,    32,   208,   169,   171,   118,    18,
     118,   118,   118,   118,   169,   122,   134,    18,    18,    18,
      18,    18,     4,     4,   170,   198,    18,    18,   274,   275,
      18,    18,   121,   158,    22,   120,    82,   118,   123,    95,
      96,   157,    82,   179,     4,     4,    86,   122,   179,   171,
      18,   123,   123,   123,   226,    25,   170,   228,   158,   204,
      26,    18,   209,    36,    37,    38,    40,    41,   118,   216,
     217,   252,   252,   252,   252,   118,   225,   123,   225,   118,
     225,   118,   225,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    97,   121,   123,   242,   243,   245,   246,   247,
     248,   249,   134,   118,   118,   119,   225,   276,   123,   225,
     276,   118,   225,   118,   225,   158,   134,   158,   158,   179,
       4,   180,   157,   157,    86,   179,   180,   118,   228,   228,
     228,   134,    26,   129,   122,   198,   123,    26,    29,    47,
      48,    49,    50,    51,    52,    68,   217,   218,   234,   260,
     261,   118,   171,   123,   260,   118,   260,   118,   158,    18,
     164,   158,   158,   158,   147,    18,    44,   244,   170,   245,
     123,   118,    18,   118,   118,   171,   123,   123,   217,   218,
     234,   279,   118,   279,   118,   120,     4,    86,    86,   180,
     129,    44,   170,   158,    26,   170,   158,   210,   158,   158,
     118,   118,   118,   118,   260,   118,   171,   260,   260,   118,
     118,   120,   120,   123,    18,   118,   122,   170,   129,   118,
     171,   171,   118,   118,   118,   279,   279,   158,   180,   180,
     158,   198,   120,   123,   260,   118,   147,    18,   170,   120,
     123,   244,    18,   279,   118,   118,   122,   158,   260,   118,
     123,    18,   170,   122,   118,   279,   279,   123,   170,   123,
     133,   211,   170,   134,   207,   208,   118,   118,   134,   134,
     207,   208,   118,   118,   134,   134,   118,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   135,   136,   136,   136,   136,   137,   137,   138,   139,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   145,   146,   146,   147,   147,   148,   148,   148,   149,
     149,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   152,   152,   152,   152,   153,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   165,   165,   166,   167,   168,   168,   168,   169,   169,
     169,   170,   170,   171,   172,   172,   172,   172,   173,   173,
     173,   173,   174,   174,   174,   175,   175,   175,   175,   176,
     177,   178,   179,   179,   179,   179,   180,   180,   181,   181,
     182,   183,   183,   183,   183,   183,   183,   183,   183,   184,
     184,   185,   185,   186,   186,   187,   188,   188,   188,   189,
     189,   189,   190,   191,   192,   192,   192,   193,   193,   194,
     194,   194,   195,   195,   195,   196,   196,   197,   197,   197,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   200,   200,
     200,   200,   201,   201,   202,   202,   202,   202,   202,   202,
     202,   202,   203,   203,   203,   204,   204,   205,   206,   206,
     206,   207,   208,   209,   209,   210,   210,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   212,   213,   213,   214,
     215,   215,   215,   215,   216,   217,   217,   217,   217,   217,
     217,   218,   219,   219,   219,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   226,
     226,   226,   227,   227,   228,   228,   228,   229,   229,   230,
     230,   231,   231,   231,   232,   232,   233,   234,   234,   234,
     234,   234,   234,   235,   236,   236,   237,   238,   239,   240,
     240,   240,   241,   241,   241,   242,   242,   243,   243,   244,
     244,   244,   244,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   246,   246,   247,   248,
     248,   249,   249,   250,   250,   250,   251,   251,   252,   252,
     252,   252,   252,   252,   252,   253,   253,   254,   255,   255,
     255,   255,   256,   256,   257,   258,   259,   259,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     264,   265,   266,   266,   267,   267,   268,   269,   270,   270,
     270,   270,   271,   271,   272,   273,   273,   273,   273,   273,
     273,   274,   274,   274,   275,   275,   275,   276,   277,   277,
     278,   278,   279,   279,   279,   279,   279,   279
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     6,     5,     7,     3,
       2,     3,     3,     2,     2,     3,     3,     3,     2,     4,
       5,     3,     1,     3,     1,     3,     0,     3,     5,     1,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     2,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     2,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     3,     3,     5,     1,     3,     2,     2,     1,
       1,     1,     1,     8,     2,     2,     3,     5,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     2,     0,     1,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     2,     3,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     6,     7,     3,     1,     3,     3,     1,
       1,     1,     4,     4,     7,     8,     8,     4,     6,     3,
       5,     5,     1,     2,     3,     1,     2,     1,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     2,     2,
       2,     2,     3,     6,     8,     1,     3,     3,     0,     2,
       3,     3,     4,     1,     3,     2,     5,     2,     3,     5,
       6,     5,     5,     6,     3,     4,     3,     1,     3,     2,
       1,     2,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     5,     6,     0,
       8,     5,     6,     5,     6,     3,     5,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     5,     2,
       4,     2,     4,     6,     2,     4,     2,     1,     1,     1,
       1,     1,     2,     2,     4,     6,     2,     4,     2,     4,
       4,     4,     2,     3,     4,     2,     3,     3,     5,     3,
       5,     4,     6,     0,     2,     2,     1,     2,     1,     2,
       3,     1,     2,     3,     5,     1,     1,     1,     1,     1,
       2,     1,     2,     0,     2,     3,     3,     3,     0,     5,
       7,     7,     7,     7,     3,     1,     1,     2,     1,     2,
       1,     2,     3,     3,     3,     3,     0,     1,     1,     1,
       0,     1,     2,     1,     2,     1,     2,     1,     2,     2,
       4,     4,     4,     5,     5,     5,     6,     7,     1,     1,
       1,     2,     1,     1,     3,     5,     2,     2,     1,     1,
       1,     1,     2,     2,     4,     1,     1,     1,     1,     2,
       2,     3,     4,     4,     6,     7,     7,     5,     4,     5,
       4,     5,     1,     1,     1,     2,     2,     2
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
        case 26:
#line 125 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2094 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 140 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2100 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 360 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2106 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 367 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2112 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 392 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2118 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 629 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2124 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 834 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2130 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 871 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2136 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 882 "delphi.ypp" /* yacc.c:1646  */
    { /*empty */ }
#line 2142 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 915 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2148 "delphi.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 922 "delphi.ypp" /* yacc.c:1646  */
    { /* empty */ }
#line 2154 "delphi.tab.cpp" /* yacc.c:1646  */
    break;


#line 2158 "delphi.tab.cpp" /* yacc.c:1646  */
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
#line 1039 "delphi.ypp" /* yacc.c:1906  */

//-- FUNCTION DEFINITIONS ---------------------------------

extern void delphirestart(FILE *);

int delphimain(QString file)
{
    if (file.length() < 1) {
        QMessageBox::information(0,
            "Warning",
            "parser file can't be open");
        return 0;
    }

    FILE *f = fopen(file.toLatin1().data(),"r");
    delphiset_in(f);

    delphirestart(f);
    int res = delphiparse();
    
    fclose(f);
    return res;
}
