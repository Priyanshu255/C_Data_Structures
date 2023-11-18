#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

struct queue q;

int isfull(){
    if(q.r == q.size-1){
        return 1;
    }
    return 0;
}

int isempty(){
    if(q.f==q.r){
        return 1;
    }
    return 0;
}

void enqueue(int val){
    if(isfull()){
        printf("queue overflow");
    }
    else{
        q.r = q.r + 1;
        q.arr[q.r] = val;
    }
}

int dequeue(){
    int a = -1;
    if(isempty()){
        printf("No element to dequeue");
    }
    else{
        q.f++;
        a = q.arr[q.f];
    }
    return a;
}

void print(){
    for(int i=q.r; i>q.f; i--){
        printf("%d  ", q.arr[i]);
    }
}

int main(){
    q.size = 4;
    q.f = q.r = -1;
    q.arr = malloc(sizeof(struct queue)*sizeof(int));

    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    enqueue(56);
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    enqueue(5);
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    enqueue(6);
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    enqueue(89);
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    //print();
    printf("\nelement: %d\n",dequeue());
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    printf("element: %d\n",dequeue());
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    printf("element: %d\n",dequeue());
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    printf("element: %d\n",dequeue());
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    //printf("element: %d\n",dequeue());
    enqueue(89);
    printf("f: %d", q.f);
    printf("r: %d", q.r);
    //print();

}