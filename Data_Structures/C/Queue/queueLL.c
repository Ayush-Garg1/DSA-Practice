#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(node **front, node **rear, int val){
    node *temp = newNode(val);
    if(*front == NULL){
        *front = temp;
        *rear = temp;
    }else{
        (*rear)->next = temp;
        *rear = temp;
    }
    temp->next = *front;
}

int dequeue(node **front, node **rear){
    if(*front != NULL){
        node *temp = *front;
        *front = (*front)->next;
        (*rear)->next = *front;
        return temp->data;
    }
    return -1;
}

int search(node *front, node *rear, int key, int pos){
    if(front == NULL){
        return 0;
    }
    if(front->data == key){
        return pos;
    }
    if(front == rear){
        if(front->data == key){
            return pos;
        }
        return 0;
    }
    pos = search(front->next, rear, key, pos+1);
    return pos;
}

int find(node *front, node *rear, int key){
    return search(front, rear, key, 1);
}

void show(node *front, node *rear){
    printf("Queue : ");
    if(front == NULL){
        printf("Empty!!!\n");
        return;
    }
    while(front != rear){
        printf("%d ",front->data);
        front = front->next;
    }
    printf("%d\n",front->data);
}

int main(){
    node *front = NULL, *rear = NULL;
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 6);
    enqueue(&front, &rear, 8);
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 12);
    show(front, rear);
    printf("pos of %d is %d\n", 12, find(front, rear, 12));

    return 0;
}