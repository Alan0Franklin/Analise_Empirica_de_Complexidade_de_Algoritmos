#include <iostream>
#include <algorithm>
#include <vector>
#include "funcoes_uteis.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "bubblesort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"

using namespace std;

int main(){
    vector<int> vetor = criador_vetor();
    int tamanho_vetor = vetor.size();
    imprimir_vetor(vetor, tamanho_vetor);
    long long saida;
    cout << endl;
    saida = cronometro_de_funcao(vetor, tamanho_vetor, selectionsort);
    cout << "Tempo de saida do Selectionsort deu: " << saida << " ms." << endl;
    saida = cronometro_de_funcao(vetor, tamanho_vetor, insertionsort);
    cout << "Tempo de saida do Insertionsort deu: " << saida << " ms." << endl;
    saida = cronometro_de_funcao(vetor, tamanho_vetor, bubblesort);
    cout << "Tempo de saida do Bubblesort deu: " << saida << " ms." << endl;
    saida = cronometro_de_funcao(vetor, tamanho_vetor, quicksort);
    cout << "Tempo de saida do Quicksort deu: " << saida << " ms." << endl;
    saida = cronometro_de_funcao(vetor, tamanho_vetor, mergesort);
    cout << "Tempo de saida do Mergesort deu: " << saida << " ms." << endl;
    return 0;
}