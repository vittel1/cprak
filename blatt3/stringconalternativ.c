#include <stdio.h>
#include <string.h>

void string_concat (char out[],char string1[], char string2[]) {

  if(string1)
    while (*string1)
      *out++=*string1++;
  if(string2)
    while(*string2)
      *out++=*string2++;
  *out=0;

}

int main (void) {

  char out[128] = { '\0' };
  printf("---Hello und World--- \n");
  string_concat(out, "Hello", "World");
  printf("%s\n", out);

  char out2[128] = { '\0' };
  printf("---Leer und Leer--- \n");
  string_concat(out2, "", "");
  printf("%s\n", out2);

  char out3[128] = { '\0' };
  printf("---Leer und World--- \n");
  string_concat(out3, "", "World");
  printf("%s\n", out3);

  char out4[128] = { '\0' };
  printf("---Hello und Leer--- \n");
  string_concat(out4, "Hello", "");
  printf("%s\n", out4);

  char out5[128] = { '\0' };
  printf("---Marcel und Super--- \n");
  string_concat(out5, "Marcel", "Super");
  printf("%s\n", out5);

  return 0;
}
