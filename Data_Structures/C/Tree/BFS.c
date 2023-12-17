#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node node;

struct queue{
    node *data;
    struct queue *next;
};
typedef struct queue queue;

node* newNode(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node *root, int val){
    if(root == NULL){
        root = newNode(val);
        return root;
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

node* inorderSuccessor(node *root){
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

node *delete(node *root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->data){
        root->left = delete(root->left, val);
    }
    else if(val > root->data){
        root->right = delete(root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
            return root;
        }
        if(root->left == NULL){
            node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }
        else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        else{
            node *inSuc = inorderSuccessor(root->right);
            root->data = inSuc->data;
            root->right = delete(root->right, inSuc->data);
        }
    }
    return root;
}

queue* newQueue(node *data){
    queue *q = (queue*)malloc(sizeof(queue));
    q->data = data;
    q->next = NULL;
    return q;
}

void enqueue(queue **q, node *data){
    if(*q == NULL){
        *q = newQueue(data);
        return;
    }
    queue *temp = *q;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newQueue(data);
}

node* dequeue(queue **q){
    if(*q == NULL){
        return NULL;
    }
    node *temp = (*q)->data;
    *q = (*q)->next;
    return temp;
}

int empty(queue *q){
    return q == NULL;
}

int size(queue *q){
    int count = 0;
    while(q != NULL){
        count++;
        q = q->next;
    }
    return count;
}

void levelOrder(node *root){
    queue *q = NULL;
    enqueue(&q, root);
    while(!empty(q)){
        int Size = size(q);
        while(Size--)
        {
            node *n = dequeue(&q);
            printf("%d ",n->data);
            if(n->left) enqueue(&q, n->left);
            if(n->right) enqueue(&q, n->right);
        }
        printf("\n");
    }
}

int main(){
    node *root = NULL;
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,3);
    root = insert(root,7);
    root = insert(root,6);
    root = insert(root,8);
    levelOrder(root);

    return 0;
}