//Copy/Pasted from D2L to zyBooks on 11/21/23 for grading.

#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//UDF for threshold
//find the minimum of the three integer values

//return the threshold otherwise

int min (int val1, int val2, int val3, int threshold) {
   int min;
   //for (i=0; i < threshold; i++);
   
   if (val1 < val2 && val1 < val3) {
    min = val1;
   }

   else if (val2 < val1 && val2 < val3) {
   min = val2;
   }
   
   else if (val3 < val1 && val3 < val2){
   min = val3;

   }
   return min;

}
////return the minimum value if all values are above the threshold
int minAbov (int val1, int val2, int val3, int threshold) {
   int minAbove;
   //for (i=0; i < threshold; i++);
   
   if (val1 < val2 && val1 < val3 && val1 > threshold) {
    min = val1;
   }

   else if (val2 < val1 && val2 < val3 && val1 > threshold) {
   min = val2;
   }
   
   else if (val3 < val1 && val3 < val2 && val1 > threshold){
   min = val3;

   }
   return minAbove;

}



int main()
{

int val1;
int val2;
int val3;
int maxThresh;
char loopAgain;
   printf("Program #2\n\n");
   printf("Dean Phillips\n");

//read in three integer values and a max threshold value

//do {

printf("enter in 3 values\n");
scanf("%d", &val1);
scanf("%d", &val2);
scanf("%d", &val3);
printf("Enter in a max threshhold\n");
scanf("%d", &maxThresh);

//call a user defined function to
printf("The minimum value is: %d", min(val1, val2, val3, maxThresh));
printf()

//printf("do you want yto enter in new values? Y/n:\n");
//scanf(" %c", &loopAgain);
//tolower (loopAgain);


//} while  (loopAgain = 'y');


/*



loop until the user wants to quit
If the user enters 2 6 4 10, the threshold is 10 and udf returns 10 (the min is not above the threshold)

If the user enters 200 600 400, 100, the threshold is 100 and udf returns 200 (the min is above or equal to threshold)

If the user enters 20 60 40 10, the threshold is 10 and the function returns 20 (the min is above or equal to threshold)

If the user enters 200 600 400, 1000, the threshold is 1000 and udf returns 1000 (the min is not above the threshold)

*/

   return 0;
}

/*
PROGRAM #2  code did not compile and run

(2pts) read in three integer values and a max threshold value
(6pts) call a user defined function to
    find the minimum of the three integer values
    return the minimum value if all values are above the threshold
    return the threshold otherwise
(2pts) loop until the user wants to quit

Test case:  28 31 21 50 returns 50
Test case:  28 31 21 10 returns 21
*/