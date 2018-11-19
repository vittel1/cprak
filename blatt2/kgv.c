#include <stdio.h>

//KGV mit GGT berechnen

int main(void) {

	int ergebnis = kgv(24,5);
	printf("Das kgv von 24 und 5 ist: %d \n", ergebnis);

	ergebnis = kgv(55,12);
	printf("Das kgv von 55 und 12 ist: %d \n", ergebnis);

	ergebnis = kgv(10,12);
	printf("Das kgv von 10 und 12 ist: %d \n", ergebnis);

	return 0;
}

int kgv(int n, int m) {
	int o = ggt(m,n);
	int p = (m*n) / o;
	return p;
}

int ggt(int n, int m) {

	if(m == 0) {
		return n;
	}
	else {
		return  ggt(m, (n%m));
	}

}

