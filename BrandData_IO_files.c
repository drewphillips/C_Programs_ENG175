#include <stdio.h>
#include <string.h>

// Brand	Industry_	Brand_Value_($_billions)	1-Yr_Value_Change_(%)	Brand_Revenue_($_billions)

typedef struct {
    char brands[25];
    char industry[35];
    double value;
    int percent;
    double revenue;
} BrandStruct;

/*
brandRecords[i].brand
brandRecords[i].industry
brandRecords[i].value
brandRecords[i].percent
brandRecords[i].revenue
*/

int main(void) {
	BrandStruct brandRecords[100];
	int i = 0;
	int numRecords = 0;
    char minBrand[35];
    char maxBrand[35];
    double minValue;
    double maxValue;
    double avgValue;
    double minRevenue;
    double maxRevenue;
    double avgRevenue;
	
	char brandInput[25] = "BrandData.txt";
	FILE* brandINFILE = NULL;
	char brandOutput[25] = "BrandOUTData.txt";
	FILE* brandOUTFILE = NULL;
	
    //open files for read and write
	brandINFILE = fopen(brandInput, "r");
    brandOUTFILE = fopen(brandOutput, "w");

	if (brandINFILE == NULL) {
	   printf("Error!  Not able to read input file.\n");
	   return 1;
	}
	else {
	   printf("Read successful!\n");

        //read in records
        while (!feof(brandINFILE)){
     
        fscanf(brandINFILE, "%s", brandRecords[i].brands);
        fscanf(brandINFILE, "%s", brandRecords[i].industry);
        fscanf(brandINFILE, "%lf", &brandRecords[i].value);
        fscanf(brandINFILE, "%d", &brandRecords[i].percent);
        fscanf(brandINFILE, "%lf", &brandRecords[i].revenue);
        // to be completed

            i = i + 1;
        }
        
        //Find and print the min, max and avg BrandRevenue ($billions). Associate the Industry with the min.  Print to the same file

        numRecords = i;
        minValue = 999999;
        maxValue = 0;
        for (i = 0; i < numRecords; i++) {
            if (brandRecords[i].value < minValue) {
                //strcpy(minBrand, brandRecords[i].industry);
                minValue = brandRecords[i].value;
            }
            if (brandRecords[i].value > maxValue) {
                //strcpy(maxBrand, brandRecords[i].industry);
                maxValue = brandRecords[i].value;
            }

            avgValue = avgValue + brandRecords[i].value;
        }

        //Find and print the min, max and avg BrandRevenue ($billions). Associate the Industry with the min.  Print to the same file

        numRecords = i;
        minRevenue = 999999;
        maxRevenue = 0;
        for (i = 0; i < numRecords; i++) {
            if (brandRecords[i].revenue < minRevenue) {
                strcpy(minBrand, brandRecords[i].industry);
                minRevenue = brandRecords[i].revenue;
            }
            if (brandRecords[i].revenue > maxRevenue) {
                strcpy(maxBrand, brandRecords[i].industry);
                maxRevenue = brandRecords[i].revenue;
            }

            avgRevenue = avgRevenue + brandRecords[i].revenue;
        }
   
	    fprintf(brandOUTFILE, "_____________________BRAND RECORDS_____________________\n\n");

        //Find and print the min, max and avg BrandValue ($billions) to a file

       fprintf(brandOUTFILE, "The lowest brand value is: $%lf Billion \n", minValue);

       fprintf(brandOUTFILE, "The max brand value is: $%lf Billion \n", maxValue);

       fprintf(brandOUTFILE, "The average brand value is %lf\n", avgValue / numRecords);

    // Find and print the min, max and avg BrandRevenue ($billions). Associate the Industry with the min.  Print to the same file

 fprintf(brandOUTFILE, "The lowest brand revenue is: $%lf Billion from the industy %s \n", minRevenue, minBrand);

       fprintf(brandOUTFILE, "The max brand revenue is: $%lf Billion from the industry %s \n", maxRevenue, maxBrand);

       fprintf(brandOUTFILE, "The average brand revenue is %lf\n", avgRevenue / numRecords);
    
        for (i = 0; i < numRecords; i++) {
        //	fprintf(brandOUTFILE, "Brand: %d \n", i + 1);
        fprintf(brandOUTFILE, "Brand: %s \n", brandRecords[i].brands);
         fprintf(brandOUTFILE, "The industry is: %s \n", brandRecords[i].industry);
          fprintf(brandOUTFILE, "The company value is: $%lf Billion \n", brandRecords[i].value);
           fprintf(brandOUTFILE, "1 year Value has changed %d %% \n", brandRecords[i].percent);
            fprintf(brandOUTFILE, "Brand revenue is: $%.2lf Billion \n", brandRecords[i].revenue);

        
        // to be completed

            fprintf(brandOUTFILE, "\t**************************************************** \n\n");
        }

	    //close all opened files
        fclose(brandINFILE);        
        fclose(brandOUTFILE);
    }

	return 0;
}