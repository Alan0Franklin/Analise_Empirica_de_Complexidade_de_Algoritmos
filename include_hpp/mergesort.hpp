#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>

// Função para fundir os conjuntos no algoritmo do Merge Sort.
void merge(std::vector<int> &vetor, int esquerda, int meio, int direita);

// Algoritmo de ordenação Merge Sort.
void mergesort(std::vector<int> &vetor, int esquerda, int direita);

// Algoritmo de ordenação Merge Sort adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void mergesort(std::vector<int> &vetor, int tamanho_vetor);

#endif