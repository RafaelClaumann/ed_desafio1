#include "requisicao.h"

char *get_nome(Requisicao *req) { 
    return req->nome;
}

int *get_inscricao(Requisicao *req) { 
    return &req -> codigo_inscricao;
}

char *get_procedimento(Requisicao *req) { 
    return req->codigo_procedimento;
}
