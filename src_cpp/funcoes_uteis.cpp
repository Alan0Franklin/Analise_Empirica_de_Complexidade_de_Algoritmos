#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <algorithm>
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
vector<int> criador_vetor(int tamanho_vetor){
    //cout << "> Digite o tamanho do vetor que deseja: ";
    //int tamanho_vetor = ler_inteiro("> Digite o numero do tamanho que voce deseja que o vetor tenha: ", 0, 0);
    vector<int> vetor(tamanho_vetor);   // vetor à ser criado.
    random_device rd;  // gerador de seed aleatória. Em alguns sistemas (especialmente Windows com algumas versões de compiladores), não é realmente aleatório.
    mt19937 gen(rd()); // gerador Mersenne Twister.
    for (int i = 0; i < tamanho_vetor; i++){vetor[i] = i + 1;}
    shuffle(vetor.begin(), vetor.end(), gen);
    //cout << "=== // ===" << endl;
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

// Função para trocar a posição de dois elementos em um vetor.
void trocar_de_posicao(vector<int> &vetor, int id1, int id2){
    int hold = vetor[id1];
    vetor[id1] = vetor[id2];
    vetor[id2] = hold;
}

// Função para cronometrar os tempos de execução de um dado algoritmo.
long long cronometro_de_funcao(vector<int> &vetor, int tamanho_vetor, function<void(vector<int> &vetor, int tamanho_vetor)> func){
    vector<int> v = vetor;
    auto start = high_resolution_clock::now();
    func(v, tamanho_vetor);
    auto end = high_resolution_clock::now();
    long long tempo_de_execucao = duration_cast<nanoseconds>(end - start).count();
    return tempo_de_execucao;
}

// Função para verificar se o arquivo existe.
bool arquivo_existe(const string &nome_arquivo){
    struct stat buffer;
    return (stat(nome_arquivo.c_str(), &buffer) == 0);
}

// Função para escrever as saídas em um arquivo.
bool registrar_no_arquivo(const string &nome_arquivo, int n, vector<string> &nome_algoritmos, vector<long long> &tempos_de_exec){
    bool arquivo_existia = arquivo_existe(nome_arquivo); // Verifica se o arquivo já existia antes
    ofstream arquivo(nome_arquivo, ios::app); // Abre o arquivo para escrita. Se não existir, será criado.

    if (!arquivo.is_open()) { // Verifica se o arquivo foi aberto corretamente.
        cerr << "Erro ao abrir ou criar o arquivo!" << endl;
        return false;
    }

    int qnt_algoritmos = nome_algoritmos.size();
    if (!arquivo_existia){ // Se o arquivo não existia antes, acabou de ser criado: escreva o cabeçalho.
        arquivo << "n";
        for (int i = 0; i < qnt_algoritmos; i++){
            arquivo << ";" << nome_algoritmos[i];
        }
        arquivo << "\n";
    }

    arquivo << n;
    for (int i = 0; i < qnt_algoritmos; i++){ // Escrevendo dados no final do arquivo.
        arquivo << ";" << tempos_de_exec[i];
    }
    arquivo << "\n";

    arquivo.close(); // Fecha o arquivo.

    //cout << "Dados adicionados ao arquivo " << nome_arquivo << " com sucesso!" << endl;
    return true;
}
