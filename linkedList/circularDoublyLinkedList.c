#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prevlink;
    int num;
    struct node *nextlink;
} *node1, *node2, *temp, *head;

typedef struct node  nodemaker;

int nNodes;
void createList(){
    printf("\nInput the number of nodes: ");
    scanf("%d", &nNodes);
    
    int num, i;
    node1 = malloc(sizeof(nodemaker));

    if (node1 == NULL){
        printf("memory can not be allocated");
    }
    else{
        printf("Input data for node 1: ");
        scanf("%d", &num);
        node1 -> num = num;
        node1 -> prevlink = NULL;
        node1 -> nextlink = NULL;
        head = node1;
        temp = head;

        for(i=2; i<=nNodes; i++){
            node2 = malloc(sizeof(nodemaker));
            
            if(node2 == NULL){
                printf("memory can not be allocated");
                break;
            }
            else{
                printf("Input data for node %d: ",i);
                scanf("%d", &num);
                node2 -> num = num;
                node2 -> nextlink = NULL;
                node2 -> prevlink = temp;
                temp -> nextlink = node2;
                temp = temp -> nextlink;
            }
        }
        node2 -> nextlink = head;
        node1 -> prevlink = node2;
    }
}

// 1

void insertfirst(){
    int num;
    printf("\nEntering a node at starting: \n");

    nodemaker *firstnode;

    firstnode = malloc(sizeof(nodemaker));

    printf("Input data for new node: ");
    scanf("%d", &num);

    firstnode -> num = num;

    temp = head;
    temp = temp -> prevlink;

    temp -> nextlink = firstnode;
    firstnode -> nextlink = head;
    head -> prevlink = firstnode;
    firstnode -> prevlink = temp;
    head = firstnode;


}

// 2

void insertlast(){
    int num;
    printf("\nEntering a node at last: \n");

    nodemaker *lastnode;

    lastnode = malloc(sizeof(nodemaker));

    printf("Input data for new node: ");
    scanf("%d", &num);

    lastnode -> num = num;

    temp = head;
    temp = temp -> prevlink;

    temp -> nextlink = lastnode;
    lastnode -> nextlink = head;
    lastnode -> prevlink = temp;
    head -> prevlink = lastnode;
    
}

// 3

void insertatIndex(){
    int num, n, i=0;
    printf("\nEntering a node in between: \n");
    printf("Enter the Index: ");
    scanf("%d", &n);

    nodemaker *betweennode;

    betweennode = malloc(sizeof(nodemaker));

    temp = head;

    printf("Input data for new node: ");
    scanf("%d", &num);

    while(i!=(n-1)){
        temp = temp -> nextlink;
        i++;
    }
    betweennode -> num = num;
    betweennode -> nextlink = temp -> nextlink;
    betweennode -> prevlink = temp;
    (temp -> nextlink) -> prevlink = betweennode;
    temp -> nextlink = betweennode;
}

// 4

void deletefirst(){
    printf("\nDeleteing a node at starting: \n");

    temp = head;
    head = temp->nextlink;
    head -> prevlink = temp -> prevlink;
    (head -> prevlink) -> nextlink = head;

    free(temp);
}

// 5

void deletelast(){
    printf("\nDeleteing a node at last: \n");

    temp = head;
    temp = head -> prevlink;
    (temp->prevlink) -> nextlink = head;
    head -> prevlink = temp -> prevlink;
    
    free(temp);
}

// 6

void deleteatIndex(){
    int n, i=0;
    printf("\nDeleteing a node in between: \n");
    printf("Enter the Index: ");
    scanf("%d", &n);

    temp = head;
    while(i!=n){
        temp = temp -> nextlink;
        i++;
    }
    (temp -> prevlink) -> nextlink = temp -> nextlink;
    (temp -> nextlink) -> prevlink = temp -> prevlink;
    free(temp);
}

// 7

int searchinList(){
    int num;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &num);

    temp=head;

    int index=0;

    while(temp->nextlink!=head){
        if (temp->num==num){
            printf("Element %d found at index %d.",num,index);
            break;
        }
        temp = temp -> nextlink;
        index++;
    }
}

// 8

void updatenode(){
    int n, i=0, num;
    printf("\nEnter the Index whose element has to be updated: ");
    scanf("%d", &n);

    printf("Input data for node: ");
    scanf("%d", &num);

    temp=head;

    while(i!=n){
        temp = temp -> nextlink;
        i++;
    }
    temp->num=num;
}

void traverse(){
    printf("\nData entered:\n");
    if(head == NULL){
            printf("list is empty");
    }
    else{
        
        temp = head;
        do{
            printf("%d ", temp->num);
            temp = temp -> nextlink;
        }
        while(temp!=head);
        
        printf("\n");
        /*
        int n=0;
        while(n!=10){
            printf("%d ", temp->num);
            temp = temp -> nextlink;
            n++;
        }
        printf("\n");
        */
        //To traverse in opposite direction (using prevlink)
        
        printf("\nIn opposite direction (using prevlink):\n");
        temp = head;
        do{
            printf("%d ", (temp->prevlink) ->num );
            temp = temp -> prevlink;
        }
        while(temp!=head);
        
        printf("\n");
        /*
        n=0;
        while(n!=10){
            printf("%d ", (temp->prevlink) ->num);
            temp = temp -> prevlink;
            n++;
        }
        */
    }
    printf("\n");
}



int main(){
    int n;

    printf("\nCIRCULAR DOUBLY LINKED LIST: \n\n");
    createList();
    while(n!=10){
    printf("\nOPERATION ON CIRCULAR DOUBLY LINKED LIST: \n\n");
    printf("1. Insert first element.\n");
    printf("2. Insert last element\n");
    printf("3. Insert at random position.\n");
    printf("4. Delete first element.\n");
    printf("5. Delete last element.\n");
    printf("6. Delete from random position.\n");
    printf("7. Update a node in list.\n");
    printf("8. Search an element in list.\n");
    printf("9. Traverse\n");
    printf("10. Exit.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &n);

    switch(n){
        case 1:
            insertfirst();
            traverse();
            break;
        case 2:
            insertlast();
            traverse();
            break;
        case 3:
            insertatIndex();
            traverse();
            break;
        case 4:
            deletefirst();
            traverse();
            break;
        case 5:
            deletelast();
            traverse();
            break;
        case 6:
            deleteatIndex();
            traverse();
            break;
        case 7:
            updatenode();
            traverse();
            break;
        case 8:
            searchinList();
            break;
        case 9:
            traverse();
            break;
        default: 
            break;
    }   
    }
    return 0;
}