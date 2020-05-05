%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 25 Jul 19   */

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

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */
%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN
%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT
%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH

%%

  program           : PROGRAM IDENTIFIER LPAREN id_list RPAREN SEMICOLON lblock DOT { parseresult = makeprogram($2, $4, $7); } ;
                    ;
  unsigned_constant :  NUMBER |  NIL |  STRING
                    ;
  sign              :  PLUS |  MINUS
                    ;
  constant          :  sign IDENTIFIER { $$ = unaryop($1, $2); } | IDENTIFIER |  sign NUMBER { $$ = unaryop($1, $2); } | NUMBER |  STRING
                    ;
  id_list           :  IDENTIFIER COMMA id_list { $$ = cons($1, $3); } |  IDENTIFIER    { $$ = cons($1, NULL); }
                    ;
  simple_type       :  IDENTIFIER   { $$ = findtype($1); }
                    |  LPAREN id_list RPAREN         { $$ = instenum($2); }
                    |  constant DOTDOT constant     { $$ = instdotdot($1, $2, $3); }
                    ;
  simple_type_list  :  simple_type COMMA simple_type_list  { $$ = cons($1, $3); }
                    |  simple_type   { $$ = cons($1, NULL); }
                    ;
  type              :  simple_type
                    |  ARRAY LBRACKET simple_type_list RBRACKET OF type   { $$ = instarray($3, $6); }
                    |  RECORD field_list END                          { $$ = instrec($1, $2); }
                    |  POINT IDENTIFIER                              { $$ = instpoint($1, $2); }
                    ;
  fields            :  id_list COLON type  { $$ = instfields($1, $3); }
                    ;
  field_list        :  fields SEMICOLON field_list   { $$ = nconc($1, $3); }
                    |  fields
                    ;
  expr_list         :  expression COMMA expr_list { $$ = cons($1, $3); }  | expression
                    ;
  variable          :  IDENTIFIER                            { $$ = findid($1); }
                    |  variable LBRACKET expr_list RBRACKET   { $$ = arrayref($1, $2, $3, $4); }
                    |  variable DOT IDENTIFIER                { $$ = reducedot($1, $2, $3); }
                    |  variable POINT                         { $$ = dopoint($1, $2); }
                     ;
  factor            :  unsigned_constant
                    |  variable
                    |  LPAREN expression RPAREN   { $$ = $2; }       
                    |  funcall
                    |  NOT factor { $$ = unaryop($1, $2); }
                    ;
  funcall           :  IDENTIFIER LPAREN expr_list RPAREN    { $$ = makefuncall($2, $1, $3); }
                    ;
  times_op          :  TIMES | DIVIDE | DIV | MOD | AND
                    ;
  term              :  term times_op factor { $$ = binop($2, $1, $3); }
                    |  factor
                    ;
  plus_op           :  PLUS | MINUS | OR
                    ;
  simple_expression :  sign term { $$ = unaryop($1, $2); } | term 
                    |  simple_expression plus_op term  { $$ = binop($2, $1, $3); }
                    ;
  compare_op        :  EQ | LT | GT | NE | LE | GE | IN
                    ;
  expression        :  expression compare_op simple_expression { $$ = binop($2, $1, $3); }
                    |  simple_expression 
                    ;
  numlist           :  NUMBER COMMA numlist  { instlabel($1); }
                    |  NUMBER                { instlabel($1); }
                    ;
  lblock            :  LABEL numlist SEMICOLON cblock  { $$ = $4; }
                    |  cblock
                    ;
  cdef              :  IDENTIFIER EQ constant { instconst($1, $3); }
                    ;
  cdef_list         :  cdef SEMICOLON cdef_list | cdef SEMICOLON          
                    ;  
  cblock            :  CONST cdef_list tblock { $$ = $3; } 
                    | tblock
                    ;
  tdef              :  IDENTIFIER EQ type     { insttype($1, $3); }
                    ;
  tdef_list         :  tdef SEMICOLON tdef_list |tdef SEMICOLON
                    ;
  tblock            :  TYPE tdef_list vblock  { $$ = $3; } 
                    | vblock
                    ;
  vdef              :  id_list COLON type { instvars($1, $3); }
                    ;
  vdef_list         :  vdef SEMICOLON vdef_list   |  vdef SEMICOLON            
                    ;
  vblock            :  VAR vdef_list block { $$ = $3; } 
                    |  block
                    ;
  block             :  BEGINBEGIN statement endpart  { $$ = makeprogn($1,cons($2, $3)); }  
                    ;

  endpart           :  SEMICOLON statement endpart  { $$ = cons($2, $3); }  
                    |  END  { $$ = NULL; }
                    ;
  label             :  NUMBER COLON statement      { $$ = dolabel($1, $2, $3); }
                    ;
  statement         :  BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }
                    |  IF expression THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
                    |  assignment
                    |  funcall
                    |  WHILE expression DO statement       { $$ = makewhile($1, $2, $3, $4); }
                    |  FOR assignment TO expression DO statement   { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
                    |  REPEAT statement_list UNTIL expression              { $$ = makerepeat($1, $2, $3, $4); }
                    |  GOTO NUMBER                  { $$ = dogoto($1, $2); }
                    |  label
                    ;
  statement_list    :  statement SEMICOLON statement_list  { $$ = cons($1, $3); } | statement
                    ;
  endif             :  ELSE statement  { $$ = $2; }  |  /* empty */  { $$ = NULL; }
                    ; 
  assignment        :  variable ASSIGN expression   { $$ = binop($2, $1, $3); }
                    ;
  var_specs         :  var_group SEMICOLON var_specs   
                    |  var_group SEMICOLON            
                    ;
  var_group         :  id_list COLON type { instvars($1, $3); }
                    ;

%%

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
#define DB_INSTLABEL    0
#define DB_INSTENUM     0
#define DB_INSTDOTDOT   0
#define DB_INSTARRAY    0
#define DB_INSTFIELD    0
#define DB_INSTREC      0
#define DB_INSTPOINT    0
#define DB_INSTTYPE     0
#define DB_FINDTYPE     0

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labeltable[50];

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

/* cons links a new item onto the front of a list.  Equivalent to a push.
   (cons 'a '(b c))  =  (a b c)    */
TOKEN cons(TOKEN item, TOKEN list)           // add item to front of list 
  { item->link = list;
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
    tok->realval = (double) tok->intval;
    return tok;
  } else {
    TOKEN floatop = makeop(FLOATOP);
    floatop->operands = tok;
    return floatop;
  }
}

  int isInteger(TOKEN tok) {
  if(tok->basicdt == INTEGER)
    return 1;
  else 
    return 0;
}

