#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*stnode;

void createNodeList(int n);     //function to create the list
int NodeCount();	            //function to count the nodes
void displayList();             //function to display the list
void MinMaxAvg();

int main() {
    int n, totalNode;
    int menu = 5;
    char loopAgain;
    char loopMenu;

    do {

        printf("\n\nCreate a singly linked list and count the number of nodes :\n");
        printf("------------------------------------------------------------------------------\n");
        printf(" Input the number of nodes : ");
        scanf("%d", &n);
        createNodeList(n);

        do {

            printf("\n\t4 menu options to select from, please enter 0-3\n\n");
            printf("\t0) Exit the program.\n\t1) Display list.\n\t2) Count nodes in list.\n\t3) Find the Min/Max average of the list.\n");
            scanf("\t%d", &menu);
            switch (menu) {



            case 0:
                return 0;
                break;

            case 1:

                printf("\n Data entered in the list are : \n");
                displayList();
                break;

            case 2:

                totalNode = NodeCount();
                printf("\n Total number of nodes = %d\n", totalNode);

                break;

            case 3:

                //add one udf to calculate the min, max and average of the data in the linked lists.  Add 3. MinMaxAvg List to the menu.
                //printf("Min Max average = ");
                MinMaxAvg();

                break;


            default:
                printf("You can only select 0-3, please try again.\n");

            }

            printf("Would you like to select a new menu option? y/n");
            scanf(" %c", &loopMenu);
            loopMenu = toupper(loopMenu);

        } while (loopMenu == 'Y');

        printf("Would you like to start over y/n");
        scanf(" %c", &loopAgain);
        loopAgain = toupper(loopAgain);

    } while (loopAgain == 'Y');

    return 0;
}

void createNodeList(int n) {
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) //check whether the stnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode-> num = num;      
        stnode-> nextptr = NULL; //Links the address field to NULL
        tmp = stnode;
//Creates n nodes and adds to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
} 

int NodeCount() {
    int ctr = 0;
    struct node *tmp;
    tmp = stnode;
    while(tmp != NULL)
    {
        ctr++;
        tmp = tmp->nextptr;
    }
    return ctr;
}

void displayList() {
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
} 

//add one udf to calculate the min, max and average of the data in the linked lists.  Add 3. MinMaxAvg List to the menu.

    void MinMaxAvg() {
        struct node *tmp;
        double min = 9999, max = 0;
        double avg;
      
        tmp = stnode;
      
        while(tmp != NULL) {

            if (tmp->num > max) { 
                max = tmp->num;
                
            }    
            tmp = tmp->nextptr;   
        }

        tmp = stnode;

        while(tmp != NULL) {

            if (tmp->num < min) { 
            min = tmp->num;
            
            }    
            tmp = tmp->nextptr;   
         }

    printf("the min is: %.2lf and the max is: %.2lf\n\n", min, max);
    printf("The Min/Max average is: %.2lf\n", min + max /2);

    return; 
    }

    
    
