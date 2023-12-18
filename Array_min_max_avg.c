#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
//declarVars
char loopAgain;
int N;
double array1[25];
int i;
int min = 1000000;
int max = -1000000;

do{
    printf("Calulating the min and max average of a list of numbers!\n");
    printf("How many numbers are in the array? N =\n");
    scanf("%d", &N);

    //printf("%d", N);

    for (i = 0; i < N; i++) {
        
        printf("element =\n");
        scanf("%lf", &array1[i]);

        for (i = 0; i < N; i++) {
        printf("%.1lf ", array1[i]);
        }
        
        printf("\n{ ");
        if (i != (N-1)){
        printf("%.1lf, ", array1[i]);
        }
        else{
        printf("%.1lf ", array1[i]);
        }
        }

        printf("\n{ ");


        /* print min max average
        min = array1[0];
        max = array1[0];


        for (i =0; i < N; i++) {
        if (array[i] < main);
        }

        for (i =0; i < N; i++) {
        if (array[i] > max);
        }
        */
        printf("Do you want to go again?");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
    } while (loopAgain == 'Y');


    return 0;
}
