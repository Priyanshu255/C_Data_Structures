// all type of rotations LL, RR, LR, RL

#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct node nodemaker;

int getHeight(nodemaker *n){
    if(n == NULL)
        return 0;
    return n->height;
    
}

nodemaker* createNode(int key){
    nodemaker *node = (nodemaker*) malloc(sizeof(nodemaker));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int max(int a, int b){
    return a>b?a:b;
}

int getBalanceFactor(nodemaker *n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

nodemaker* rightRotate(nodemaker *y){
    nodemaker *x = y->left;
    nodemaker *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
} 

nodemaker* leftRotate(nodemaker *x){
    nodemaker *y = x->right;
    nodemaker *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
} 

nodemaker* insert(nodemaker *node, int key){
    if (node == NULL){
        return(createNode(key));
    }
    if (key < node->key){
        node->left = insert(node->left, key);
    }
    else if (key > node->key){
        node->right = insert(node->right, key);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // left left case

    if(bf > 1 && key < node->left->key){
        return rightRotate(node);
    }

    // right right case

    if(bf < -1 && key > node->right->key){
        return leftRotate(node);
    }
    
    // left right case

    if(bf > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // right left case
    
    if(bf < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preorder(nodemaker *root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    nodemaker *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);
}