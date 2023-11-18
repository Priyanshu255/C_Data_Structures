#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node no;

no *top = NULL;


int isempty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int isfull(){
    no* p = (no*) malloc(sizeof(no));
    if(p==NULL){
        return 1;
    }
    return 0;
}
no* push(int x){
    if(isfull()){
        printf("\nStack Overflow\n");
    }
    else{
        no* n = (no*) malloc(sizeof(no));
        n->data = x;
        n->next = top;
        top=n;
        return top;
    }
}

int pop(){
    if(isempty()){
        printf("\nStack is Underflow\n");
    }
    else{
        no* t = top;
        top = (top)->next;
        int x = t->data;
        free(t);
        return x;
    }
}

int peek(int pos){
    no* temp = top;
    for(int i=0; (i<pos-1 && temp!=NULL); i++){
        temp = temp->next;
    }
    if(temp!=NULL){
        return temp->data;
    }
    return -1;
}

int stacktop(){
    return top->data;
}

int stackbottom(){
    no* temp = top;
    while(temp->next!=NULL){
        temp = temp-> next;
    }
    return temp->data;
}


void traverse(no* temp){
    printf("\nData entered:\n");
    if(isempty(temp)){
        printf("list is empty");
    }
    else{
        while(temp!=NULL){
            printf("%d\n", temp->data);
            temp = temp -> next;
        }
    }
}

int main(){
    top = push(78);
    top = push(7);
    top = push(8);
    top = push(67);
    //traverse(top);

    // printf("\nPopped material: %d\n", pop());
    // printf("\nPopped material: %d\n", pop());
    // printf("\nPopped material: %d\n", pop());
    // printf("\nPopped material: %d\n", pop());
    // printf("\nPopped material: %d\n", pop());

    traverse(top);
    printf("top: %d  ", stacktop());
    printf("bottom: %d", stackbottom());
}