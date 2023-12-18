//COPY and PASTED CODE FROM D2L for grading on 10/28/23

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
   int start;
   int stop;
    int i;
    char loopAgain;
    int array[25];
    int sum;
   

    //i - 3 to the power of 2 i = start.

   printf("Program #4\n\n");

   do {

       printf(" Calulate the sum of  summation of x-3^2 from start to stop. \n");
       printf("Start = ");
       scanf("%d", &start);
       printf("Stop = ");
       scanf("%d", &stop);

       printf("\n");
       sum =0;
       for (i = start; i <= stop; i++) {
           sum = sum + pow(i - 3, 2);

       }
       printf("sum = %d\n", sum);



       printf("Do you want to loop again? y/n\n");
       scanf(" %c", &loopAgain);
       loopAgain = tolower(loopAgain);
       printf(" %c", loopAgain);
   } while (loopAgain == 'y');



   return 0;
}

/*
//COPY and PASTED CODE FROM D2L for grading on 10/28/23

(8 pts) calculate and print the summation
Test case: From x = 0 to 10, Sum = 154
Test case: From x = 7 to 10, Sum = 126

(2 pts) loop until the user wants to quit.
*/