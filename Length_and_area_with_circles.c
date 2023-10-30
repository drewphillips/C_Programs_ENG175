#include <stdio.h>
#include <math.h>
#include <ctype>

// print area function



// print length function



int main() {


	double radius, theta;
	double area, length;

	char q, select;

	printf("ENter in a ratius and agnel of theta in degrees.\n");
	printf("Radius = ");
	scanf("%lf", &radius);
	printf("Enter in theta");
	scanf("%lf", &theta);
	
	
	do {

		printf(" what calulation woudl you lieki top do, "L" for Length, A for area");
		scanf(" %c", &select);
		if (select == a) {
			selesct = toupper(select);
		}

		else if (selects == 'l') {
			selects = toupper(select);

		}


		if select == 'A') {
			//call function print area
		}

		else if (select == 'L') {
			//call function print length
		}


	} while (q != 'q');

	return 0;
}


//sudo code