int isReal(TOKEN tok) {
  if(tok->basicdt == REAL)
    return 1;
  else 
    return 0;
}
//CHECK  BINOP IF ERROR
/* binop links a binary operator op to two operands, lhs and rhs. */
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs) {       /* reduce binary operator */
    
    op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP){ 
      printf("binop\n");
      dbugprinttok(op);
      dbugprinttok(lhs);
      dbugprinttok(rhs);
    };
    if (isReal(lhs) && isInteger(rhs)){
      //if multiplying
      op->basicdt = REAL;
      TOKEN ftok = makefloat(rhs);
      lhs->link = ftok;
    } else if (isInteger(lhs) && isReal(rhs)){
          //if multiplying 
          if (op->whichval==TIMESOP) {
            op->basicdt = REAL;
            TOKEN ftok = makefloat(lhs);
            ftok->link = rhs;
        } //assign int(lhs) is an int
        else if (op->whichval == ASSIGNOP){
            op->basicdt = INTEGER;
        } 
    } else if(isReal(lhs) && isReal(rhs) ){
        op->basicdt = REAL;   
    } else if (lhs->whichval == FUNCALLOP){
         op->basicdt = REAL; 
    }
    return op;
  }

/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
  
  op->operands = lhs;
  lhs->link = NULL;
  if (DEBUG & DB_UNOP){ 
    printf("unaryop\n");
    dbugprinttok(op);
    dbugprinttok(lhs);
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
    TOKEN tok = talloc();
    TOKEN nameToArgs = talloc();
    tok->tokentype = OPERATOR;
    tok->whichval = PROGRAMOP;
    tok->operands = name;
    nameToArgs = makeprogn(nameToArgs, args);
    name->link = nameToArgs;
    nameToArgs->link = statements;
    if (DEBUG & DB_MAKEPROGRAM) { 
      printf("makeprogram\n");
      dbugprinttok(tok);
      dbugprinttok(nameToArgs);
    };
    return tok;
  }

  /* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok) {  
  SYMBOL typesym, sym; 
  int align;
  typesym = typetok->symtype;
  align = alignsize(typesym);
  while ( idlist != NULL )  {  
    sym = insertsym(idlist->stringval);
    sym->kind = VARSYM; 
    sym->offset = wordaddress(blockoffs[blocknumber], align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = sym->offset + sym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    idlist = idlist->link;
  };
}

  /* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok) { 
  SYMBOL sym, typ;
  sym = searchst(tok->stringval);
  tok->symentry = sym;
    if (sym->kind == CONSTSYM) {
      if (sym->basicdt == REAL) {
        tok->tokentype = NUMBERTOK;
        tok->basicdt = REAL;
        tok->realval = sym->constval.realnum;
      }
      else if (sym->basicdt == INTEGER) {
        tok->tokentype = NUMBERTOK;
        tok->basicdt = INTEGER;
        tok->intval = sym->constval.intnum;
      }

      if (DEBUG & DB_FINDID) { 
        dbugprinttok(sym);
        debugprinttok(tok);
      };
      return tok;
    }

    typ = sym->datatype;
    tok->symtype = typ;
    if ( typ->kind == BASICTYPE || typ->kind == POINTERSYM)
        tok->basicdt = typ->basicdt;

    return tok;
  }

//DIFFERENT
/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {
    SYMBOL sym = searchst(tok->stringval);
    if (sym->kind == TYPESYM) 
      sym = sym->datatype;
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
  if(tok->tokentype == NUMBERTOK) {
    tok->basicdt = INTEGER;
    tok->intval = (int) tok->realval;
    return tok;
  } else { 
    TOKEN fixop = makeop(FIXOP);
    fixop->operands = tok;
    return fixop;
  }
}

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
if (strcmp(fn->stringval, "new") == 0) {
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

  } else if (strcmp(fn->stringval, "writeln") == 0) {
    if (args->basicdt == REAL) {
        strcpy(fn->stringval, "writelnf");
    } else if (args->tokentype == STRINGTOK) {
        strcpy(fn->stringval, "writeln");
    } else {
        strcpy(fn->stringval, "writelni");
    }
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link=args; 

  } else {
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link=args;
  }
  if (DEBUG && DB_MAKEFUNCALL) {
         printf("makefuncall\n");
         dbugprinttok(tok);
  }
  return tok;
}

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok) {
  TOKEN copy = talloc();
  copy->tokentype = origtok->tokentype;
  copy->whichval = origtok->whichval;
  copy->basicdt = origtok->basicdt;
  copy->symtype = origtok->symtype;
  copy->symentry = origtok->symentry;
  copy->link = origtok->link;
  copy->intval = origtok->intval;
  copy->realval = origtok->realval;
  if (DEBUG & DB_MAKECOPY) {
    printf("copytok\n");
    dbugprinttok(copy);
  }
  return copy;
}

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel() {
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = LABELOP;
  tok->operands = makeintc(labelnumber++);
  if (DEBUG & DB_MAKELABEL) {
      printf("makelabel\n");
      dbugprinttok(tok);
  }
  return tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label){
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = GOTOOP;
  tok->operands = makeintc(label); ///makeintc(num)
  if (DEBUG && DB_MAKEGOTO) {
    printf("makegoto\n");
    dbugprinttok(tok);
  }
  return tok;
}

///PENDING CORRECT
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

  TOKEN ifs = talloc();
  TOKEN body = talloc();
  body = makeprogn(body, statement);

  TOKEN leftoper = makeop(LEOP);
  ifs = makeif(ifs, leftoper, body, NULL);
  TOKEN iden1 = copytok(asg->operands);
  TOKEN iden2 = copytok(iden1);
  TOKEN iden3 = copytok(iden1);
  iden1->link = endexpr;
  leftoper->operands = iden1;

  TOKEN assgn = makeop(ASSIGNOP);
  TOKEN increment = makeop(PLUSOP);

  iden3->link=makeintc(1);
  increment->operands=iden3;
  iden2->link=increment;
  assgn->operands=iden2;

  int currentnum = labelnumber - 1;
  TOKEN gototok = makegoto(currentnum);
  assgn->link = gototok;
  statement->link = assgn;

  leftoper->link = body;
  ifs->operands = leftoper;
  label->link = ifs;
  if (DEBUG && DB_MAKEFOR) {
      printf("makefor\n");
      dbugprinttok(tok);
  }
  return tok;
}

/* instconst installs a constant in the symbol table */
void  instconst(TOKEN idtok, TOKEN consttok){
  SYMBOL sym;
  sym = insertsym(idtok->stringval);
  sym->kind = CONSTSYM;
  sym->basicdt = consttok->basicdt;
  if(sym->basicdt == REAL) 
      sym->constval.realnum = consttok->realval;

  if(sym->basicdt == INTEGER) 
      sym->constval.intnum = consttok->intval;
 
  if (DEBUG & DB_INSTCONST) {
    printf("instconst\n");
    dbugprinttok(sym);
  }
}

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr){

   TOKEN label = makelabel();
   int current = labelnumber - 1;
   tok = makeprogn(tok, label);
   TOKEN body = tokb;
   body = makeprogn(body, statements);
   label->link = body;
   TOKEN gototok = makegoto(current);
   TOKEN emptytok = makeprogn((TOKEN) talloc(), NULL);
   emptytok->link = gototok;
   TOKEN ifs = talloc();
   ifs = makeif(ifs, expr, emptytok, gototok);
   body->link = ifs;

   if (DEBUG && DB_MAKEREPEAT) {
         printf("make repeat\n");
         dbugprinttok(tok);
   }

   return tok;  
}

