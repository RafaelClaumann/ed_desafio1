#include <stdio.h>

int main() {
  char list[5] = {'a', 'b', 'c', 'd', 'e'};

  // point aponta para o primeiro elemento de list
  char *point = list;
  printf("O list[0] = [ %c ] que é igual *point = [ %c ]\n", list[0], *point);

  printf("\n");

  // list[2] é a mesma coisa que *(point + 2)
  printf("O terceiro elemento do vetor é : %c\n", list[2]);
  printf("O terceiro elemento do vetor é : %c\n", *(point + 2));

  printf("\n");

  // alterando o conteúdo de list[2] usando pointer
  *(point + 2) = 'J';
  printf("O terceiro elemento do vetor é : %c\n", list[2]);
  printf("O terceiro elemento do vetor é : %c\n", *(point + 2));

  printf("\n");

  // desmontrando que também é possível alterar usando a lista com indice
  // lembre-se que: *nome_variavel é igual a nome_variavel[0]
  list[2] = 'K';
  printf("O terceiro elemento do vetor agora é : %c\n", list[2]);
  printf("O terceiro elemento do vetor agora é : %c\n", *(point + 2));

  printf("\n");

  // obtendo o endereço de list[2], ou seja, (point + 2)
  printf("O endereço do terceiro elemento do vetor é : %p\n", &list[2]);
  printf("O endereço do terceiro elemento do vetor é : %p\n", (point + 2));

  return 0;
}
