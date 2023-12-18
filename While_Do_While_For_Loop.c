#include <stdio.h>
# include <ctype.h>
/*
Write a C program that  ...

Reads in a start and stopping value for summation notation whose formula is  3x - 7
Use a while loop to calculate and print each term of the sequence in the form {-4  -1  2  ...  20  29}
Calculate and print the sum of 3x-7
Use a do-while loop to loop until the user wants to quit
*/

int main()
{
    
    //declareVar 
    char loopAgain;
    int startVal, stopVal;
    int sum;
    int i;
    int runningSum;

    do {
       
    
        printf("We will be calulating the sum of 3x -7 ...");
        printf("Enter a start value\n");
        scanf("%d", &startVal);
        printf("Enter a stop value\n");
        scanf("%d", &stopVal);

        i = startVal;
        sum = 0;
        while ( i <= stopVal) {
        printf("%d ", i);
        sum = sum + (3*i -7);
        i++;
        
    }



    printf("\nThe sum is: %d\n", sum);

    printf("Another summation? y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);

    } while (loopAgain == 'y'); 

    return 0;
}
