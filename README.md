# Análise Empírica de Complexidade de Algoritmos

Um programa desenvolvido com a capacidade de coletar tempos de execução para diferentes tamanhos de entrada.

## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição das Funções](#2-descricao_das_funcoes)

---

## Estrutura <a name="1-estrutura"></a>
```
Analise_Empirica_de_Complexidade_de_Algoritmos/
├── include_cpp/
│   ├── bubblesort.hpp
│   ├── busca_binaria.hpp
│   ├── busca_sequencial.hpp
│   ├── funcoes_uteis.hpp
│   ├── insertionsort.hpp
│   ├── mergesort.hpp
│   ├── quicksort.hpp
│   └── selectionsort.hpp
├── src_cpp/
│   ├── bubblesort.cpp
│   ├── busca_binaria.cpp
│   ├── busca_sequencial.cpp
│   ├── funcoes_uteis.cpp
│   ├── insertionsort.cpp
│   ├── main.cpp
│   ├── mergesort.cpp
│   ├── quicksort.cpp
│   └── selectionsort.cpp
├── Graficos_da_Analise_Empirica_de_Complexidade_de_Algoritmos.ipynb
├── Makefile
├── README.md
└── Registro_-_Tempos_de_Execucao.csv
```

## Descrição das Funções <a name="2-descricao_das_funcoes"></a>

### + int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup)
Função para ler um número inteiro do terminal, bloqueando qualquer entrada que não seja um inteiro. Após validar que a entrada é um número inteiro, verifica-se se o valor pertence ao intervalo fechado \[`lim_inf`, `lim_sup`]. Se pertencer, a função retorna esse valor e é finalizada. Caso contrário, a `mensagem_erro` será exibida e um novo valor deverá ser inserido até que seja uma entrada válida. Se `lim_inf` e `lim_sup` forem iguais, o intervalo para conferência do valor principal será \[-∞, +∞]
- `mensagem_erro`: String correspondente à mensagem de erro que deve ser exposta caso um valor não inteiro seja recebido do dispositivo de entrada.
- `lim_inf`: Inteiro correspondente ao primeiro número de um intervalo fechado o qual o valor que deve pertencer.
- `lim_inf`: Inteiro correspondente ao último número de um intervalo fechado o qual o valor que deve pertencer.

### + vector\<int> criador_vetor()
Função que cria e retorna um vetor aleatoriamente ordenado de inteiros. Ela solicita um número inteiro que define o tamanho desejado do vetor. Em seguida, é gerado um vetor de inteiros que corresponde ao intervalo fechado \[`lim_inf`, `lim_sup`]. Os elementos desse vetor são espalhados aleatoriamente com ajuda da biblioteca `random`.

### + void imprimir_vetor(vector\<int> &vetor, int tamanho_vetor)
Função para imprimir o `vetor` recebido no terminal.
- `vetor`: Vetor de inteiros que deseja ser impresso no terminal.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do `vetor`.

### + void trocar_de_posicao(vector\<int> &vetor, int id1, int id2)
Função que troca a posição dos elementos do `vetor` nos índices `id1` e `id2`.
- `vetor`: Vetor de inteiros que deseja ter elementos trocados.
- `id1`: Índice do primeiro número que deseja ser trocado de posição com o número em `id2`.
- `id2`: Índice do segundo número que deseja ser trocado de posição com o número em `id1`.

### + long long cronometro_de_funcao(std::vector<int> &vetor, int tamanho_vetor, std::function<void(std::vector<int> &vetor, int tamanho_vetor)> func);
Função para cronometrar os tempos de execução em nanosegundos de um dado algoritmo do tipo `void(std::vector<int> &vetor, int tamanho_vetor)>`. Ou seja, a `func` passada como parâmetro desta função - a fim de ser cronometrada - deve aceitar como tipos de argumentos um `vetor` de inteiros e o `tamanho_vetor` inteiro dele e devem ter como tipo de retorno o `void` (nenhum valor retornado). Caso o algoritmo que deseja-se cronometrar não tiver essa tipagem, uma versão adaptada desse algoritmo deve ser implementado seguindo esse padrão. Caso uma versão adaptada de uma função for criada com o mesmo nome, mas com diferentes listas de parâmetros (tipos ou número de argumentos), o compilador consegue distinguir qual função chamar em tempo de compilação - essa é a definição de sobrecarga de funções em C++ -. Entretanto, se a `func` tiver uma mesma assinatura que outra função - o que seria uma aplicação dessa sobrecarga -, deve-se passar para a função a especificação do tipo da função: `static_cast<void(*)(vector<int>&, int)>(func)`. Somente assim o programa será compilado sem apresentar erros. Lembre-se também de incluir o header da sua função no `main.cpp` para que o programa reconheça a função, "`#include "nome_do_header_da_função.hpp"`" :P.
- `vetor`: Vetor de inteiros que será passado para a `func`.
- `tamanho_vetor`: Inteiro correspondente ao tamanho do `vetor`. Deve aceitar como tipos de argumentos um `vetor` de inteiros e o `tamanho_vetor` inteiro dele e devem ter como tipo de retorno o `void` (nenhum valor retornado).
- `func`: Função que deseja-se ter seu tempo de execução cronometrado.

### + bool arquivo_existe(const std::string &nome_arquivo);
Função para verificar se um dado arquivo existe.
- `nome_arquivo`: String correspondente ao nome do arquivo que deseja-se verificar se existe ou não.

### + bool registrar_no_arquivo(const std::string &nome_arquivo, int n, std::vector<std::string> &nome_algoritmos, std::vector<long long> &tempos_de_exec);
Função para registrar as saídas dos algoritmos ao final de um arquivo, pensado para a formatação do `.csv`. Caso o arquivo `nome_arquivo` não exista, ele criará um novo com o cabeçalho já incluso.
- `nome_arquivo`: String correspondente ao nome do arquivo que manterá o registro dos tempos de execução dos algoritmos.
- `n`: Inteiro correspondente à quantidade de entradas que os algoritmos receberam.
- `nome_algoritmos`: Vetor de strings correspondente aos nomes dos algoritmos que terão seus tempos de execução registrados.
- `tempos_de_exec`: Vetor de inteiros grandes correspondente aos tempos de execução dos algoritmos que serão registrados.
