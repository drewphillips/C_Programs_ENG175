/*
Write a C program to work with strings.  Your program must ...

read in an engineering term
print the string
calculate and print the length of the string
calculate and print the number of a's, e's i's, o's and u's
loop until the user wants to quit
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
 char loopAgain;

int main()
{
    //declarVars
    char engTerm[30];
    int termLength;
    int i;
    int numVowels;
    
    do {
        printf("Enter and Engineering phrase: ");
        scanf("%s", engTerm);

        //print the string
        printf("\tYour eng phrase is: %s\n", engTerm);
    
        //calculate and print the length of the string
        termLength = strlen(engTerm);
        printf("\tYour term length is: %d\n", termLength);

        numVowels = 0;
        for (i = 0; i < termLength -1; i++) {
        
            switch(engTerm[i]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
            numVowels++;
            }

        }

        //calculate and print the number of a's, e's i's, o's and u's
        printf("\tNumber of vowels are: %d", numVowels);

        //loop until the user wants to quit
        printf("\nDo you want to enter a new word? y/n\n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);

    } while (loopAgain == 'y');
    

    return 0;
}
