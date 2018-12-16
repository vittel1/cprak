#include <stdio.h>
#include <stdlib.h>

void ptr_info (int **ppi) {
  printf("Adresse vom Pointer: %p\n", (void*)ppi);
  printf("Pointerinhalt: %p\n", (void*)*ppi);
  printf("Wert auf den Pointer verweist: %d\n", **ppi);
}

void set_to_1(int *pi) {
  *pi = 1;
  ptr_info(&pi);
}

void set_to_2(int **ppi) {
  **ppi = 2;
  ptr_info(ppi);

}

int main (int argc, char** argv) {
  int i = 5;
  //Adresse vom i
  int *pi = &i;
  //Adresse vom Pointer
  int **ppi = &pi;
  
  ptr_info(ppi);
  printf("----------------------\n");

  set_to_1(pi);

  printf("----------------------\n");
  set_to_2(&pi);

  return 0;
}
