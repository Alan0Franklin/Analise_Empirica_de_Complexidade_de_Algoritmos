#ifndef FUNCOES_UTEIS_HPP
#define FUNCOES_UTEIS_HPP

#include <string>
#include <vector>
#include <functional>

// Função para ler um número inteiro do terminal.
int ler_inteiro(std::string mensagem_erro, int lim_inf, int lim_sup);

// Função para criar o vetor à ser analisado.
std::vector<int> criador_vetor();

// Função para imprimir os elementos dos vetores no terminal.
void imprimir_vetor(std::vector<int> &vetor, int tamanho_vetor);

// Função para trocar a posição de dois elementos em um vetor.
void trocar_de_posicao(std::vector<int> &vetor, int id1, int id2);

// Função para cronometrar os tempos de execução de um dado algoritmo de ordenação.
long long cronometro_de_funcao(std::vector<int> &vetor, int tamanho_vetor, std::function<void(std::vector<int> &vetor, int tamanho_vetor)> func);

// Função para verificar se o arquivo existe.
bool arquivo_existe(const std::string &nome_arquivo);

// Função para escrever as saídas em um arquivo.
bool registrar_no_arquivo(const std::string &nome_arquivo, int n, std::vector<std::string> &nome_algoritmos, std::vector<long long> &tempos_de_exec);

#endif