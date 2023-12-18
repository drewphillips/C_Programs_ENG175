#include <stdio.h>
#include <stdlib.h> //still not understandiong this. 
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX 30
 
struct emp_data {
    int  empno;
    char empName[MAX];
    char designation[MAX];
    struct emp_data *next;
};
 
// Function to insert a node at the front of the linked list.
struct emp_data *insert(struct emp_data *front, int id, char name[], char desg[]) {
    struct emp_data *newnode;
 
    newnode = (struct emp_data*)malloc(sizeof(struct emp_data));
 
    if (newnode == NULL)
    {
        printf("\n Allocation failed \n");
        exit(2);
    }
    newnode->empno = id;
    strcpy(newnode->empName, name);
    strcpy(newnode->designation, desg);
    newnode->next = front;
    front = newnode;
    return(front);
} //End of insert
 
// Function to display a node in a linked list
void printNode(struct emp_data *p) {
    printf("\n Employee Details...\n");
    printf("\n Emp No: %d", p->empno);
    printf("\n Name: %s", p->empName);
    printf("\n Designation: %s\n", p->designation);
    printf("-------------------------------------\n");
}  //End of printNode()
 
// Function to delete a node based on employee number
struct emp_data* deleteNode(struct emp_data *front, int id) {
    struct emp_data *ptr;
    struct emp_data *bptr;
 
    if (front->empno == id) {
        ptr = front;
        printf("\n Node deleted:");
        printNode(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next, bptr = bptr->next) {
        if (ptr->empno == id) {
            printf("\n Node deleted:");
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\n Employee Number %d not found ", id);
    return(front);
} //End of delete node
 
// Function to search the nodes in a linear fashion based emp ID
void search(struct emp_data *front, int key) {
    struct emp_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr -> next) {
        if (ptr->empno == key) {
            printf("\n Key found:");
            printNode(ptr);
            return;
        }
    }
    printf("\n Employee Number %d not found ", key);
} //End of search()
 
// Function to display the linked list
void display(struct emp_data  *front) {
    struct emp_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr->next) {
        printNode(ptr);
    }
} //End of display()
 
// Function to display the menu of operations on a linked list
void menu() {
    printf("---------------------------------------------\n");
    printf("Press 1 to INSERT a node into the list       \n");
    printf("Press 2 to DELETE a node from the list       \n");
    printf("Press 3 to DISPLAY the list                 \n");
    printf("Press 4 to SEARCH the list                   \n");
    printf("Press 5 to count the number of HR employee designations\n");
    printf("Press 6 to EXIT                              \n");
    printf("---------------------------------------------\n");
} //End of menu()
 
// Function to select the option
int option() {
    int choice;
 
    printf("\n\n>> Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5: // this new menue option...
        case 6:   return(choice);
        default :   printf("\n Invalid choice.");
    }
    return choice;
} //End of option()
 
// The main() program begins
int main() {
    struct emp_data *linkList;
    char name[21], desig[51];
    char choice;
    int eno;
 
    linkList = NULL;
    printf("\n Welcome to demonstration of singly linked list \n");
    menu();
    do {
        choice = option();
        switch(choice) {
        case 1:
            printf("inserting a node ...\n");
            printf("\n Enter the Employee Number: ");
            scanf("%d", &eno);
            printf("Enter the Employee name: ");
            fflush(stdin);
            scanf(" %c", name);
            printf("Enter the Employee Designation : ");
            scanf(" %c", desig);
            linkList = insert(linkList, eno, name, desig);
            break;
        case 2:
            printf("deleting a node ...\n");
            printf("\n\n Enter the employee number to be deleted: ");
            scanf("%d", &eno);
            linkList = deleteNode(linkList, eno);
            break;
        case 3:
            printf("displaying the list ...\n");
            if (linkList == NULL) {
                printf("\n List empty.");
                break;
            }
            display(linkList);
            break;
        case 4:
            printf("searching the list ...\n");
            printf("\n\n Enter the employee number to be searched: ");
            scanf("%d", &eno);
            search(linkList, eno);
            break;

        case 5:
        printf("this is where the code goes if I have time");
        //  elemint of the linked list "desig" == HR emplyee, then add 1 to a counter...
        //numHR = numHR +1
        //something like that. Ill take half credit. thanks, peace!
        break;

        case 6: 
            printf(" g o o d    b y e  ...\n");
            break;
        }
    } while (choice != '6');

    return 0;
}
/*
Program 4  

(-5 of 5 pts) Compile and run the code fixing any syntax or logic errors code reads in first employee number then an infinite loop for emp name, code does not Exit
(3 pts) change all gets commands to scanf commands
(-2 of 2 pts) remove any fflush commands needed for gets  not completed
(-5 of 5 pts) add a menu option to count the number of HR employee designations not completed

Test cases vary.
*/