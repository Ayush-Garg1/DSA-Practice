import java.util.*;

//User defined stack class 
class stack{
    private
        static final int MAX = 1000; //maximum size of stack declared here
        int top; //always points to the top most element in the stack
        int[] st = new int[MAX];
    
    public
        //Constructor
        stack(){
            top = -1;
        }

        //push function to add element at the top of the stack
        void push(int data){
            st[++top] = data;   //always increment the top before pushing the element
        }

        //pop function removes top most data from the stack
        void pop(){
            top--;
        }

        //returns the data at the top of the stack
        int atTop(){
            return st[top];
        }

        //check whether the stack is empty or not
        boolean empty(){
            return top == -1;
        }

        //display the stack from top to bottom
        void display(){
            if(top == -1){
                System.out.println("Stack Empty");
                return;
            }
            int temp = top;
            System.out.print("Stack : ");
            while(temp != -1){
                System.out.print(st[temp] + " ");
                temp--;
            }
            System.out.println();
        }
}

//public class
public class stackUsingArray{
    public static void main(String[] args){
        stack s = new stack();
        s.display();
        for(int i = 1 ;i<=10;i++){
            s.push(i);
        }
        s.display();
        s.pop();
        s.display();
        System.out.println("Element at top : " + s.atTop());
    }
}