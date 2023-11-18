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

void inorder(nodemaker *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(nodemaker *root){
    static nodemaker *prev = NULL;
    if(root != NULL){
        if ( !isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){

    nodemaker *p = createnode(5);
    nodemaker *p1 = createnode(3);
    nodemaker *p2 = createnode(6);
    nodemaker *p3 = createnode(1);
    nodemaker *p4 = createnode(4);

    //       5
    //      / \
    //     3   6
    //    / \
    //   1   4

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\nInorder: ");
    inorder(p);
    printf("\nIs BST: %d", isBST(p));

    return 0;

}