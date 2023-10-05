import java.util.*;

class stack{
    private
        static final int MAX = 1000;
        int top;
        char[] st = new char[MAX];

    public
        //Constructor
        stack(){
            top = -1;
        }

        //push the character
        void push(char data){
            st[++top] = data;
        }

        //pop top most character
        void pop(){
            top--;
        }

        //return the element at the top of the stack
        char atTop(){
            return st[top];
        }

        //check whether the stack is empty
        boolean empty(){
            return top == -1;
        }

        //check whether the element at top of the stack and the incoming element are matching
        boolean match(char ch){
            boolean ans;
            if(st[top] == '(' && ch == ')'){
                ans = true;
            } else if(st[top] == '{' && ch == '}'){
                ans = true;
            } else if(st[top] == '[' && ch == ']'){
                ans = true;
            } else if(st[top] == '<' && ch == '>'){
                ans = true;
            } else{
                ans = false;
            }
            return ans;
        }
}

public class validParenthesis {
    public static void main(String[] args){

        stack s = new stack();

        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();

        for(int i = 0; i < str.length(); i++){
            if(!isParenthesis(str.charAt(i))){
                continue;
            }

            if(str.charAt(i) == '(' || str.charAt(i) == '{' || str.charAt(i) == '[' || str.charAt(i) == '<'){
                s.push(str.charAt(i));
            } else{
                if(s.empty()){
                    System.out.println("Invalid");
                    return;
                }else{
                    if(s.match(str.charAt(i))){
                        s.pop();
                    }
                    else{
                        System.out.println("Invalid");
                        return;
                    }
                }
            }
        }
        if(s.empty()){
            System.out.println("Valid");
        } else{
            System.out.println("Invalid");
        }
    }

    //check whether the incoming character is parenthesis or not
    static boolean isParenthesis(char ch){
        switch(ch){
            case '(':
            case '{':
            case '[':
            case '<':
            case ')':
            case '}':
            case ']':
            case '>':
                return true;
        }
        return false;
    }
}
