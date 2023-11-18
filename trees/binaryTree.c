#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right; 
};

typedef struct node nodemaker;

nodemaker* createnode(int data){
    nodemaker *n;
    n = (nodemaker*) malloc(sizeof(nodemaker));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}


int main(){
    /*
    nodemaker *p;
    p = (nodemaker*) malloc(sizeof(nodemaker));
    p->left = NULL;
    p->right = NULL;
    p->data = 2;
    
    nodemaker *p1;
    p1 = (nodemaker*) malloc(sizeof(nodemaker));
    p1->left = NULL;
    p1->right = NULL;
    p1->data = 1;

    nodemaker *p2;
    p2 = (nodemaker*) malloc(sizeof(nodemaker));
    p2->left = NULL;
    p2->right = NULL;
    p2->data = 4;

    p->left = p1;
    p->right = p2;
    */

    nodemaker *p = createnode(2);
    nodemaker *p1 = createnode(1);
    nodemaker *p2 = createnode(6);

    p->left = p1;
    p->right = p2;

    return 0;
}