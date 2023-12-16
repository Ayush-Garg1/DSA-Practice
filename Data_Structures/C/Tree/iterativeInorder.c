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

void push(stack **st, node *val){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = val;
    temp->next = *st;
    *st = temp;
}

node* pop(stack **st){
    if(*st != NULL){
        node *temp = (*st)->data;
        *st = (*st)->next;
        return temp;
    }
    return NULL;
}

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

node* top(stack *st){
    return st->data;
}

int empty(stack *st){
    return st == NULL;
}

void inorder(node *root){
    printf("In-Order : ");
    stack *st = NULL;
    while(1){
        if(root != NULL){
            push(&st, root);
            root = root->left;
        }else{
            if(empty(st) == 1){
                break;
            }
            root = pop(&st);
            printf("%d ",root->data);
            root = root->right;
        }
    }
    printf("\n");
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
    inorder(root);

    return 0;
}