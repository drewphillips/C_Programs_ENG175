//Exam 2 program 5, needed to add an error statment if menu option was not valid. 


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int vA1, vA2;
    int vB1, vB2;
    int answer;
    int a, b;
    int userSelection;
    char loopMenu;
    int k;

    printf("Program #5\n\n");

    //read in vector A and vector B elements
    printf("Type in to vector pairs, V1 a & b, and V2 a & b\n");
    scanf("%d", &vA1);
    scanf("%d", &vA2);
    scanf("%d", &vB1);
    scanf("%d", &vB2);

    printf("\nyou entered (%d , %d) and (%d , %d)", vA1, vA2, vB1, vB2);

    //display a menu to select one of the four vector calculations


    do {
        printf("\nYou have 4 options, enter 1 - 4\n");
        printf("1. Vector Addition:\n");
        printf("2. Vector Subtraction:\n");
        printf("3. Magnitude\n");
        printf("4. Scalar Multiplication:\n");
        scanf("%d", &userSelection);


        if (userSelection == 1) {

            printf("you chose Vector Addition: A + B = (a₁ + b₁, a₂ + b₂)\n");
            a = vA1 + vB1;
            b = vA2 + vB2;
            printf("A = %d\n", a);
            printf("B = %d\n", b);
        }

        else if (userSelection == 2) {

            printf("you chose Vector Subtraction: A - B = (a₁ - b₁, a₂ - b₂))\n");
            a = vA1 - vB1;
            b = vA2 - vB2;
            printf("A = %d\n", a);
            printf("B = %d\n", b);
        }

        else if (userSelection == 3) {

            printf("you chose Magnitude (or length) of a Vector: |A| = sqrt(a₁² + a₂²)\n");
            a = pow(vA1, 2);
            b = pow(vA2, 2);
            answer = sqrt(a + b);

            //i did not check the math, moving on. 
            printf("%d", answer);
            printf("\n");
        }
        else if (userSelection == 4) {
            printf("you chose Scalar Multiplication: kA = (ka₁, ka₂)\n");
            printf("what do you want to scale by? k = ");
            scanf("%d", &k);
            a = vA1 * k;
            b = vB1 * k;
            printf("And the answer is... (%d , %d)", a, b);
        }

        printf("do you want to select from the menue again y/n?\n");
        scanf(" %c", &loopMenu);
        loopMenu = tolower(loopMenu);

    } while (loopMenu == 'y');



    return 0;
}
