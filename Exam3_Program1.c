//Copy/Pasted from D2L to zyBooks on 11/21/23 for grading.

//unfinished program, but what I had at 330 when I was booted.

#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
   printf("Program #1\n\n");
   printf("Dean Phillips\n");

int numElements = 10;
char array1[10];
char array2[10];
char array3[10];
int numS =0;
int numP =0;
int i;

printf("Enter in three words\n");

scanf(" %s", array1);
scanf(" %s", array2);
scanf(" %s", array3);

printf("you entered\n%s\n %s\n%s\n", array1, array2, array3);

for (i = 0; i <10; i ++);

   if (array1[i] == 's')
   numS = numS + 1;

    if (array1[i] == 'p')
   numP = numP + 1;


   printf("%d %d", numS, numP);



 /*
populate an array with 3 strings received from the user
print each string and add "!!!" to the end
print the number of "p" and "s" letters for each string
do not loop, no menu
If the input is: Apples Houses Cars, the output is:

Apples!!!  has 3 p and s letters
Houses!!!  has 2 p and s letters
Cars!!!  has 1 p and s letters
 */

   return 0;
}


/*
(-5 of 5pts) populate an array with 3 strings received from the user  an array of strings not used
(-1 of 2pts) print each string and add "!!!" to the end  "!!!" not added to end
(-3 of 3pts) print the number of "p" and "s" letters for each string  not printed
do not loop, no menu

Test case Apples!!!  has 2 p and 1 s letters
          Houses!!!  has 0 p and 2 s letters
          Cars!!!  has 0 p and 1 s letters
*/