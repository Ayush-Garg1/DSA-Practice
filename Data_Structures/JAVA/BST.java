import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(){}
    Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
    Node(int data, Node left, Node right){
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

class tree{
    Node root;

    tree(){
        root = null;
    }

    Node insert(int data){
        root = insertHelper(root,data);
        return root;
    }

    Node insertHelper(Node root, int data){
        if(root == null){
            return (root = new Node(data));
        } else if(data < root.data){
            root.left = insertHelper(root.left, data);
        } else{
            root.right = insertHelper(root.right, data);
        }
        return root;
    }

    Node search(Node root, int key){
        if(root == null || root.data == key){
            return root;
        } else if(key < root.data){
            return search(root.left, key);
        } else{
            return search(root.right, key);
        }
    }

    void inorder(Node root){
        if(root == null){
            return;
        }
        inorder(root.left);
        System.out.print(root.data);
        inorder(root.right);
    }

    void preorder(Node root){
        if(root == null){
            return;
        }
        System.out.print(root.data);
        preorder(root.left);
        preorder(root.right);
    }

    void postorder(Node root){
        if(root == null){
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data);
    }

    Node delete(int data){
        return (root = deleteHelper(root,data));
    }

    Node inorderSuccessor(Node temp){
        while(temp.left != null){
            temp = temp.left;
        }
        return temp;
    }

    Node deleteHelper(Node root, int data){
        if(root == null){
            return root;
        }
        if(data < root.data){
            return deleteHelper(root.left, data);
        } else if(data > root.data){
            return deleteHelper(root.right, data);
        } else{
            if(root.left == null && root.right == null){
                root = null;
            } else if(root.left == null){
                root = root.right;
            } else if(root.right == null){
                root = root.left;
            } else{
                Node suc = inorderSuccessor(root.right);
                root.data = suc.data;
                deleteHelper(root.right, suc.data);
            }
        }
        return root;
    }
}

public class BST{
    public static void main(String[] args){
        tree tre = new tree();
        tre.insert(5);
        tre.insert(2);
        tre.insert(1);
        tre.insert(3);
        tre.insert(8);
        System.out.println((tre.search(tre.root, 5)) != null);
        tre.delete(8);
        System.out.println((tre.search(tre.root, 5)) != null);
        // tre.inorder(tre.root);
        // System.out.println();
        // tre.preorder(tre.root);
        // System.out.println();
        // tre.postorder(tre.root);
    }
}