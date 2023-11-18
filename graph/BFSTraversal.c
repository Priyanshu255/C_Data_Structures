#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

//typedef struct queue qu;


int isfull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isempty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isfull(q)){
        printf("queue overflow");
    }
    else{
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isempty(q)){
        printf("No element to dequeue");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void print(struct queue *q){
    for(int i=q->r; i>q->f; i--){
        printf("%d  ", q->arr[i]);
    }
}

int main(){
    struct queue *q;

    q->size = 400;
    q->f = q->r = 0;
    q->arr = (int*) malloc(sizeof(struct queue)*sizeof(int));

    //BSF implementation
    int u;
    int i=4;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(q, i);   //enqueue i for exploration
    while(!isempty(q)){
        int node = dequeue(q);
        for(int j=0; j<7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

}