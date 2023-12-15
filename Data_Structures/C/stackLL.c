#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node;

node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(node **stack, int data){
    node *temp = newNode(data);
    temp->next = *stack;
    *stack = temp;
}

int pop(node **stack){
    if(*stack == NULL){
        return -1;
    }
    node *temp = *stack;
    (*stack) = (*stack)->next;
    return temp->data;
}

int empty(node *stack){
    return stack == NULL;
}

void pushBottom(node **stack, int data){
    if(*stack == NULL){
        (*stack) = newNode(data);
        return;
    }
    int n = pop(stack);
    pushBottom(stack, data);
    push(stack, n);
}

int search(node **stack, int key, int pos){
    if(*stack == NULL){
        return 0;
    }
    if((*stack)->data == key){
        return pos;
    }
    int temp = pop(stack);
    pos = search(stack, key, pos+1);
    push(stack, temp);
    return pos;
}

void reverse(node **stack){
    if(*stack == NULL){
        return;
    }
    int n = pop(stack);
    reverse(stack);
    pushBottom(stack, n);
}

int find(node** stack, int key){
    return search(stack, key, 1);
}

void show(node **stack){
    if(*stack == NULL){
        return;
    }
    int n = pop(stack);
    printf("%d ",n);
    show(stack);
    push(stack, n);
}

int main(){
    node *stack = NULL;
    push(&stack, 2);
    push(&stack, 5);
    push(&stack, 8);
    push(&stack, 11);
    push(&stack, 14);
    push(&stack, 17);
    show(&stack);
    printf("\n");
    pop(&stack);
    show(&stack);
    printf("\nSearch : %d\n",find(&stack, 2));
    pushBottom(&stack, -10);
    show(&stack);
    printf("\n");
    pop(&stack);
    show(&stack);
    printf("\n");
    reverse(&stack);
    show(&stack);

    return 0;
}