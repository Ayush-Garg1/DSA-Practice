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

        void push(char data){
            st[++top] = data;
        }

        void pop(){
            top--;
        }

        char atTop(){
            return st[top];
        }

        boolean empty(){
            return top == -1;
        }

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
