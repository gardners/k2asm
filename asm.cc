/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

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
     SCOPE = 258,
     MODULE = 259,
     FUNC = 260,
     PSEUDO = 261,
     PSBUFF = 262,
     PSLINE = 263,
     PSEXPORT = 264,
     PSGLOBAL = 265,
     PSLOCAL = 266,
     ENCODING = 267,
     ENC = 268,
     TO = 269,
     LABEL = 270,
     R_REL = 271,
     OPCODE_1 = 272,
     IDENT = 273,
     DNCHEX = 274,
     DNCBIN = 275,
     DEC = 276,
     MOD = 277,
     DIV = 278,
     ORG = 279,
     STRING = 280,
     CHAR = 281,
     NEG = 282
   };
#endif
#define SCOPE 258
#define MODULE 259
#define FUNC 260
#define PSEUDO 261
#define PSBUFF 262
#define PSLINE 263
#define PSEXPORT 264
#define PSGLOBAL 265
#define PSLOCAL 266
#define ENCODING 267
#define ENC 268
#define TO 269
#define LABEL 270
#define R_REL 271
#define OPCODE_1 272
#define IDENT 273
#define DNCHEX 274
#define DNCBIN 275
#define DEC 276
#define MOD 277
#define DIV 278
#define ORG 279
#define STRING 280
#define CHAR 281
#define NEG 282




/* Copy the first part of user declarations.  */
#line 2 "asm.yy"


#include <iostream>
#include <stdlib.h>
#include <string>

#include "Value.h" 
#include "Expr.h" 
#include "SymTable.h" 
#include "CodeTreeBuilder.h"

extern CodeTreeBuilder* builder;

int yylex();
void yyendofline();
  
