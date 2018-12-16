#include <stdio.h>
#include <stdlib.h>


void ausgabe(int *array1, int *array2, int size) {

	if(size == 1) {
		printf(" %d ",array1[0]);
	}
	else {
		for(int i=0; i<size; i++) {
			printf(" %d ", array1[i]);
			array2[i] = array1[i];
		}

		array1 = realloc(array1, (size-1)*sizeof(int));

		for(int i=0; i<size-1; i++) {
			array1[i] = array2[i] + array2[i+1];
		}

		array2 = realloc(array2, (size-1)*sizeof(int));
		printf("\n");

		ausgabe(array1, array2, (size-1));
	}
	printf("\n");

	free(array1);
	free(array2);

}

// TODO: Signatur anpassen
void readInput()
{
	int gesamtZahl, summand;

	printf("Gesamtzahl Summanden:\n");

	scanf("%d", &gesamtZahl);
	if(gesamtZahl > 10)
	{
		printf("Eingabe-Limit wird auf 10 Summanden gesetzt\n");
		gesamtZahl = 10;
	}

	int *array1 = malloc(gesamtZahl*sizeof(int));
	int *array2 = malloc(gesamtZahl*sizeof(int));


	printf("Summanden:\n");
	for (int i = 0; i < gesamtZahl; ++i)
	{
		scanf("%d", &summand);
		array1[i] = summand;
	}
	//TODO
	//printf("%d\n", gesamtZahl);
	ausgabe(array1, array2, gesamtZahl);

	//Freigebem der Arrays
	//free(array1);
	//free(array2);

}

int main()
{
	readInput();
	return 0;
}
