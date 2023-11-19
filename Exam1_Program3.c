/*Program in zyBooks, copy / paste code in the text box provided with this D2L question before your time has exceeded.

Write a C program that ...

ask the user for N, the number of integers to be read
use a while loop to read in N integers
calculate and print the sum of the integers
calculate and print the average to 1 decimal place
loop until the user wants to quit

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

Hide question 23 feedback
//COPY and PASTED CODE FROM D2L for grading on 10/16/23

code asks for the radius of the cone
(3) read in N = 5 INTEGERS
(3) while loop to read
{ 23 34 45 56 67 }
(2) sum = 225 and avg = 45.0
(2) loop
*/