#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char loopAgain;
    int userValue;
    int min = 1000000000;
    int max = -1000000000;
    int count;
    int sum;
    double avg;

    do {
        
        count = 0;
        sum = 0;
        do {
            printf("Enter 9999 when done...\n");
            printf("Enter and integer: \n");
            scanf("%d", &userValue);

            if (userValue < min) {
            min = userValue;
            }
            
            if ((userValue != 9999) && (userValue > max)) {
                max = userValue;
            }
                
                if (userValue != 9999) {
                count = count +1;
                sum = sum + userValue;
                }



        } while (userValue != 9999);
        
        printf("\t Min = %d\n", min);
        printf("\t Min = %d\n", max);

        printf("you entered in %d integers.\n", count);
        printf(" The sum of all your entires are: %d\n", sum);
        //avg = (sum/count);
        printf("\t The average = %.1lf\n", (double)sum/count);

        printf("\tAnother list y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = toupper(loopAgain);
    }   while (loopAgain == 'y');
    
    return 0;
}
