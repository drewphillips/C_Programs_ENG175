//COPY and PASTED CODE FROM D2L for grading on 10/28/23

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
   
int matrix[3][3];
int i, j;
int multiplier =10;

printf("Program #1\n\n");

for (i=0; i<3; i++) {
   for (j=0; j<3; j++) {
   scanf("%d", &matrix[i][j]);
   }
   }

   for (i=0; i <3; i++) {
       for (j=0; j<3; j++) {
   printf("%5d", matrix[i][j]);

       }
       printf("\n");
       printf("\n");
       }

   matrix[0][0] = matrix[0][0] * multiplier;
   matrix[1][1] = matrix[1][1] * multiplier;
   matrix[2][2] = matrix[2][2] * multiplier;

    for (i=0; i <3; i++) {
       for (j=0; j<3; j++) {
   printf("%5d", matrix[i][j]);
       }
       printf("\n");
       }

   return 0;
}

/*
(3 pts) read in and print a 3x3 integer matrix
(4 pts) change the main diagonal entries by multiplying each value by 10
(3 pts) print the new matrix 
do not loop
*/