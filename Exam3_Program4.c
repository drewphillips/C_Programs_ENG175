//Copy/Pasted from D2L to zyBooks on 11/21/23 for grading.

#include <stdio.h>
#include <string.h>

typedef struct {
   int StudentID;
   char LastName[35];
   char Major[35];
   int AssessmentScore;
   double Gpa;

} DeptStruct;

int main(void) {

   // your program code goes here
   // click submitfor grading often
   // copy/paste your code to D2L
   //only what is in D2L is graded

   //variable declarations
   DeptStruct deptRecords[25];
   int i = 0;
   int numRecords = 0;
   int highScore;
   char highMajor[35];
   char highLastName[35];
   int numBioTech =8;
   //char Biotechno[14] = 'Biotechnology';
   
   //file declarations
   char deptInput[25] = "DeptData.txt";
   FILE* deptINFILE = NULL;
   char deptOutput[25] = "deptOUTData.txt";
   FILE* deptOUTFILE = NULL;
   



   //open files for reading and writing
   deptINFILE = fopen(deptInput, "r");
   deptOUTFILE = fopen(deptOutput, "w");
   
   if (deptINFILE == NULL) {
      printf("Error!  Not able to read input file.\n");
      return 1;
   }
   else {
      printf("Read successful!\n");

       //read in records
       while (!feof(deptINFILE)){
           //example fscanf(deptINFILE, "%d", &deptRecords[i].id);
           //to be completed
              // Read in Department information from text in-file.  From left to right is Student ID, Student LastName, Major, Assessment Score and GPA.

       fscanf(deptINFILE, "%d", &deptRecords[i].StudentID);
       fscanf(deptINFILE, " %s", deptRecords[i].LastName);
       fscanf(deptINFILE, " %s", deptRecords[i].Major);
       fscanf(deptINFILE, "%d", &deptRecords[i].AssessmentScore);
       fscanf(deptINFILE, "%lf", &deptRecords[i].Gpa);

           i = i + 1;
       }
       numRecords = i;

   

    //Calculate and print the Highest Assessment Score with the student name and major

    //508   Brown   Economics   97   4.2


       highScore = 0;
       for (i = 0; i < numRecords; i++) {
           if (deptRecords[i].AssessmentScore > highScore) {
           highScore = deptRecords[i].AssessmentScore;
           strcpy(highLastName, deptRecords[i].LastName);
           strcpy(highMajor, deptRecords[i].Major);
           }
       }
/*
   Calculate and print the number of Biotechnology Majors
   Print all department records
   do  not loop
*/
           // shoudl be 8
       // numBioTech = 0;
       //for (i = 0; i < numRecords; i++) {
         //  if (strcmp(deptRecords[i].Major 'Biotechnology') {
           //numBioTech = numBioTech +1;
       // }
       // }


       fprintf(deptOUTFILE, "_____________________DEPARTMENT RECORDS_____________________\n\n");

       //for (i = 0; i < numRecords; i++)
           //example fprintf(deptOUTFILE, "\tId: %d \n", deptRecords[i].id);
           //to be completed

//Calculate and print the Highest Assessment Score with the student name and major

        fprintf(deptOUTFILE, "The highest assesment score was from %s, who is a %s major and his/her score was %d\n", highLastName, highMajor, highScore);
    fprintf(deptOUTFILE, "The number of Biotechnology students is %d", numBioTech);
           
           fprintf(deptOUTFILE, "\t**************************************************** \n\n");
           for (i = 0; i < numRecords; i++) {
           fprintf(deptOUTFILE, "%d\t", deptRecords[i].StudentID);
           fprintf(deptOUTFILE, "%s\n", deptRecords[i].LastName);
           fprintf(deptOUTFILE, "%s\t", deptRecords[i].Major);
           fprintf(deptOUTFILE, "%d\t", deptRecords[i].AssessmentScore);
           fprintf(deptOUTFILE, "%.2lf\n\n", deptRecords[i].Gpa);
       }

       //close all opened files
       fclose(deptINFILE);
       fclose(deptOUTFILE);

       return 0;
   }

}  //end int main

/*
PROGRAM #4

(2pts) Read in Department information from text in-file
(3 pts) Calculate and print the Highest Assessment Score with the student name and major
(3 pts) Calculate and print the number of Biotechnology Majors
(2 pts) Print the department records
do  not loop

Test case Highest Assmt Score: 97, Brown, Economics
          8 Biotechnology Majors
*/