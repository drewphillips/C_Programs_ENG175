/*
Modify the C program by ...

Adding a "Do-While Loop" to loop until the user wants to quit
Adding an "If-Else" structure to ask if male or female to calculate calories burned (instead of printing both calculations)
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) {

	double age, weight;
	double HRate, time;
	double caloriesFemale, caloriesMale;
    char loopAgain;
    char gender;

    do {
	printf("*****   Calories Burned Calculator!    *****\n");
	printf("Enter Age: ");
	scanf("%lf", &age);
	printf("Enter Weight: ");
	scanf("%lf", &weight);
	printf("Enter Heart Rate: ");
	scanf("%lf", &HRate);
	printf("Enter time: ");
	scanf("%lf", &time);

	caloriesMale = ((age * 0.2017) + (weight * 0.09036) + (HRate * 0.6309) - 55.0969) * time / 4.184;
	caloriesFemale = ((age * 0.074) - (weight * 0.05741) + (HRate * 0.4472) - 20.4022) * time / 4.184;

    printf(" Enter M for male and F for Female:\n");
    scanf(" %c", &gender);
    gender = toupper(gender);
    
    if (gender == 'M') {
	printf("\nTotal calories burned *****\n");
    printf("\n\tmen = %.2lf\n", caloriesMale);
    }
    else {
    printf("\nTotal calories burned *****\n");
	printf("\n\twomen = %.2lf\n", caloriesFemale);
    }

    printf("DO a nerw calulater? y/n\n");
    scanf(" %c", &loopAgain);
    loopAgain = tolower(loopAgain);
    } while (loopAgain == 'y');

	return 0;
}