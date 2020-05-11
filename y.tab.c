/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     PLUS = 261,
     MINUS = 262,
     TIMES = 263,
     DIVIDE = 264,
     ASSIGN = 265,
     EQ = 266,
     NE = 267,
     LT = 268,
     LE = 269,
     GE = 270,
     GT = 271,
     POINT = 272,
     DOT = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     DIV = 277,
     MOD = 278,
     IN = 279,
     COMMA = 280,
     SEMICOLON = 281,
     COLON = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     DOTDOT = 287,
     ARRAY = 288,
     BEGINBEGIN = 289,
     CASE = 290,
     CONST = 291,
     DO = 292,
     DOWNTO = 293,
     ELSE = 294,
     END = 295,
     FILEFILE = 296,
     FOR = 297,
     FUNCTION = 298,
     GOTO = 299,
     IF = 300,
     LABEL = 301,
     NIL = 302,
     OF = 303,
     PACKED = 304,
     PROCEDURE = 305,
     PROGRAM = 306,
     RECORD = 307,
     REPEAT = 308,
     SET = 309,
     THEN = 310,
     TO = 311,
     TYPE = 312,
     UNTIL = 313,
     VAR = 314,
     WHILE = 315,
     WITH = 316
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316




/* Copy the first part of user declarations.  */
#line 1 "parse.y"
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 25 Jul 19   */

