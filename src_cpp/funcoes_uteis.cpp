#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <limits>
#include <chrono>
#include "funcoes_uteis.hpp"

using namespace std;
using namespace std::chrono;

// Função para ler um número inteiro do terminal.
int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup){
    float hold;
    while (true){
        cin >> hold;
        /* 1) Se houve erro de conversão (ex.: letra, vazio, etc.);
        Isso pode acontecer quando o usuário digita letras, caracteres especiais, espaços em branco ou quando pressiona Enter sem digitar nada.
        */
        if (cin.fail()){
            cout << "> Error: Entrada invalida!" << endl << mensagem_erro;
            cin.clear(); // reseta o estado de erro do stream de entrada.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta todos os caracteres restantes até encontrar uma quebra de linha. esse numeric_limits é para dizer que limpe o máximo possível (tudo).
            continue; // retorna ao início do loop para solicitar uma nova entrada válida.
        }

        /* 2) Se o número está fora da faixa exigida;
        Verifica se a quantidade informada está dentro do intervalo permitido.
        Se estiver fora desse intervalo, exibe uma mensagem de erro e solicita uma nova entrada através do continue, que retorna ao início do loop.
        */
        if (hold != (int) hold || ((hold < lim_inf || hold > lim_sup) && lim_inf != lim_sup)){
            cout << "> Error: Numero invalido!" << endl << mensagem_erro;
            continue; // volta para o início do loop para solicitar uma nova entrada válida.
        }
        break;
    }
    return hold;
}

// Função para criar o vetor à ser analisado.
vector<int> criador_vetor(){
    cout << "> Digite o tamanho do vetor que deseja: ";
    int tamanho_vetor = ler_inteiro("> Digite o numero do tamanho que voce deseja que o vetor tenha: ", 0, 0);
    vector<int> vetor(tamanho_vetor);   // vetor à ser criado.
    random_device rd;  // gerador de seed aleatória. Em alguns sistemas (especialmente Windows com algumas versões de compiladores), não é realmente aleatório.
    mt19937 gen(rd()); // gerador Mersenne Twister.
    for (int i = 0; i < tamanho_vetor; i++){vetor[i] = i + 1;}
    shuffle(vetor.begin(), vetor.end(), gen);
    cout << "=== // ===" << endl;
    return vetor;
}

// Função para imprimir os elementos dos vetores no terminal.
void imprimir_vetor(vector<int> &vetor, int tamanho_vetor){
    cout << "> Vetor:";
    cout << "{";
    for (int i = 0; i < tamanho_vetor; i++){
        if (i != 0){cout << ", ";}
        cout << vetor[i];
    }
    cout << '}' << endl;
}

// Função para comparar os algoritmos de ordenação em relação à um vetor dado.
long long cronometro_de_funcao(vector<int> &vetor, int tamanho_vetor, std::function<void(std::vector<int> &vetor, int tamanho_vetor)> func){
    vector<int> v = vetor;
    auto start = high_resolution_clock::now();
    func(v, tamanho_vetor);
    auto end = high_resolution_clock::now();
    long long tempo_de_execucao = duration_cast<microseconds>(end - start).count();
    imprimir_vetor(v, tamanho_vetor);
    return tempo_de_execucao;
}

// Função para trocar a posição de dois elementos em um vetor.
void trocar_de_posicao(vector<int> &vetor, int id1, int id2){
    int hold = vetor[id1];
    vetor[id1] = vetor[id2];
    vetor[id2] = hold;
}