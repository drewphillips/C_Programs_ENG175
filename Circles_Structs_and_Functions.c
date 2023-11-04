#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {

	double radius;
	double degreeAngle;
    double radianAngle;

}circleStruct;

//UDF's declarations
void circleLength( circleStruct circle);

void circleArea( circleStruct circle);



int main()
{
   char loopAgain;
   circleStruct circle;
   int userSelection;

   do {
       //read in a radius and degree angle
       printf(" ----- Circle Length and Circle Area! -----\n");
       printf("Enter in the radius and degree angle\n");
       scanf("%lf", &circle.radius);
       printf("\n");
       scanf("%lf", &circle.degreeAngle);
       printf("\n");
       

        circle.radianAngle = circle.degreeAngle * M_PI /180;

        //printf("%d", circleStruct);
        //menu
        printf("Do you want to calulate length or area of the circle?\n");
        printf("1) Length\n");
        printf("2) Area\n");
        scanf("%d", &userSelection);

        if (userSelection == 1){
        printf("Calulate length\n");
        circleLength(circle);
        }
        else if (userSelection == 2) {
        printf("Calulate Area\n");
        circleArea(circle);
        }

        else {
            printf("You can only enter 1 or 2 try afgain.");
        }



        printf("Do you want to enter new values and start over? y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
   } while (loopAgain == 'y');
    
    return 0;
}


//udf definition

void circleLength(circleStruct Circle) {

    double arcLen, chordLen;
    arcLen = Circle.radius * Circle.radianAngle;
    chordLen = 2 * Circle.radius*sin(Circle.radianAngle/2.0);

    printf("Length of Arc = %.2lf\n", arcLen);
    printf("Length of Chord = %.2lf\n", chordLen);
}

void circleArea(circleStruct Circle) {
    double areaSegment, areaTriangle, areaSector;

    areaSegment = 1.0/2.0 * pow(Circle.radius, 2) * (Circle.radianAngle - sin(Circle.radianAngle));
    areaTriangle = 1.0/2.0 * pow(Circle.radius, 2) * sin(Circle.radianAngle);
    areaSector = 1.0/2.0 * pow(Circle.radius, 2) * Circle.radianAngle;

    printf("Area of the Segment = %2lf\n", areaSegment);
    printf("Area of the Triangle = %2lf\n", areaTriangle);
    printf("Area of the Sector = %2lf\n", areaSector);

}