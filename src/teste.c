#include "requisicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main() {

  Requisicao *r = cria_requisicao("Rafael", 123, "PROC2");

  printf("Nome: %s\n", get_nome(r));
  printf("Inscrição: %i\n", get_inscricao(r));
  printf("Procedimento: %s\n", get_procedimento(r));

  libera(r);
  return EXIT_SUCCESS;
}
