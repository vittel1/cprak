#include <stdio.h>
#include <string.h>

void string_concat (char out[],char string1[], char string2[]) {

  int laenge1 = strlen(string1);
  //printf("Laenge String1: %d\n", laenge1);
  int laenge2 = strlen(string2);
  //printf("Laenge String2: %d\n", laenge2);
  int laenge_gesamt = laenge1 + laenge2;

  for (int i = 0; i < laenge_gesamt; i++) {
      out[i] = string1[i];
  }

  for (int i = 0; i < laenge_gesamt; i++) {
      out[laenge1+i] = string2[i];
  }

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
