/*
ENG 175 Comp Program Engineering
code borrowed from...
 https://www.sanfoundry.com/c-program-perform-matrix-multiplication/
https://www.geeksforgeeks.org/c-transpose-matrix/
https://www.sanfoundry.com/c-program-compute-determinant-matrix/
 https://www.tutorialspoint.com/how-to-calculate-transpose-of-a-matrix-using-c-program // this one did not help me solve number 5....
 
My code on GitHub: https://github.com/drewphillips/matrix_calulator.c

Notes: 
I spent the better part of Sunday trying to calculate the Determinant the hard way by expanding the matrix and cross multiplying, 
trying to come up with some fancy for loop. 
That's how I learned how to find the determinant not realizing there was a simpler formula for programming... 
oy vey, that code is still below commented out.

And error detection could be better on option 6 as if one matrix is square but the other is not, the code could still compute the square matrix.

Adding color, all answers are in blue, and errors are in red.

*/ 

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main()
{
    int matrix1[10][10];
    int matrix2[10][10];
    int m1Rows = 0;
    int m1Colum = 0;
    int m2Rows = 0;
    int m2Colum = 0;
    char loopAgain;
    int i, j, k;
    int userChoice;
    int loopMenu;
    int multiplyer = 0;
    int answer[10][10];
    int outputMatrix[10][10];
    int transM1[m1Colum][m1Rows];  // set with the inverse of the primary array
    int transM2[m2Colum][m2Rows];   // set with the inverse of the primary array
    int determTotal1;
    int determTotal2;
    int m155[5][5];
    int m255[5][5];
    int determinant1;
    int determinant2;
    
    //Read in integers for two r x c matrices A and B.Max size for both matrices is 10x10.  

    do {
        printf("Lets set up two matrix tables, max 10x10 each. How many rows and columns do you want to create for the first table?\n");
        printf("Rows = ");
        scanf("%d", &m1Rows);
        printf("Columns = ");
        scanf("%d", &m1Colum);
        printf("\n");


        printf("How many rows and columns do you want to create for the second table? max 10\n");
        printf("Rows = ");
        scanf("%d", &m2Rows);
        printf("Columns = ");
        scanf("%d", &m2Colum);
        printf("\n");

        //scan in matrix 1
        for (i = 0; i < m1Rows; i++) {
            for (j = 0; j < m1Colum; j++) {
            printf("Enter values one at a time for Matrix #1\n");
            scanf("%d", &matrix1[i][j]);
            }
        }

         //scan in matrix 2
         for (i = 0; i < m2Rows; i++) {
            for (j = 0; j < m2Colum; j++) {
            printf("Enter values one at a time for Matrix #2\n");
            scanf("%d", &matrix2[i][j]);
            }
        }

         //Print matrix A and matrix B.

         printf("\n");
         printf("Matrix Array 1\n");
            
         for (i = 0; i < m1Rows; i++) {
            for (j = 0; j < m1Colum; j++) {
                    printf("%5d", matrix1[i][j]);
            }
                printf("\n");
         }

          printf("\n");
          printf("Matrix Array 2\n");
            
          for (i = 0; i < m2Rows; i++) {
            for (j = 0; j < m2Colum; j++) {
                    printf("%5d", matrix2[i][j]);
            }
                printf("\n");
          }
    


          //Display menu to choose from add, subtract, scalar multiply, matrix multiply, transposeand determinant
          do {
              
                printf(ANSI_COLOR_MAGENTA);
                printf("\n\n\n");
                printf("M E N U\n");
                printf("1. Add Matrix 1 + Matrix 2\n");
                printf("2. Subtract Matrix 1 + Matrix 2\n");
                printf("3. Scalar multiply Matrix 1 & Matrix 2 * a Constant Variable\n");
                printf("4. Matrix multiplyMatrix 1 + Matrix 2\n");
                printf("5. Transpose Matrix 1 + Matrix 2\n");
                printf("6. Determinant Matrix 1 + Matrix 2\n");
                printf(ANSI_COLOR_RESET);

                //and now a menue
                printf("\nChoose an option: ");
                scanf("%d", &userChoice);

                switch (userChoice) {

                    //If add is selected, calculateand print A + B or specific error if operation is not possible
                case 1:
                    printf("Add Matrix 1 and 2\n");
                    printf("\n");

                    if ((m1Rows == m2Rows) && (m1Colum == m2Colum)) {
                        for (i = 0; i < m1Rows; i++) {
                            for (j = 0; j < m1Colum; j++) {
                                answer[i][j] = matrix1[i][j] + matrix2[i][j];
                            }
                        }

                        for (i = 0; i < m1Rows; i++) {
                            for (j = 0; j < m1Colum; j++) {
                                printf(ANSI_COLOR_BLUE);
                                printf("%d ", answer[i][j]);
                                printf(ANSI_COLOR_RESET);
                            }
                            printf("\n");
                        }
                    }

                    else {
                        printf("\n");
                        printf(ANSI_COLOR_RED);
                        printf("ERROR! Matrices must be the same size to add together.");
                        printf(ANSI_COLOR_RESET);
                        printf("\n");
                    }

                    break;

                    //If subtract is selected, calculateand print A - B or specific error if operation is not possible
                case 2:
                    printf("Subtract Matrix 1 from Matrix 2\n");
                    printf("\n");

                    if ((m1Rows == m2Rows) && (m1Colum == m2Colum)) {
                        for (i = 0; i < m1Rows; i++) {
                            for (j = 0; j < m1Colum; j++) {
                                answer[i][j] = matrix1[i][j] - matrix2[i][j];
                            }
                        }

                        for (i = 0; i < m1Rows; i++) {
                            for (j = 0; j < m1Colum; j++) {
                                printf(ANSI_COLOR_BLUE);
                                printf("%d ", answer[i][j]);
                                printf(ANSI_COLOR_RESET);
                            }
                            printf("\n");
                        }
                    }

                    else {
                        printf("\n");
                        printf(ANSI_COLOR_RED);
                        printf("ERROR! Matrices must be the same size to subtract.");
                        printf(ANSI_COLOR_RESET);
                        printf("\n");
                    }

                    break;

                    //If scalar multiply is selected, read in scalarand calculateand print scalar* A and scalar* B
                case 3:

                    printf("Scalar Multiply");
                    printf("scalar multiply, what is the value of the constant to multipy by? \n");
                    scanf("%d", &multiplyer);
                    printf("You entered %d\n", multiplyer);

                    for (i = 0; i < m1Rows; i++) {
                        for (j = 0; j < m1Colum; j++) {
                            answer[i][j] = multiplyer * matrix1[i][j];
                        }

                    }

                    printf("Multiplied Matrix 1 by Constant = \n");
                    for (i = 0; i < m1Rows; i++) {
                        printf("\n");
                        for (j = 0; j < m1Colum; j++) {
                            printf(ANSI_COLOR_BLUE);
                            printf("%d ", answer[i][j]);
                            printf(ANSI_COLOR_RESET);
                        }
                    }

                    // calulate martix 2

                    for (i = 0; i < m2Rows; i++) {
                        for (j = 0; j < m2Colum; j++) {
                            answer[i][j] = multiplyer * matrix2[i][j];
                        }

                    }

                    printf("\n");
                    printf("\nMultiplied Matrix 2 by constant =\n");
                    for (i = 0; i < m2Rows; i++) {
                        printf("\n");
                        for (j = 0; j < m2Colum; j++) {
                            printf(ANSI_COLOR_BLUE);
                            printf("%d ", answer[i][j]);
                            printf(ANSI_COLOR_RESET);
                        }
                    }
                    printf("\n");
                    printf("\n");

                    break;

                    //If matrix multiplication is selected, calculateand print A* B or specific error if operation is not possible
                case 4:
                    printf("matrix multiply\n");

                    //outputMatrix[i][j] = 0;

                    if (m1Colum != m2Rows) {
                        printf(ANSI_COLOR_RED);
                        printf("\n");
                        printf("Matriices cant be multiplied together\n");
                        printf(ANSI_COLOR_RESET);
                    }


                    for (i = 0; i < m1Rows; i++) {
                        for (j = 0; j < m1Colum; j++) {
                            outputMatrix[i][j] = 0;
                        
                            for (k = 0; k < m1Colum; k++) {

                                outputMatrix[i][j] = matrix1[i][k] * matrix2[k][j] + matrix1[i][j] * matrix2[k][k];



                            }

                        }

                    }
                    printf("\n");
                    printf("Multiplied matrix\n");
                    for (int i = 0; i < m1Rows; i++) {
                        for (int j = 0; j < m2Colum; j++) {

                            printf(ANSI_COLOR_BLUE);
                            printf("%d\t", outputMatrix[i][j]);
                            printf(ANSI_COLOR_RESET);
                        }
                        printf("\n");
                    }

                    break;
                    
                    //If transpose is selected, calculateand print A^ T or specific error if operation is not possible
                    case 5:
                    printf("Transpose\n");
                    
                    /* Vars used
                    int transM1[m1Colum][m1Rows];  // set with the inverse of the primary array
                    int transM2[m2Colum][m2Rows];   // set with the inverse of the primary array
                    
                    */
                    for (i = 0; i < m1Rows; i++) {
                        
                        for (j = 0; j < m1Colum; j++) {
                        
                            transM1[j][i] = matrix1[i][j]; 
                   
                        }
                    }

                    printf("Transposed matrix\n");
                    for (i = 0; i < m1Colum; i++) {
                        for (j = 0; j < m1Rows; j++) {

                            printf(ANSI_COLOR_BLUE);
                            printf("%d\t", transM1[i][j]);
                            printf(ANSI_COLOR_RESET);
                        }
                        printf("\n");
                    }



                    break;
                
                    //If determinant is selected, calculateand print 2x2 or 3x3 determinants or specific error if operation is not possible
                case 6:
                    printf("Determinant\n");
                    printf("\n");

                    //error reporting
                    if (m1Rows != m1Colum) {
                        printf("\n");
                        printf(ANSI_COLOR_RED);
                        printf("ERROR! Matrices 1 must be square to find the determinant\n");
                        printf(ANSI_COLOR_RESET);
                        printf("\n");
                    }

                    else if (m2Rows != m2Colum) {
                        printf("\n");
                        printf(ANSI_COLOR_RED);
                        printf("ERROR! Matrices 2 must be square to find the determinant\n");
                        printf(ANSI_COLOR_RESET);
                        printf("\n");
                    }



                    // 2x2 simple math
                    else if (m1Rows == 2 && m1Colum == 2 && m2Rows == 2 && m2Colum == 2) {
                        
                        determTotal1 = matrix1[0][0] * matrix1[1][1] - matrix1[1][0] * matrix1[0][1];
                        printf(ANSI_COLOR_BLUE);
                        printf("Matrix 1 = %d\n", determTotal1);
                        
                    
                        determTotal2 = matrix2[0][0] * matrix2[1][1] - matrix2[1][0] * matrix2[0][1];
                        printf("Martix 2 = %d", determTotal2);
                        printf(ANSI_COLOR_RESET);
                       
                        printf("\n");
                    }

                    //3x3 the easy way. 
                    else if (m1Rows == 3 && m1Colum == 3 && m2Rows == 3 && m2Colum == 3) {
                        determinant1 = matrix1[0][0] * ((matrix1[1][1] * matrix1[2][2]) - (matrix1[2][1] * matrix1[1][2])) - matrix1[0][1] * (matrix1[1][0] * matrix1[2][2] - matrix1[2][0] * matrix1[1][2]) + matrix1[0][2] * (matrix1[1][0] * matrix1[2][1] - matrix1[2][0] * matrix1[1][1]);
                        determinant2 = matrix2[0][0] * ((matrix2[1][1] * matrix2[2][2]) - (matrix2[2][1] * matrix2[1][2])) - matrix2[0][1] * (matrix2[1][0] * matrix2[2][2] - matrix2[2][0] * matrix2[1][2]) + matrix2[0][2] * (matrix2[1][0] * matrix2[2][1] - matrix2[2][0] * matrix2[1][1]);

                        printf(ANSI_COLOR_BLUE);
                        printf("\nDeterminant of the first 3X3 matrix: %d", determinant1);
                        printf("\n");

                        printf("\n");

                        printf("\nDeterminant of the second 3X3 matrix: %d", determinant2);
                        printf(ANSI_COLOR_RESET);
                        printf("\n");

                    } 

                    break;

                             //THe hard way, yet the easy way in math on paper... 
                            /*
                            else if (m1Rows == 3 && m1Colum == 3 && m2Rows == 3 && m2Colum == 3) {

                            //convert Matrix 1 to 5x3
                            for (i = 0; i < m1Rows; i++) {
                                for (j = 0; j < m1Colum; j++) {
                                    (m155[i][j] = matrix1[i][j]);

                                }
                            }



                            m155[0][3] = matrix1[0][0];
                            m155[1][3] = matrix1[1][0];
                            m155[2][3] = matrix1[2][0];

                            m155[0][4] = matrix1[0][1];
                            m155[1][4] = matrix1[1][1];
                            m155[2][4] = matrix1[2][1];

                            printf("Matrix Array 1 converted to 5x3\n");

                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 5; j++) {
                                    printf("%5d", m155[i][j]);
                                }
                                printf("\n");
                            }

                            //convert Matrix 2 to 5x3
                            /*
                            for (i = 0; i < m2Rows; i++) {
                                for (j = 0; j < m2Colum; j++) {
                                    (m255[i][j] = matrix2[i][j]);

                                }
                            }
                            m255[0][3] = matrix2[0][0];
                            m255[1][3] = matrix2[1][0];
                            m255[2][3] = matrix2[2][0];

                            m255[0][4] = matrix2[0][1];
                            m255[1][4] = matrix2[1][1];
                            m255[2][4] = matrix2[2][1];

                            printf("Matrix Array 2 5x3\n");

                            for (i = 0; i < 5; i++) {
                                for (j = 0; j < 3; j++) {
                                    printf("%5d", m255[i][j]);
                                }
                                printf("\n");
                            }

                            printf("now we apply the long math ... \n");

                            determTotal1 = ((matrix1[0][0] * matrix1[1][1] * matrix1[2][2]) + (matrix1[0][1] * matrix1[1][2] * matrix1[2][3]) + (matrix1[0][2] * matrix1[1][3] * matrix1[2][4])) - ((matrix1[2][0] * matrix1[1][1] * matrix1[0][2]) + (matrix1[2][1] * matrix1[1][2] * matrix1[0][3]) + (matrix1[2][2] * matrix1[1][3] * matrix1[0][4]));

                            printf("Matrix 1 = %d\n", determTotal1);

                            /*
                            determTotal2 = matrix2[0][0] * matrix2[1][1] * matrix2[2][2] + matrix2[0][1] * matrix2[1][2] * matrix2[2][3] + matrix2[0][2] * matrix2[1][3] * matrix2[2][4] - matrix2[2][0] * matrix2[1][1] * matrix2[0][2] + matrix2[2][1] * matrix2[1][2] * matrix2[0][3] + matrix2[2][2] * matrix2[1][3] * matrix2[0][4];



                            printf("Martix 2 = %d\n", determTotal2);

                            printf("and I have no idea what the jiberish output on the screen is ... \n");
                            }


                            printf("\n");
                            */
                    
                    // print a red error warning if 1 - 6 is not selected.
                    default:
                    printf(ANSI_COLOR_RED);
                    printf("Invalid option, please select 1 - 6 only\n");
                    printf(ANSI_COLOR_RESET);

                }
                                
          } while (loopMenu == 'y'); // end loop menue
            
        //Loop the entire program until the user wants to quit.
        
        printf("Set up two more Matrixes? y/n ");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);
     
    } while (loopAgain == 'y');

        return 0;
}

/*
Overall Feedback
+2 reads and prints A 2x2 and B 3x3

-2 menu does not loop (for each selection A and B have to be re-entered)
+2 error for subtraction
+2 error for multiplication
+0 transposes A and B (not completed)
+0 determinant A and B (not completed)
*/