/* Jaime Solis 
UTEID: js96986*/
/* Copyright (c) 2019 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */
/* 30 Jul 13 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input
                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D
                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D
           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 288 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    16,    18,    20,    22,    25,
      27,    30,    32,    34,    38,    40,    42,    46,    50,    54,
      56,    58,    65,    69,    72,    76,    80,    82,    86,    88,
      90,    95,    99,   102,   104,   106,   110,   112,   115,   120,
     122,   124,   126,   128,   130,   134,   136,   138,   140,   142,
     145,   147,   151,   153,   155,   157,   159,   161,   163,   165,
     169,   171,   175,   177,   182,   184,   188,   192,   195,   199,
     201,   205,   209,   212,   216,   218,   222,   226,   229,   233,
     235,   239,   243,   245,   249,   253,   259,   261,   263,   268,
     275,   280,   283,   285,   289,   291,   294,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    51,     3,    28,    67,    29,    26,    84,
      18,    -1,     5,    -1,    47,    -1,     4,    -1,     6,    -1,
       7,    -1,    65,     3,    -1,     3,    -1,    65,     5,    -1,
       5,    -1,     4,    -1,     3,    25,    67,    -1,     3,    -1,
       3,    -1,    28,    67,    29,    -1,    66,    32,    66,    -1,
      68,    25,    69,    -1,    68,    -1,    68,    -1,    33,    30,
      69,    31,    48,    70,    -1,    52,    72,    40,    -1,    17,
       3,    -1,    67,    27,    70,    -1,    71,    26,    72,    -1,
      71,    -1,    82,    25,    73,    -1,    82,    -1,     3,    -1,
      74,    30,    73,    31,    -1,    74,    18,     3,    -1,    74,
      17,    -1,    64,    -1,    74,    -1,    28,    82,    29,    -1,
      76,    -1,    21,    75,    -1,     3,    28,    73,    29,    -1,
       8,    -1,     9,    -1,    22,    -1,    23,    -1,    19,    -1,
      78,    77,    75,    -1,    75,    -1,     6,    -1,     7,    -1,
      20,    -1,    65,    78,    -1,    78,    -1,    80,    79,    78,
      -1,    11,    -1,    13,    -1,    16,    -1,    12,    -1,    14,
      -1,    15,    -1,    24,    -1,    82,    81,    80,    -1,    80,
      -1,     5,    25,    83,    -1,     5,    -1,    46,    83,    26,
      87,    -1,    87,    -1,     3,    11,    66,    -1,    85,    26,
      86,    -1,    85,    26,    -1,    36,    86,    90,    -1,    90,
      -1,     3,    11,    70,    -1,    88,    26,    89,    -1,    88,
      26,    -1,    57,    89,    93,    -1,    93,    -1,    67,    27,
      70,    -1,    91,    26,    92,    -1,    91,    26,    -1,    59,
      92,    94,    -1,    94,    -1,    34,    97,    95,    -1,    26,
      97,    95,    -1,    40,    -1,     5,    27,    97,    -1,    34,
      97,    95,    -1,    45,    82,    55,    97,    99,    -1,   100,
      -1,    76,    -1,    60,    82,    37,    97,    -1,    42,   100,
      56,    82,    37,    97,    -1,    53,    98,    58,    82,    -1,
      44,     5,    -1,    96,    -1,    97,    26,    98,    -1,    97,
      -1,    39,    97,    -1,    -1,    74,    10,    82,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    77,    77,    77,    79,    79,    81,    81,
      81,    81,    81,    83,    83,    85,    86,    87,    89,    90,
      92,    93,    94,    95,    97,    99,   100,   102,   102,   104,
     105,   106,   107,   109,   110,   111,   112,   113,   115,   117,
     117,   117,   117,   117,   119,   120,   122,   122,   122,   124,
     124,   125,   127,   127,   127,   127,   127,   127,   127,   129,
     130,   132,   133,   135,   136,   138,   140,   140,   142,   143,
     145,   147,   147,   149,   150,   152,   154,   154,   156,   157,
     159,   162,   163,   165,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   177,   177,   179,   179,   181
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "unsigned_constant", "sign", "constant", "id_list", "simple_type",
  "simple_type_list", "type", "fields", "field_list", "expr_list",
  "variable", "factor", "funcall", "times_op", "term", "plus_op",
  "simple_expression", "compare_op", "expression", "numlist", "lblock",
  "cdef", "cdef_list", "cblock", "tdef", "tdef_list", "tblock", "vdef",
  "vdef_list", "vblock", "block", "endpart", "label", "statement",
  "statement_list", "endif", "assignment", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    76,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    86,    86,    87,    87,
      88,    89,    89,    90,    90,    91,    92,    92,    93,    93,
      94,    95,    95,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    99,    99,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     3,     1,     1,     3,     3,     3,     1,
       1,     6,     3,     2,     3,     3,     1,     3,     1,     1,
       4,     3,     2,     1,     1,     3,     1,     2,     4,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     4,     1,     3,     3,     2,     3,     1,
       3,     3,     2,     3,     1,     3,     3,     2,     3,     1,
       3,     3,     1,     3,     3,     5,     1,     1,     4,     6,
       4,     2,     1,     3,     1,     2,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    14,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,    64,    69,
      74,    79,    29,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    92,     0,    86,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
      29,     0,    91,     5,     3,     6,     7,     0,     0,     4,
      33,     0,    34,    45,    36,    50,    60,     0,    94,     0,
       0,     0,    32,     0,     0,     0,    82,    80,     0,    67,
      68,     0,     0,     0,    72,    73,     0,    77,    78,     0,
      28,    83,    84,     0,    37,     0,    49,    39,    40,    43,
      41,    42,     0,    46,    47,    48,     0,    52,    55,    53,
      56,    57,    54,    58,     0,     0,     0,     0,     0,    97,
      31,     0,     0,     9,    12,    11,     0,    65,    66,    61,
      63,    15,     0,     0,     0,     0,     0,    20,    70,    71,
      75,    76,    38,     0,     0,    35,    44,    51,    96,    59,
      93,    90,    88,    30,    81,     8,    10,    23,     0,     0,
       0,    26,     0,     0,    27,     0,     0,    85,    16,    19,
       0,     0,     0,    22,    17,    89,    95,     0,     0,    24,
      25,    18,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    60,    61,   136,    43,   137,   170,   138,   161,
     162,    89,    62,    63,    64,   102,    65,   106,    66,   115,
      90,    39,    17,    36,    37,    18,    41,    42,    19,    44,
      45,    20,    21,    77,    32,    68,    69,   167,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
     -28,    32,    38,    23,  -145,    67,    48,    37,    67,    50,
    -145,    63,    41,    71,    73,    77,    67,    70,  -145,  -145,
    -145,  -145,    64,    66,    41,    93,   111,   128,    41,   128,
      72,  -145,  -145,     8,  -145,   106,    95,   -16,    94,    98,
     114,   101,   -12,   102,   110,   112,  -145,   128,    41,     8,
    -145,    91,  -145,  -145,  -145,  -145,  -145,   140,   128,  -145,
    -145,   140,    96,  -145,  -145,    46,    19,   126,   122,   107,
     158,   128,  -145,   148,   128,    41,  -145,  -145,   206,    71,
    -145,    73,   143,    25,    77,  -145,    25,    67,  -145,   123,
     211,  -145,  -145,   128,  -145,   192,    46,  -145,  -145,  -145,
    -145,  -145,   140,  -145,  -145,  -145,   140,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,    41,   128,    41,   128,    41,   217,
    -145,   129,     8,  -145,  -145,  -145,    47,  -145,  -145,  -145,
    -145,   121,   156,    67,   134,    67,   144,  -145,  -145,  -145,
    -145,  -145,  -145,   128,   177,  -145,  -145,    46,   127,    19,
    -145,   217,  -145,  -145,  -145,  -145,  -145,  -145,   149,    56,
     153,   157,   145,   206,  -145,    41,    41,  -145,  -145,   159,
     155,    25,    67,  -145,  -145,  -145,  -145,    56,   146,  -145,
    -145,  -145,    25,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,   -59,   -72,    -5,  -144,    20,   -84,  -145,
      24,   -64,   -11,   -46,    -8,  -145,   -49,  -145,    83,  -145,
     -22,   118,  -145,  -145,   136,   135,  -145,   150,   181,  -145,
     132,   178,   193,   -41,  -145,    -3,   124,  -145,   212
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -10
static const yytype_int16 yytable[] =
{
       7,    30,   140,    10,    31,    67,   127,    70,    92,    33,
     121,    94,    96,    30,    30,   169,    31,    30,    12,   126,
      31,    49,    12,     1,   126,   103,   104,   126,   131,   124,
     125,    55,    56,   169,    75,     3,    95,    30,     4,   105,
      31,    15,   132,    16,    22,    91,    23,    16,    76,   119,
     155,     5,   156,   133,    97,    98,   146,   147,   134,   131,
     124,   125,    55,    56,    30,    99,     9,    31,   100,   101,
       6,   144,   122,     8,    35,    24,    11,   135,    38,   164,
      40,   154,    71,    25,   133,    26,    27,   179,    46,    72,
      73,   174,    47,    48,    28,   151,    50,    12,   183,    13,
     126,    29,    74,    30,   126,    30,    31,    30,    31,    14,
      31,   148,   126,    72,    73,   152,    52,    78,   126,    81,
      15,    79,    16,   126,    82,    83,    74,    84,   158,    86,
     160,    22,    53,    54,    55,    56,    87,   107,   108,   109,
     110,   111,   112,    22,    53,    54,    12,    93,   116,    57,
     113,   120,   142,    -9,    30,    30,    58,    31,    31,   157,
     153,    57,   175,   176,   159,   117,   166,   160,    58,   107,
     108,   109,   110,   111,   112,    59,   163,    12,   168,    13,
     171,   114,   113,   172,   177,   173,   178,    59,   107,   108,
     109,   110,   111,   112,   182,   118,   180,   181,   149,   129,
      15,   113,    16,   107,   108,   109,   110,   111,   112,   123,
     124,   125,    55,    56,   165,   128,   113,   130,    80,   141,
      85,   145,   107,   108,   109,   110,   111,   112,   107,   108,
     109,   110,   111,   112,   139,   113,   143,    51,    88,     0,
     150,   113
};

static const yytype_int16 yycheck[] =
{
       5,    12,    86,     8,    12,    27,    78,    29,    49,    12,
      74,    57,    61,    24,    25,   159,    24,    28,    34,    78,
      28,    24,    34,    51,    83,     6,     7,    86,     3,     4,
       5,     6,     7,   177,    26,     3,    58,    48,     0,    20,
      48,    57,    17,    59,     3,    48,     5,    59,    40,    71,
       3,    28,     5,    28,     8,     9,   102,   106,    33,     3,
       4,     5,     6,     7,    75,    19,    29,    75,    22,    23,
       3,    93,    75,    25,     3,    34,    26,    52,     5,   143,
       3,   122,    10,    42,    28,    44,    45,   171,    18,    17,
      18,   163,    28,    27,    53,   117,     3,    34,   182,    36,
     159,    60,    30,   114,   163,   116,   114,   118,   116,    46,
     118,   114,   171,    17,    18,   118,     5,    11,   177,    25,
      57,    26,    59,   182,    26,    11,    30,    26,   133,    27,
     135,     3,     4,     5,     6,     7,    26,    11,    12,    13,
      14,    15,    16,     3,     4,     5,    34,    56,    26,    21,
      24,     3,    29,    32,   165,   166,    28,   165,   166,     3,
      31,    21,   165,   166,    30,    58,    39,   172,    28,    11,
      12,    13,    14,    15,    16,    47,    32,    34,    29,    36,
      27,    55,    24,    26,    25,    40,    31,    47,    11,    12,
      13,    14,    15,    16,    48,    37,   172,   177,   115,    81,
      57,    24,    59,    11,    12,    13,    14,    15,    16,     3,
       4,     5,     6,     7,    37,    79,    24,    82,    37,    87,
      42,    29,    11,    12,    13,    14,    15,    16,    11,    12,
      13,    14,    15,    16,    84,    24,    25,    25,    45,    -1,
     116,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    67,    25,    29,
      67,    26,    34,    36,    46,    57,    59,    84,    87,    90,
      93,    94,     3,     5,    34,    42,    44,    45,    53,    60,
      74,    76,    96,    97,   100,     3,    85,    86,     5,    83,
       3,    88,    89,    67,    91,    92,    18,    28,    27,    97,
       3,   100,     5,     4,     5,     6,     7,    21,    28,    47,
      64,    65,    74,    75,    76,    78,    80,    82,    97,    98,
      82,    10,    17,    18,    30,    26,    40,    95,    11,    26,
      90,    25,    26,    11,    26,    93,    27,    26,    94,    73,
      82,    97,    95,    56,    75,    82,    78,     8,     9,    19,
      22,    23,    77,     6,     7,    20,    79,    11,    12,    13,
      14,    15,    16,    24,    55,    81,    26,    58,    37,    82,
       3,    73,    97,     3,     4,     5,    65,    66,    86,    83,
      87,     3,    17,    28,    33,    52,    66,    68,    70,    89,
      70,    92,    29,    25,    82,    29,    75,    78,    97,    80,
      98,    82,    97,    31,    95,     3,     5,     3,    67,    30,
      67,    71,    72,    32,    73,    37,    39,    99,    29,    68,
      69,    27,    26,    40,    66,    97,    97,    25,    31,    70,
      72,    69,    48,    70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 75 "parse.y"
    { parseresult = makeprogram((yyvsp[(2) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(7) - (8)])); }
    break;

  case 8:
#line 81 "parse.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 10:
#line 81 "parse.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 13:
#line 83 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 14:
#line 83 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (1)]), NULL); }
    break;

  case 15:
#line 85 "parse.y"
    { (yyval) = findtype((yyvsp[(1) - (1)])); }
    break;

  case 16:
#line 86 "parse.y"
    { (yyval) = instenum((yyvsp[(2) - (3)])); }
    break;

  case 17:
#line 87 "parse.y"
    { (yyval) = instdotdot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 18:
#line 89 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 19:
#line 90 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (1)]), NULL); }
    break;

  case 21:
#line 93 "parse.y"
    { (yyval) = instarray((yyvsp[(3) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 22:
#line 94 "parse.y"
    { (yyval) = instrec((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 23:
#line 95 "parse.y"
    { (yyval) = instpoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 24:
#line 97 "parse.y"
    { (yyval) = instfields((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 25:
#line 99 "parse.y"
    { (yyval) = nconc((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 27:
#line 102 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 29:
#line 104 "parse.y"
    { (yyval) = findid((yyvsp[(1) - (1)])); }
    break;

  case 30:
#line 105 "parse.y"
    { (yyval) = arrayref((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 31:
#line 106 "parse.y"
    { (yyval) = reducedot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 32:
#line 107 "parse.y"
    { (yyval) = dopoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 35:
#line 111 "parse.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 37:
#line 113 "parse.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 38:
#line 115 "parse.y"
    { (yyval) = makefuncall((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 44:
#line 119 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 49:
#line 124 "parse.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 51:
#line 125 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 59:
#line 129 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 61:
#line 132 "parse.y"
    { instlabel((yyvsp[(1) - (3)])); }
    break;

  case 62:
#line 133 "parse.y"
    { instlabel((yyvsp[(1) - (1)])); }
    break;

  case 63:
#line 135 "parse.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 65:
#line 138 "parse.y"
    { instconst((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 68:
#line 142 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 70:
#line 145 "parse.y"
    { insttype((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 73:
#line 149 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 75:
#line 152 "parse.y"
    { instvars((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 78:
#line 156 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 80:
#line 159 "parse.y"
    { (yyval) = makeprogn((yyvsp[(1) - (3)]),cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]))); }
    break;

  case 81:
#line 162 "parse.y"
    { (yyval) = cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 82:
#line 163 "parse.y"
    { (yyval) = NULL; }
    break;

  case 83:
#line 165 "parse.y"
    { (yyval) = dolabel((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 84:
#line 167 "parse.y"
    { (yyval) = makeprogn((yyvsp[(1) - (3)]),cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]))); }
    break;

  case 85:
#line 168 "parse.y"
    { (yyval) = makeif((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 88:
#line 171 "parse.y"
    { (yyval) = makewhile((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 89:
#line 172 "parse.y"
    { (yyval) = makefor(1, (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 90:
#line 173 "parse.y"
    { (yyval) = makerepeat((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 91:
#line 174 "parse.y"
    { (yyval) = dogoto((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 93:
#line 177 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 95:
#line 179 "parse.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 96:
#line 179 "parse.y"
    { (yyval) = NULL; }
    break;

  case 97:
#line 181 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;


/* Line 1267 of yacc.c.  */
#line 1915 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 189 "parse.y"


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.
   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG           0             /* set bits here for debugging, 0 = off  */
