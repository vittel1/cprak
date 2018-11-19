#include <stdio.h>

enum status{
  FOO,
  BAR
};

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

  enum status a;

};

int main(void) {

  printf("struct foobar: %lu\n", sizeof(struct foobar));

  struct foobar c;
  c.a = FOO;
  printf("foo aktiv: %d\n", c.a);

  c.a = BAR;
  printf("bar aktiv: %d\n", c.a);

  return 0;
}
