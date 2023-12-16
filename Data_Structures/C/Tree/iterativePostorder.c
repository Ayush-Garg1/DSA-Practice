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
void push(stack **st, node *data){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = data;
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

int empty(stack *st){
    return st == NULL;
}

stack* postorder(node *root){
    printf("Post-Order : ");
    stack *st1 = NULL, *st2 = NULL;
    push(&st1, root);
    while(empty(st1) == 0){
        node *temp = pop(&st1);
        push(&st2, temp);
        if(temp->left){
            push(&st1, temp->left);
        }
        if(temp->right){
            push(&st1, temp->right);
        }
    }
    return st2;
}

void show(stack *st){
    if(st == NULL){
        return ;
    }
    printf("%d ",st->data->data);
    show(st->next);
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
    show(postorder(root));

    return 0;
}