//COPY and PASTED CODE FROM D2L for grading on 10/28/23

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{

int userHeight[3];
int i;


   printf("Program #2\n\n");

   // read in.
   for (i=0; i < 3; i++) {
       scanf("%d", userHeight);
   }

   for (i=0; i < 3; i++)
   if (userHeight[i] < 36);
       printf("Cannot ride\n");
   if (userHeight[i] < 45 && userHeight[i]>= 36);
       printf("Can ride low-thrill rides\n");
   if (userHeight[i] > 45 && userHeight[i] <= 51);
       printf("Can ride medium-thrill rides\n");
   if (userHeight[i] > 51);
       printf("Can ride high-thrill rides\n");


   // Height:        Output:
//0 to 35        Cannot ride
//36 to 45      Can ride low-thrill rides
//46 to 51      Can ride medium-thrill rides
//52 or more  Can ride high-thrill rides

//Write a C program to ...

//read in 3 integer height values and store them in an array
//for each height value in the array, output the appropriate string as indicated in the given table
//do not loop

   return 0;
}

/*
//COPY and PASTED CODE FROM D2L for grading on 10/28/23

Height:    Output:
0 to 35    Cannot ride
36 to 45   Can ride low-thrill rides
46 to 51   Can ride medium-thrill rides
52 or more Can ride high-thrill rides

(-5 of 6 pts) read in 3 integer height values and store them in an array code did not use an array for reading
(-2 of 4 pts) for each height value in the array, output the appropriate string as indicated in the given table  code prints all values no matter the input
do not loop
*/