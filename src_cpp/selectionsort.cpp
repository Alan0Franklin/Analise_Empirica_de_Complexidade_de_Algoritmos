#include "selectionsort.hpp"
#include "funcoes_uteis.hpp"

// Algoritmo de ordenação Selection Sort.
void selectionsort(std::vector<int> &vetor, int tamanho_vetor){
    for (int id_valor_atual = 0, id_valor_menor; id_valor_atual < tamanho_vetor - 1; id_valor_atual++){
        id_valor_menor = id_valor_atual;
        for (int i = id_valor_atual + 1; i < tamanho_vetor; i++){if (vetor[id_valor_atual] > vetor[i] && vetor[id_valor_menor] > vetor[i]){id_valor_menor = i;}}
        trocar_de_posicao(vetor, id_valor_menor, id_valor_atual);
    }
}