////NEEEEEEEEEW
/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
/* nconc should return lista, or listb if lista is NULL. */
TOKEN nconc(TOKEN lista, TOKEN listb){
  TOKEN temp = lista;
  while(temp->link) {
    temp = temp->link;
  }
  temp->link = listb;
  if (DEBUG & DB_NCONC) {
   printf("nconc\n");
   dbugprinttok(temp);
  };
  return temp;
}

/* makeintc makes a new integer number token with num as its value */
TOKEN makeintc(int number) {
  TOKEN tok = talloc();
  tok->tokentype = NUMBERTOK;
  tok->basicdt = INTEGER;
  tok->intval = number;
  if (DEBUG & DB_MAKEINTC) {
      printf("makeintc\n");
      dbugprinttok(tok);
  }
  return tok;
}

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok){
    if (var->whichval == AREFOP) {
    TOKEN plusop = makeop(PLUSOP);
    TOKEN oldoff = var->operands->link;
    oldoff->link = off;
    plusop->operands = oldoff;
    var->operands->link = plusop;
    var->basicdt = var->symentry->basicdt;

    return var;

    if (DEBUG && DB_MAKEAREF) {
        printf("makearef couple\n");
        printf("symentry: %s", var->symentry->namestring);
        dbugprinttok(var);
    }

  } 

  TOKEN areftok = makeop(AREFOP);
  var->link = off;
  areftok->operands = var;
  areftok->symentry = var->symentry; 
  areftok->basicdt = var->symentry->basicdt;  

  if (DEBUG && DB_MAKEAREF) {
      printf("makearef\n");
      printf("symentry: %s", var->symentry->namestring);
      dbugprinttok(areftok);
      dbugprinttok(var);
  }

  return areftok;
}

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement){
  TOKEN label = makelabel();
  int current = labelnumber - 1;
  tok = makeprogn(tok, label);

  TOKEN gototok = makegoto(current);
  statement->link = gototok;
  TOKEN body = makeprogn(tokb, statement);

  TOKEN ifs = talloc();
  ifs = makeif(ifs, expr, body, NULL);
  label->link = ifs;

  if (DEBUG && DB_MAKEWHILE) {
     printf("makewhile\n");
     dbugprinttok(tok);
  }
  return tok;
}


