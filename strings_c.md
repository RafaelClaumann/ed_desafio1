## Entendendo strncpy

```c
struct Requisicao {
    char nome[40];  // sizeof(r->nome) == 40
    ...
};

Requisicao *cria_requisicao(char *nome_, int inscricao_, char *procedimento_) {
    ...
    // strncpy(destino, fonte, size);
    strncpy(r->nome, nome_, sizeof(r->nome) - 1);
    r->nome[sizeof(r->nome) - 1] = '\0';
    ...
}
```

### `nome_` menor que o array
- `strncpy` copia todos os caracteres de nome_.
- `r->nome[39] = '\0'` garante que o último byte seja nulo (não altera nada neste caso, mas segura se a string fosse maior).
```c
char nome_[] = "Joao"; // 4 caracteres + '\0'

r->nome: [ J | o | a | o | \0 | ? | ? | ... ? ... ? ]  // 40 bytes
                            ^ string válida até '\0'
```

### `nome_` igual ou maior que o array
- `strncpy` copia no máximo sizeof(r->nome) - 1 = 39 bytes.
- A linha `r->nome[39] = '\0'` garante que o array termina com nulo, evitando overflow ou strings sem terminador.
```c
char nome_[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"; // > 40

r->nome: [ A | B | C | D | ... | X | \0 ]
                                      ^ string truncada em 39 caracteres
                                      ^ último byte (39) forçado a '\0'
```

### Resumo do comportamento
| Cenário                | Resultado em r->nome                  | Observação |
|------------------------|--------------------------------------|------------|
| `nome_` menor que 40    | Copia toda a string + `\0`          | Seguro |
| `nome_` >= 40           | Copia apenas 39 primeiros chars + `\0` | String truncada |
| Sempre                   | `r->nome[39] = '\0'`               | Garante terminador seguro |

### O que é o terminador ('\0')
- Em C, strings são arrays de char terminados por `'\0'` (o caractere nulo).
- `'\0'` tem valor zero (0x00) e indica o fim da string.
- Sem ele, funções de string (`strlen`, `strcpy`, `printf("%s")`, etc.) não sabem onde parar, podendo ler memória além do array
- É implícito em literais de string: `char s[] = "Hello";`

### Funções da biblioteca C
- `strlen()`        - Conta caracteres até encontrar '\0'
- `strcpy()`        - Copia até o '\0'
- `strcmp()`        - Compara caracteres até '\0'
- `printf("%s")`    - Imprime até encontrar '\0'