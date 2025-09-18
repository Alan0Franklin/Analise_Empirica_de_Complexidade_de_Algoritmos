#include "quicksort.hpp"
#include "funcoes_uteis.hpp"

// Função para particionar o vetor no algoritmo do Quick Sort.
int partition(std::vector<int> &vetor, int esquerda, int direita){
    int pivo = vetor[direita];
    int i = esquerda - 1;
    for (int j = esquerda; j <= direita - 1; j++){
        if (vetor[j] <= pivo){
            i++;
            trocar_de_posicao(vetor, i, j);
        }
    }
    trocar_de_posicao(vetor, i + 1, direita);
    return i + 1;
}

// Algoritmo de ordenação Quick Sort (ou Partition Sort).
void quicksort(std::vector<int> &vetor, int esquerda, int direita){
    if (esquerda < direita){
        int i_pivo = partition(vetor, esquerda, direita);
        quicksort(vetor, esquerda, i_pivo - 1);
        quicksort(vetor, i_pivo + 1, direita);
    }
}

// Algoritmo de ordenação Quick Sort adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void quicksort(std::vector<int> &vetor, int tamanho_vetor){quicksort(vetor, 0, tamanho_vetor - 1);}