/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high){
  SYMBOL subrange = symalloc();
  subrange->kind = SUBRANGE;
  subrange->basicdt = INTEGER;
  subrange->lowbound = low;
  subrange->highbound = high;
  subrange->size = basicsizes[INTEGER];
  tok->symtype = subrange;

  if (DEBUG & DB_MAKESUB) {
    printf("making subrange\n");
    dbugprinttok(tok);
  }

  return tok;
}

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field){
   SYMBOL recsym = var->symentry;
  SYMBOL curfield = recsym->datatype->datatype;
  int offset = 0;
  while(curfield) {
    if (strcmp(curfield->namestring, field->stringval) == 0) {
      offset = curfield->offset;
      var->symentry = curfield;
      break;
    } else {
      curfield = curfield->link;
    }
  }

  dot = makearef(var, makeintc(offset), dot);

  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedot\n");
    //printf("-- %s ** %s", curfield->namestring, field->stringval);
    dbugprinttok(var);
    dbugprinttok(dot);
    dbugprinttok(field);
  }
  return dot;
 
}

//ORIGINAL CHANGE?
/* finds label number in label table for user defined labels */
int findlabelnumber(int label) {
  if (DEBUG & DB_FINDLABEL) {
    printf("finding label\n");
  }
  for(int i = 0; i < labelnumber; i ++) {
    if (labeltable[i] == label) {
      if (DEBUG & DB_FINDLABEL) {
       printf("found label : ");
       printf("%d\n", i);
      }
      return i;
    }
  }
  return -1;
}

//PENDING CORRECT
/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
  if (subs->link) {
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


  } else {
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


    if (DEBUG & DB_ARRAYREF) {
        printf("arrayref\n");
        //printf("low : %d, high : %d, total size : %d, size of ele %d", low, high, arr->symtype->size, size);
        dbugprinttok(arr);
        dbugprinttok(subs);
        dbugprinttok(plusop);
    }
    return makearef(arr, plusop, tokb);
  }

  
}

