#include<stdio.h>
#define MAX 10

void enqueue(int *front, int *rear, int q[], int val){
    if(*front != (*rear + 1)%MAX){
        *rear = (*rear + 1)%MAX;
        q[*rear] = val;
        if(*front == -1){
            (*front) = 0;
        }
    }
}

void dequeue(int *front, int *rear, int q[]){
    if(*front != -1){
        (*front)++;
        if(*front == MAX){
            *front = -1;
            *rear = -1;
        }
    }
}

void show(int front, int rear, int q[]){
    if(front == -1){
        printf("Queue Empty\n");
        return;
    }
    while(front != rear){
        printf("%d ",q[front]);
        front = (front + 1)%MAX;
    }
    printf("%d\n",q[front]);
}

int main(){
    int q[MAX], front = -1, rear = -1;
    enqueue(&front, &rear, q, 2);
    enqueue(&front, &rear, q, 3);
    enqueue(&front, &rear, q, 5);
    enqueue(&front, &rear, q, 26);
    enqueue(&front, &rear, q, 21);
    enqueue(&front, &rear, q, 88);
    enqueue(&front, &rear, q, 9);
    enqueue(&front, &rear, q, 7);
    enqueue(&front, &rear, q, 19);
    enqueue(&front, &rear, q, 192);
    enqueue(&front, &rear, q, 109);
    show(front, rear, q);
    dequeue(&front, &rear, q);
    show(front, rear, q);

    return 0;
}