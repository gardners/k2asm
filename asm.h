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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 22 "asm.yy"
typedef union YYSTYPE {
  Value* v;
  Number* n;
  int    i;
  string*  s;
} YYSTYPE;
/* Line 1240 of yacc.c.  */
#line 97 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



