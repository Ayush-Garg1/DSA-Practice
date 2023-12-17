#include<stdio.h>
#include<stdlib.h>

struct node{
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

node *insert(node *head, int val){
    if(head == NULL){
        head = newNode(val);
        return head;
    }
    node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode(val);
    return head;
}

void show(node *head){
    printf("LIST : ");
    if(head == NULL){
        printf("Empty!");
    }
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

node* reverse(node *head){
    node *temp = head;
    head = (head)->next;
    temp->next = NULL;
    while(head){
        node *temp2 = head;
        head = (head)->next;
        temp2->next = temp;
        temp = temp2;
    }
    return temp;
}

node* findKth(node *head, int k){
    int count = 1;
    while(head != NULL && count != k){
        head = head->next;
        count++;
    }
    return head;
}

node* reverseInKgroups(node *head, int k){
    node *temp = head;
    node *previous = NULL;
    while(temp){
        node *kth = findKth(temp, k);
        if(kth == NULL){
            if(temp != head){
                previous->next = temp;
            }
            break;
        }
        node *nextNode = kth->next;
        kth->next = NULL;
        kth = reverse(temp);
        if(temp == head){
            head = kth;
        }
        if(previous != NULL){
            previous->next = kth;
        }
        previous = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 9);
    show(head);
    // head = reverse(head);
    // show(head);
    head = reverseInKgroups(head, 3);
    show(head);

    return 0;
}