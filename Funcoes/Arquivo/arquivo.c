#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeArquivo(int *V, int tam, char metodo[50]) {
  FILE *arq;
  char caminho[50] = "./Dados/";
  strcat(caminho, metodo);
  arq = fopen(caminho, "r");
  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo\n");
  } else {
    for (int i = 0; i < tam; i++) {
      fscanf(arq, "%d\n", &V[i]);
    }
    fclose(arq);
  }
}

void SalvarArquivoOriginal(int *V, int tam, char *nome) {
  FILE *arq;
  char caminho[50] = "./Dados/";
  strcat(caminho, nome);
  arq = fopen(caminho, "w");

  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    for (int i = 0; i < tam; i++) {
      fprintf(arq, "%d", V[i]);
      if (i < tam - 1)
        fprintf(arq, "\n");
    }
    fclose(arq);
  }
}

void SalvarArquivoOrdenado(int *V, int tam, char *nome, char *aux, double time, int comparacoes, int trocas) {
  FILE *arq;

  char caminho[50] = "./Saidas/";
  strcat(caminho, aux);
  strcat(caminho, nome);
  arq = fopen(caminho, "w");

  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    for (int i = 0; i < tam; i++) {
      fprintf(arq, "%d", V[i]);
      if (i < tam - 1)
        fprintf(arq, "\n");
    }
    fprintf(arq, "\n\nTempo decorrido: %f", time);
    fprintf(arq, "\nComparações: %d", comparacoes);
    fprintf(arq, "\nTrocas: %d", trocas);
    fclose(arq);
  }
}

void Relatorios(int tam, char nome[], double time, int comparacoes, int trocas) {

  FILE *arq;

  char caminho[50] = "./Relatorios/Relatorio.txt";
  arq = fopen(caminho, "a");

  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    fprintf(arq, "\nMédodo %s, Quantidade %d\n", nome, tam);
    fprintf(arq, "Tempo decorrido: %f\n", time);
    fprintf(arq, "Comparações: %d\n", comparacoes);
    fprintf(arq, "Trocas: %d", trocas);
    fclose(arq);
  }
}