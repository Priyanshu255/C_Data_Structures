#include <stdio.h>
#include <stdlib.h>


struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

typedef struct circularQueue qu;

qu q;

int isfull(){
    if((q.r+1)%q.size == q.f){
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
        q.r = (q.r+1)%q.size;
        q.arr[q.r] = val;
    }
}

int dequeue(){
    int a = -1;
    if(isempty()){
        printf("No element to dequeue");
    }
    else{
        q.f = (q.f+1)%q.size;
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
    /*
    q.size = 4;
    q.f = q.r = -1;
    q.arr = malloc(sizeof(struct circularQueue)*sizeof(int));

    enqueue(56);
    enqueue(5);
    enqueue(6);
    enqueue(89);
    print();
    printf("\nelement: %d\n",dequeue());
    //printf("element: %d\n",dequeue());

    print();
    */
    q.size = 4;
    q.f = q.r = 0;
    q.arr = malloc(sizeof(struct circularQueue)*sizeof(int));

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
    print();
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
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    enqueue(9);
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    printf("element: %d\n",dequeue());
    printf("f: %d\n", q.f);
    printf("r: %d\n", q.r);
    print();
}