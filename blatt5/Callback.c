#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
Implementieren Sie eine Funktion, der Sie eine Callback-Funktion übergeben können.
Die Callback-Funktion soll die Signatur
double foo(double x,double y)
haben. Außer dem Callback-Parameter soll die Funktion ein 2D Array übergeben bekommen.
Ziel ist es, die Rückgabewerte der Callback-Funktion in den übergebenen Array zu
schreiben. Die Funktion soll mit folgendem Code aufrufbar sein:
*/

//Callback Function
double foo(double x, double y) {
	return x*x + y;
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
}


int main() {
	const size_t height = 2, width = 3;
	double data[height][width];
	const double x_min = -1, x_max = 1;
	const double y_min = 1, y_max = 3;

	fillMatrixWithResults(height, y_min, y_max,
	                      width, x_min, x_max,
	                      data, &foo);

	assert(data[0][0] == 2);
	assert(data[0][1] == 1);
	assert(data[0][2] == 2);
	assert(data[1][0] == 4);
	assert(data[1][1] == 3);
	assert(data[1][2] == 4);
}x
