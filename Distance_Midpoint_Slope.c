#include <stdio.h>
#include <math.h>

//    read in two souble points (x1, y1) and (x2, y2)
//    calculate and print the distance between the points
//    calculate and print the midpoint of the points
//    calculate and print the slope of the points
//    loop until the user wants to quit
//    print to 2 decimal places

int main()
{

//declare variables
    double x1, y1;
    double x2, y2;
    double distance = 0.0;
    double Midpoint = 0.0;
    double slope = 0.0; 
    double midx;
    double midy;

    char loopAgain = 'y';
    
    while (loopAgain == 'y') {

//read in the length and with values
printf("Distance, Midpoint and Slope\n: ");
printf("enter two (X,Y) cordinates\n");
printf("\tx1=");
scanf("%lf\n", &x1);
printf("\ty1=");
scanf("%lf\n", &y1);
printf("\tX2=");
scanf("%lf\n", &x2);
printf("\ty2=");
scanf("%lf\n", &y2);


//distance
distance = sqrt( pow(x2-x1, 2) + (y2-y1)*(y2-y1) ) ;
printf("\n\tDistance = %.2lf\n\n", distance);


//midpoint
midx = ((x1+x2)/(2));
midy = ((y1+y2)/(2));
printf("Midpoint + ( %.2lf ,%2lf\n ) " , midx , midy);

//slope
slope = (y2 - y1)-(x2-x1);
printf("slope = %.2lf", slope);

//loop
printf("\nEnter a new cordinates? y/n: ");
scanf(" %c", &loopAgain);

 }

    return 0;
}
