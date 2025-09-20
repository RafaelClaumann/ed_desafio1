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

Estrutura *create() {
  Estrutura *queue = (Estrutura *)malloc(sizeof(Estrutura));
  if (queue == NULL)
    return NULL;

  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;

  return queue;
}

void inserir(Estrutura *queue, Requisicao *requisicao_) {
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  if (temp == NULL)
    return;

  temp->requisicao = requisicao_;
  temp->next = NULL;

  if (queue->head == NULL) {
    queue->head = temp;
    queue->tail = temp;
  } else {
    queue->tail->next = temp;
    queue->tail = temp;
  }

  queue->size++;
}

Requisicao *remover(Estrutura *queue) {
  if (queue == NULL || queue->head == NULL)
    return NULL;

  NODE *old_head = queue->head;
  Requisicao *req = old_head->requisicao;

  queue->head = old_head->next;

  if (queue->head == NULL)
    queue->tail = NULL;

  queue->size--;

  free(old_head);
  return req;
}

int get_size(Estrutura *queue) {
  return queue->size;
}

void libera_estrutura(Estrutura *queue) {
  if (queue == NULL)
    return;

  NODE *temp = queue->head;
  while (temp != NULL) {
    NODE *prox = temp->next;

    if (temp->requisicao != NULL)
      free(temp->requisicao);

    free(temp);

    temp = prox;
  }

  free(queue);
}
