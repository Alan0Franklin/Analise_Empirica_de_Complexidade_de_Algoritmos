# Analise_Empirica_de_Complexidade_de_Algoritmos

Para adicionar outro algoritmo ao programa, basta adicionar o código cpp na pasta src_cpp e o hpp na pasta include_hpp.

Na Main:

- Se o seu algoritmo tiver a mesma formatação que a função cronometrar_função:
  Você fará o include necessário (#include "nome_do_algoritmo.hpp") e adicionará:

  tempos_de_exec[X] = cronometro_de_funcao(vetor, tamanho_vetor, nome_do_algoritmo);
  cout << "Tempo de saida do nome_do_algoritmo deu: " << tempos_de_exec[X] << " microsegundos." << endl;

  onde X é um número que segue a sequencia já presente no código.

- Se o seu algoritmo não tiver a mesma formatação que a função cronometrar_função:
  no seu código cpp, para adapta-lo ao formato exigido pela função cronometrar_função, você terá que adicionar no fim dele:

  -Para casos de algoritmos de busca:
   void nome_do_algoritmo2(std::vector<int> &vetor, int tamanho_vetor){nome_do_algoritmo(vetor, tamanho_vetor, tamanho_vetor);} 

  -Para casos de algoritmos de ordenação:
   void nome_do_algoritmo2(std::vector<int> &vetor, int tamanho_vetor){nome_do_algoritmo(vetor, 0, tamanho_vetor - 1);}

Obs: caso você não queira mudar o nome da função, terá que utilizar sobrecarga. Na Main, utilizará o código:

  tempos_de_exec[X] = cronometro_de_funcao(vetor, tamanho_vetor, static_cast<void(*)(vector<int>&, int)>(nome_do_algoritmo));
  cout << "Tempo de saida do nome_do_algoritmo deu: " << tempos_de_exec[X] << " microsegundos." << endl;

  onde X é um número que segue a sequencia já presente no código.

