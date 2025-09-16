#include "busca_sequencial.hpp"

int busca_sequencial(std::vector<int> &vetor, int valor_alvo, int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++){if (vetor[i] == valor_alvo){return valor_alvo;}}
    return -1;
}