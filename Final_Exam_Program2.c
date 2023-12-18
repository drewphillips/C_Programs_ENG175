#include <stdio.h>
//#include <stlib> // still dont know what you want here. 
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int MaxSize = 25;
    double myArray[MaxSize];
    int i = 0, k = 0;
    double min = 9999.9, max, avg;


    

    printf("Program #2\n");
    printf("Dean Phillips\n");

    printf("Lets create an array, how large do you want the array to be? Max 25:\n");
    scanf("%d", &MaxSize);
    printf("Cool, your array is %d elements long\n", MaxSize);
    
    printf("Enter in the elements of the array one at a time:\n");
    while (i < MaxSize) {
      
        scanf("%lf", &myArray[i]);
        i = i+1;
    }

    printf("Thats a nice arracy you have here, you elements are:\n");
    for (i=0; i < MaxSize; i++) {
    printf("%.2lf, ", myArray[i]);
    }

      
    for (i=0; i < MaxSize; i++) {
        if (myArray[i] < min) {
        min = myArray[i];
        }

    
    }
    printf("\nThe min of the arracy is:\n");
    printf("%.2lf, ", min);

     for (i=0; i < MaxSize; i++) {
        if (myArray[i] > max) {
        max = myArray[i];
        }

    
    }
    printf("\nThe max of the arracy is:\n");
    printf("%.2lf, ", max);

    for (i=0; i < MaxSize; i++) {
        if (myArray[i] < min) {
        min = myArray[i];
        }

    
    }
    

     for (i=0; i < MaxSize; i++) {
        avg = avg + myArray[i]; 
    }

    printf("\nThe Average of the arracy is:\n");
    printf("%.2lf, ", avg / MaxSize);



    return 0;
}

/*
Write a program to ...

in zyBooks, change this command to #include <stdlib>
ask the user for the size of an array with max size 25
use a while loop to read in decimal elements into the array
print the array elements
print the min, max and average of he array elements
do not loop
Possible Test Case: N = 6 elements  {5.6, 3.7, 1.2, 9.3, 6.1, 8.8}     min = 12, max = 9.3, avg = 5.78

Program 2

(1 pts) ask for size of array <=25
(4 pts) while loop to read in elements into array
(2 pts) print the array elements
(3 pts) print the min, max and average
do not loop

Test Case: N = 5   {9.8, 7.6, 5.4, 3.2, 1.1}
min = 1.1     max = 9.8    avg = 5.42
*/