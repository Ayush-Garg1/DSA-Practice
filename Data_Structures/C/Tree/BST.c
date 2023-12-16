#include<stdio.h>
#include<stdlib.h>

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

int count(node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
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

int maxDepth(node *root){
    if(root == NULL){
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + ( (lh > rh) ? lh : rh );
}

void preorder(node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
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
    printf("PREORDER : ");
    preorder(root);
    printf("\nINORDER : ");
    inorder(root);
    printf("\nPOSTORDER : ");
    postorder(root);
    printf("\nCount : %d\n",count(root));
    printf("MAX Depth : %d",maxDepth(root));

    return 0;
}