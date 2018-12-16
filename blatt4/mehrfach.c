#include <stdio.h>
#include <stdlib.h>

void ptr_info(int **ppi, int *pi) {
  printf("Adresse vom Pointer: %p\n", &pi);
  printf("Pointerinhalt: %p\n", *ppi);
  printf("Wert auf den Pointer verweist: %d\n", *pi);
}

int main (int argc, char** argv) {
  int i = 5;
  int *pi = &i;

  int **ppi = &pi;
  ptr_info(ppi, pi);
  return 0;
}
