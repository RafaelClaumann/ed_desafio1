#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct {
    char nome[40];
    int codigo_inscricao;
    char codigo_procedimento[10];
} Requisicao;

char *get_nome(Requisicao *req);

#endif
