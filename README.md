Uma organização está construindo uma aplicação que recebe milhares de requisições para atendimento de saúde. Essas requisições possuem as seguintes informações:

- `Nome do Paciente` – uma string de 40 caracteres
- `Código de inscrição que o identifica no sistema de saúde` – um número de tipo inteiro
- `Código do procedimento solicitado` – uma string de 10 caracteres

Essas requisições precisam ser organizadas por ordem de chegada e são consumidas pela aplicação na medida que se consegue alocar o paciente na instituição que irá atendê-lo.

Assim, é necessário a criação de um TAD (Tipo abstrato de dados) que permita a inserção desta requisição, que será realizada quando ela chegar, e permita a remoção dela quando a aplicação conseguir alocá-la em uma instituição.

Outra característica necessária do TAD é fornecer a quantidade de requisições de espera, pois, conforme o tamanho, as instituições parceiras da organização também podem ser usadas para acelerar o processo de atendimento dos pacientes.

Ao final de sua elaboração, devem constar dois arquivos:
- O cabeçalho do TAD denominado estrutura.h
- A implementação do TAD com o código-fonte, denominado estrutura.c

A estrutura da requisição é fornecida pelos arquivos:
- requisicao.h
- requisicao.c

Para seus testes de validação de sua implementação, está sendo fornecido um exemplo de código com uma função main, que pode ser usada para verificar seu funcionamento: `teste.c`