#define DB_CONS         0             /* bit to trace cons */
#define DB_BINOP        0             /* bit to trace binop */
#define DB_MAKEIF       0             /* bit to trace makeif */
#define DB_MAKEPROGN    0             /* bit to trace makeprogn */
#define DB_PARSERES     0            /* bit to trace parseresult */
#define DB_MAKEPROGRAM  0
#define DB_MAKEOP       0
#define DB_MAKEFUNCALL  0
#define DB_MAKEGOTO     0
#define DB_MAKELABEL    0
#define DB_MAKECOPY     0
#define DB_MAKEINTC     0
#define DB_MAKEFOR      0

#define DB_UNOP         0
#define DB_FINDID       0  
#define DB_INSTCONST    0  
#define DB_MAKEREPEAT   0

#define DB_NCONC        0
#define DB_MAKEINTC     0
#define DB_MAKEAREF     0
#define DB_MAKEWHILE    0
#define DB_MAKESUB      0
#define DB_REDUCEDOT    0
#define DB_FINDLABEL    0
#define DB_ARRAYREF     0
#define DB_DOLABEL      0
#define DB_DOGOTO       0
#define DB_DOPOINT      0
#define DB_INSTENUM     0
#define DB_INSTDOTDOT   0
#define DB_INSTARRAY    0
#define DB_INSTFIELD    0
#define DB_INSTREC      0
#define DB_INSTPOINT    0
#define DB_INSTTYPE     0
#define DB_FINDTYPE     0

   /*  Note: you should add to the above values and insert debugging
      printouts in your routines similar to those that are shown here.     */

