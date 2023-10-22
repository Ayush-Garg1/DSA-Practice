import java.util.*;

class Queue{
    private
    final int max = 10;
    int[] arr = new int[max];
    int front;
    int rear;

    public
    Queue(){
        front = -1;
        rear = -1;
    }

    void insert(int val){
        if((rear+1)%max != front){
            if(front == -1){
                front++;
            }
            rear = (rear+1)%max;
            arr[rear] = val;
        }
    }

    int remove(){
        int num = 0;
        if(front != -1){
            num = arr[front];
            front = (front+1)%max;
        }
        return num;
    }

    void display(){
        int temp = front;
        while(temp != rear){
            System.out.print(arr[temp] + " ");
            temp = (temp+1)%max;
        }
        System.out.println(arr[temp]);
    }

}

public class queueDS {
    public static void main(String[] args){
        Queue q = new Queue();
        for(int i = 0;i<10;i++){
            q.insert(i);
        }
        q.display();
        for(int i = 0;i<10;i++){
            q.remove();
            q.display();
            q.insert(i+10);
            q.display();
        }
        System.out.println();
        q.insert(20);
        q.display();
    }
}