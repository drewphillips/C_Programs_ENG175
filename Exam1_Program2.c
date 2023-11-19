/*Program in zyBooks, copy / paste code in the text box provided with this D2L question before your time has exceeded.

Write a C program that ...

reads in a color into a string
prints the string and the string length
reads in an animal into a string
prints the string and the string length
compare the color string to "orange" and print results
concatenate color and animal and print results with a space in between
do not loop
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char color[30];
	char animal[30];
	char stringLength;
	printf("PROGRAM #2\n\n");

	//reads in a color into a string prints the string and the string length
	printf("Enter a color:\n");
	scanf("%s", color);
	printf("The color is: %s\n", color);
	printf("The string length is: %lu\n", strlen(color));

	//reads in an animal into a string prints the string and the string length
	printf("Enter a animal:\n");
	scanf("%s", animal);
	printf("\tThe Animal is: %s\n", animal);
	printf("\tThe string length is: %lu\n", strlen(animal));

	//compare the color string to "orange" and print results

	if (strcmp(color, "orange") == 0) {
		printf("\tYour colors match\n");
	}
	else {
		printf("\tYour colors don't match\n");
	}

	//concatenate color and animal and print results with a space in between
	strcat(color, " ");
	strcat(color, animal);
	printf("\t%s\n", color);

	/*
 do not loop
 */

	return 0;
}

/*
The correct answer is not displayed for Written Response type questions.

Hide question 22 feedback
//COPY and PASTED CODE FROM D2L for grading on 10/16/23

(2.5) reads color, prints, length

(2.5) reads animal, prints, length

(2.5) strcmp for color and "orange"

(2.5) strcat with color, space and animal
*/
