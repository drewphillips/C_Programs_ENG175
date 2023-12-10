#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*stnode, *ennode;



void createNodeList(int n);     //function to create the list
int NodeCount();	            //function to count the nodes
void displayList();             //function to display the list
void MinMaxAvg();
void IncertNodeAtBegining(int num);     // function to incet node at begining of the list. 
void IncertNodeAtTheEnd(int num);
void IncertNodeAtMiddle(int num, int pos);
void DeleteFirstNode();
void DeleteMiddleNode(int pos);
void DeleteLastNode();
int FindElement(int);

int main(){
    int n, totalNode;
    int menu;
    char loopAgain;
    char loopMenu;
    int num, pos;
    int FindElem, FindPlc;
    //stnode->nextptr=NULL;
    ennode=stnode;

    do {

            printf("\n\nCreate a singly linked list and count the number of nodes :\n");
		    printf("------------------------------------------------------------------------------\n");
            printf(" Input the number of nodes : ");
            scanf("%d", &n);
            createNodeList(n);


            do {
             
                printf("\n\t10 menu options to select from, please enter 0-10\n\n");
                printf("\t00) Exit the program.\n\t 1) Display list.\n\t 2) Count nodes in list.\n\t 3) Find the Min/Max average of the list.\n");
                printf("\t 4) Insert a new node at the beginning of the list.\n\t 5) Insert a new node at the end of the list.\n\t 6) Insert a new node in the middle of the list.\n");
                printf("\t 7) Delete the first node of the list.\n\t 8) Delete the middle node of the list.\n\t 9) Delete the last node of the list.\n");
                printf("\t10) Search for an existing element of the list.\n");
                scanf("\t%d", &menu);
    
                if (menu == 1) {
                printf("\n Data entered in the list are : \n");		
                displayList();
                }

                else if (menu == 2) {
                totalNode = NodeCount();
                printf("\n Total number of nodes = %d\n", totalNode);
        
                }

                else if (menu == 3) {
                //add one udf to calculate the min, max and average of the data in the linked lists.  Add 3. MinMaxAvg List to the menu.
                //printf("Min Max average = ");
                MinMaxAvg();
                }

                else if (menu == 0) {
                return 0;
                }

                else if (menu == 4) {
                    //call UDF add one udf to insert a new node at the beginning of the list.  Add 4. Insert Node at Beginning to the menu.
                printf("Incert a node at the begining of the list\n");
                printf("Input the data to incert at the begining of the list:");
                scanf("%d", &num);
                IncertNodeAtBegining(num);
                printf("Data ater inserted in the list is:\n");
                displayList();

                }

                else if (menu == 5) {
                    //add one udf to insert a new node at the end of the list.  Add 5.  Insert Node at End to the menu.
                    printf("Incert a nod at the end of the list, enter data:");
                    scanf("%d", &num);
                    IncertNodeAtTheEnd(num);
                    printf("\nThe data after incerting the node is:\n");
                    displayList();
                }

                else if (menu == 6) {
                    //add one udf to insert a new node in the middle of the list.  Add 6.  Insert Node in Middle to the menu.
                    printf("Enter a node in the midel of the list, enter data: ");
                    scanf("%d", &num);
                    printf("incert the position to incert the node : ");
                    scanf("%d", &pos);
                        if(pos<=1 || pos>= n) {
                            printf("\n Insertion can not be possible in that position\n");
                        }
                        if (pos>1 && pos<n) {
                        }
                    IncertNodeAtMiddle(num, pos);
                    printf("\n Insertion completed Sucssfully.\n");
                
                    printf("\nThe new list is: \n");
                    displayList();
                }

                else if (menu == 7) {
                    //add one udf to delete the first node of the list.
                    printf("Delete the first node of the list.");
                    DeleteFirstNode();
                    printf("\nThe data after deleting the node is:\n");
                    displayList();
                }

                else if (menu == 8) {
                    //add one udf to delete the middle node of the list.
                    printf("Delete the middle node of the list.\n");
                    printf("Input the possition of the node to be deleted :");
                    scanf("%d", &pos);
                    DeleteMiddleNode(pos);
                    printf("\nThe data after deleting the node is:\n");
                    displayList();
                }

                 else if (menu == 9) {
                    //add one udf to delete the last node of the list.
                    printf("Delete the last node of the list.");
                    DeleteLastNode();
                    printf("\nThe data after deleting the last node is:\n");
                    displayList();
                }

                else if (menu == 10) {
                    // add UDF to search for an element
                    printf("input the element to be searched : ");
                    scanf("%d", &FindElem);
                    if(FindPlc<=n)
                    printf("Element found at node %d \n\n", FindPlc);
                    else
                    printf("This element does not exists in linked list. \n\n");

                }
                
                else {
                printf("You can only select 0-10, please try again.\n");
                }

                printf("Would you like to select a new menu option? y/n");
                scanf(" %c", &loopMenu);
                loopMenu = toupper(loopMenu);


            } while (loopMenu == 'y');

            printf("Would you like to start over? y/n");
            scanf(" %c", &loopAgain);
            loopAgain = toupper(loopAgain);

        
        
        } while (loopAgain == 'Y');    


        return 0;
}  

