#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node *link;
} *node1, *node2, *temp, *head;

typedef struct node nodemaker;

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
        node1 -> link = NULL;
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
                node2 -> link = NULL;
                temp -> link = node2;
                temp = temp -> link;
            }
        }
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
    firstnode -> link = head;
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

    temp = head;
    while(temp->link != NULL){
        temp = temp -> link;
    }
    lastnode -> num = num;
    lastnode -> link = NULL;
    temp -> link = lastnode;
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
        temp = temp -> link;
        i++;
    }
    betweennode -> num = num;
    betweennode -> link = temp -> link; 
    temp -> link = betweennode;
}

// 4 

void deletefirst(){
    printf("\nDeleteing a node at starting: \n");
    temp = head;
    head = temp->link;
    free(temp);
}

// 5

void deletelast(){
    printf("\nDeleteing a node at last: \n");
    nodemaker *tempnext;

    temp = head;
    tempnext = temp->link;
    while(tempnext->link!=NULL){
            temp = temp -> link;
            tempnext = tempnext->link;
        }
    free(tempnext);
    temp->link=NULL;
}

// 6

void deleteatIndex(){
    int n, i=0;
    printf("\nDeleteing a node in between: \n");
    printf("Enter the Index: ");
    scanf("%d", &n);

    nodemaker *backnode;

    backnode = head;
    temp = backnode->link;

    
    while(i!=(n-1)){
        backnode = backnode->link;
        temp = temp -> link;
        i++;
    }
    backnode->link = temp->link;
    free(temp);
}

// 7

void searchinList(){
    int num;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &num);

    temp=head;

    int index=0;

    while(temp!=NULL){
        if (temp->num==num){
            printf("Element %d found at index %d.",num,index);
            break;
        }
        temp = temp->link;
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
        temp = temp -> link;
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
        while(temp!=NULL){
            printf("%d ", temp->num);
            temp = temp -> link;
        }
    }
}

int main() {
    printf("\nSINGLY LINKED LIST: \n\n");
    createList();
    int n;
    while(n!=10){
    
    printf("\nOPERATION ON SINGLY LINKED LIST: \n\n");
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
