#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point_t {
  double x;
  double y;
};

double distance(struct point_t *p1, struct point_t *p2) {
    return (sqrt(pow ((p2->y - p1->y),2))+(pow ((p2->x - p1->x),2)));
}


int main() {
  struct point_t a = {3.0, 4.0};
  struct point_t b = {10.0, 4.0};

  //Werte von Struct a anzeigen
  printf("Werte struct a: %f %f\n", a.x, a.y);

  struct point_t *ptra = &a;
  struct point_t *ptrb = &b;

  //Auf Werte zugreifen mit Pointer
  printf("Werte von Struct a: %f %f\n", ptra->x, (*ptra).y);

  double x = distance(ptra, ptrb);

  printf("Entfernung: %f\n", x);

  return 0;
}
