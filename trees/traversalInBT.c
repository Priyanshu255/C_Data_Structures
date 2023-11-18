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

void preorder(nodemaker *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(nodemaker *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(nodemaker *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){

    nodemaker *p = createnode(4);
    nodemaker *p1 = createnode(1);
    nodemaker *p2 = createnode(6);
    nodemaker *p3 = createnode(5);
    nodemaker *p4 = createnode(2);

    //       4
    //      / \
    //     1   6
    //    / \
    //   5   2

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder: ");
    preorder(p);
    printf("\nPostorder: ");
    postorder(p);
    printf("\nInorder: ");
    inorder(p);
    return 0;
}