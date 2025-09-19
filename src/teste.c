#include "estrutura.h"
#include "requisicao.h"
#include <stdio.h>
#include <string.h>

// ---------- Funções auxiliares ----------
Requisicao *make_req(const char *nome, int cod, const char *proc) {
  return cria_requisicao((char *)nome, cod, (char *)proc);
}

// ---------- Testes ----------
void test_criar_e_liberar_vazia() {
  Estrutura *q = create();
  if (q && get_size(q) == 0) {
    printf("✔ test_criar_e_liberar_vazia passou\n");
  } else {
    printf("✘ test_criar_e_liberar_vazia falhou\n");
  }
  libera_estrutura(q);
}

void test_inserir_remover_unico() {
  Estrutura *q = create();
  Requisicao *r = make_req("Joao", 1, "PROC1");
  inserir(q, r);
  Requisicao *rem = remover(q);

  if (rem == r && get_size(q) == 0) {
    printf("✔ test_inserir_remover_unico passou\n");
  } else {
    printf("✘ test_inserir_remover_unico falhou\n");
  }

  libera(rem);
  libera_estrutura(q);
}

void test_inserir_remover_varios() {
  Estrutura *q = create();
  Requisicao *r1 = make_req("A", 10, "P1");
  Requisicao *r2 = make_req("B", 20, "P2");
  Requisicao *r3 = make_req("C", 30, "P3");

  inserir(q, r1);
  inserir(q, r2);
  inserir(q, r3);

  if (get_size(q) == 3) {
    printf("✔ test_inserir_remover_varios (inserção) passou\n");
  } else {
    printf("✘ test_inserir_remover_varios (inserção) falhou\n");
  }

  Requisicao *out1 = remover(q);
  Requisicao *out2 = remover(q);
  Requisicao *out3 = remover(q);

  if (out1 == r1 && out2 == r2 && out3 == r3 && get_size(q) == 0) {
    printf("✔ test_inserir_remover_varios (remoção) passou\n");
  } else {
    printf("✘ test_inserir_remover_varios (remoção) falhou\n");
  }

  libera(out1);
  libera(out2);
  libera(out3);
  libera_estrutura(q);
}

void test_intercalar() {
  Estrutura *q = create();
  Requisicao *r1 = make_req("X", 11, "AA");
  Requisicao *r2 = make_req("Y", 22, "BB");

  inserir(q, r1);
  Requisicao *out1 = remover(q);

  inserir(q, r2);
  Requisicao *out2 = remover(q);

  if (out1 == r1 && out2 == r2 && get_size(q) == 0) {
    printf("✔ test_intercalar passou\n");
  } else {
    printf("✘ test_intercalar falhou\n");
  }

  libera(out1);
  libera(out2);
  libera_estrutura(q);
}

void test_libera_com_elementos() {
  Estrutura *q = create();
  inserir(q, make_req("AA", 1, "PR1"));
  inserir(q, make_req("BB", 2, "PR2"));
  inserir(q, make_req("CC", 3, "PR3"));

  libera_estrutura(q);
  printf("✔ test_libera_com_elementos passou (estrutura liberada sem leak)\n");
}

void test_remover_null() {
  Requisicao *r = remover(NULL);
  if (r == NULL) {
    printf("✔ test_remover_null passou\n");
  } else {
    printf("✘ test_remover_null falhou\n");
  }
}

void test_remover_vazio() {
  Estrutura *q = create();
  Requisicao *r = remover(q);
  if (r == NULL && get_size(q) == 0) {
    printf("✔ test_remover_vazio passou\n");
  } else {
    printf("✘ test_remover_vazio falhou\n");
  }
  libera_estrutura(q);
}

void test_inserir_dados_grandes() {
  Estrutura *q = create();
  char nome[REQ_TAMANHO_NOME + 10];
  memset(nome, 'A', sizeof(nome));
  nome[REQ_TAMANHO_NOME - 1] = '\0';

  char proc[REQ_TAMANHO_PROCEDIMENTO + 5];
  memset(proc, 'B', sizeof(proc));
  proc[REQ_TAMANHO_PROCEDIMENTO - 1] = '\0';

  Requisicao *r = make_req(nome, 12345, proc);
  inserir(q, r);

  Requisicao *out = remover(q);
  if (strcmp(get_nome(out), nome) == 0 &&
      strcmp(get_procedimento(out), proc) == 0) {
    printf("✔ test_inserir_dados_grandes passou\n");
  } else {
    printf("✘ test_inserir_dados_grandes falhou\n");
  }

  libera(out);
  libera_estrutura(q);
}

// ---------- Main ----------
int main() {
  test_criar_e_liberar_vazia();
  test_inserir_remover_unico();
  test_inserir_remover_varios();
  test_intercalar();
  test_libera_com_elementos();
  test_remover_null();
  test_remover_vazio();
  test_inserir_dados_grandes();

  printf("\nTodos os testes executados.\n");
  return 0;
}