/* cons links a new item onto the front of a list.  Equivalent to a push.
   (cons 'a '(b c))  =  (a b c)    */

// add item to front of list
TOKEN cons(TOKEN item, TOKEN list) {
  item->link = list;
  if (DEBUG & DB_CONS){ 
    printf("cons\n");
    dbugprinttok(item);
    dbugprinttok(list);
  };
    return item;
}

/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */   
TOKEN makefloat(TOKEN tok){
  
   if(tok->tokentype == NUMBERTOK) {
      tok->basicdt = REAL;
      tok->realval = (double)tok->intval;
      
  } else {
      TOKEN op = makeop(FLOATOP);
      op->operands = tok;
      return op;
  }
  return tok;
}

/* binop links a binary operator op to two operands, lhs and rhs. */
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs) {       /* reduce binary operator */
    op->operands = lhs;        
    lhs->link = rhs;             
    rhs->link = NULL;            
    if (DEBUG & DB_BINOP){ 
      printf("binop\n");
      dbugprinttok(op);
      dbugprinttok(lhs);
      dbugprinttok(rhs);
    };

     if ((lhs->basicdt==INTEGER) && (rhs->basicdt==REAL)){
        //multiplying 
        if (op->whichval==TIMESOP) {
            op->basicdt = REAL;
            TOKEN ftok = makefloat(lhs);
            ftok->link = rhs;
        } 

        //assign int(lhs) is an int
         if (op->whichval == ASSIGNOP)
            op->basicdt = INTEGER;
    }  

    if ((lhs->basicdt== REAL)&& (rhs->basicdt==INTEGER)){
      //multiplying
      op->basicdt = REAL;
      TOKEN ftok = makefloat(rhs);
      lhs->link = ftok;
    };  
    
    if(((lhs->basicdt==REAL) && (rhs->basicdt==REAL)) || (lhs->whichval == FUNCALLOP) )
        op->basicdt = REAL;   
  
    return op;
  }

