#include <stdio.h>
//#include <stlib> // already here
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{

    double x1, x2;
    double y1, y2;
    int userSelection;
    double answer;
    char loopAgain;
    double takeRoot;
    double x3, y3;

    printf("Program #1\n");
    printf("Dean Phillips\n");

   do {

    printf("Read in two pairs of cordinates, first x1 and y1, then x2 and y2\n");
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    
    scanf("%lf", &x2);
    scanf("%lf", &y2);

    printf("You entered, %.1lf, %.1lf and %.1lf, %.1lf\n", x1, y1, x2, y2);

 
    printf("Pick from one of 3 menu options\n");
    printf("1) Distance\n2) Midpoint\n3) Slope\n");
    scanf("%d", &userSelection);

    if (userSelection == 1) {
        printf("Distance...\n");
        takeRoot = pow(x2 + x1, 2) + pow(y2 + y1, 2);  
        answer = sqrt(takeRoot);
        printf("%.1lf\n", answer);

    }
    else if (userSelection == 2) {
        printf("Midpoint...\n");
        x3 = (x2 + x1) / 2;
        y3 = (y2 + y1) / 2;
        printf("The MidPoint is: %.1lf, %.1lf\n", x3, y3);

    }

    else if (userSelection == 3) {
        printf("Slope... \n");
        x3 = x2 - x1;
        y3 = y2 - y1;
        answer = y3 / x3;
        printf("The slope is: %.1lf\n", answer);
        // I think that test case is wrong, 0.5 is corect, with the numbers given. 
    }   

    else 
    printf("You can only select 1, 2, or 3. Try again.\n");

    printf("do you want to enter new cordinates? y/n");
    scanf(" %c", &loopAgain);
    loopAgain = tolower(loopAgain);
    } while (loopAgain == 'y');

    return 0;
}

/*
Program in zyBooks Final Exam Program #1.

Copy/paste code in the text box provided with this D2L question before your time has exceeded.  Only what is in D2L is graded.



Write a program to ...

in zyBooks, change this command to #include <stdlib>
read in two decimal coordinates (x1, y1) and then (x2, y2)
provide a menu to select from distance or midpoint or slope
use a multi-if-else-if structure to calculate and print the result to 1 decimal places
loop until the user wants to quit
Test Case (0, 0) and (-4, 3):  distance = 5.0

Test Case (-1, -3) and (3, 2):  midpoint = (1.0, -0.5)

Test Case (0, -1) and (4, 1):  slope = -2.0

Program 1

(2pts) read 2 decimal (x1, y1) and then (x2, y2)
(2pts) menu to select distance or midpoint or slope
(4pts) use a multi-if-else-if structure to calc and print 1 decimal
(2pts) loop until the user wants to quit

Test Case: (4, 3) (5, -2)   
dist = 5.1     midpt = (4.5, 0.5)     slope = -5.0

(-1) code returns 9.1 for distance

*/
