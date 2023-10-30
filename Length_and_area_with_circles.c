#include <stdio.h>
#include <math.h>
#include <ctype.h>

// print area function
//void printArea(double rad, double theata) {
	//double 
//}


// print length function



int main() {


	double radius, theta;
	double area, length;

	int loopAgain;
	//char 'y';
	char select;

	do {

	printf("Enter in a ratius and agnel of theta in degrees.\n");
	printf("Radius = ");
	scanf("%lf", &radius);
	printf("Theta =");
	scanf("%lf", &theta);
	printf("\n");
	


		printf(" what calulation would you like to do, 'L' for Length, 'A' for area\n");
		scanf(" %c", &select);
		if (select == 'a') {
			select = toupper(select);
		}

		else if (select == 'l') {
			select = toupper(select);

		}


		if (select == 'A') {
			//call function print area
		}

		else if (select == 'L') {
			//call function print length
		}

		printf("Woudl you like to do a new calulation? y/n");
		scanf(" %c", loopAgain);
		

	} while (loopAgain == 'y');

	return 0;
}


//sudo code