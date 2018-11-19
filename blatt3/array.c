#include <stdio.h>
#include <string.h>

//array test
int main(void) {

  char out[3] = { '1', '2', '3' };

  printf("%c\n", out[0]);
  printf("%c\n", out[1]);
  printf("%c\n", out[2]);
  printf("%c\n", out[3]);
  printf("%ld\n", strlen(out));
  return 0;

}
