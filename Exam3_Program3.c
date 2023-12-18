
//Copy/Pasted from D2L to zyBooks on 11/21/23 for grading.

//unfinished program, but what I had at 330 when I was booted.

#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char fruitName;
  int quantity;
  double price;
} grocery_struct;

int main()
{
   printf("Program #3\n\n");
   printf("Dean Phillips\n");

grocery_struct fruitData[5];
int i;
double sum;

for (i = 0; i < 5; i ++) {
printf("Enter in 5 types of fruit, the quantity and the price to calulate the average price for all fruits\n");
printf("Fruit name\n");
scanf(" %s", &fruitData[i].fruitName);
printf("Quantity\n");
scanf("%d", &fruitData[i].quantity);
printf("price\n");
scanf("%lf", &fruitData[i].price);

}

sum = 0;
for (i = 0; i < 5; i++) {
   sum = sum + fruitData[i].price;
}

printf("The average price of the frute is: $%.2lf", sum / 5);




 /*
read in data from the keyboard for 5 fruits into an array using the structure
calculate and print the average price for all fruits
do not loop and no menu
 */

   return 0;
}

/*
PROGRAM #3

(4 pts)use the provided structure
    typedef struct {
          char fruitName;  //need to change for strings
         int quantity;
        double price;
    } grocery_struct;

(3 pts) read in data from the keyboard for 5 fruits into an array using the structure
(3 pts) calculate and print the average price for all fruits
do not loop and no menu

Test case {4.5 6.7 8.9 4.3 6.5} avg = 6.18
*/