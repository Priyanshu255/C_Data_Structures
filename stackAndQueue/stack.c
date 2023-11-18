#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};
typedef struct stack stack;

int isempty(stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int isfull(stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}

void push(stack *s, int a){
    if(isfull(s)){
        printf("\nStack Overflow\n");
        printf("Cannot push %d in stack.", a);
    }
    else{
        s->top++;
        s->arr[s->top]=a;
        //printf("%d\n", s->top);
    }
}

void pop(stack *s){
    if(isempty(s)){
        printf("\nStack is Underflow\n");
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        printf("\nPopped %d from the stack\n", val);
        //printf("%d\n", s->top);
    }
}

int peek(stack *s, int i){
    int arrayind = s->top -i ;
    if(arrayind<0){
        printf("Not a valid position for the stack");
        return -1;
    }
    else{
        return s->arr[arrayind];
    }
}

void display(stack *s){
    printf("%d <-- top\n", s->arr[s->top]);
    //for(int i = s->top-1; i>=0; i--){
    //    printf("%d\n", s->arr[i]);
    //}
    for(int i = 0; i<=s->top-1; i++){
        //printf("%d\n", s->arr[s->top-i]);
        printf("%d\n", peek(s,i));
    }
}


int main(){
    stack *sp = (stack *) malloc(sizeof(stack));
    sp->size = 4;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    //pop(sp);
    push(sp,34);
    push(sp,67);
    push(sp,89);
    push(sp,12);
    //push(sp,92);
    display(sp);

    pop(sp);

    display(sp);

}