int FindElement(int FindElem) {
    int ctr=1;
    ennode=stnode;
    while(ennode->nextptr!=NULL)
    {
        if(ennode->num==FindElem)
        break;
        else
        ctr++;
        ennode=ennode->nextptr;
    }
}

void DeleteLastNode() {
    struct node *toDelLast, *preNode;
    if(stnode == NULL) {
    printf("There are no nodes in the lsit to delete");
    }
    else {
        toDelLast = stnode;
        preNode = stnode;
        //traverse to the last node of the list
        while(toDelLast->nextptr != NULL) {
            preNode = toDelLast;
            toDelLast = toDelLast->nextptr;
        }

        if(toDelLast == stnode) {
            stnode = NULL;
        }
        else {
            //disconnects the link of the second to last node with last node
            preNode->nextptr = NULL;
        }

        //delete the last node
        free(toDelLast);
        
        
    }
}


void DeleteMiddleNode(int pos) {
    int i;
    struct node *toDelMid, *preNode;
    if(stnode == NULL) {
    printf("There are no nodes in the lsit to delete");
    }
    else {
        toDelMid = stnode;
        preNode = stnode;

        for(i=2; i<=pos; i++) {
            preNode = toDelMid;
            toDelMid = toDelMid->nextptr;

            if(toDelMid != NULL) {
                if(toDelMid == stnode)
                stnode = stnode->nextptr;

                preNode->nextptr = toDelMid->nextptr;
                toDelMid->nextptr = NULL;
                free(toDelMid);
            }
            else
            {
                printf("Deletion can not be possible from that position.");
            }
        }
        
       
    }
}

void DeleteFirstNode() {
    struct node *toDelptr;
    if(stnode == NULL) {
    printf("There are no nodes in the lsit to delete");
    }
    else {
        toDelptr = stnode;
        stnode = stnode->nextptr;
        printf("\n Data of node 1 which is being deleted is : %d\n", toDelptr->num);

        free(toDelptr);
    }
}

void IncertNodeAtMiddle(int num, int pos) {
    int i;

    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf("Memory an not be allocated");
    }
    else {
        fnNode->num = num;
        fnNode->nextptr = NULL;
        tmp = stnode;
        for (i=2; i<=pos-1; i++) {
            tmp = tmp->nextptr;
                if(tmp == NULL)
                break;
        }
        if(tmp != NULL) {
            fnNode->nextptr = tmp->nextptr;
            tmp->nextptr = fnNode;

        }
        
    }



}

void IncertNodeAtTheEnd(int num) {
     struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf("Memory an not be allocated");
    }
    else {
        fnNode->num = num;
        fnNode->nextptr = NULL;
        tmp = stnode;
        while(tmp->nextptr != NULL)
            tmp =tmp->nextptr;
        tmp->nextptr = fnNode;
    }


}

void IncertNodeAtBegining(int num) {
    struct node *fnNode;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf("Memory an not be allocated");
    }
    else {
        fnNode->num = num;
        fnNode->nextptr = stnode;
        stnode = fnNode;
    }

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

    
    
