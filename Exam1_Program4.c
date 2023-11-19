/*Program in zyBooks, copy / paste code in the text box provided with this D2L question before your time has exceeded.

Write a C program that ...

reads in(x₁, y₁) and (x₂, y₂) values
use a menu to select from slope and line or vectors
use an if - else - if structure
if slope and line
calculate and print the Slope(m) = (y2 - y1) / (x2 - x1)
print the Line equation : y - y1 = m(x - x1)  in this form without simplifying
if vectors
calculate and print the Dot product = x1 * x2 + y1 * y2
if the dot product = 0, the vectors are perpendicular, test and print results
calculate and print the Magnitude = √(x1 ^ 2 + y1 ^ 2) for each vector
print to two decimals
do not loop

*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    double x1;
    double y1;
    double x2;
    double y2;
    double slope;
    double dotProduct;
    double magnitude;
    int userSelection;

    printf("PROGRAM #4\n\n");


    //reads in (x₁, y₁) and (x₂, y₂) values
    printf("Enter a pair of cordinates.\n X1: ");
    scanf("%lf", &x1);
    printf("Enter Y1:\n");
    scanf("%lf", &y1);
    printf("Enter X2:\n");
    scanf("%lf", &x2);
    printf("Enter Y2:\n");
    scanf("%lf", &y2);

    printf("You enterd: %.2lf, %.2lf, %.2lf, %.2lf\n", x1, y1, x2, y2);

    //use a menu to select from slope and line or vectors

    printf("\nWhat operation do you want to do, Slope =1, equation = 2 dot product = 3 and something = 4\n");
    scanf("%d", &userSelection);

    if (userSelection == 1) {
        //calculate and print the Slope (m) = (y2 - y1) / (x2 - x1)

        slope = (y2 - y1) / (x2 - x1);
        printf("\nThe slope is: %.2lf", slope);
    }

    else if (userSelection == 2) {
        printf("print the Line equation: y - y1 = m(x - x1) ");
    }

    else if (userSelection == 3) {
        printf("this is the fomula for alculate and print the Dot product = x1 * x2 + y1 * y2 ");
    }

    else if (userSlection == 4) {
        printf("calculate and print the Magnitude = √(x1^2 + y1^2) for each vector print to two decimals");

    }
    else printf("You can only selec t 1-4 as an options, try again");

    /*


 use an if-else-if structure
 if slope and line
 calculate and print the Slope (m) = (y2 - y1) / (x2 - x1)
 print the Line equation: y - y1 = m(x - x1)  in this form without simplifying
 if vectors
 calculate and print the Dot product = x1 * x2 + y1 * y2
 if the dot product = 0, the vectors are perpendicular, test and print results
 calculate and print the Magnitude = √(x1^2 + y1^2) for each vector
 print to two decimals
 do not loop
    */

    //program code goes here

    return 0;
}

/*
The correct answer is not displayed for Written Response type questions.

Hide question 24 feedback
//Code did not compile and run

//COPY and PASTED CODE FROM D2L for grading on 10/18/23

(2) menu slope_line or vectors

(2) if else structure

(2) (4, 7)  (3, 3)
slope = 4
line  y - 3 = 4 (x - 3)
or y - 7 = 4 (x - 4)

(2) dot product 33
dp not 0 not perpendicular

(2) mag1 = 8.06 and mag2 = 4.243
*/