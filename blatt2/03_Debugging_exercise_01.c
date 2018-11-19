#include <stdio.h>

//return value ist ein int
//void zu int geändert
//methodenname darf nicht mit einer zahl beginnen
int OO00O(int eingabe)
{
	return eingabe*eingabe;
}

char testfunktion00()
{
	char output = 'A';
	printf("Diese Funktion testet auch etwas\n");

}

void testfunktion01(char eingabe)
{
	printf("Eingabe war %d\n", eingabe);
}


//void fehlt als argument im main aufruf
int main()
{
	//== zu = ändern
	int counter = 0;
	//- als zeichen in variablennamen unzulässig
	char beliebigeszeichen = 'J';
	char charOut;

	//ein semikolon aus dem for statement entfernen
	for(;;)
	{
		//ein + zuviel
		counter++;
		//beliebeszeichen aus aufruf entfernen, weil die funktion nur int erwartet
		//methodennamen ändern
		OO00O(counter);
		charOut = testfunktion00();
		testfunktion01(charOut);
		//= zu == ändern
		if(counter%10 == 0)
		{
			break;
		}
	}
	//der aufruf keinen sinn?
	//testfunktion();

	//; am ende fehlt
	printf("Das Programm konnte erfolgreich kompiliert werden!\n");
	return 0;
}


