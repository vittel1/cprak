#include <stdio.h>
#include <stdlib.h>


void ausgabe(int **array, int size) {

	if(size == 1) {
		printf(" %d ", (*array)[0]);
	}
	else {
		for(int i=0; i<size; i++) {
			printf(" %d ", (*array)[i]);
			(*array)[i] = (*array)[i] + (*array)[i+1];
		}
		*array = realloc(*array, (size-1)*sizeof(int));
		printf("\n");

		ausgabe(array, (size-1));
	}
	printf("\n");

}

void readInput(int **array)
{
	int gesamtZahl, summand;

	printf("Gesamtzahl Summanden:\n");

	scanf("%d", &gesamtZahl);
	if(gesamtZahl > 10)
	{
		printf("Eingabe-Limit wird auf 10 Summanden gesetzt\n");
		gesamtZahl = 10;
	}

	*array = (int*)malloc(sizeof(int) * gesamtZahl);

	printf("Summanden:\n");
	for (int i = 0; i < gesamtZahl; ++i)
	{
		scanf("%d", &summand);
		(*array)[i] = summand;
	}

	ausgabe(array, gesamtZahl);
}

int main(void)
{
	int *array;
	readInput(&array);
	free(array);
	return 0;
}