/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
  op->operands = lhs;
  lhs->link = NULL;
  if (DEBUG & DB_UNOP){ 
    printf("unaryop\n");
  };
  return op;  
}

/* makeif makes an IF operator and links it to its arguments.
   tok is a (now) unused token that is recycled to become an IFOP operator */
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
{  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
    tok->whichval = IFOP;
    if (elsepart != NULL) elsepart->link = NULL;
    thenpart->link = elsepart;
    exp->link = thenpart;
    tok->operands = exp;
    if (DEBUG & DB_MAKEIF){ 
      printf("makeif\n");
      dbugprinttok(tok);
      dbugprinttok(exp);
      dbugprinttok(thenpart);
      dbugprinttok(elsepart); 
    };
     return tok;
}


/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN){ 
       printf("makeprogn\n");
       dbugprinttok(tok);
       dbugprinttok(statements);
      };
     return tok;
}

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
    
    TOKEN tok1 = talloc();
    tok1->tokentype = OPERATOR;
    tok1->whichval = PROGRAMOP;
    tok1->operands = name;

    TOKEN tok2 = talloc();
    tok2->tokentype = OPERATOR;
    tok2->whichval = PROGNOP;
    name->link = tok2;
    tok2->operands = args;
    tok2->link = statements;
    
    if (DEBUG & DB_MAKEPROGRAM) { 
      printf("makeprogram\n");
    }
    return tok1;
  }

  /* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok) {  
  int align;
  SYMBOL type, sym; 
  type = typetok->symtype;
  align = alignsize(type);
  while (idlist != NULL)  {  
      sym = insertsym(idlist->stringval);
      sym->kind = VARSYM; 
      sym->offset = wordaddress(blockoffs[blocknumber],align);
      sym->size = type->size;
      blockoffs[blocknumber] = sym->offset + sym->size;
      sym->datatype = type;
      sym->basicdt = type->basicdt;
    idlist = idlist->link;
  };
}

  /* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok) { 
  SYMBOL sym = sym = searchst(tok->stringval);
  
    if (sym->kind == CONSTSYM) {
      tok->tokentype = NUMBERTOK;
      tok->basicdt = sym->basicdt;
      tok->symentry = sym;

      switch(sym->basicdt)
      {
        case INTEGER:
        tok->intval = sym->constval.intnum;
        break;

        case REAL: 
        tok->realval = sym->constval.realnum;
        break;

        case STRING: 
        strcpy(sym->constval.stringconst, tok->stringval);
        break;
      }
      
      if (DEBUG & DB_FINDID) { 
        dbugprinttok(sym);
        debugprinttok(tok);
      }
      return tok;
    }

    tok->symentry = sym;
    SYMBOL type = sym->datatype;
    tok->symtype = type;

    switch(type->kind)
    {
      case BASICTYPE:
      tok->basicdt = type->basicdt;
      break;

      case POINTERSYM:
       tok->basicdt = type->basicdt;
       break;

    }
    return tok;
  }

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {
    SYMBOL sym = searchst(tok->stringval);

    switch(sym->kind){
       case TYPESYM:
       sym = sym->datatype;
       break;

       case BASICTYPE:
       tok->symtype = sym; 
       tok->basicdt = sym->basicdt; 
    }
  
   tok->symtype = sym;
    if (DEBUG & DB_FINDTYPE) {
      printf("fin\n");
      dbugprinttok(tok);
    }

    return tok;
}

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum){
    TOKEN tok = talloc();
    tok->tokentype = OPERATOR;
    tok->whichval = opnum;
    if (DEBUG & DB_MAKEOP) {
      printf("makeop\n");
      dbugprinttok(tok);
    }
    return tok;
}

/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok){

  switch(tok->tokentype){
    case NUMBERTOK:
    tok->basicdt = INTEGER;
    tok->intval = (int) tok->realval;
    break;
  }
  return tok;
  TOKEN fixop = makeop(FIXOP);
  fixop->operands = tok;
  return fixop;
}

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  int func; 
  if (strcmp(fn->stringval, "new") == 0)
    func = 0; 
  else if (strcmp(fn->stringval, "writeln") == 0)
    func = 1; 
  else func = 2;

  switch(func)
  {
    case 0: 
      tok = makeop(ASSIGNOP);
      tok->operands = args;

      SYMBOL typsym = args->symtype;
      typsym = typsym->datatype;

      TOKEN funcal = talloc();
      funcal->tokentype = OPERATOR;
      funcal->whichval = FUNCALLOP;
      funcal->operands = fn;
      fn->link = makeintc(typsym->size);
      args->link = funcal;

      break; 

    case 1: 
      if (args->basicdt == REAL) 
        strcpy(fn->stringval, "writelnf");
      if (args->tokentype == STRINGTOK) 
        strcpy(fn->stringval, "writeln");
     else strcpy(fn->stringval, "writelni");
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link=args; 
    break; 

    case 2: 
     tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link=args;
  }

  if (DEBUG && DB_MAKEFUNCALL) {
         printf("makefuncall\n");
  }
  return tok;
}

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok) {

  if (!origtok) 
		return NULL;
  else {
     TOKEN copy = talloc();
    copy->tokentype = origtok->tokentype;
    copy->basicdt = origtok->basicdt;

    copy->symtype = origtok->symtype;
    copy->symentry = origtok->symentry;

    copy->whichval = origtok->whichval;
  
    copy->link = origtok->link;
    copy->intval = origtok->intval;
    copy->realval = origtok->realval;

  return copy;
  }
	
  if (DEBUG & DB_MAKECOPY) 
    printf("copytok\n");
  
}


int labelnumber = 0;  
/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel() {
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = LABELOP;
  tok->operands = makeintc(labelnumber++);
  
  if (DEBUG & DB_MAKELABEL) 
      printf("makelabel\n");
  return tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label){
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = GOTOOP;
  tok->operands = makeintc(label); 
  if (DEBUG && DB_MAKEGOTO) 
    printf("makegoto\n");
  return tok;
}

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, 
      TOKEN tokc, TOKEN statement) 
{
  tok = makeprogn(tok, asg);
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN iftok = talloc();
  TOKEN bodytok = talloc();
  bodytok = makeprogn(bodytok, statement);

  TOKEN leftop = makeop(LEOP);
  iftok = makeif(iftok, leftop, bodytok, NULL);
  TOKEN iden1 = copytok(asg->operands);
  TOKEN iden2 = copytok(iden1);
  TOKEN iden3 = copytok(iden1);
  iden1->link = endexpr;
  leftop->operands = iden1;

  TOKEN assgn = makeop(ASSIGNOP);
  TOKEN increment = makeop(PLUSOP);

  iden3->link= makeintc(1);
  increment->operands=iden3;
  iden2->link=increment;
  assgn->operands=iden2;

  int currentnum = labelnumber - 1;
  TOKEN gototok = makegoto(currentnum);
  assgn->link = gototok;
  statement->link = assgn;

  leftop->link = bodytok;
  iftok->operands = leftop;
  label->link = iftok;
  if (DEBUG && DB_MAKEFOR) 
      printf("makefor\n");

  return tok;
}

/* instconst installs a constant in the symbol table */
void  instconst(TOKEN idtok, TOKEN consttok){
  SYMBOL sym;
  sym = insertsym(idtok->stringval);
  sym->kind = CONSTSYM;
  sym->basicdt = consttok->basicdt;

  switch(sym->basicdt){
    case REAL:
    sym->constval.realnum = consttok->realval;
    break; 

    case INTEGER:
    sym->constval.intnum = consttok->intval;
    break;
  }
 
  if (DEBUG & DB_INSTCONST) 
    printf("instconst\n");
   
}

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr){

   TOKEN label = makelabel();
   int currentlabel[1];
   currentlabel[0] = labelnumber - 1;
   tok = makeprogn(tok, label);
   TOKEN body = tokb;
   body = makeprogn(body, statements);
   label->link = body;
   TOKEN gototok = makegoto(currentlabel[0]);
   TOKEN emptytok = makeprogn((TOKEN) talloc(), NULL);
   emptytok->link = gototok;
   TOKEN iftok = talloc();
   iftok = makeif(iftok, expr, emptytok, gototok);
   body->link = iftok;

   if (DEBUG && DB_MAKEREPEAT) {
         printf("make repeat\n");
   }

   return tok;  
}

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
/* nconc should return lista, or listb if lista is NULL. */
TOKEN nconc(TOKEN lista, TOKEN listb){
  TOKEN fullist = lista;
  if (lista==NULL)
  return lista;
  else {
    while(fullist->link) 
      fullist = fullist->link;
    fullist->link = listb;
  }

  if (DEBUG & DB_NCONC) {
   printf("nconc\n");
  }
  return fullist;
}

