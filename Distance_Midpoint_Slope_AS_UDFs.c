#include <stdio.h>
#include <ctype.h>
#include <math.h>

//Call a udf to calculate the distance, d.  Print in int main(void)
double CalcDistance(double x1, double y1, double x2, double y2) {
    double distance;
    distance = sqrt (pow(x2-x1, 2) + pow(y2-y1, 2));

return distance;
}
//Call a udf to calculate the midpoint (x, y).  Print in udf
double CalcMidPoint(double x1, double y1, double x2, double y2) {
    double midX, midY;
    midX = ((x1+x2) /2);
    midY = ((y1+y2) /2);
    printf(" The mid point is (%.2lf , %.2lf)", midX, midY);

}

//Call a udf to calculate the slope, m.  Print in int main(void)
double CalcSlope(double x1, double y1, double x2, double y2) {
    double slope;
    slope = (y2-y1) / (x2-x1);
return slope;
}

int main()
{
double x1;
double y1;
double x2;
double y2;
char loopAgain;
int userSelection;

// /Read in two double (x, y) coordinates
do {


printf("Enter in the first (x,y) coordinates\n");
scanf("%lf", &x1);
scanf("%lf", &y1);

printf("Enter in the seconed (x,y) coordinates\n");
scanf("%lf", &x2);
scanf("%lf", &y2);

printf("you entered (%.2lf , %.2lf) & (%.2lf , %.2lf) \n", x1, y1, x2, y2);

printf("Select one of the following 3 calulations.\n");

printf("1.) Distance formula\n");
printf("2.) Midpoint Formula\n");
printf("3.) Calulate the slope\n");
scanf("%d", &userSelection);

if ( userSelection == 1) {
    printf("1.) Distance formula\n");
    printf("Distance = %.2lf", CalcDistance(x1, y1, x2, y2));
}
else if ( userSelection == 2) {
    printf("2.) Midpoint Formula\n");
    CalcMidPoint(x1, y1, x2, y2);
}
else if (userSelection == 3) {
    printf("3.) Calulate the slope formula\n");
    printf("The slope is = %.2lf", CalcSlope(x1, y1, x2, y2));
}

else 
    printf("You can only select 1-3, try again.");


//Loop until the user wants to quit
printf("\nDo you want to enter new coordinates? y/n\n");
scanf(" %c", &loopAgain);
loopAgain = tolower(loopAgain);

}while (loopAgain == 'y');
    
    return 0;
}
