#ifndef BUSCA_BINARIA_HPP
#define BUSCA_BINARIA_HPP

#include <vector>

// Algoritmo de Busca Binário.
bool busca_binaria(std::vector<int> &vetor, int valor_alvo, int tamanho_vetor);

// Algoritmo de Busca Binário adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void busca_binaria(std::vector<int> &vetor, int tamanho_vetor);

#endif