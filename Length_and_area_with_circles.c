#include <stdio.h>
#include <math.h>
#include <ctype.h>



/*
Write a C program to work with Length and Area with Circles.  Your code must ...

Read in r and degree angle theta
Ask the user to choose area or length
Based on the user choice
Call a user defined function to calculate and print the area of the sector, segment and triangle.  Print to 3 decimals.
Call a user defined function to calculate and print the length of the chord and arc.  Print to 3 decimals.
Loop until the user wants to quit.
*/


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