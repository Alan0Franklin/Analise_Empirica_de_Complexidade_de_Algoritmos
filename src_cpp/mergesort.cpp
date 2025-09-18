#include "mergesort.hpp"
#include "funcoes_uteis.hpp"

// Função para fundir os conjuntos no algoritmo do Merge Sort.
void merge(std::vector<int> &vetor, int esquerda, int meio, int direita){
    int n1 = meio - esquerda + 1, n2 = direita - meio;
    std::vector<int> E(n1), D(n2);
    for (int i = 0; i < n1; i++){E[i] = vetor[esquerda + i];}
    for (int j = 0; j < n2; j++){D[j] = vetor[meio + 1 + j];}
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2){
        if (E[i] <= D[j]){
            vetor[k] = E[i];
            i++;
        } 
        else{
            vetor[k] = D[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        vetor[k] = E[i];
        i++;
        k++;
    }
    while (j < n2){
        vetor[k] = D[j];
        j++;
        k++;
    }
}

// Algoritmo de ordenação Merge Sort.
void mergesort(std::vector<int> &vetor, int esquerda, int direita){
    if (esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;
        mergesort(vetor, esquerda, meio);
        mergesort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}

// Algoritmo de ordenação Merge Sort adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void mergesort(std::vector<int> &vetor, int tamanho_vetor){mergesort(vetor, 0, tamanho_vetor - 1);}