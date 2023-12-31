#include "./Funcoes/Arquivo/arquivo.h"
#include "./Funcoes/Binaria/insercaoBinaria.h"
#include "./Funcoes/Bolha/bolha.h"
#include "./Funcoes/BucketSort/bucketSort.h"
#include "./Funcoes/Direta/insercaoDireta.h"
#include "./Funcoes/HeapSort/heapSort.h"
#include "./Funcoes/Imprime/imprime.h"
#include "./Funcoes/MergeSort/mergeSort.h"
#include "./Funcoes/QuickSort/quickSort.h"
#include "./Funcoes/RadixSort/radixSort.h"
#include "./Funcoes/Selecao/selecao.h"
#include "./Funcoes/ShellSort/shellSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(int argc, char *argv[]) {

  if (argc != 4) {
    printf("Você deve fornecer exatamente 3 argumentos na execução.\n");
    printf("Deve seguir o padrão: \n./ordena bolha n entrada.txt.\n");
    printf("bolha -> Método de ordenação\n");
    printf("n -> O tamanho do vetor a ser ordenado\n");
    printf("entrada.txt -> Nome do banco de dados\n");
    exit(0);
  }

  char *metodo = argv[1];
  char *tamanho = argv[2];
  char *arquivo = argv[3];

  int tam = atoi(argv[2]);

  int V[tam];

  clock_t inicio, fim;
  double tempo_decorrido;

  if (strcmp(metodo, "bolha") == 0) {
    LeArquivo(V, tam, arquivo);
    ordenaBolha(V, tam);
  } else {
    if (strcmp(metodo, "insercaodireta") == 0) {
      LeArquivo(V, tam, arquivo);
      insercaoDireta(V, tam);
    } else {
      if (strcmp(metodo, "insercaobinaria") == 0) {
        LeArquivo(V, tam, arquivo);
        insercaoBinaria(V, tam);
      } else {
        if (strcmp(metodo, "shellsort") == 0) {
          LeArquivo(V, tam, arquivo);
          shellsort(V, tam);
        } else {
          if (strcmp(metodo, "selecaodireta") == 0) {
            LeArquivo(V, tam, arquivo);
            selecao(V, tam);
          } else {
            if (strcmp(metodo, "heapsort") == 0) {
              LeArquivo(V, tam, arquivo);
              heapSort(V, tam);
            } else {
              if (strcmp(metodo, "quicksortini") == 0) {
                LeArquivo(V, tam, arquivo);
                inicio = clock();
                int comparacoes = 0;
                int trocas = 0;

                quickSortIni(V, tam, 0, tam - 1, &comparacoes, &trocas);

                char nome[50];
                char aux[50] = "QuickSort/Inicio/";
                sprintf(nome, "QuickSortIni%d.txt", tam);
                fim = clock();
                tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                SalvarArquivoOrdenado(V, tam, nome, aux, tempo_decorrido, comparacoes, trocas);

                char metodo[50] = "Quick Sort Inicio";

                Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);
              } else {
                if (strcmp(metodo, "quicksortcentro") == 0) {
                  LeArquivo(V, tam, arquivo);
                  inicio = clock();
                  int comparacoes = 0;
                  int trocas = 0;

                  quickSortCentro(V, tam, 0, tam - 1, &comparacoes, &trocas);

                  char nome[50];
                  char aux[50] = "QuickSort/Centro/";
                  sprintf(nome, "QuickSortCentro%d.txt", tam);
                  fim = clock();
                  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                  SalvarArquivoOrdenado(V, tam, nome, aux, tempo_decorrido, comparacoes, trocas);

                  char metodo[50] = "Quick Sort Centro";

                  Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);
                } else {
                  if (strcmp(metodo, "quicksortmediana") == 0) {
                    LeArquivo(V, tam, arquivo);
                    inicio = clock();
                    int comparacoes = 0;
                    int trocas = 0;

                    quickSortMediana(V, tam, 0, tam - 1, &comparacoes, &trocas);

                    char nome[50];
                    char aux[50] = "QuickSort/Mediana/";
                    sprintf(nome, "QuickSortMediana%d.txt", tam);
                    fim = clock();
                    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                    SalvarArquivoOrdenado(V, tam, nome, aux, tempo_decorrido, comparacoes, trocas);

                    char metodo[50] = "Quick Sort Mediana";

                    Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);

                  } else {
                    if (strcmp(metodo, "mergesort") == 0) {
                      LeArquivo(V, tam, arquivo);

                      inicio = clock();
                      int comparacoes = 0;
                      int trocas = 0;

                      mergeSort(V, tam, 0, tam - 1, &comparacoes, &trocas);

                      char nome[50];
                      char aux[50] = "MergeSort/";
                      sprintf(nome, "MergeSort%d.txt", tam);
                      fim = clock();
                      tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                      SalvarArquivoOrdenado(V, tam, nome, aux, tempo_decorrido, comparacoes, trocas);

                      char metodo[50] = "MergeSort";

                      Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);
                    } else {
                      if (strcmp(metodo, "radixsort") == 0) {
                        LeArquivo(V, tam, arquivo);
                        inicio = clock();
                        int comparacoes = 0;
                        int trocas = 0;

                        radixSort(V, tam, &comparacoes, &trocas);

                        char nome[50];
                        char aux[50] = "RadixSort/";
                        sprintf(nome, "RadixSort%d.txt", tam);
                        fim = clock();
                        tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                        SalvarArquivoOrdenado(V, tam, nome, aux, tempo_decorrido, comparacoes, trocas);

                        char metodo[50] = "Radix Sort";

                        Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);
                      } else {
                        if (strcmp(metodo, "bucketsort") == 0) {
                          LeArquivo(V, tam, arquivo);
                          inicio = clock();
                          int comparacoes = 0;
                          int trocas = 0;

                          bucketSort(V, tam, &comparacoes, &trocas);

                          char nome[50];
                          char aux[50] = "BucketSort/";
                          sprintf(nome, "BucketSort%d.txt", tam);
                          fim = clock();
                          tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                          SalvarArquivoOrdenado(V, tam, nome, aux, tempo_decorrido, comparacoes, trocas);

                          char metodo[50] = "Bucket Sort";

                          Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);

                        } else {
                          printf("Algum dado foi passado errado!!!\n");
                          exit(0);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}