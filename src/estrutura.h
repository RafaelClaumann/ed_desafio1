#include "requisicao.h"

#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct Node_t {
  Requisicao *requisicao;
  struct Node_t *next;
} NODE;

typedef struct Estrutura_t {
  NODE *head;
  NODE *tail;
  int size;
} Estrutura;

Estrutura *create();

void inserir(Estrutura *estrutura, Requisicao *requisicao);

Requisicao *remover(Estrutura *estrutura);

int get_size(Estrutura *estrutura);

void libera_estrutura(Estrutura *r);

#endif
