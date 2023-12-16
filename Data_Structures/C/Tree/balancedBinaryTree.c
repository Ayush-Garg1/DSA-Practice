#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node node;

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

// BALANCED TREE FINDING FUNCTION

int height(node *root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    if(lh == -1){
        return -1;
    }
    int rh = height(root->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh- rh) > 1){
        return -1;
    }
    return 1 + ((lh > rh)? lh : rh);
}

int isBalanced(node *root){
   return (height(root) == -1);
}

int main(){
    node *root = NULL;
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,8);
    root = insert(root,15);
    root = insert(root,12);
    root = insert(root,18);
    root = insert(root,25);
    root = insert(root,30);
    printf("Balanced : %d",isBalanced(root));

    return 0;
}