
/* -------------------------------------------------------------------
 *            Aquivo: compilador.c
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Funções auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "compilador.h"


/* -------------------------------------------------------------------
 *  variáveis globais
 * ------------------------------------------------------------------- */

simbolos simbolo, relacao;
char token[TAM_TOKEN];

FILE* fp=NULL;
void geraCodigo (char* rot, char* comando) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }

  if ( rot == NULL ) {
    fprintf(fp, "     %s\n", comando); fflush(fp);
  } else {
    fprintf(fp, "%s: %s \n", rot, comando); fflush(fp);
  }
}

int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}


/* -------------------------------------------------------------------
 *  Adições à biblioteca
 * ------------------------------------------------------------------- */

elTabelaSimbolos* elTabelaSimbolosConstructor(char* token, int nivelLexico, int offset, int type, int class) {
  elTabelaSimbolos* novo = malloc(sizeof(elTabelaSimbolos));
  novo->token = token;
  novo->nivelLexico = nivelLexico;
  novo->offset = offset;
  novo->type = type;
  novo->class = class;
  return novo;
}

void elTabelaSimbolosDestructor(elTabelaSimbolos* el) {
  free(el);
}

int convertType(char* type) {
  if (strcmp(type, "integer") == 0) {
    return INTEGER;
  } else if (strcmp(type, "boolean") == 0) {
    return BOOLEAN;
  } else {
    fprintf(stderr, "Tipo não reconhecido: %s\n", type);
    exit(0);
  }
}

void updateTypes(stack* s, char* type){
  elTabelaSimbolos** arr = (elTabelaSimbolos**) s->dataArr;

  int convertedType = convertType(type);

  for(int i = s->elements - 1; i >= 0 && arr[i]->type == UNDEFINED; i--){
    arr[i]->type = convertedType;
  }
}

int cleanLexicalLevel(stack* s, int level){
  elTabelaSimbolos** arr = (elTabelaSimbolos**) s->dataArr;
  int ret = 0;

  for(int i = s->elements - 1; i >= 0 && arr[i]->nivelLexico == level; i--){
    s->elements--;
    ret++;
  }

  return ret;
}

void printElTabelaSimbolos(elTabelaSimbolos* el) {
  printf(
    "Token: %s, Nivel Lexico: %d, Offset: %d, Type: %d, Class: %d\n",
    el->token, 
    el->nivelLexico, 
    el->offset, 
    el->type, 
    el->class
  );
}
