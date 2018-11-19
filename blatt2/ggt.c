#include <stdio.h>

int main(void) {

	int ergebnis = ggt(8,4);
	printf("GGT von 8 und 4 ist: %d \n", ergebnis);

	ergebnis = ggt(24,3);
	printf("GGT von 24 und 3 ist: %d \n", ergebnis);

	ergebnis = ggt(1071, 1029);
	printf("GGT von 1071 und 1029 ist: %d \n", ergebnis);

	return 0;

}

/*BSP an 1071, 1029
 *ggt(m, (n%m) -> 1029, (1071%1029) = 42
 *ggt(m, (n%m) -> 42, (1029%42) = 21
 *ggt(m, (n%m) -> 21, (42%21) = 0
*/

int ggt(int n, int m) {

	if(m == 0) {
		return n;
	}
	else {
		return  ggt(m, (n%m));
	}

}
