#include <stdio.h>
#include <ctype.h>

// 14.6.1 UDF

void SelectionSort(int numbers[], int numbersSize) {
   int i;
   int j;
   int indexSmallest;
   int temp;      // Temporary variable for swap
   
   for (i = 0; i < numbersSize - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < numbersSize; ++j) {
         printf("%d ", numbers[j]);
         if ( numbers[j] < numbers[indexSmallest] ) {
            indexSmallest = j;
            printf("\n");
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}

//14.7.1 UDF 

void InsertionSort(int numbers[], int numbersSize) {
   int i;
   int j;
   int temp;      // Temporary variable for swap
   
   for (i = 1; i < numbersSize; ++i) {
      j = i;
      printf("%d ", numbers[i]);
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
      printf("\n");
   }
}

int main()
{

    char loopAgain;
    //int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
    const int NUMBERS_SIZE = 8;
    int i;
    int userSelectiuon;

    do {

        int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };

        printf("Lets sort some things, what type of algo do you want to use?\n1) Selection Sort\n2) Insertion Sort.\n");
        scanf("%d", &userSelectiuon);
        if (userSelectiuon == 1) {

            printf("UNSORTED: ");
            for (i = 0; i < NUMBERS_SIZE; ++i) {
            printf("%i ", numbers[i]);
            }
            printf("\n");
   
            SelectionSort(numbers, NUMBERS_SIZE);
   
            printf("\nSORTED: ");
            for (i = 0; i < NUMBERS_SIZE; ++i) {
            printf("%i ", numbers[i]);
            }
            printf("\n");
        }
        else if (userSelectiuon == 2) { 
        
        printf("UNSORTED: ");
        for (i = 0; i < NUMBERS_SIZE; ++i) {
        printf("%i ", numbers[i]);
        }
        printf("\n");
   
        InsertionSort(numbers, NUMBERS_SIZE);
   
        printf("\nSORTED: ");
        for (i = 0; i < NUMBERS_SIZE; ++i) {
        printf("%i ", numbers[i]);
        }
            printf("\n");

        
        }

        else 
        printf("You can only select 1 or 2, please try again.");
        

        printf("do you want to go again? y/n");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
    } while (loopAgain == 'y');
    
    
    return 0;
}
