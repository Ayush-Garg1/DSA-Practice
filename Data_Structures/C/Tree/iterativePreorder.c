#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node node;

struct stack{
    node *data;
    struct stack *next;
};
typedef struct stack stack;

node* newNode(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void push(stack **st, node *val){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = val;
    temp->next = NULL;

    temp->next = *st;
    *st = temp;
}

node* pop(stack **st){
    node *temp = (*st)->data;
    (*st) = (*st)->next;
    return temp;
}

int empty(stack *st){
    return st == NULL;
}

// PREORDER ---> ROOT LEFT RIGHT
void preorder(node *root){
    printf("Pre-Order : ");
    stack *st = NULL;
    push(&st, root);
    while(!empty(st)){
        node *n = pop(&st);
        printf("%d ",n->data);
        if(n->right){
            push(&st, n->right);
        }
        if(n->left){
            push(&st, n->left);
        }
    }
    printf("\n");
}

node* insert(node *root, int val){
    if(root == NULL){
        root = newNode(val);
        return root;
    }else if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

node* inorderSuccessor(node *root){
    while(root->left){
        root = root->left;
    }
    return root;
}

node* delete(node *root, int val){
    if(root == NULL){
        return root;
    } else if(val < root->data){
        root->left = delete(root->left, val);
    } else if(val > root->data){
        root->right = delete(root->right, val);
    } else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }else if(root->left == NULL){
            node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }else{
            node *suc = inorderSuccessor(root->right);
            root->data = suc->data;
            root->right = delete(root->right, suc->data);
        }
    }
    return root;
}

int main(){
    node *root = NULL;
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,7);
    root = insert(root,6);
    root = insert(root,8);
    // printf("PREORDER : ");
    preorder(root);

    return 0;
}