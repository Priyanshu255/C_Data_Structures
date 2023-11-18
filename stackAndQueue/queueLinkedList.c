#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node no;

no *f=NULL;
no *r=NULL;

int isempty(){
    if(f==NULL){
        return 1;
    }
    return 0;
}

int isfull(){
    if(r==NULL){
        return 1;
    }
    return 0;
}

void enqueue(int val){
    no *n = (no*) malloc(sizeof(no));
    if(n==NULL){
        printf("queue overflow");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

int dequeue(){
    int val = -1;
    no *p = f;
    if(isempty()){
        printf("queue empty");
    }
    else{
        f=f->next;
        val = p->data;
        free(p);
    }
    return val;
}

void traverse(){
    printf("\nData entered:\n");
    if(f == NULL){
            printf("list is empty");
    }
    else{
        no *temp = f;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp -> next;
        }
    }
}
int main(){

    printf("element: %d\n",dequeue());
    enqueue(45);
    enqueue(4);
    enqueue(5);
    traverse();
    printf("element: %d\n",dequeue());
    
    traverse();
    
}