/* makeintc makes a new integer number token with num as its value */
TOKEN makeintc(int num) {
  TOKEN tok = talloc();
  tok->tokentype = NUMBERTOK;
  tok->basicdt = INTEGER;
  tok->intval = num;
  if (DEBUG & DB_MAKEINTC) {
      printf("makeintc\n");
  }
  return tok;
}

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok){
    int flag = 0;
    if (tok != NULL){ 
    if (var->whichval == AREFOP)
      flag = 1; 
      switch (flag){
        case 1:
        {
          TOKEN plusop = makeop(PLUSOP);
          TOKEN oldoff = var->operands->link;
          oldoff->link = off;
          plusop->operands = oldoff;
          var->operands->link = plusop;
          var->basicdt = var->symentry->basicdt;
          return var;
        }
      }     

  TOKEN areftok = makeop(AREFOP);
  var->link = off;
  areftok->operands = var;
  areftok->symentry = var->symentry; 
  areftok->basicdt = var->symentry->basicdt;  

  if (DEBUG && DB_MAKEAREF) 
      printf("makearef\n");
  return areftok;
  }
}

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement){
  if (tok != NULL){
    TOKEN label = makelabel();
    int currentlabel = labelnumber - 1;
    tok = makeprogn(tok, label);

    TOKEN gototok = makegoto(currentlabel);
    statement->link = gototok;
    TOKEN bodytok = makeprogn(tokb, statement);

    TOKEN iftok = talloc();
    iftok = makeif(iftok, expr, bodytok, NULL);
    label->link = iftok;

  if (DEBUG && DB_MAKEWHILE) {
     printf("makewhile\n");
     dbugprinttok(tok);
  }
  return tok;

  } else return NULL;
  
}


