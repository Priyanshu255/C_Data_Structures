#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};
typedef struct stack stack;

char stacktop(stack *sp){
    return sp->arr[sp->top];
}

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

void push(stack *s, char a){
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

char pop(stack *s){
    if(isempty(s)){
        printf("\nStack is Underflow\n");
    }
    else{
        char val = s->arr[s->top];
        s->top--;
        return val;
        //printf("\nPopped %c from the stack\n", val);
        //printf("%d\n", s->top);
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '*' || ch == '-' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

char* infixToPostfix(char *infix){
    stack *sp = (stack*) malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*) malloc(sp->size * sizeof(char));
    char *postfix = (char*) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; //track infix traversal
    int j=0; //track postfix addition

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i]) > precedence(stacktop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isempty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}


int main(){
    char *infix = "a-b";

    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
