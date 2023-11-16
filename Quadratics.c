#include <stdio.h>
#include <math.h>
#include <ctype.h>

// call one udf to calculate solutions and print in int main(void) pass a, b, c by value pass solutions by reference (pointers)
void imagUDF(double A, double B, double C, double* Real, double* Imag) {
    *Real = -B / (2.0 * A);
    *Imag = (sqrt((pow(B, 2) - 4 * (A) * (C)) * -1)) / (2.0 * A);

    return;

}

void realTwoUDF(double A, double B, double C, double* Real1, double* Real2) {
    double Discrim;
    double AbsDiscrim;
    Discrim = B * B - 4 * A * C;
    AbsDiscrim = fabs(Discrim);

    *Real1 = (-B + sqrt(Discrim)) / 2 * A;
    *Real2 = (-B - sqrt(Discrim)) / 2 * A;

    return;

}

void oneReal(double A, double B, double C, double* Real) {
    double Discrim = 0; // you dont need this for the calculation.

    *Real = -B / 2 * A;
    return;

}

int main()
{

    double a;
    double b;
    double c;
    double discrim;
    char loopAgain;
    double real;
    double imag;
    double real1;
    double real2;

    do {

        //read in coefficients a, b, c in int main(void)

        printf("-- Quadratic Calulations --\n\n");
        printf("\tRead in coefficients a, b and c.\n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        scanf("%lf", &c);

        printf("Calculating The Discriminant...\n");
        discrim = b * b - 4 * a * c;

        printf("Discrimanat = %lf\n", discrim);

        /*
        print a message that there are two imaginary solutions
        call one udf to calculate solutions and print in int main(void)
        pass a, b, c by value
        pass solutions by reference (pointers)
        */

        if (discrim < 0) {
            printf("\tCalulating two imaginary solutions....\n");
            imagUDF(a, b, c, &real, &imag);
            printf("\t%.2lf +/- %.2lf i \n", real, imag);
        }

        /*
        print a message that there are two real solutions
        call one udf to calculate solutions and print in int main(void)
        pass a, b, c by value
        pass solutions by reference (pointers)
        */

        else if (discrim > 0) {
            printf("\tCalulating two real solutions...\n");
            realTwoUDF(a, b, c, &real1, &real2);
            printf("\tThere are two real solution: %.2lf & %.2lf \n", real1, real2);

        }

        /*
        print a message that there are two real solutions all one udf to calculate solutions and print in int main(void)
        pass a, b, c by value pass solutions by reference (pointers)
        */
        
        else if (discrim == 0) {
            printf("\tCalulating one real solutions...\n");
            oneReal(a, b, c, &real);
            printf("\tThere is one real solution: %.2lf \n", real);

        }

        //Loop until the user wants to quit

        printf("\n\nAnother quadrati? y/n: ");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);

    } while (loopAgain == 'y');

    return 0;
}