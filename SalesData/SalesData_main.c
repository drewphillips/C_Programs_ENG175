#include <stdio.h>
#include <string.h>

typedef struct {

   //Bill_MacArthur	Ashford	17111	1	67678	135567	100.31

   char agent[35];
   char city[35];
   int empId;
   int goldMedals;
   int lastYear;
   int thisYear;
   double percentInc;


} SalesStruct;

int main(void) {
	SalesStruct salesRecords[25];
	int i = 0;
	int numRecords = 0;
    int numGoldMedals =0;
    double minPercent;
    char cityPercent[35];
    int maxSales;
    int maxSalesId;
    char maxSalesName[35];
    
	
	char salesInput[25] = "SalesData.txt";
	FILE* salesINFILE = NULL;
	char salesOutput[25] = "SalesOUTData.txt";
	FILE* salesOUTFILE = NULL;
	
	salesINFILE = fopen(salesInput, "r");
    salesOUTFILE = fopen(salesOutput, "w"); 


	if (salesINFILE == NULL) {
	   printf("Error!  Not able to read input file.\n");
	   return 1;
	}
	else {
	   printf("Read successful!\n");

        //read in records
        while (!feof(salesINFILE)){
        
            fscanf(salesINFILE, "%s", salesRecords[i].agent);
            fscanf(salesINFILE, "%s", salesRecords[i].city);
            fscanf(salesINFILE, "%d", &salesRecords[i].empId);
            fscanf(salesINFILE, "%d", &salesRecords[i].goldMedals);
            fscanf(salesINFILE, "%d", &salesRecords[i].lastYear);
            fscanf(salesINFILE, "%d", &salesRecords[i].thisYear);
            fscanf(salesINFILE, "%lf", &salesRecords[i].percentInc);
            
  

            i = i + 1;
         }
        numRecords = i;

        //calulations beofe printing

        //goldmedals
        
        for (i=0; i < numRecords; i++) {
        if (salesRecords[i].goldMedals > 0) {
            numGoldMedals = numGoldMedals + 1;
            }
        
        
        
        }

        //Find and print the min %Increase and the associated City.  Print to the same file
        minPercent = 999999;
        for (i=0; i < numRecords; i++) {
        if (salesRecords[i].percentInc < minPercent) {
            minPercent = salesRecords[i].percentInc;
            strcpy(cityPercent, salesRecords[i].city);
            }
        }

        //Find and print the max sales for ThisYear and the associated Manager, City and Emp#. Print to the same file
        for (i=0; i < numRecords; i++) {
        if (salesRecords[i].thisYear > maxSales);
        maxSales = salesRecords[i].thisYear;
        maxSalesId = salesRecords[i].empId;
        strcpy(maxSalesName, salesRecords[i].agent);


        }

        fprintf(salesOUTFILE, "_____________________SALES RECORDS_____________________\n\n");

         //Find and print the number of managers with GoldMedals to a file
         fprintf(salesOUTFILE, "Number of managers with gold medals = %d\n", numGoldMedals);

        //fprintf(salesOUTFILE, "The city with the lowest percent in sales was  with %.4lf\n", minPercent);

        fprintf(salesOUTFILE, "The city with the lowest percent in sales was %s with %.4lf\n", cityPercent, minPercent);

        //Find and print the max sales for ThisYear and the associated Manager, City and Emp#. Print to the same file

         fprintf(salesOUTFILE, "The max sales this year was %d from %s whos ID number is %d\n", maxSales, maxSalesName, maxSalesId);



        fprintf(salesOUTFILE, "\n\n");



        //print everything, needs better formating. 
        for (i = 0; i < numRecords; i++) {
        //	fprintf(salesOUTFILE, "Brand: %d \n", i + 1);

            fprintf(salesOUTFILE, "%s\t", salesRecords[i].agent);
            fprintf(salesOUTFILE, "%s\n", salesRecords[i].city);
            fprintf(salesOUTFILE, "%d\t", salesRecords[i].goldMedals);
            fprintf(salesOUTFILE, "%d\t", salesRecords[i].lastYear);
            fprintf(salesOUTFILE, "%d\t", salesRecords[i].thisYear);
            fprintf(salesOUTFILE, "%.2lf\t", salesRecords[i].percentInc);

        
        // to be completed

            fprintf(salesOUTFILE, "\t**************************************************** \n\n");
        }

        //close opened files
         fclose(salesINFILE);
         fclose(salesOUTFILE);
    }

	return 0;
}