#include <stdio.h>
#include <ctype.h>

int main()
{
    int arrayA[5][5];
    int numRows = 0;
    int numColum = 0;
    char loopAgain;
    int i, j;
    int sum, columSum, grandTotal;

    do {
    printf("Lets set up a matrix, max 5x5. How many rows and columns do you want to create?\n");
    printf("Rows = ");
    scanf("%d", &numRows);
    printf("Columns = ");
    scanf("%d", &numColum);
    printf("\n");


        for (i = 0; i < numRows; i++) {
            for (j = 0; j < numColum; j++) {
            printf("Enter values one at a time\n");
            scanf("%d", &arrayA[i][j]);
            }
        }

        printf("Your Matrix Table\n");
        for (i = 0; i < numRows; i++) {
            sum = 0;
            for (j = 0; j < numColum; j++) {
            printf("%5d ", arrayA[i][j]);
            sum = sum + arrayA[i][j];
            grandTotal = grandTotal + arrayA[i][j];
            }
            
            printf(" = %5d", sum);
            printf("\n");
           
            }
             printf("\n");

             


            printf("The columns sums \n");
            for (j=0; j<numColum; j++) {
                columSum = 0;
             for (i=0; i<numRows; i++){
            
            columSum = columSum + arrayA[i][j];
            }
            printf("%5d", columSum);
            
            }
            printf("\n");
            printf("And the Grand total is...\n");
                printf("%d\n", grandTotal);

    printf("Another table? y/n ");
    scanf(" %c", &loopAgain);
    loopAgain = tolower(loopAgain);
    } while (loopAgain == 'y');


    
    return 0;
}
