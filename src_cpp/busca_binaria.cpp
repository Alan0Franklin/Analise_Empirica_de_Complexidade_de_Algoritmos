#include "busca_binaria.hpp"

int busca_binaria(std::vector<int> &vetor, int valor_alvo, int tamanho_vetor) {
    int lim_inf = 0, lim_sup = tamanho_vetor - 1;
    while(lim_inf <= lim_sup){
        int n = (lim_sup + lim_inf)/ 2;
        if (vetor[n] == valor_alvo){return vetor[n];}
        else if(vetor[n] > valor_alvo){lim_sup = n - 1;}
        else{lim_inf = n + 1;}
    }
    return -1;
}