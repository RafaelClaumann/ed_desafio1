#ifndef REQUISICAO_H
#define REQUISICAO_H

#define REQ_TAMANHO_NOME 40
#define REQ_TAMANHO_PROCEDIMENTO 10

typedef struct {
    char nome[REQ_TAMANHO_NOME];
    int codigo_inscricao;
    char codigo_procedimento[REQ_TAMANHO_PROCEDIMENTO];
} Requisicao;

Requisicao *cria_requisicao(char *nome, int codigo_inscricao, char *codigo_procedimento);

void destroi_requisicao(Requisicao *r);

char *get_nome(Requisicao *req);

int get_inscricao(Requisicao *req);

char *get_procedimento(Requisicao *req);

#endif
