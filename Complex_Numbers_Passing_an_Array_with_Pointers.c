#include <stdio.h>
#include <ctype.h>
#include <math.h>

void readUDF(double Coeffs[5]) {
    printf("First conplex number a+bi... \n");
    printf(" a = ");
    scanf("%lf", &Coeffs[0]);
    printf(" b = ");
    scanf("%lf", &Coeffs[1]);
    printf("First conplex number c+di... \n");
    printf(" c = ");
    scanf("%lf", &Coeffs[2]);
    printf(" d = ");
    scanf("%lf", &Coeffs[3]);
}

void divideUDF(double Coeffs[5]) {
    double real, imag;
    real = ( Coeffs[0]*Coeffs[2] + Coeffs[1] * Coeffs[3] / pow(Coeffs[2], 2) + pow(Coeffs[3], 2) );
    imag = (Coeffs[1]*Coeffs[2] - Coeffs[0]* Coeffs[3] / pow(Coeffs[2], 2) + pow(Coeffs[4], 2) );

    printf(" ... Deviding + %.2lf + %.2lf i", real, imag);

    return;
}

void AddSubUDF(double Coeffs[5]) {
    double add;
    double addImag;
    double sub;
    double subImag;
    add = ( Coeffs[0] + Coeffs[2]);
    addImag = + (Coeffs[1] + Coeffs[3]);
    sub = (Coeffs[0] - Coeffs[2]);
    subImag = (Coeffs[1] - Coeffs[3]);

    printf("Adding the complex numbers = %.2lf + %.2lfi\n", add, addImag);
    printf("Subtracting the complex numbers = %.2lf + %.2lfi\n", sub, subImag);

    return;
}

void multiplyUDF(double Coeffs[5]) {
    double first;
    double outer;
    double iner;
    double last;
    double iSquared;
    double addReal;
    double addImag;
    first =  Coeffs[0] * Coeffs[2];
    outer =  Coeffs[0] * Coeffs[3];
    iner =  Coeffs[1] * Coeffs[2]; 
    last =  Coeffs[1] * Coeffs[3];
    iSquared = last * -1; 
     
    addReal = first + iSquared;
    addImag = outer + iner;

    printf("Multiply the complext numbers and you get: %.2lf + %.2lfi", addReal, addImag);

//FIX me, So now I see how it is that this formula would work with less code, so can I hack it...
// (ac-bd) + (ad+bc)i
//  https://www.youtube.com/watch?v=wQnXN0xljR0

    return;
}

void multiply2UDF(double Coeffs[5]) {
    double real;
    double imag;
    real = ( (Coeffs[0] * Coeffs[2]) - (Coeffs[1] * Coeffs[3]) );
    imag = ( (Coeffs[0] * Coeffs[3]) + (Coeffs[1] * Coeffs[2]) );
    printf("Multiply the complext numbers and you get: %.2lf + %.2lfi", real, imag);

    return;
}

void TimesConjugate(double Coeffs[5]) {
    double answer1;
    double answer2;
    answer1 = (Coeffs[0] * Coeffs[0] + Coeffs[1] * Coeffs[1]);
    answer2 = (Coeffs[2] * Coeffs[2] + Coeffs[3] * Coeffs[3]);
    printf("Times Conjugate = %.2lf & %.2lf", answer1, answer2);

    return;
}

int main()
{
    char loopAgain;
    double coeffs[5];
    int userSelection;

    do {
        printf("Complex Number Claulator\n");
        readUDF(coeffs);

        printf("a + bi = %.2lf + %.2lf i \n", coeffs[0], coeffs[1]);
        printf("c + di = %.2lf + %.2lf i \n", coeffs[2], coeffs[3]);

        //provide a menu to select one of three choices:  1. add/sub or 2. multiply or 3. divide

        printf("--- MENU ---\n");
        printf("1. add/sub\n");
        printf("2. Multiply\n");
        printf("3. Times Conjugate\n");
        printf("4. Divide\n");
        printf("5. Multiply with less code\n");
        printf("Make a selection, 1, 2, 3, 4 or 5.\n");
        scanf("%d", &userSelection);

        if (userSelection == 1) {
            printf("1. add/sub\n");
            AddSubUDF(coeffs);
        }

        else if (userSelection == 2 ) {
            printf("2. multiply\n");
            multiplyUDF(coeffs);
        }

        else if (userSelection == 3) {
            printf("3. times conjugate");
            TimesConjugate(coeffs);
        }

        else if (userSelection == 4 ) {
            printf("3. divide = ");
            divideUDF(coeffs);
        }

        else if (userSelection == 5) {
            printf("5. Multiply with less code\n");
            multiply2UDF(coeffs);

        }

        else 
            printf("\nYou can ony select 1, 2, 3, 4 or 5\n");


        printf("\nDo you want to go again? Y/N");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
    } while (loopAgain == 'y');
    
    return 0;
}
