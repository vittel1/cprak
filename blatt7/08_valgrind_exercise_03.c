#include <stdio.h>
#include <stdlib.h>

// Koordinaten-Struct, keine Änderungen notwendig
typedef struct
{
	//Koordinaten
	int x,y;
} myCoordinate;

typedef struct {
	unsigned int size;
	unsigned int cap;
	myCoordinate** data;
} array;

//Methode kann verwendet werden, um die Ausgabe in den print-Methoden zu realisieren
void printStruct(myCoordinate *input)
{
	printf("%d\t%d\n", input->x, input->y);
}

//##############################################################################
//##############################################################################
//##############################################################################

// Eine neue Struct-Speicher-Datenstruktur wird angelegt und ist nach Rückgabe
// betriebsbereit
array *createStructStorage()
{
	array *structStorage = malloc(sizeof(myCoordinate));
	structStorage->size=0;
	structStorage->cap=3;
	structStorage->data = realloc(structStorage->data, (sizeof(myCoordinate*) * structStorage->cap));
	return structStorage;
}

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
void freeStructStorage(array *structStorage)
{
	for(int i=0; i<structStorage->size; i++) {
		free(structStorage->data[i]);
	}
	free(structStorage);
}

//##############################################################################

// Füge ein neues Element am Ende des Struct-Speichers ein
void insert(array *structStorage, myCoordinate *input)
{
	if(structStorage->size == structStorage->cap) {
		structStorage->cap *= 2;
		structStorage->data = realloc(structStorage->data, (sizeof(myCoordinate*) * structStorage->cap));
	}
	structStorage->data[structStorage->size] = input;
	structStorage->size++;
}

// Füge ein neues Element an Position pos ein
void insertAt(array *structStorage, int pos, myCoordinate *input)
{
	if(structStorage->size == structStorage->cap) {
		structStorage->cap *= 2;
		structStorage->data = realloc(structStorage->data, sizeof(myCoordinate*) * structStorage->cap);
	}
	for(int i = structStorage->size; i>=pos; i--) {
		structStorage->data[i+1] = structStorage->data[i];
	}
	structStorage->data[pos] = input;
	structStorage->size++;
}

//##############################################################################

// Gib die Koordinaten des Elements an Position pos aus
void printAt(array *structStorage, int pos)
{
	printf("%d %d \n", structStorage->data[pos]->x, structStorage->data[pos]->y);
}

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
void printRange(array *structStorage, int pos1, int pos2)
{
	for(;pos1<pos2; pos1++) {
		printf("%d %d \n", structStorage->data[pos1]->x, structStorage->data[pos1]->y);
	}
}

// Gib die Koordinaten aller Elemente aus
void printAll(array *structStorage)
{
	for(int i=0; i<structStorage->size; i++) {
		printf("%d %d \n", structStorage->data[i]->x, structStorage->data[i]->y);
	}
}

//##############################################################################

// Lösche das Element an Position pos
void deleteAt(array *structStorage, int pos)
{
	for(int i = structStorage->size; pos<=i; pos++) {
		structStorage->data[pos] = structStorage->data[pos+1];
	}
	structStorage->size--;
}

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
void deleteRange(array *structStorage, int pos1, int pos2)
{
	for(; pos1<=pos2; pos1++) {
		structStorage->data[pos1] = structStorage->data[pos1+1];
		structStorage->size--;
	}
}

// Leere die gesamte Struct-Speicher-Datenstruktur
void deleteAll(array *structStorage)
{
	free(structStorage);
	structStorage = malloc(sizeof(myCoordinate));
	structStorage->size=0;
	structStorage->cap=3;
	structStorage->data = realloc(structStorage->data, sizeof(myCoordinate*));
}

//##############################################################################

// Gib die Anzahl enthaltener Elemente aus
void printSize(array *structStorage)
{
	int numElements = 0;

	for(int i=0; i<structStorage->size; i++) {
		numElements++;
	}

	printf("Gesamtzahl Elemente: %d\n", numElements);
}

// Gib die Anzahl enthaltener Elemente aus
int getSize(array *structStorage)
{
	int numElements = 0;
	for(int i=0; i<structStorage->size; i++) {
		numElements++;
	}
	return numElements;
}


//##############################################################################
//##############################################################################
//##############################################################################
// Nachfolgend ein paar Testmethoden, die bei der Korrektheitsprüfung helfen
// sollen. An den test-Methoden muss nichts geändert werden, Sie können sie aber
// natürlich bei Bedarf erweitern

// Einfacher Ausgabetest
void test1()
{
	printf("Test1:\n");
	myCoordinate *test = (myCoordinate*)malloc(sizeof(myCoordinate));
	test->x = 1;
	test->y = 10;

	array *storage = createStructStorage();

	//TEST!
  //printf("Size of Array %d\n", getSize(storage));

	insert(storage, test);

	// Die beiden nachfolgenden Methoden sollten die gleiche Ausgabe produzieren
	printAll(storage);
	printStruct(test);

	freeStructStorage(storage);
}

// Hinzufügen und löschen einzelner Elemente
void test2()
{
	printf("Test2:\n");

	myCoordinate **testArray = (myCoordinate **)malloc(3*sizeof(myCoordinate*));
	for (int i = 0; i < 3; ++i)
	{
		testArray[i] = (myCoordinate *)malloc(sizeof(myCoordinate));
		testArray[i]->x = i;
		testArray[i]->y = i*10;
	}

	array *storage = createStructStorage();

	insert(storage, testArray[0]);
	insert(storage, testArray[1]);
	insertAt(storage,0,testArray[2]);

	printSize(storage);

	deleteAt(storage,1);

	printSize(storage);
	printAll(storage);

	freeStructStorage(storage);
}

// Hinzufügen und Löschen ganzer Bereiche
void test3()
{
	printf("Test3:\n");

	array *storage = createStructStorage();

	myCoordinate **testArray = (myCoordinate **)malloc(10*sizeof(myCoordinate*));
	for (int i = 0; i < 10; ++i)
	{
		testArray[i] = (myCoordinate *)malloc(sizeof(myCoordinate));
		testArray[i]->x = i;
		testArray[i]->y = i*10;

		insert(storage,testArray[i]);
		printAt(storage,i);
	}
	printSize(storage);

	printRange(storage,0,4);
	deleteRange(storage,0,2);
	printRange(storage,0,4);

	printSize(storage);

	deleteAll(storage);

	printSize(storage);

	freeStructStorage(storage);
}

//##############################################################################
//##############################################################################
//##############################################################################

int main()
{
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	return 0;
}
