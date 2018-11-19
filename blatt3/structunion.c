#include <stdio.h>

struct foobar {

  union {
    struct foo {
      int a;
      int b;
    } a1;

    struct bar {
      float a;
      float b;
    } b1;
  };
};

int main(void) {

  printf("struct foobar größe: %lu\n", sizeof(struct foobar));

  struct foobar c = {.a1.a = 23, .a1.b=24};
  printf("%d und %d \n", c.a1.a, c.a1.b);

  struct foobar d = {.b1.a = 23.0, .b1.b = 42.0};
  printf("%f und %f \n", d.b1.a, d.b1.b);

  return 0;
}
