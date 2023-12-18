#include <stdio.h>
#include <ctype.h>

int main()
{

    //declareVars
    char loopAgain;
    int n, i;

    do {
        printf("Sum squares from one to n!\n");
        printf("Enter an integer:\n");
        scanf("%d", &n);

        printf("\n\t");
        for (i = 1; i <= n; i++) {
            if (i != n) {
                printf("%d,", i*i);
            }
            else {
                printf("%d ", i*i);
            }

        }

        printf("\nAnother sum? y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);

    } while (loopAgain == 'y');
   

    return 0;
}
