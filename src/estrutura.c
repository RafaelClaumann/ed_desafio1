#include "estrutura.h"
#include "requisicao.h"
#include <stdlib.h>

typedef struct Node_t {
  Requisicao *requisicao;
  struct Node_t *next;
} NODE;

struct Estrutura {
    NODE *head;
    NODE *tail;
    int size;
};

// Função para criar uma nova estrutura (fila)
// Aloca memória para a estrutura e inicializa seus campos
Estrutura *create() {
  // Aloca memória para a estrutura da fila
  Estrutura *queue = (Estrutura *)malloc(sizeof(Estrutura));
  if (queue == NULL)
    return NULL; // Retorna NULL se falhar a alocação

  // Inicializa os ponteiros da fila (vazia)
  queue->head = NULL; // Primeiro elemento da fila
  queue->tail = NULL; // Último elemento da fila
  queue->size = 0;    // Contador de elementos

  return queue; // Retorna a fila criada
}

// Função para inserir uma requisição na fila
void inserir(Estrutura *queue, Requisicao *requisicao_) {
  // Aloca memória para um novo nó
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  if (temp == NULL)
    return; // Sai se falhar a alocação

  // Configura o novo nó
  temp->requisicao = requisicao_; // Armazena a requisição
  temp->next = NULL;             // Próximo nó é NULL (será o último)

  // Se a fila está vazia
  if (queue->head == NULL) {
    queue->head = temp; // Novo nó é o primeiro (head)
    queue->tail = temp; // Novo nó também é o último (tail)
  } else {
    // Se a fila não está vazia
    queue->tail->next = temp; // O último nó atual (tail) aponta para o novo
    queue->tail = temp;       // Novo nó se torna o último (tail)
  }

  queue->size++; // Incrementa o contador de elementos
}

// Função para remover e retornar a primeira requisição da fila
Requisicao *remover(Estrutura *queue) {
  // Verifica se a fila existe ou está vazia
  if (queue == NULL || queue->head == NULL)
    return NULL;

  // Guarda referência para o nó que será removido (primeiro)
  NODE *old_head = queue->head;
  Requisicao *req = old_head->requisicao; // Salva a requisição

  // Atualiza o head para o próximo nó
  queue->head = old_head->next;

  // Se a fila ficou vazia após a remoção
  if (queue->head == NULL)
    queue->tail = NULL; // Atualiza tail também para NULL

  queue->size--; // Decrementa o contador de elementos

  free(old_head); // Libera a memória do nó removido
  return req;     // Retorna a requisição removida
}

// Função que retorna o tamanho atual da fila
int get_size(Estrutura *estrutura) { return estrutura->size; }

// Função para liberar toda a memória alocada pela estrutura
void libera_estrutura(Estrutura *r) {
  if (r == NULL)
    return;

  // Percorre todos os nós da fila liberando a memória
  NODE *temp = r->head;
  while (temp != NULL) {
    NODE *prox = temp->next; // Guarda referência para o próximo nó

    // Libera a memória da requisição (se existir)
    if (temp->requisicao != NULL)
      free(temp->requisicao);

    free(temp); // Libera o nó atual

    temp = prox; // Avança para o próximo nó
  }

  free(r); // Libera a estrutura principal
}