#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "funcoes_uteis.hpp"
#include "busca_sequencial.hpp"
#include "busca_binaria.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "bubblesort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"

using namespace std;

int main(){
    vector<int> vetor = criador_vetor(); // Cria um vetor aleatório de n entradas
    int tamanho_vetor = vetor.size(); // Tamanho do Vetor
    vector<string> nome_algoritmos = {"Bubble Sort", "Merge Sort", "Busca Sequencial", "Busca Binaria"};
    vector<long long> tempos_de_exec(4);

    tempos_de_exec[0] = cronometro_de_funcao(vetor, tamanho_vetor, bubblesort);
    cout << "Tempo de saida do Bubblesort deu: " << tempos_de_exec[0] << " nanosegundos." << endl;

    tempos_de_exec[1] = cronometro_de_funcao(vetor, tamanho_vetor, static_cast<void(*)(vector<int>&, int)>(mergesort));
    cout << "Tempo de saida do Mergesort deu: " << tempos_de_exec[1] << " nanosegundos." << endl;

    sort(vetor.begin(), vetor.end());
    tempos_de_exec[2] = cronometro_de_funcao(vetor, tamanho_vetor, static_cast<void(*)(vector<int>&, int)>(busca_sequencial));
    cout << "Tempo de saida do Busca Sequencial deu: " << tempos_de_exec[2] << " nanosegundos." << endl;

    tempos_de_exec[3] = cronometro_de_funcao(vetor, tamanho_vetor, static_cast<void(*)(vector<int>&, int)>(busca_binaria));
    cout << "Tempo de saida do Busca Binaria deu: " << tempos_de_exec[3] << " nanosegundos." << endl;

    registrar_no_arquivo("Registro_-_Tempos_de_Execucao.csv", tamanho_vetor, nome_algoritmos, tempos_de_exec);
    return 0;
}
