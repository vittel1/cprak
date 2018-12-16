#include <stdio.h>
#include <stdlib.h>

void ptr_info (int **ppi) {
  printf("Adresse vom Pointer: %p\n", (void*)ppi);
  printf("Pointerinhalt: %p\n", (void*)*ppi);
  printf("Wert auf den Pointer verweist: %p\n", *ppi);
}

int main (int argc, char** argv) {
  int i = 5;
  int *pi = &i;

  int **ppi = &pi;
  ptr_info(ppi);
  return 0;
}
