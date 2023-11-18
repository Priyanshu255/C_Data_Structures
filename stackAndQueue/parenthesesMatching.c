#include <stdio.h>
#include <stdlib.h>

// this program never shows expretions validity only check parenthesis 

struct stack {
    int size;
    int top;
    char *arr;
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

void pop(stack *s){
    if(isempty(s)){
        printf("\nStack is Underflow\n");
    }
    else{
        char val = s->arr[s->top];
        s->top--;
        //printf("\nPopped %c from the stack\n", val);
        //printf("%d\n", s->top);
    }
}

int parenthesisMatch(char *exp){
    // create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    
    for(int i=0; exp[i] != '\0'; i++){
        if (exp[i] == '('){
            push(sp, '(');
        }
        else if (exp[i] == ')'){
            if(isempty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(isempty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){

    char * exp = "8*(9)";
    if(parenthesisMatch(exp)){
        printf("the parenthesis is matching");
    }
    else{
        printf("the parenthesis is not matching");
    }

    return 0;

}