/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high){

  int flag = 0; 
  if (tok != NULL)
    flag = 1;

  switch (flag){
    case 1:{
        SYMBOL subrange = symalloc();
        subrange->kind = SUBRANGE;
        subrange->basicdt = INTEGER;
        subrange->lowbound = low;
        subrange->highbound = high;
        subrange->size = basicsizes[INTEGER];
        tok->symtype = subrange;
        return tok;
    }
  } 
  
  if (DEBUG & DB_MAKESUB)
    printf("makesubrange\n");
}

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field){
   SYMBOL record = var->symentry;
  SYMBOL curfield = record->datatype->datatype;
  int offset = 0;
  int off;
  while(curfield) {
    if (strcmp(curfield->namestring, field->stringval) == 0)
      off = 0; 
    else off = 1; 
    switch(off){
      case 0: 
      offset = curfield->offset;
      var->symentry = curfield;
      break;
      
      case 1: 
      curfield = curfield->link;
      break;
    }
    if (off==0)
        break;
  }

  dot = makearef(var, makeintc(offset), dot);

  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedot\n");
  }
  return dot;
 
}

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
    int flag = 0;
  if (subs->link) 
      flag = 1; 

  switch (flag){
    case 1:
  {
      TOKEN timesop = makeop(TIMESOP);
    int low = arr->symtype->lowbound;
    int high = arr->symtype->highbound;
    int size = (arr->symtype->size / (high + low - 1));

    TOKEN s = copytok(subs);
    s->link = NULL;
    TOKEN elesize = makeintc(size);
    elesize->link = s;
    timesop->operands = elesize;

    TOKEN nsize = makeintc(-1 * size);
    nsize->link = timesop;
    TOKEN plusop = makeop(PLUSOP);
    plusop->operands = nsize;

    TOKEN subarref = makearef(arr, plusop, tokb);
    
    subarref->symtype = arr->symtype->datatype;

    return arrayref(subarref, tok, subs->link, tokb);
  }  
    default:
    {
      TOKEN timesop = makeop(TIMESOP);
    int low = arr->symtype->lowbound;
    int high = arr->symtype->highbound;
    int size = (arr->symtype->size / (high + low - 1));

    TOKEN elesize = makeintc(size);
    elesize->link = subs;
    timesop->operands = elesize;

    TOKEN nsize = makeintc(-1 * size);
    nsize->link = timesop;
    TOKEN plusop = makeop(PLUSOP);
    plusop->operands = nsize;
    return makearef(arr, plusop, tokb);
    }
  }
  
   if (DEBUG & DB_ARRAYREF) 
        printf("arrayref\n");
}

int labeltable[100];
 