/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
    int real_label = findlabelnumber(labeltok->intval);
    if (real_label == -1) {
      printf("Error: user defined label not found");
    }

    labeltok = makeop(LABELOP);
    TOKEN tokb = makeintc(real_label);
    labeltok->operands=tokb;
    labeltok->link = statement;
    tok = makeprogn(tok, labeltok);

    if (DEBUG & DB_DOLABEL) {
      printf("dolabel\n");
      dbugprinttok(tok);
    }

    return tok;
}

//PENDING CORRECT
/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
    int real_label = findlabelnumber(labeltok->intval);
    if (real_label == -1) {
      printf("Error: user defined label not found");
    }  

    tok = makegoto(real_label);
    if (DEBUG & DB_DOGOTO) {
      printf("dogoto\n");
      dbugprinttok(tok);
    }

    return tok;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
  tok->symentry = var->symentry->datatype->datatype;
  tok->operands = var;

  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(tok);
  }

  return tok;
}

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) {
  labeltable[labelnumber++] = num->intval;  
  if (DEBUG & DB_INSTLABEL) {
    printf("instlabel\n");
    printf("current\n");
    for (int i = 0; i < labelnumber; i ++) {
      printf("label ");
      printf("%d  :", i);
      printf("%d\n", labeltable[i]);
    }
  }
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
  int count = 0;

  TOKEN list = copytok(idlist);
  while (list) {
    instconst(list, makeintc(count));
    count ++;
    list = list->link;
  }

  TOKEN tok = makesubrange(idlist, 0, count - 1);
  if (DEBUG & DB_INSTENUM) {
    printf("instenum\n");
    dbugprinttok(idlist);
  }

  return tok;
}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
  int low = lowtok->intval;
  int high = hightok->intval;

  if (DEBUG & DB_INSTDOTDOT) {
    printf("install dot dot\n");
    dbugprinttok(lowtok);
    dbugprinttok(hightok);
  }

  return makesubrange(dottok, low, high);
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {
  if (bounds->link) {
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
    if (DEBUG & DB_INSTARRAY) {
        printf("instarray\n");
        dbugprinttok(typetok);
    }
  return typetok;

  } else {

    SYMBOL subrange = bounds->symtype;
    SYMBOL typesym = typetok->symtype;
    SYMBOL arraysym = symalloc();
    arraysym->kind = ARRAYSYM;
    arraysym->datatype = typesym;
    arraysym->lowbound = subrange->lowbound;
    arraysym->highbound = subrange->highbound;
    arraysym->size = (arraysym->highbound - arraysym->lowbound +  1) * (typesym->size);
    typetok->symtype = arraysym;
    if (DEBUG & DB_INSTARRAY) {
      printf("install array base\n");
      dbugprinttok(typetok);
    }

    return typetok;
  }
}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
  SYMBOL typesym = typetok->symtype;
  TOKEN temp = idlist;
  while(temp) {
    temp->symtype = typesym;     
    temp = temp->link;
  }

  if (DEBUG & DB_INSTFIELD) {
      printf("instfields\n");
      dbugprinttok(idlist);
  }

  return idlist;
}

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  SYMBOL recsym = symalloc();
  recsym->kind = RECORDSYM;
  int count = 0, next = 0, align;

  SYMBOL prev = NULL;
  while (argstok) {
    align = alignsize(argstok->symtype);
    SYMBOL recfield = makesym(argstok->stringval);
    recfield->datatype = argstok->symtype;
    recfield->offset = wordaddress(next, align);
    recfield->size = argstok->symtype->size;
    next = recfield->offset + recfield->size;
    if (count == 0) {
      recsym->datatype = recfield;
      prev = recfield;
    } else {
      prev->link = recfield;
      prev = recfield;
    }
    recfield->link = NULL;
    count ++;
    argstok = argstok->link;
  }

  recsym->size = wordaddress(next, 16); 
  rectok->symtype = recsym;

  if (DEBUG & DB_INSTREC) {
      printf("instrect\n");
      dbugprinttok(rectok);

  }
  return rectok;
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {

  SYMBOL typesym = searchins(typename->stringval);
  SYMBOL pointsym = symalloc();
  pointsym->datatype = typesym;
  pointsym->kind = POINTERSYM;
  pointsym->size = basicsizes[POINTER];
  pointsym->basicdt = POINTER;

  tok->symtype = pointsym;

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
    printf("install type\n");
    dbugprinttok(typename);
    dbugprinttok(typetok);
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
  }