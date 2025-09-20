#include "requisicao.h"
#include <stdlib.h>
#include <string.h>

#define REQ_TAMANHO_NOME 40
#define REQ_TAMANHO_PROCEDIMENTO 10

struct Requisicao {
  char nome[REQ_TAMANHO_NOME];
  int codigo_inscricao;
  char codigo_procedimento[REQ_TAMANHO_PROCEDIMENTO];
};

Requisicao *cria_requisicao(char *nome_, int inscricao_, char *procedimento_) {
  if (!nome_ || !procedimento_)
    return NULL;

  Requisicao *r = malloc(sizeof(Requisicao));
  if (!r)
    return NULL;

  strncpy(r->nome, nome_, sizeof(r->nome) - 1);
  r->nome[sizeof(r->nome) - 1] = '\0';

  r->codigo_inscricao = inscricao_;

  strncpy(r->codigo_procedimento, procedimento_, sizeof(r->codigo_procedimento) - 1);
  r->codigo_procedimento[sizeof(r->codigo_procedimento) - 1] = '\0';

  return r;
}

char *get_nome(Requisicao *req) {
  if (!req)
    return NULL;
  return req->nome;
}

int get_inscricao(Requisicao *req) {
  if (!req)
    return -1;
  return req->codigo_inscricao;
}

char *get_procedimento(Requisicao *req) {
  if (!req)
    return NULL;
  return req->codigo_procedimento;
}

void libera(Requisicao *r) {
  free(r);
}