/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
    //finding label number
    int i=0; 
    int found = 0; 
    int labelnum;
    while(i < labelnumber){
      if (labeltable[i] == labeltok->intval){
        labelnum = i; 
        found = 1;
      }
      i++;
    }
    if (found==0)
      printf("Error");

    labeltok = makeop(LABELOP);
    TOKEN tokb = makeintc(labelnum);
    labeltok->operands=tokb;
    labeltok->link = statement;
    tok = makeprogn(tok, labeltok);

    if (DEBUG & DB_DOLABEL) {
      printf("dolabel\n");
    }

    return tok;
}

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
    int i=0; 
    int found = 0; 
    int labelnum;
    while(i < labelnumber){
      if (labeltable[i] == labeltok->intval){
        labelnum = i; 
        found = 1;
      }
      i++;
    }
    if (found==0)
      printf("Error");

    tok = makegoto(labelnum);
    if (DEBUG & DB_DOGOTO)
      printf("dogoto\n");

    return tok;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
  tok->symentry = var->symentry->datatype->datatype;
  tok->operands = var;

  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
  }

  return tok;
}

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) {
  labeltable[labelnumber++] = num->intval;  
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
  int size = 0;
  TOKEN list = copytok(idlist);

  for (int i=0; list; i++) {
    instconst(list, makeintc(size));
    size ++;
    list = list->link;
  }

  TOKEN tok = makesubrange(idlist, 0, size - 1);
  if (DEBUG & DB_INSTENUM) 
    printf("instenum\n");

  return tok;
}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
  
  int low = lowtok->intval;
  int high = hightok->intval;
  return makesubrange(dottok, low, high);
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {
  int ready = 0; 
  if (bounds->link)
    ready = 1; 

  switch (ready) {
    case 1 : 
    {
    typetok = instarray(bounds->link, typetok);

    SYMBOL subrange = bounds->symtype;
    SYMBOL typesym = typetok->symtype;
    SYMBOL arraysym = symalloc();

    arraysym->kind = ARRAYSYM;
    arraysym->datatype = typesym;
    arraysym->lowbound = subrange->lowbound;
    arraysym->highbound = subrange->highbound;
    arraysym->size = (arraysym->lowbound + arraysym->highbound - 1) * (typesym->size);
    typetok->symtype = arraysym;
    return typetok;
    }
    case 0:
    {
    SYMBOL subrange = bounds->symtype;
    SYMBOL typesym = typetok->symtype;
    SYMBOL arraysym = symalloc();
    arraysym->kind = ARRAYSYM;
    arraysym->datatype = typesym;
    arraysym->lowbound = subrange->lowbound;
    arraysym->highbound = subrange->highbound;
    arraysym->size = (arraysym->highbound - arraysym->lowbound +  1) * (typesym->size);
    typetok->symtype = arraysym;
    return typetok;
    }
  }
    if (DEBUG & DB_INSTARRAY) 
        printf("instarray\n");
}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
  SYMBOL typesym = typetok->symtype;
  TOKEN temp = idlist;
  for(int i=0;temp;i++){
    temp->symtype = typesym;     
    temp = temp->link;
  }

  if (DEBUG & DB_INSTFIELD) {
      printf("instfields\n");
  }

  return idlist;
}

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  SYMBOL recsym = symalloc();
  recsym->kind = RECORDSYM;
  int count, next, align;
  count = 0; 
  next =0;
  SYMBOL prev = NULL;
  for (int i =0; argstok; i++){
    align = alignsize(argstok->symtype);
    SYMBOL recfield = makesym(argstok->stringval);
    recfield->datatype = argstok->symtype;
    recfield->offset = wordaddress(next, align);
    recfield->size = argstok->symtype->size;
    next = recfield->offset + recfield->size;

      switch(count){
        case 0: 
        recsym->datatype = recfield;
        prev = recfield;
        break;
        default:
        prev->link = recfield;
        prev = recfield;
        break;
      }
      recfield->link = NULL;
      count ++;
      argstok = argstok->link;
  }
 
  recsym->size = wordaddress(next, 16); 
  rectok->symtype = recsym;

  if (DEBUG & DB_INSTREC) {
      printf("instrect\n");
  }
  return rectok;
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {

  if (tok != NULL){
    SYMBOL typesym = searchins(typename->stringval);
    SYMBOL pointsym = symalloc();
    pointsym->datatype = typesym;
    pointsym->kind = POINTERSYM;
    pointsym->size = basicsizes[POINTER];
    pointsym->basicdt = POINTER;

  tok->symtype = pointsym;
  } else return NULL;

  if (DEBUG & DB_INSTPOINT) {
      printf("install point\n");
      dbugprinttok(tok);
  }

  return tok;
}

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok) {
  SYMBOL typesym = searchins(typename->stringval);
  typesym->kind = TYPESYM;
  typesym->datatype = typetok->symtype;
  typesym->size = typetok->symtype->size;

  if (DEBUG & DB_INSTTYPE) {
    printf("insttype\n");
  }
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(const char *s) /* commented in lexan.h */
  { 
    fprintf (stderr, "%s\n", s);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printstlevel(1);          
    /* to shorten, change to:  printstlevel(1);  */
    //printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) 
      dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
    /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
    */
  }

 
