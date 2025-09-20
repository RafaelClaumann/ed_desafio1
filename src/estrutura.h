#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct Estrutura Estrutura;

Estrutura *create();

void inserir(Estrutura *estrutura, Requisicao *requisicao);

Requisicao *remover(Estrutura *estrutura);

int get_size(Estrutura *estrutura);

void libera_estrutura(Estrutura *r);

#endif
