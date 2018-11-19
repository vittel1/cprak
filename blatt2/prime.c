#include <stdio.h>

int main(void) {
	printf("O: Wahr und 1: Falsch \n");
	
	int ergebnis = isPrime(3);
	printf("Ist 3 eine Primzahl? %d \n", ergebnis);
	
	ergebnis = isPrime(4);
	printf("Ist 4 eine Primzahl? %d \n", ergebnis);
	
	ergebnis = isPrime(5);
	printf("Ist 5 eine Primzahl? %d \n", ergebnis);
	
	ergebnis = isPrime(10);
	printf("Ist 10 eine Primzahl? %d \n", ergebnis);
	
	ergebnis = isPrime(13);
	printf("Ist 13 eine Primzahl? %d \n", ergebnis);

	return 0;
}

/*
 * 1 steht für false;
 * 0 steht für true;
 */
int isPrime(int eingabe) {
	if(eingabe <= 1) {
		return 1;
	}
	else if(eingabe <= 3) {
		return 0;
	}
	else if( ((eingabe%2) == 0) || ((eingabe%3) == 0)) {
	       return 1;
	}

	int i = 5;
	while(i * i <= eingabe) {
		if( ((eingabe%i) == 0) || ((eingabe%(i+2) == 0)) ) {
			return 1;
		}
		i++;
	}
	return 0;	
}

