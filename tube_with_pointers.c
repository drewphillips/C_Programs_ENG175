#include <stdio.h>
#include <ctype.h>
#include <math.h>

void AreaFunc(double inRad, double outRad, double Height, double* LatSurArea, double* TotSurArea) {
        *LatSurArea = 2.0 * M_PI * Height * (inRad + outRad );
        *TotSurArea = 2.0 * M_PI * Height * (inRad + outRad ) + 2.0 * M_PI * (outRad * outRad - inRad * inRad);
        return;
}


double VolumeFunc(double inRad, double outRad, double height) {
    double volume;
    volume = M_PI * outRad * outRad * height - M_PI * inRad * inRad * height;
    return volume;
} 

int main()
{
  
    char loopAgain;
    double r, R, h;
    int userSelection;
    double latSurArea, totSurArea;
    double volume;

    do {

        printf("Cylindracal Tube Calulator\n");
        printf("Read in r for iner radius\n");
        scanf("%lf", &r);
        printf("Red in R for the outer radius\n");
        scanf("%lf", &R);
        printf("Read in h for the height\n");
        scanf("%lf", &h);

        
        printf("\n--- Menu ---\n");
        printf("Select 1 for Area and 2 for Volume\n"); 
        scanf("%d", &userSelection);

        if (userSelection == 1) {
            printf("You selected Area\n");

            AreaFunc(r, R, h, &latSurArea, &totSurArea);
            printf("The Lateral Surface Area is %.2lf\n and the Total Surfice area is %.2lf\n", latSurArea, totSurArea);
        }
        else if (userSelection == 2) {
            printf("You selected Valume\n");
           
            printf("The volume is %.2lf\n", VolumeFunc(r, R, h));
        }

        else
            printf("You can only selcet 1 or 2, try again\n");

        printf("Do you want to go again? Y/N");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
    } while (loopAgain == 'y');

    
    return 0;
}




