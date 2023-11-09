#define _CRT_SECURE_NO_WARNINGS

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
    double aveMed;
    double aveTop;
    char medCareer[40];
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
        while (!feof(careerINFILE)) {

            // fscanf(careerINFILE, "%d", &careerRecords[i].id);
            // to be completed
            fscanf(careerINFILE, "%s", careerRecords[i].career);
            fscanf(careerINFILE, "%d", &careerRecords[i].medPay);
            fscanf(careerINFILE, "%d", &careerRecords[i].topPay);

            i = i + 1;
        }
        numRecords = i;

        //min median pay
        for (i = 0; i < numRecords; i++) {

            if (careerRecords[i].medPay < min) {
                min = careerRecords[i].medPay;
            }


        }

        //max top pay 

        for (i = 0; i < numRecords; i++) {

            if (careerRecords[i].topPay < max) {
                max = careerRecords[i].topPay;
            }


        }

        //last part max pay for best job
        aveTop = careerRecords[i].topPay;
        for (i = 0; i < numRecords; i++) {
            if (careerRecords[i].topPay > aveTop) {
                aveTop = careerRecords[i].topPay;
                strcpy(maxCareer, careerRecords[i].career);
            }



        }


        aveMed = careerRecords[i].medPay;
        for (i = 0; i < numRecords; i++) {
            if (careerRecords[i].topPay > aveMed) {
                aveMed = careerRecords[i].topPay;
                strcpy(medCareer, careerRecords[i].career);
            }



        }
        //average med and top pay



        fprintf(careerOUTFILE, "_____________________CAREER RECORDS_____________________\n\n");

        fprintf(careerOUTFILE, "Minimum Median Pay = %d\n", min);
        fprintf(careerOUTFILE, "Maximum Top Pay = %d\n", max);

        fprintf(careerOUTFILE, "The Average Median Pay for %s = %.2lf\n", medCareer, aveMed / numRecords);
        fprintf(careerOUTFILE, "The Average Top Pay for %s = %.2lf\n", maxCareer, aveMed / numRecords);

        for (i = 0; i < numRecords; i++) {
            //	fprintf(careerOUTFILE, "STUDENT: %d \n", i + 1);
            // to be completed

            fprintf(careerOUTFILE, " %s ", careerRecords[i].career);
            fprintf(careerOUTFILE, "%d ", careerRecords[i].medPay);
            fprintf(careerOUTFILE, "%d \n ", careerRecords[i].topPay);
        }

        //close all opened files
        fclose(careerINFILE);
        fclose(careerOUTFILE);
    }

    return 0;
}