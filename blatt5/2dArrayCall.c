#include <stdio.h>

//Implementieren Sie eine Funktion, die einen 2D Array als Matrix auf der Konsole
//ausgeben kann. Diese Funktion soll mit folgendem Aufruf nutzbar sein:

void print2dArray(size_t height, size_t width, double data[height][width]) {

	for(size_t y = 0; y < height; y++) {
		for(size_t x = 0; x < width; x++) {
			printf("%f ", data[y][x]);
		}
		printf("\n");
	}
}

int main() {
	const size_t width = 4, height = 3;
	double data[height][width];
	for(size_t y = 0; y < height; y++) {
		for(size_t x = 0; x < width; x++) {
			data[y][x] = 0;
			if(y == 1 && x == 1) data[y][x] = 4;
			if(y == 1 && x == 2) data[y][x] = 2;
		}
	}

	print2dArray(height, width, data);

	return 0;
}
