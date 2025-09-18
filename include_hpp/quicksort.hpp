#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

// Função para particionar o vetor no algoritmo do Quick Sort.
int partition(std::vector<int> &vetor, int esquerda, int direita);

// Algoritmo de ordenação Quick Sort (ou Partition Sort).
void quicksort(std::vector<int>& vetor, int esquerda, int direita);

// Algoritmo de ordenação Quick Sort adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void quicksort(std::vector<int> &vetor, int tamanho_vetor);

#endif