//copy and paste code above changing from while loop to do-while loop

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	int number, remainder;
	int i = 1;
	int sum = 0;

	printf("Enter a Number\n");
	scanf("%d", &number);

	do  {
		remainder = number % i;
		if (remainder == 0) {
			sum = sum + i;
			printf("%d divides in to %d\n", i, number);
		}
		
		i = i + 1;
	}
    while (i < number);
	if (sum == number)
		printf("Number %d is perfect number\n\n", number);
	else
		printf("Number %d is not a perfect number\n\n", number);

	return 0;
}