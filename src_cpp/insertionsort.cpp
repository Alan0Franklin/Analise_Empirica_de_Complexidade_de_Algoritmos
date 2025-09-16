#include "insertionsort.hpp"
#include "funcoes_uteis.hpp"

// Algoritmo de ordenação Insertion Sort.
void insertionsort(std::vector<int> &vetor, int tamanho_vetor){
    for (int id_valor_atual = 1; id_valor_atual < tamanho_vetor; id_valor_atual++){
        for (int i = id_valor_atual; i > 0; i--){
            if (vetor[i] < vetor[i - 1]){trocar_de_posicao(vetor, i - 1, i);}
            else{break;}
        }
    }
}