#ifndef BUSCA_SEQUENCIAL_HPP
#define BUSCA_SEQUENCIAL_HPP

#include <vector>

// Algoritmo de Busca Sequencial.
bool busca_sequencial(std::vector<int> &vetor, int valor_alvo, int tamanho_vetor);

// Algoritmo de Busca Sequencial adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void busca_sequencial(std::vector<int> &vetor, int tamanho_vetor);

#endif