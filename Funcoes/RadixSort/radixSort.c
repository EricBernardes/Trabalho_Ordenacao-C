#include <stdio.h>
#include <stdlib.h>

int findMax(int *v, int n) {
  int max = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  return max;
}

void countingSort(int *v, int n, int exp, int *comparacoes, int *trocas) {
  const int range = 10;
  int output[n];
  int count[range];

  for (int i = 0; i < range; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    (*comparacoes)++;
    count[(v[i] / exp) % 10]++;
  }

  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(v[i] / exp) % 10] - 1] = v[i];
    count[(v[i] / exp) % 10]--;
    (*trocas)++;
  }

  for (int i = 0; i < n; i++) {
    v[i] = output[i];
    (*trocas)++;
  }
}

void radixSort(int *v, int n, int *comparacoes, int *trocas) {
  int max = findMax(v, n);

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(v, n, exp, comparacoes, trocas);
  }
}
