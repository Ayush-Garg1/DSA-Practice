import java.util.*;

public class searchInStack {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Stack<Integer> s = new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);
        System.out.println();
        int item = scan.nextInt();
        int index = search(s,item,1);
        System.out.println(index);
    }
    public static int search(Stack<Integer> s,int n,int index){
        if(s.empty()){
            return -1;
        }
        if(s.peek() == n){
            return index;
        }
        int top = s.pop();
        index = search(s, n,index+1);
        s.push(top);
        return index;
    }
}
