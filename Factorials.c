/*
Write a C program that ...

Reads in an integer n
Use a For Loop to calculate and print n!
print using the form n! = 1x2x3x4...xn = answer
Loops until the user wants to quit
*/

#include <stdio.h>

int main()
{
    //declareVars
    int n;
    char loopAgain;
    int i;

    do {
        printf("Enter a number to calulate N factoria!:\n");
        scanf("%d", &n);
    
        for (i = 1; i <= n; i++) {
        
            if (i != n) {
            printf("%d x ", i);
            }
            else {
                printf("%d ", i);
            }
        

        }
            printf("\nAnother factorial? y/n\n");
            scanf(" %c", &loopAgain);

        } while ((loopAgain == 'y') || (loopAgain == 'Y'));
    
        
   return 0; 
}
