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

void enqueue(node **front, node **rear, int data){
    node*temp = newNode(data);
    if(*front == NULL){
        *front = temp;
        *rear = temp;
    }
    else{
        (*rear)->next = temp;
        *rear = (*rear)->next;
    }
}

int dequeue(node **front, node **rear){
    if(*front != NULL){
        int t = (*front)->data;
        *front = (*front)->next;
        return t;
    }
    return -1;
}

int empty(node *front){
    return front == NULL;
}

void push(node **f1, node **r1, node **f2, node **r2, int val){
    enqueue(f2, r2, val);

    while(!empty(*f1)){
        int n = dequeue(f1, r1);
        enqueue(f2, r2, n);
    }

    // SWAPPING
    node *temp = *f1;
    *f1 = *f2;
    *f2 = temp;

    temp = NULL;
    temp = *r1;
    *r1 = *r2;
    *r2 = temp;
}

int pop(node **f1, node **r1){
    return dequeue(f1, r1);
}

void show(node *f, node *r){
    if(f == NULL){
        printf("Stack Empty!!!\n");
        return ;
    }
    while(f != r){
        printf("%d ",f->data);
        f = f->next;
    }
    printf("%d\n",f->data);
}

int main(){
    node *f1 = NULL , *r1 = NULL , *f2 = NULL , *r2 = NULL;
    push(&f1, &r1, &f2, &r2, 2);
    push(&f1, &r1, &f2, &r2, 4);
    push(&f1, &r1, &f2, &r2, 6);
    push(&f1, &r1, &f2, &r2, 8);
    push(&f1, &r1, &f2, &r2, 10);
    push(&f1, &r1, &f2, &r2, 12);
    show(f1, r1);
    pop(&f1, &r1);
    show(f1, r1);

    return 0;
}
