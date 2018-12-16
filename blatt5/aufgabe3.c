#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double max(double x, double y) {
  if(x<=y) {
    return y;
  }
  else {
    return x;
  }
}

double f(double x, double y) {
	return x*y;
}

double g(double x, double y) {
	return sin(x)*sin(y);
}

double h(double x, double y) {
	return max(x,y);
}

void print2dArray(size_t height, size_t width, double data[height][width]) {

	for(size_t y = 0; y < height; y++) {
		for(size_t x = 0; x < width; x++) {
			printf("%f ", data[y][x]);
		}
    printf("\n");
	}
}

void fillMatrixWithResults(size_t height,double y_min, double y_max, size_t width, double x_min, double x_max, double data[height][width], double (*foo)(double x, double y)) {

	double xGrowth = ((x_max-x_min)/(width-1));
	double yGrowth = ((y_max-y_min)/(height-1));
	double x;
	double y = y_min;

	for(size_t i = 0; i < height; i++) {
		x = x_min;
		for(size_t j = 0; j < width; j++) {
				data[i][j] = foo(x,y);
				x += xGrowth;
		}
		y += yGrowth;
	}

  print2dArray(height, width, data);

}


int main(void) {

  //FUNTKION F
  double schrittweite = 0.5;
	double x_min = -1, x_max = 1;
	double y_min = -1, y_max = 1;

  int sizeMatrix = (((x_max-x_min)/schrittweite)+1);
  double data[sizeMatrix][sizeMatrix];

	fillMatrixWithResults(sizeMatrix, y_min, y_max,
	                      sizeMatrix, x_min, x_max,
	                      data, &f);

  printf("\n");

  //FUNTKION G
  schrittweite = M_PI/4;
  x_min = 0, x_max = M_PI;
  y_min = 0, y_max = M_PI;

  sizeMatrix = (((x_max-x_min)/schrittweite)+1);
  //data[sizeMatrix][sizeMatrix];

  fillMatrixWithResults(sizeMatrix, y_min, y_max,
                        sizeMatrix, x_min, x_max,
                        data, &g);

  printf("\n");

  //FUNTKION H
  schrittweite = 1;
  x_min = 0, x_max = 10;
  y_min = 0, y_max = 10;

  sizeMatrix = (((x_max-x_min)/(schrittweite))+1);

  fillMatrixWithResults(sizeMatrix, y_min, y_max,
                        sizeMatrix, x_min, x_max,
                        data, &h);

  return 0;
}
