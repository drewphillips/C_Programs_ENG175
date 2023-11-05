#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {

    char firstName[20];
    char lastName[20];
    int gender;
    int ID;
    double yearsAt;
    int salary;

} employeeStruct;

int main()
{
    employeeStruct emp[6];
    int i;
    int numEmps = 2;

    printf("enter in info for 4 employees...\n");
    printf("First Name, Last Name, ID Number, Years Emplyed, Salary.\n");
    for (i = 0; i < numEmps; i++) {

        printf("\tFirst Name \n\t");
        scanf(" %s", emp[i].firstName);
        printf("\tLast Name \n\t");
        scanf(" %s", emp[i].lastName);
        printf("\tEnter 1 for male 2 for female: \n\t");
        scanf("%d", &emp[i].gender);
        printf("\tEmployee ID number \n\t");
        scanf("%d", &emp[i].ID);
        printf("\tYears at this complany \n\t");
        scanf("%lf", &emp[i].yearsAt);
        printf("\tSalary \n\t");
        scanf("%d", &emp[i].salary);

    }

    for (i = 0; i < numEmps; i++) {
        printf("\n");
        printf("Unepic Networks Employee number %d\n", i + 1);
        printf("\t%s\n", emp[i].firstName);
        printf("\t%s\n", emp[i].lastName);
        printf("\tID Number %d\n", emp[i].ID);
        printf("\t%s has been working here %.1lf years\n", emp[i].firstName, emp[i].yearsAt, emp[i].yearsAt == 1 ? "" : "s");

        if (emp[i].gender == 1) {
            printf("\tAnd we pay him $%d\n", emp[i].salary);
        }

        else if (emp[i].gender == 2) {
            printf("\tAnd we pay her $%d\n", emp[i].salary);
        }

    }

    return 0;
}