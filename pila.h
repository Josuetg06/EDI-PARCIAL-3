#include <stdio.h>
#include "constante.h"
typedef struct  {
    int data[MAX];
    int top;
} Stack;

void setup(Stack *s){
    s->top=-1;
}
int isEmpty(Stack stack){
    if (stack.top==-1)
        return 1;
    return 0;


}
int isFull(Stack stack){
    if (stack.top== MAX-1)
        return 1;
    return 0;
}
int push(Stack *s, int value){

    int r=0;
    if (isFull(*s)==0){
        s->top++;
        s->data[s->top]=value;
        r=1;
    }
    return r;
}
int pop (Stack *s, int *v){


    if (!isEmpty(*s)){
        *v= s->data[s->top];
        s->top--;
        return 1;
    }
    return 0;
}

int imprimir(Stack stack){

    for (int i = 0; i < MAX; ++i) {
        printf("%d\n",stack.data[i]);
    }
}
