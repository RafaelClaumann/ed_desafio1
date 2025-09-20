#!/bin/sh

if [ "$1" = "x" ]; then
    echo -e "Usando arquivo test_estrutura.c \n"
    gcc -Wall -Wextra ./test/teste_estrutura.c ./src/requisicao.c ./src/estrutura.c -o output && ./output
else
    echo -e "Usando arquivo test_senai.c \n"
    gcc -Wall -Wextra ./test/teste_senai.c ./src/requisicao.c ./src/estrutura.c -o output && ./output
fi

rm -r output
