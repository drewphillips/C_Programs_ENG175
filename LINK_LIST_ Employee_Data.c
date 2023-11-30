
#include <stdio.h>
#include <stdlib.h>  //library that holds malloc

typedef struct {
	char firstName[25];
	char lastName[25];
	double years;
	int salary;
	int age;
} employee;

int main(void) {

	employee* empPtr, emp[5];  //pointer and array of the data type employee
	empPtr = emp;  //set pointer to point to array
	int i;
    double avgAge = 0;

	printf("---------- ENTERING  EMPLOYEE  DATA  ----------\n");
	for (i = 0; i < 2; i++) {
		printf("Employee %d\n", i + 1);
		printf("\tFirst Name: ");
		scanf("%s", empPtr->firstName);
		printf("\tLast Name: ");
		scanf("%s", empPtr->lastName);
		printf("\tYears on job (one decimal): ");
		scanf("%lf", &empPtr->years);
		printf("\tSalary (no decimal): ");
		scanf("%d", &empPtr->salary);
		printf("\tAge (no decimal): ");
		scanf("%d", &empPtr->age);
		printf("\n");

		empPtr++;//advance pointer to next element   
    }

		empPtr = emp;//reset pointer to beginning of array


		printf("---------- EMPLOYEE  DATABASE  ----------\n");
		printf("\n");
		for (i = 0; i < 2; i++) {
			printf("EMPLOYEE %d -----\n", i + 1);
			printf("First Name: %s\n", empPtr->firstName);
			printf("Last Name: %s\n", empPtr->lastName);
			printf("Year of service: %.1lf\n", empPtr->years);
			printf("Salary: %d\n", empPtr->salary);
			printf("Age: %d\n", empPtr->age);
			printf("\n");
            avgAge = avgAge + empPtr->age;
            empPtr++;
		}

        
        printf("\nThe average age is %.2lf", avgAge / 2.0);

		return 0;
	}