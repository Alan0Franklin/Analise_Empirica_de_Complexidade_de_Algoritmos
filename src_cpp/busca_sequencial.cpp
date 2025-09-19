#include "busca_sequencial.hpp"

// Algoritmo de Busca Sequencial.
bool busca_sequencial(std::vector<int> &vetor, int valor_alvo, int tamanho_vetor){
    for (int i = 0; i < tamanho_vetor; i++){if (vetor[i] == valor_alvo){return true;}}
    return false;
}

// Algoritmo de Busca Sequencial adaptado para std::function<void(std::vector<int> &vetor, int tamanho_vetor)>.
void busca_sequencial(std::vector<int> &vetor, int tamanho_vetor){busca_sequencial(vetor, tamanho_vetor/3, tamanho_vetor);}
