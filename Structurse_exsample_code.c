#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {

	char type[15];
	char color[10];
	int quantity;
	double price;

}ToyStruct;

int main()
{
	ToyStruct toyOrder[6];
	int numToyTypes;
	int error;		//1 if misspelling
	double subTotal;
	char loopAgain;
	int i;

	do {
		subTotal = 0.0;
		i = 0;

		printf("  Enter your online order!\n\n  ");

		printf("  Toy Type: train, car, doll, yoyo or puzzle\n  ");
		printf("  Price List: train $49.95, car and doll $29.95, yoyo and puzzle $19.95\n  ");

		printf("\nHow many Toys? ");
		scanf("%d", &numToyTypes);
		printf("\n\n");

		do {
			error = 0;

			printf("Enter  Toy Type: ");
			scanf("%s", toyOrder[i].type);

			if ((strcmp(toyOrder[i].type, "train") == 0))
				toyOrder[i].price = 49.95;
			else if ((strcmp(toyOrder[i].type, "car") == 0))
				toyOrder[i].price = 29.95;
			else if ((strcmp(toyOrder[i].type, "doll") == 0))
				toyOrder[i].price = 29.95;
			else if ((strcmp(toyOrder[i].type, "yoyo") == 0))
				toyOrder[i].price = 19.95;
			else if ((strcmp(toyOrder[i].type, "puzzle") == 0))
				toyOrder[i].price = 9.95;
			else {
				printf("enter lower case and exact spelling, please!\n");
				error = 1;
			}

			if (error == 0) {
				printf("Enter Toy Color: ");
				scanf("%s", toyOrder[i].color);

				printf("How many %s %ss? ", toyOrder[i].color, toyOrder[i].type);
				scanf("%d", &toyOrder[i].quantity);
				printf("\n");

				i = i + 1;
			}

		} while (i < numToyTypes);

		if (error == 0) {
			for (i = 0; i < numToyTypes; i++) {
				subTotal = subTotal + toyOrder[i].quantity * toyOrder[i].price;
			}

			printf("\n\n---------\n");
			printf("subTotal = $%.2lf\n", subTotal);
			printf("tax = $%.2lf\n", subTotal * 0.09);
			printf("\n");
			printf("  grandTotal = $%.2lf \n\n", subTotal + subTotal * 0.09);
		}

		printf("\n\nAnother online order? y/n ");
		scanf(" %c", &loopAgain);
		loopAgain = tolower(loopAgain);

	} while (loopAgain == 'y');

	return 0;
}
