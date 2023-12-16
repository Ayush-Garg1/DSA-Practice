#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node* newNode(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(node **top, int val){
    node *temp = newNode(val);
    temp->next = *top;
    *top = temp;
}

int dequeue(node **top){
    if(*top != NULL){
        int t = (*top)->data;
        *top = (*top)->next;
        return t;
    }
    return -1;
}

void enqueue(node **top, int val){
    if(*top == NULL){
        (*top) = newNode(val);
        return;
    }
    int n = dequeue(top);
    enqueue(top, val);
    push(top, n);
}

void show(node *top){
    if(top == NULL){
        printf("Stack Empty!!!\n");
        return;
    }
    while(top != NULL){
        printf("%d ",top->data);
        top = top->next;
    }
    printf("\n");
}

int main(){
    node *stack = NULL;
    enqueue(&stack, 2);
    enqueue(&stack, 4);
    enqueue(&stack, 5);
    enqueue(&stack, 7);
    enqueue(&stack, 9);
    enqueue(&stack, 6);
    show(stack);
    dequeue(&stack);
    show(stack);
    enqueue(&stack, 10);
    show(stack);

    return 0;
}