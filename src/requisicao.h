#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct Requisicao Requisicao;

Requisicao *cria_requisicao(char *nome, int codigo_inscricao, char *codigo_procedimento);

char *get_nome(Requisicao *req);

int get_inscricao(Requisicao *req);

char *get_procedimento(Requisicao *req);

void libera(Requisicao *r);

#endif