int yyerror(char* s) { return 0; }
   


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 22 "asm.yy"
typedef union YYSTYPE {
  Value* v;
  Number* n;
  int    i;
  string*  s;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 156 "asm.cc"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 168 "asm.cc"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   695

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  16
/* YYNRULES -- Number of rules. */
#define YYNRULES  86
/* YYNRULES -- Number of states. */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    42,     2,     2,    31,     2,
      43,    37,    34,    33,    41,    32,    39,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    44,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    29,    38,     2,     2,     2,     2,
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
      25,    26,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    22,    25,    28,    31,    34,    37,    40,    42,    46,
      50,    52,    56,    60,    64,    67,    70,    72,    74,    78,
      80,    83,    86,    89,    92,    95,    98,   101,   105,   112,
     115,   118,   120,   124,   126,   130,   132,   134,   138,   142,
     144,   148,   154,   160,   164,   169,   172,   175,   179,   185,
     192,   197,   202,   207,   209,   211,   214,   218,   222,   226,
     230,   234,   238,   242,   246,   250,   254,   257,   260,   264,
     268,   271,   273,   275,   277,   279,   281
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      48,     0,    -1,    -1,    48,    49,    -1,    50,    -1,    51,
      -1,    55,    -1,    60,    -1,    59,    -1,    56,    -1,    24,
      61,    -1,    37,     1,    -1,    38,     1,    -1,     9,     1,
      -1,    10,     1,    -1,    11,     1,    -1,    39,     1,    -1,
       1,    -1,    52,    48,    53,    -1,    54,    48,    53,    -1,
      40,    -1,     3,    18,    40,    -1,     4,    18,    40,    -1,
       4,    61,    40,    -1,     3,     1,    -1,     4,     1,    -1,
      38,    -1,     1,    -1,     5,    18,    40,    -1,    15,    -1,
       9,    15,    -1,    33,    15,    -1,    10,    15,    -1,    11,
      15,    -1,     6,    58,    -1,     6,    25,    -1,     7,    61,
      -1,     7,    61,    61,    -1,     8,    21,    41,    25,    41,
      21,    -1,    12,    25,    -1,    13,    57,    -1,    61,    -1,
      61,    41,    57,    -1,    25,    -1,    25,    41,    57,    -1,
       1,    -1,    61,    -1,    61,    41,    58,    -1,    61,    41,
       1,    -1,    17,    -1,    17,    42,    61,    -1,    17,    43,
      61,    16,    37,    -1,    17,    43,    61,    37,    16,    -1,
      17,    61,    16,    -1,    17,    43,    61,    37,    -1,    17,
      61,    -1,    17,     1,    -1,    18,    44,    61,    -1,    18,
      44,    61,    14,    61,    -1,    18,    44,    61,    45,    61,
      46,    -1,    10,    18,    44,    61,    -1,     9,    18,    44,
      61,    -1,    11,    18,    44,    61,    -1,    62,    -1,    34,
      -1,    32,    61,    -1,    61,    33,    61,    -1,    61,    32,
      61,    -1,    61,    34,    61,    -1,    61,    35,    61,    -1,
      61,    23,    61,    -1,    61,    22,    61,    -1,    61,    29,
      61,    -1,    61,    31,    61,    -1,    61,    30,    61,    -1,
      43,    61,    37,    -1,    27,    61,    -1,    28,    61,    -1,
      61,    28,    61,    -1,    61,    27,    61,    -1,    43,     1,
      -1,     1,    -1,    19,    -1,    20,    -1,    21,    -1,    18,
      -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    65,    65,    66,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    85,    88,
      92,    93,    94,    95,    96,    97,   101,   102,   105,   108,
     109,   110,   111,   112,   115,   116,   117,   118,   119,   120,
     121,   124,   125,   126,   127,   128,   131,   132,   133,   136,
     137,   138,   139,   140,   141,   142,   143,   146,   147,   148,
     149,   150,   151,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   173,   177,   178,   179,   180,   181
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCOPE", "MODULE", "FUNC", "PSEUDO", 
  "PSBUFF", "PSLINE", "PSEXPORT", "PSGLOBAL", "PSLOCAL", "ENCODING", 
  "ENC", "TO", "LABEL", "R_REL", "OPCODE_1", "IDENT", "DNCHEX", "DNCBIN", 
  "DEC", "MOD", "DIV", "ORG", "STRING", "CHAR", "'<'", "'>'", "'|'", 
  "'^'", "'&'", "'-'", "'+'", "'*'", "'/'", "NEG", "')'", "'}'", "'.'", 
  "'{'", "','", "'#'", "'('", "'='", "'['", "']'", "$accept", "input", 
  "line", "scope_def", "func_def", "scope_start", "scope_end", 
  "func_start", "label", "pseu", "slist", "list", "op_1", "assign", 
  "expr", "value", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    60,    62,   124,
      94,    38,    45,    43,    42,    47,   282,    41,   125,    46,
     123,    44,    35,    40,    61,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     3,
       1,     3,     3,     3,     2,     2,     1,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     3,     6,     2,
       2,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       3,     5,     5,     3,     4,     2,     2,     3,     5,     6,
       4,     4,     4,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     1,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     0,    20,     3,     4,     5,     2,     2,     6,
       9,     8,     7,    24,     0,    25,    85,    82,    83,    84,
       0,     0,     0,    64,     0,     0,    63,     0,    81,    85,
      35,    34,    46,     0,     0,    13,    30,     0,    14,    32,
       0,    15,    33,     0,    39,    45,    43,    40,    41,    56,
       0,     0,    55,     0,    10,    31,    11,    12,    16,     0,
       0,    21,    22,    76,    77,    65,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      28,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,    50,     0,    53,    57,    17,     0,    18,
      19,    75,    71,    70,    79,    78,    72,    74,    73,    67,
      66,    68,    69,    48,    47,    76,    77,    65,     0,    61,
      60,    62,    44,    42,     0,    54,     0,     0,     0,    51,
      52,    58,     0,    38,    59
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     1,    24,    25,    26,    27,   119,    28,    29,    30,
      67,    51,    31,    32,    68,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const short yypact[] =
{
     -68,   365,   -68,   -68,    13,   247,   -10,     0,   275,   -17,
       8,    15,    49,   -15,   226,   -68,   198,   -32,   275,     2,
      21,    23,    48,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -25,   660,    20,   -68,   -68,   -68,
     275,   275,   275,   -68,   296,   616,   -68,    35,   -68,   -68,
     -68,   -68,   538,   116,    -1,   -68,   -68,    19,   -68,   -68,
      32,   -68,   -68,    33,   -68,   568,    37,   -68,   553,   585,
     275,   296,    79,   275,   646,   -68,   -68,   -68,   -68,   446,
     446,   -68,   -68,   362,   362,   -68,   -68,   630,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   -68,
     -68,   324,   275,   275,   275,   157,   646,    54,   275,   275,
     275,   226,   226,   646,   522,   -68,    24,    80,   406,   -68,
     -68,   -68,   -68,   -68,   362,   362,    39,    39,   250,   227,
     227,   -68,   -68,   568,   -68,   468,   485,   -14,    40,   646,
     646,   646,   -68,   -68,    45,   602,   275,   275,    73,   -68,
     -68,   646,   502,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -68,    14,   -68,   -68,   -68,   -68,    38,   -68,   -68,   -68,
     -67,    29,   -68,   -68,    -5,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const short yytable[] =
{
      45,    48,    52,    53,    54,   -67,   -67,   -67,    47,    55,
      64,    72,    73,    74,    33,    81,    58,    75,    49,    37,
      38,    39,    76,    56,    77,    50,    57,    40,    41,   -67,
      59,    34,    42,    60,    43,    83,    84,    85,   146,    87,
     107,    79,    80,    44,   142,   143,    88,    89,   106,    78,
      61,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      82,    88,    89,   108,    62,   113,   114,    63,   116,   147,
      94,    95,    96,    97,    98,   100,   109,   110,   111,   138,
     -27,   148,   149,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   153,   115,    52,   135,   136,   137,
     131,    88,    89,   139,   140,   141,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,   -36,    48,   120,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     134,   -36,     0,   -36,    49,    37,    38,    39,    88,    89,
     -36,   151,   152,   102,   103,    92,    93,    94,   104,    96,
     105,    98,     0,   -36,   -36,   -36,   -36,   -64,    48,    44,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,     0,   -64,     0,   -64,    49,    37,    38,    39,   -64,
     -64,   -64,     0,     0,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,     0,   -64,   -64,   -64,   -64,   -49,    69,
      44,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,     0,   -49,     0,   -49,    49,    37,    38,    39,
       0,     0,   -49,     0,     0,    40,    41,    65,     0,     0,
      42,   -49,    43,     0,     0,   -49,   -49,   -49,   -49,     0,
      70,    71,     0,     0,    49,    37,    38,    39,    35,    88,
      89,    66,     0,    40,    41,     0,     0,     0,    42,     0,
      43,    97,    98,     0,     0,    36,    37,    38,    39,    44,
       0,     0,    88,    89,    40,    41,    48,     0,     0,    42,
       0,    43,    95,    96,    97,    98,     0,     0,     0,     0,
      44,     0,     0,    49,    37,    38,    39,    86,     0,     0,
       0,     0,    40,    41,     0,     0,     0,    42,     0,    43,
       0,     0,     0,     0,    49,    37,    38,    39,    44,     0,
       0,     0,     0,    40,    41,   133,     0,     0,    42,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    49,    37,    38,    39,     0,     0,     0,     0,
       0,    40,    41,     0,     0,     0,    42,     0,    43,     0,
       0,     0,     0,     0,     0,     2,     3,    44,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,     0,    16,    17,    88,    89,     0,     0,     0,    18,
       0,    92,    93,    94,    95,    96,    97,    98,    19,     0,
       0,     0,    20,    21,    22,    23,   -26,    77,     0,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
       0,   -26,     0,   -26,   -26,     0,     0,     0,     0,     0,
     -26,     0,     0,     0,     0,     0,     0,     0,     0,   -26,
       0,     0,     0,   -26,   -26,   -26,   -26,   117,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,    15,     0,    16,    17,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,    20,   118,    22,    23,   -79,   -79,   -79,
      88,    89,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    98,   -78,   -78,   -78,    88,    89,     0,
       0,   -79,     0,     0,    92,    93,    94,    95,    96,    97,
      98,     0,     0,     0,    88,    89,     0,     0,   -78,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   144,     0,
       0,     0,     0,     0,    88,    89,     0,     0,   154,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   145,
      88,    89,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    88,    89,     0,     0,   101,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
     -81,   -81,     0,     0,   112,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,     0,     0,     0,   -81,   -81,   -81,
       0,     0,   -81,   -81,   -81,   -81,   -81,   -81,   150,   -81,
     -81,     0,     0,     0,   -75,   -75,     0,     0,     0,   -75,
     -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,    88,    89,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    88,    89,     0,     0,    99,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,   121,    88,    89,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   -81,   -81,     0,     0,     0,   -81,   -81,   -81,
     -81,   -81,   -81,     0,   -81,   -81
};

static const short yycheck[] =
{
       5,     1,     7,     8,    21,    19,    20,    21,    18,     1,
      25,    16,    44,    18,     1,    40,     1,    15,    18,    19,
      20,    21,     1,    15,     1,    25,    18,    27,    28,    43,
      15,    18,    32,    18,    34,    40,    41,    42,    14,    44,
      41,    27,    28,    43,   111,   112,    22,    23,    53,     1,
       1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      40,    22,    23,    44,    15,    70,    71,    18,    73,    45,
      31,    32,    33,    34,    35,    40,    44,    44,    41,    25,
       0,    41,    37,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    21,    16,   101,   102,   103,   104,
     105,    22,    23,   108,   109,   110,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,     0,     1,    80,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     101,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,   146,   147,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    38,    39,    40,     0,     1,    43,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,     0,     1,
      43,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    21,
      -1,    -1,    24,    -1,    -1,    27,    28,     1,    -1,    -1,
      32,    33,    34,    -1,    -1,    37,    38,    39,    40,    -1,
      42,    43,    -1,    -1,    18,    19,    20,    21,     1,    22,
      23,    25,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
      34,    34,    35,    -1,    -1,    18,    19,    20,    21,    43,
      -1,    -1,    22,    23,    27,    28,     1,    -1,    -1,    32,
      -1,    34,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    18,    19,    20,    21,     1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,    34,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    43,    -1,
      -1,    -1,    -1,    27,    28,     1,    -1,    -1,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    43,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    17,    18,    22,    23,    -1,    -1,    -1,    24,
      -1,    29,    30,    31,    32,    33,    34,    35,    33,    -1,
      -1,    -1,    37,    38,    39,    40,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    40,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    19,    20,    21,    22,    23,    -1,
      -1,    43,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    22,    23,    -1,    -1,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    46,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    37,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    22,    23,    -1,    -1,    41,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      22,    23,    -1,    -1,    41,    27,    28,    29,    30,    31,
      32,    16,    34,    35,    -1,    -1,    -1,    22,    23,    41,
      -1,    -1,    27,    28,    29,    30,    31,    32,    16,    34,
      35,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    22,    23,    -1,    -1,    40,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    48,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    17,    18,    24,    33,
      37,    38,    39,    40,    49,    50,    51,    52,    54,    55,
      56,    59,    60,     1,    18,     1,    18,    19,    20,    21,
      27,    28,    32,    34,    43,    61,    62,    18,     1,    18,
      25,    58,    61,    61,    21,     1,    15,    18,     1,    15,
      18,     1,    15,    18,    25,     1,    25,    57,    61,     1,
      42,    43,    61,    44,    61,    15,     1,     1,     1,    48,
      48,    40,    40,    61,    61,    61,     1,    61,    22,    23,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    40,
      40,    41,    27,    28,    32,    34,    61,    41,    44,    44,
      44,    41,    41,    61,    61,    16,    61,     1,    38,    53,
      53,    37,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,     1,    58,    61,    61,    61,    25,    61,
      61,    61,    57,    57,    16,    37,    14,    45,    41,    37,
      16,    61,    61,    21,    46
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 10:
#line 75 "asm.yy"
    { builder->setEnv(SymTable::PO_ORG,yyvsp[0].v); }
    break;

  case 11:
#line 76 "asm.yy"
    { builder->error("unmatched closing brace"); }
    break;

  case 12:
#line 77 "asm.yy"
    { builder->error("unmatched closing scope"); }
    break;

  case 13:
#line 78 "asm.yy"
    { builder->error("assignment or label expected"); }
    break;

  case 14:
#line 79 "asm.yy"
    { builder->error("assignment or label expected"); }
    break;

  case 15:
#line 80 "asm.yy"
    { builder->error("assignment or label expected"); }
    break;

  case 16:
#line 81 "asm.yy"
    { builder->error("undefined pseudo opcode"); }
    break;

  case 17:
#line 82 "asm.yy"
    { builder->error("unknown opcode or command"); }
    break;

  case 20:
#line 92 "asm.yy"
    { builder->beginScope(); }
    break;

  case 21:
#line 93 "asm.yy"
    { builder->beginNamedScope(yyvsp[-1].i); }
    break;

  case 22:
#line 94 "asm.yy"
    { builder->beginModuleScope(yyvsp[-1].i); }
    break;

  case 23:
#line 95 "asm.yy"
    { builder->beginModuleScope(yyvsp[-1].v); }
    break;

  case 24:
#line 96 "asm.yy"
    { builder->error("invalid scope declaration"); }
    break;

  case 25:
#line 97 "asm.yy"
    { builder->error("invalid module declaration"); }
    break;

  case 26:
#line 101 "asm.yy"
    { builder->endScope(); }
    break;

  case 27:
#line 102 "asm.yy"
    { builder->error("scope end ('}') expected"); }
    break;

  case 28:
#line 105 "asm.yy"
    { builder->beginFuncScope(yyvsp[-1].i); }
    break;

  case 29:
#line 108 "asm.yy"
    { builder->localLabel(yyvsp[0].i); }
    break;

  case 30:
#line 109 "asm.yy"
    { builder->exportLabel(yyvsp[0].i); }
    break;

  case 31:
#line 110 "asm.yy"
    { builder->exportLabel(yyvsp[0].i); }
    break;

  case 32:
#line 111 "asm.yy"
    { builder->globalLabel(yyvsp[0].i); }
    break;

  case 33:
#line 112 "asm.yy"
    { builder->memberLabel(yyvsp[0].i); }
    break;

  case 34:
#line 115 "asm.yy"
    { builder->endValueList(yyvsp[-1].i); }
    break;

  case 35:
#line 116 "asm.yy"
    { builder->addCStr(yyvsp[0].s); }
    break;

  case 36:
#line 117 "asm.yy"
    { builder->addByteBuffer(yyvsp[-1].i,yyvsp[0].v); }
    break;

  case 37:
#line 118 "asm.yy"
    { builder->addByteBuffer(yyvsp[-2].i,yyvsp[-1].v,yyvsp[0].v); }
    break;

  case 38:
#line 119 "asm.yy"
    { builder->setFilePos(yyvsp[-2].s,*(yyvsp[-4].n)); }
    break;

  case 39:
#line 120 "asm.yy"
    { builder->setEncoding(yyvsp[0].s); }
    break;

  case 40:
#line 121 "asm.yy"
    { builder->endValueList(yyvsp[-1].i); }
    break;

  case 41:
#line 124 "asm.yy"
    { builder->addListValue(yyvsp[0].v); }
    break;

  case 42:
#line 125 "asm.yy"
    { builder->addListValue(yyvsp[-2].v); }
    break;

  case 43:
#line 126 "asm.yy"
    { builder->addListValue(yyvsp[0].s); }
    break;

  case 44:
#line 127 "asm.yy"
    { builder->addListValue(yyvsp[-2].s); }
    break;

  case 45:
#line 128 "asm.yy"
    { builder->error("comma separedted list expected"); }
    break;

  case 46:
#line 131 "asm.yy"
    { builder->addListValue(yyvsp[0].v); }
    break;

  case 47:
#line 132 "asm.yy"
    { builder->addListValue(yyvsp[-2].v); }
    break;

  case 48:
#line 133 "asm.yy"
    { builder->error("comma separedted list expected"); }
    break;

  case 49:
#line 136 "asm.yy"
    { builder->op_implied(yyvsp[0].i); }
    break;

  case 50:
#line 137 "asm.yy"
    { builder->op_immediate(yyvsp[-2].i,yyvsp[0].v); }
    break;

  case 51:
#line 138 "asm.yy"
    { builder->op_indir_x(yyvsp[-4].i,yyvsp[-2].v,yyvsp[-1].i); }
    break;

  case 52:
#line 139 "asm.yy"
    { builder->op_indir_y(yyvsp[-4].i,yyvsp[-2].v,yyvsp[0].i); }
    break;

  case 53:
#line 140 "asm.yy"
    { builder->op_absrel(yyvsp[-2].i,yyvsp[-1].v,yyvsp[0].i); }
    break;

  case 54:
#line 141 "asm.yy"
    { builder->op_indirect(yyvsp[-3].i,yyvsp[-1].v); }
    break;

  case 55:
#line 142 "asm.yy"
    { builder->op_absolute(yyvsp[-1].i,yyvsp[0].v); }
    break;

  case 56:
#line 143 "asm.yy"
    { builder->error("malformed operand"); }
    break;

  case 57:
#line 146 "asm.yy"
    { builder->localDefine(yyvsp[-2].i,yyvsp[0].v); }
    break;

  case 58:
#line 147 "asm.yy"
    { builder->localDefine(yyvsp[-4].i,yyvsp[-2].v); }
    break;

  case 59:
#line 148 "asm.yy"
    { builder->localDefine(yyvsp[-5].i,yyvsp[-3].v); }
    break;

  case 60:
#line 149 "asm.yy"
    { builder->globalDefine(yyvsp[-2].i,yyvsp[0].v); }
    break;

  case 61:
#line 150 "asm.yy"
    { builder->exportDefine(yyvsp[-2].i,yyvsp[0].v); }
    break;

  case 62:
#line 151 "asm.yy"
    { builder->memberDefine(yyvsp[-2].i,yyvsp[0].v); }
    break;

  case 64:
#line 155 "asm.yy"
    { yyval.v = builder->anonLabel(); }
    break;

  case 65:
#line 156 "asm.yy"
    { yyval.v = Expr::expr(Value::constValue(0),yyvsp[0].v, OpMinus::obj); }
    break;

  case 66:
#line 157 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpPlus::obj); }
    break;

  case 67:
#line 158 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpMinus::obj); }
    break;

  case 68:
#line 159 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpMult::obj); }
    break;

  case 69:
#line 160 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpDiv::obj); }
    break;

  case 70:
#line 161 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpDiv::obj); }
    break;

  case 71:
#line 162 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpMod::obj); }
    break;

  case 72:
#line 163 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpBitOr::obj); }
    break;

  case 73:
#line 164 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpBitAnd::obj); }
    break;

  case 74:
#line 165 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpBitXor::obj); }
    break;

  case 75:
#line 166 "asm.yy"
    { yyval.v = yyvsp[-1].v; }
    break;

  case 76:
#line 167 "asm.yy"
    { yyval.v = Expr::unaryExpr(yyvsp[0].v, OpLowByte::obj); }
    break;

  case 77:
#line 168 "asm.yy"
    { yyval.v = Expr::unaryExpr(yyvsp[0].v, OpHighByte::obj); }
    break;

  case 78:
#line 169 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpShr::obj); }
    break;

  case 79:
#line 170 "asm.yy"
    { yyval.v = Expr::expr(yyvsp[-2].v,yyvsp[0].v, OpShl::obj); }
    break;

  case 80:
#line 171 "asm.yy"
    { yyval.v = Value::constValue(0); 
                                  builder->error("invalid expression, ')' expected"); }
    break;

  case 81:
#line 173 "asm.yy"
    { yyval.v = Value::constValue(0); 
                                  builder->error("invalid expression"); }
    break;

  case 82:
#line 177 "asm.yy"
    { yyval.v = Value::constValue(*(yyvsp[0].n)); }
    break;

  case 83:
#line 178 "asm.yy"
    { yyval.v = Value::constValue(*(yyvsp[0].n)); }
    break;

  case 84:
#line 179 "asm.yy"
    { yyval.v = Value::constValue(*(yyvsp[0].n)); }
    break;

  case 85:
#line 180 "asm.yy"
    { yyval.v = Value::lookupValue(yyvsp[0].i); }
    break;

  case 86:
#line 181 "asm.yy"
    { yyval.v = Value::constValue(0); 
                                  builder->error("maformed value"); }
    break;


    }

/* Line 999 of yacc.c.  */
#line 1661 "asm.cc"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 185 "asm.yy"


