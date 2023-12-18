#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main() 
{

    char loopAgain;
    int start, stop;
    int sum;
    int i;
    int array[25];

    do {

       
        printf("Calulating the sum of i(i+1) from start to stop\n\n");
        printf(" Start = ");
        scanf("%d", &start);
        printf(" Stop = ");
        scanf("%d", &stop);
        printf("\n");

        sum = 0;
        for (i = start; i <= stop; i++) {

            array[i]  = i * (i +1);
            sum = sum + array[i];
        }

        printf("Sum = %d\n", sum);


        printf("Do you want to go again?\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
        } while (loopAgain == 'Y');

    return 0;
}
