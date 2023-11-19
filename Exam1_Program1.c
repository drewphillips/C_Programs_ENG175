/*Program in zyBooks, copy / paste code in the text box provided with this D2L question before your time has exceeded.

Formulas:

Circular cone formulas

Write a C program to calculate and print the volume(V) and slant height(S) for a right circular cone.Print to 2 decimals.Do not loop.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	printf("PROGRAM #1\n\n");

	double radius;
	double hight;
	double slantHight;
	double volume = 5;
	double tempCalc = 0;
	double tempCalcSlant = 0;


	printf("Enter the radius of the cone:\n");
	scanf("%lf", &radius);
	printf("enter the hight of the cone\n");
	scanf("%lf", &hight);
	printf("Enter the Slant Hight of the cone\n");
	scanf("%lf", &slantHight);

	printf("you entered %.2lf, %.2lf, %.2lf", radius, hight, slantHight);

	tempCalc = pow(radius, 2);
	//printf("%.2lf", tempCalc);
	volume = 1 / 3 * M_PI * tempCalc * hight;
	printf("\nthe volume is: %.2lf\n", volume);

	tempCalcSlant = pow(radius, 2) + pow(hight, 2);
	slantHight = sqrt(tempCalcSlant);
	printf("The Slant Hights is: %.2lf\n", slantHight);

	/*  Write a C program to calculate and print the volume (V) and slant height (S) for a right circular cone.  Print to 2 decimals.  Do not loop.

 volume = 1/3 Pi r^2 h

 slant height = squrt (r^2+h^2

 r radius
 h hight
 s slant hight

 */


 //program code goes here

	return 0;
}



/*
The correct answer is not displayed for Written Response type questions.

Hide question 21 feedback
//COPY and PASTED CODE FROM D2L for grading on 10/16/23

Test case r = 5.5 and h = 10 returns correct values of V = 316.78 and S = 11.41

Used M_PI

(-5) Volume prints as 0.00
In formula 1 / 3 = 0 in integer division.

(-2) User should not be entering slant height, code should calculate
*/