#include "bubblesort.hpp"
#include "funcoes_uteis.hpp"

// Algoritmo de ordenação Bubble Sort.
void bubblesort(std::vector<int> &vetor, int tamanho_vetor){
    bool loop;
    for (int lim_sup = 0; tamanho_vetor - lim_sup > 1; lim_sup++){
        loop = false;
        for (int i = 0; i < tamanho_vetor - lim_sup - 1; i++){
            if (vetor[i] > vetor[i + 1]){
                trocar_de_posicao(vetor, i, i + 1);
                loop = true;
            }
        }
        if (loop == false){break;}
    }
}