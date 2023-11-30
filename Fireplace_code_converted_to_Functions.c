// Yes I just copied the exsample code, now reading the instuctions, Ill make this in to UDF's.

#include <stdio.h>
#include <ctype.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"


//add a UDF and use pointers to read in the table values
void ReadInUDF(int ArrayFP[3][2]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter an array [%d][%d]:", i + 1, j + 1);
            scanf("%d", &ArrayFP[i][j]);
        }
    }


}


//add a UDF to calculate row totals

void RowSum(int ArrayFP[3][2]) {
    int i, j;
    int RowTot = 0;
    for (j = 0; j < 2; j++) {
        RowTot = RowTot + ArrayFP[i][j];
    }
        printf("\x1b[33m");
        printf("%10d", RowTot);
        printf("\x1b[0m");
        printf("\n\n");
    
    return;
}

/*
grandSum = 0;
                printf("Total\t");
                for (j=0; j<2; j++) {
                colSum = 0;
                for (i=0; i<3; i++) {
                colSum = colSum + arrayFP[i][j];

                }
                }
                printf("\x1b[35m");
                printf("%9d", colSum);
                printf("\x1b[0m");

                grandSum = grandSum + colSum;


                printf("\x1b[36m");
                printf("%9d", grandSum);
                printf("\x1b[0m");
*/


int main()
{
    char loopAgain;
    int i, j;
    int arrayFP[3][2];
    int rowSum, colSum, grandSum;

    do {

        printf("FirePlace Data!\n");
        ReadInUDF(arrayFP);

        printf("\n\n");
        printf("---------------------------------\n");
        printf(" Bonus if sale price > $175,000\n");
        printf("#Fireplaces   NoBonus   Bonus   Total\n");
        printf("---------------------------------\n");

        for (i = 0; i < 3; i++) {
            if (i == 0)
                printf("\t 0");
            else if (i == 1)
                printf("\t1");
            else if (i == 2)
                printf("\t2");

        }

        RowSum(arrayFP);


        printf("\nThe user can't quit, you must loop again, do it again? y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);

    } while (loopAgain == 'y');

    return 0;
}