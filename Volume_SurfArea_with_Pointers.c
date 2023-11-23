#include <stdio.h>
#include <math.h>
#include <ctype.h>

void sphereUDF(double Radius, double* Volptr, double* SurfAreaptr) {
	*Volptr = (4.0 / 3.0) * M_PI * pow(Radius, 3);
	*SurfAreaptr = 4 * M_PI * pow(Radius, 2);
	return;
}

void cylinderUDF(double Radius, double Height, double* Volptr, double* SurfAreaptr) {
	*Volptr = M_PI * pow(Radius, 2)*Height;
	*SurfAreaptr = 2 * M_PI * pow(Radius, 2)+2*M_PI*Radius*Height;
	return;
}

void coneUDF(double Radius, double Height, double* VolumePtr, double* SurfaceAreaPtr) {
//Cone: If r=1.8, h = 8.8 then V= 29.858, SA= 60.972
double SideP;
SideP = sqrt(Height * Height + Radius * Radius);
*VolumePtr = (1.0/3.0) * M_PI * Radius * Radius * Height;
*SurfaceAreaPtr = M_PI * Radius * Radius + M_PI * Radius * SideP;

    return;
}

double pyramidUDF(double Side, double Height) {
    double Volume;
    Volume = (1.0/3.0) * Side * Side * Height;

    return Volume;
}

int main(void) {
	double radius;
	double sideP;
	double height;
	double volume = 0.0;
	double surfaceArea = 0.0;
	int userChoice;
	char loopAgain;
	do {
		printf("********* Shape Volume & Surface Area Calculator *********\n");
		printf("\t   1............Sphere\n");
		printf("\t   2............Cylinder\n");
		printf("\t   3............Cone\n");
		printf("\t   4............Pyramid\n");
		printf("Shape Selection: ");
		scanf("%d", &userChoice);
		printf("\n");
		switch (userChoice) {
		case 1:
			printf("You have chosen to calculate the volume and surface area of a sphere!\n");
			printf("\tEnter the radius: ");
			scanf("%lf", &radius);
			sphereUDF(radius, &volume, &surfaceArea);
			printf("Volume of a sphere = %.2lf\n", volume);
			printf("Surface area of a sphere = %.2lf\n", surfaceArea);
			break;
		case 2:
			printf("You have chosen to calculate the volume and surface area of a cylinder!\n");
			printf("\tEnter the radius: ");
			scanf("%lf", &radius);
			printf("\tEnter the height: ");
			scanf("%lf", &height);
			cylinderUDF(radius, height, &volume, &surfaceArea);
			printf("Volume of a cylinder = %.2lf\n", volume);
			printf("Surface area of a cylinder = %.2lf\n", surfaceArea);
			break;
		case 3:
			printf("You have chosen to calculate the volume and surface area of a cone!\n");
            printf("\tEnter the radius: ");
			scanf("%lf", &radius);
			printf("\tEnter the height: ");
			scanf("%lf", &height);

            coneUDF(radius, height, &volume, &surfaceArea);
            printf("Volume of a cone = %.2lf\n", volume);
			printf("Surface area of a vone = %.2lf\n", surfaceArea);

			break;
		case 4:
			printf("You have chosen to calculate the volume of a pyramid!\n");
            printf("\tEnter the side length: ");
			scanf("%lf", &sideP);
			printf("\tEnter the height: ");
			scanf("%lf", &height);
             
             printf("Volume of a Pyramid = %.2lf\n", pyramidUDF(sideP, height));
			break;
		default:
			printf("ERROR: Options are only 1-4!!!\n");
		}
		printf("\n");
		printf("Another 3D shape? y/n: \n");
		scanf(" %c", &loopAgain);
		loopAgain = tolower(loopAgain);

	} while (loopAgain == 'y');
	return 0;
}