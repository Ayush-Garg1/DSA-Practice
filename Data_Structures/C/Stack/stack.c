#include<stdio.h>

#define MAX 100

void push(int stack[], int *top, int val){
    if(*top != MAX - 1){
        stack[++(*top)] = val;
    }
}

int pop(int stack[], int *top){
    if(*top != -1){
        int temp = stack[*top];
        (*top)--;
        return temp;
    }
    return 0;
}

int empty(int top){
    return top == -1;
}

void show(int stack[], int top){
    if(top == -1){
        printf(":(");
    }
    while(top != -1){
        printf("%d ",stack[top]);
        top--;
    }
    printf("\n");
}

int search(int stack[], int *top, int val, int pos){
    if(empty(*top)){
        return 0;
    }
    if(stack[*top] == val){
        return pos;
    }
    int n = pop(stack, top);
    pos = search(stack, top, val, pos+1);
    push(stack, top, n);
    return pos;
}

int find(int stack[], int *top, int val){
    return search(stack, top, val, 1);
}

void pushBottom(int stack[], int *top, int val){
    if(*top == -1){
        stack[++(*top)] = val;
        return;
    }
    int n = pop(stack, top);
    pushBottom(stack, top, val);
    push(stack, top, n);
}

void reverse(int stack[], int *top){
    if(*top == -1){
        return;
    }
    int n = pop(stack, top);
    reverse(stack, top);
    pushBottom(stack, top, n);
}

int main(){
    int stack[MAX], top = -1;
    push(stack, &top, 10);
    push(stack, &top, 8);
    push(stack, &top, 6);
    push(stack, &top, 4);
    push(stack, &top, 2);
    show(stack, top);
    printf("Find %d : %d\n",10,find(stack, &top, 10));
    push(stack, &top, 0);
    pushBottom(stack, &top, 12);
    show(stack, top);
    pop(stack, &top);
    show(stack, top);
    reverse(stack, &top);
    show(stack, top);

    return 0;
}