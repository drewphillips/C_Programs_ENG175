#include <stdio.h>
#include <math.h>

//create one udf for cuboid calculations.  Print in int main(void) { }

double CalcCuboid(double length, double width, double height) {
double cuboid;
cuboid = length * width * height;
return cuboid;
}

//create one udf for cylinder calculations.  Print in the udf

// C = PI r^2 * H
double CalcCylinder (double height, double radius) {
    double cylinder;
    cylinder = ((M_PI * (pow(radius, 2))) * height);
    printf("The cylinders voulume is = %.2lf", cylinder);
}

//create one udf for hemisphere calculations.  Print the area and volume
// surface area of a hemisphere + 3PIr^2
double CalcAreaHemisphere(double radius) {
    double HemisphereArea;
    HemisphereArea = 2 * M_PI * pow(radius, 2);
    return HemisphereArea;
}

// (⅔)𝜋r3 cubic units. is vlume of a hemispher

double CalcVolumeHemispher(double radius) {
    double HemisphereVolume;
    HemisphereVolume = 2 * M_PI * pow(radius, 3) / 3;
    return HemisphereVolume;
}

int main()
{

    int userSelection;
    double length;
    double width;
    double height;
    double radius;


printf("Selct one of the folloing 3 options\n");
printf("1) Cuboid calculations.\n");
printf("2) Cylinder calculations.\n");
printf("3) Hemisphere calculations.\n");
scanf("%d", &userSelection);

if (userSelection == 1) {
    printf("Cuboid calculations.\n");
    printf("Enter a length, a width and a hight\n");
    scanf("%lf", &length);
    scanf("%lf", &width);
    scanf("%lf", &height);
    printf("%.2lf", CalcCuboid(length, width, height));
}
else if (userSelection == 2) {
    printf("Cylinder calculations.\n");
    printf("Enter the Height and Radius of the cylinder\n");
    scanf("%lf", &height);
    scanf("%lf", &radius);
    CalcCylinder(height, radius);
}
else if (userSelection == 3) {
    printf("Hemisphere calculations.\n");
    printf("Enter the radius of the hemispher\n");
    scanf("%lf", &radius);
    printf("The total surface area of the hemisphere is = %.2lf\n", CalcAreaHemisphere(radius));
    printf("The volume of the hemisphere is = %.2lf\n", CalcVolumeHemispher(radius));
}
else {
printf("Please only select 1-3, try again.");
}

//


    
    return 0;
}
