#include <stdio.h>
#include <string.h>

typedef struct {
    char career[40];
    int medPay;
    int topPay;
    

} CareerStruct;

int main(void) {

    //variable declarations
	CareerStruct careerRecords[25];
	int i = 0;
	int numRecords = 0;
    int min;
    int max;
    double aveMed = 0;
    double aveTop = 0;
    char maxCareer[40];
  
    
	
    //file declarations
	char careerInput[25] = "CareersData.txt";
	FILE* careerINFILE = NULL;
	char careerOutput[25] = "CareersOUTData.txt";
	FILE* careerOUTFILE = NULL;
	
    //open files for read and write
	careerINFILE = fopen(careerInput, "r");
    careerOUTFILE = fopen(careerOutput, "w"); 


	if (careerINFILE == NULL) {
	   printf("Error!  Not able to read input file.\n");
	   return 1;
	}
	else {
	   printf("Read successful!\n");
	
        //read in records
        while (!feof(careerINFILE)){
            
            // fscanf(careerINFILE, "%d", &careerRecords[i].id);
            // to be completed
            fscanf(careerINFILE, "%s", careerRecords[i].career);
            fscanf(careerINFILE, "%d", &careerRecords[i].medPay);
            fscanf(careerINFILE, "%d", &careerRecords[i].topPay);

                i = i + 1;
        }
        numRecords = i;

          //min median & max pay
            min = 99999999;
            max = 0;
            for (i = 0; i < numRecords; i++) {

                if (careerRecords[i].medPay < min) {
                min = careerRecords[i].medPay;
                }

                if (careerRecords[i].topPay > max) {
                    strcpy(maxCareer, careerRecords[i].career);
                max = careerRecords[i].topPay;
                }


                aveTop = aveTop + careerRecords[i].topPay;
                aveMed = aveMed + careerRecords[i].medPay;
            }


   
        fprintf(careerOUTFILE, "_____________________CAREER RECORDS_____________________\n\n");
        
        //fprintf(careerOUTFILE, "The number of entries is: %d\n", numRecords);

        //Find and print the minimum median pay to a file
 
        fprintf(careerOUTFILE, "Minimum Median Pay = %d\n", min);

        //Find and print the maximum top pay and the career associated with the max to the same file

        fprintf(careerOUTFILE, "The top paying job on this list is %s at a whopping $%d\n", maxCareer, max);

        //Find and print the average median and top pay to the same file

        fprintf(careerOUTFILE, "The Average median pay is %.2lf and the average top pay is %lf\n", aveMed / numRecords, aveTop / numRecords);
        
        //fprintf(careerOUTFILE, "The Average Top Pay for %s = %.2lf\n", maxCareer, (aveTop / numRecords));

        fprintf(careerOUTFILE, "\n\n\n");

        for (i = 0; i < numRecords; i++) {
        //	fprintf(careerOUTFILE, "STUDENT: %d \n", i + 1);
        // to be completed

            fprintf(careerOUTFILE," %s ", careerRecords[i].career);
            fprintf(careerOUTFILE,"%d ", careerRecords[i].medPay);
            fprintf(careerOUTFILE,"%d \n ", careerRecords[i].topPay);
        }

        //close all opened files
        fclose(careerINFILE);
        fclose(careerOUTFILE);
    }

	return 0;
}