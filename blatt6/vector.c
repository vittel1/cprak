#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	unsigned int size;
	unsigned int capacity;
	char** data;
} svector_t;


void svector_init(svector_t* svector) {
	svector->size=0;
	svector->capacity=3;
	svector->data = realloc(svector->data, sizeof(char*) * svector->capacity);
}
void svector_append(svector_t* svector, char* elem) {

	if(svector->size == svector->capacity) {
		svector->capacity *= 2;
		svector->data = realloc(svector->data, sizeof(char*) * svector->capacity);
	}
	svector->data[svector->size] = elem;
	svector->size++;

}

void svector_print(svector_t* svector) {
	for(int i=0; i < svector->size; i++)
		printf("%s \n", svector->data[i]);
}


int main(int argc, char** argv) {

	//Größe für den String im Heap anlegen
	char *stringFranz = malloc(sizeof(char)*(strlen("Franz Maier")+1));
	char *stringTobias = malloc(sizeof(char)*(strlen("Tobias Schroeder")+1));
	char *stringAnne = malloc(sizeof(char)*(strlen("Anne Kraus")+1));
	char *stringTom = malloc(sizeof(char)*(strlen("Tom Hook")+1));

	//String in den vorgesehenden Platz eintragen
	strcpy(stringFranz, "Franz Maier");
	strcpy(stringTobias, "Tobias Schroeder");
	strcpy(stringAnne, "Anne Kraus");
	strcpy(stringTom, "Tom Hook");

	//SVector anlegen und initialisieren
	svector_t* svector = malloc(sizeof(svector_t));
	svector_init(svector);

	svector_append(svector, stringFranz);
	svector_append(svector, stringTobias);
	svector_append(svector, stringAnne);
	svector_append(svector, stringTom);

	//Ausgabe
	svector_print(svector);

	//Löschen
	free(svector);
	free(stringFranz);
	free(stringTobias);
	free(stringAnne);
	free(stringTom);

	return 0;
}
