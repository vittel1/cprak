#include <stdio.h>
#include <stdlib.h>

void ptr_info(int **ppi, int *pi) {
  printf("Adresse vom Pointer: %p\n", &pi);
  printf("Pointerinhalt: %p\n", *ppi);
  printf("Wert auf den Pointer verweist: %d\n", *pi);
}

void set_to_1(int *pi) {
  //*ptr1 = 1;
  //ptr_info(&ptr1);
  *pi = 1;
  int **ppi = &pi;
  ptr_info(ppi, pi);
}

void set_to_2(int **ppi) {
  //**ptr2 = 2;
  //ptr_info(ptr2);
  **ppi = 2;
  int *pi = *ppi;
  ptr_info(ppi, pi);
}

int main (int argc, char** argv) {
  int i = 5;
  printf("wert von i nach initialisierung: %d\n", i);
  printf("----------------------\n");
  //Adresse vom i
  int *pi = &i;
  //Adresse vom Pointer
  int **ppi = &pi;
  ptr_info(ppi, pi);
  printf("----------------------\n");

  set_to_1(pi);
  printf("wert nach änderung auf 1: %d\n", i);
  printf("----------------------\n");

  set_to_2(&pi);
  printf("wert nach änderung auf 2: %d\n", i);
  printf("----------------------\n");

  return 0;
}
