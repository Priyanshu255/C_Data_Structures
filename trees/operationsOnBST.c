//search (recursive, iterative)
//insertion
//deletion (leaf node, non leaf node, root node or non leaf node child)


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

//recursive search
nodemaker* search(nodemaker* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key == root->data){
        return root;
    }
    else if (key < root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

//iterative search
nodemaker* searchIterative(nodemaker* root, int key){
    if(root == NULL){
        return NULL;
    }
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if (key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    
}

//insertion 

void insert(nodemaker *root, int key){
    nodemaker* prev = NULL;

    while (root != NULL)
    {
        prev = root;
        if(key == root->data){
            printf("Cannot insert %d, already exist.", key);
            return;
        }
        else if (key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    nodemaker *newNode = createnode(key);
    if(key < prev->data){
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }
    
}

//deletion
void inorder(nodemaker *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

nodemaker* inOrderPredecessor(nodemaker* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

nodemaker *deleteNode(nodemaker *root, int value){
    //deciding which type of root it is.
    if (root == NULL){
        return NULL;
    }
    if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    
    //search for the node to be deleted
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data){
        root->right = deleteNode(root->right, value);
    }

    //deleting

    else{
        nodemaker *iPre = inOrderPredecessor(root);
        root-> data = iPre->data;
        root-> left = deleteNode(root->left, iPre->data);
    }
    return root;

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

    //searching
    //nodemaker *s = search(p, 1);
    //printf("\nFound(recursive): %d", s->data);
    //nodemaker *s1 = searchIterative(p, 1);
    //printf("\nFound(Iterative): %d", s1->data);

    //insertion
    //insert(p,6);
    //checking if inserted or not
    //printf("%d", p->right->right->data);

    //deletion
    inorder(p);
    deleteNode(p, 5);
    printf("\n");
    inorder(p);

    return 0;
}