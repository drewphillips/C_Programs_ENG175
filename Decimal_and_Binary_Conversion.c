/*
Write a C program to work with Decimal and Binary numbers.  Your program must ...

ask the user what they are converting: Dec to Bin or Bin to Dec
Based on the selection, calculate and print
loop until the user wants to quit
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{

    int binaryNum[8];
    int decimalNum = 0;
    int power = 7;
    int base = 2;
    char loopAgain;
    int i=0;
    
 
    
    //enter a binary num and print it. 
    printf("Ener a binary number in cluding leading zeros, number must be 8 charictors long untill I figure out how to convert a 4 digit number to an 8 digit number with leading zeros. \n");
    for(i = 0; i < 8; i++) {
        scanf("%d",&binaryNum[i]);
    }
    for( i = 0; i < 8; i++) {
        printf("%d", binaryNum[i]);
    }
    printf("\n");


  
    do {
    
        printf("The user wants to quit...");

        //for (i = 0; i < 7; i++) {
        
            if (binaryNum[i] == 1) {
            decimalNum = decimalNum + pow(base, power);
            power = power -1;

            printf("power = \n%d\n", power);
            printf("i = %d", i);
            i--;
            printf("\nnow i = %d\n", i);
            
            }
            

       
         printf("%d\n", decimalNum);

              
        
        // print testing
        //printf("%d\n", binaryNum);
    

        printf("\nConvert a new binary number? y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
    } while ((loopAgain == 'y') || (loopAgain == 'Y'));

    
    
    
    // your code goes here

    return 0;
}
