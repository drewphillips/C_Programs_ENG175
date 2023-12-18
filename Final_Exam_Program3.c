#include <stdio.h>
//#include <stlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//#include <stdio.h>
//int sum(int n);

int gcd (int n1, int n2);
int sum (int n);

int main() {
    printf("Program #3\n");
    printf("Dean Phillips\n");

    int number1, number2, result;
    //int sum;

    printf("Enter a 1st positive integer: ");
    scanf("%d", &number1);
    
    printf("Enter a 2nd positive integer: ");
    scanf("%d", &number2);

    //sum = sum(number2);
    result = gcd (number1, number2);

    printf("gcd = %d\n", result);
    printf("The sum was: %d", sum(number2));
    return 0;
}  
 








    //add code to call sum with number2


int sum(int n) {
    if (n != 0)
        // sum() function calls itself
        return n + sum(n-1); 
    else
        return n;
}







int gcd (int n1, int n2) {
    
    if (n1 == 0)
        // sum() function calls itself
        return n2; 
    else
        return gcd (n2 % n1, n1);
}

/*
Program 3

(3 pts) read in two integers
(-2 of 4 pts) call one udf to calculate the sum of the two integers  prints one sum but not both
(4 pts) call one udf to calculate the gcd of the two integers
do not loop
(4 pts) use the recursion code provided to combine into one program

Test Case:  24, 18
sum for 24 = 300     sum for 18 = 171     gcd = 6
*/