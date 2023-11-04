#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {

	char firstName[20];
    char lastName[20];
    int ID;
    double yearsAt;
    int salary;

} employeeStruct ;

int main()
{
    employeeStruct emp[2]; 
    int i;
    int numEmps = 2;

    printf("enter in info for 4 employees...\n");
    printf("First Name, Last Name, ID Number, Years Emplyed, Salary.\n");
    for (i =0; i < numEmps; i++) {

        printf("\tFirst Name = \n");
        scanf(" %s", emp[i].firstName);
        printf("\tLast Name = \n");
        scanf(" %s", emp[i].lastName);
        printf("\tEmployee ID number = \n");
        scanf("%d", &emp[i].ID);
        printf("\tYears at this complany = \n");
        scanf("%lf", &emp[i].yearsAt);
        printf("\tSalary = \n");
        scanf("%d", &emp[i].salary);

    
    }
    
    for (i=0; i < numEmps; i++) {
        printf("\n");
        printf("\t%s\n", emp[i].firstName);
        printf("\t%s\n", emp[i].lastName);
        printf("\tID Number %d\n", emp[i].ID);
        printf("\t%s has been working here %.2lf years\n", emp[i].firstName, emp[i].yearsAt);
        printf("\tAnd we pay him/her $%d\n", emp[i].salary);
    }
    
    return 0;
}