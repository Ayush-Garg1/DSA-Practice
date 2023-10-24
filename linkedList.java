import java.util.*;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
    Node(int data,Node next){
        this.data = data;
        this.next = next;
    }
}

class LL{
    private
    Node head;
    public
    LL(){
        this.head = null;
    }
    void addFirst(int data){
        Node node = new Node(data);
        node.next = head;
        head = node;
    }

    void addLast(int data){
        Node node = new Node(data);
        if(head == null){
            head = node;
            return;
        }
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = node;
    }

    void insert(int data,int index){
        if(index == 0){
            addFirst(data);
            return;
        }
        Node temp = head;
        Node node = new Node(data);
        int count = 1;
        while(temp.next != null && count != index){
            temp = temp.next;
            count++;
        }
        if(count == index){
            node.next = temp.next;
            temp.next = node;
        }else{
            System.out.println(data + " Can't be inserted as index " + index + " doesn't exist");
        }
    }

    int deleteLast(){
        if(head == null){
            return -1;
        }
        if(head.next == null){
            int t = head.data;
            head = null;
            return t;
        }
        Node temp = head;
        while(temp.next.next != null){
            temp = temp.next;
        }
        int t = temp.next.data;
        temp.next = null;
        return t;
    }

    int deleteLast(int k){
        if(k == 1){
            return deleteLast();
        }
        Node lead = head;
        for(int i = 0;i<k;i++){
            lead = lead.next;
            if(lead == null){
                return -1;
            }
        }
        Node index = head,prev = null;
        while(lead.next != null){
            prev = index;
            index = index.next;
            lead = lead.next;
        }
        int t = index.data;
        prev = index.next;
        return t;
    }

    int deleteFirst(){
        if(head == null){
            return -1;
        }
        int t = head.data;
        head = head.next;
        return t;
    }

    int delete(int index){
        if(head == null){
            return -1;
        }
        if(index == 0){
            return deleteFirst();
        }
        Node temp = head;
        int count = 1;
        while(temp.next != null && count != index){
            temp = temp.next;
            count++;
        }
        int t = -1;
        if(count == index){
            t = temp.next.data;
            temp.next = temp.next.next;
        }
        return t;
    }

    boolean empty(){
        return head == null;
    }

    int size(){
        if(head == null){
            return 0;
        }
        Node temp = head;
        int s = 0;
        while(temp != null){
            temp = temp.next;
            s++;
        }
        return s;
    }

    boolean find(int val){
        Node temp = head;
        while(temp != null){
            if(temp.data == val){
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    void reverse(){
        Node prev = null,current = null,next = null;
        current = head;
        while(current != null){
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void rev(){
        if(head == null){
            return;
        }
        int n = deleteFirst();
        rev();
        addLast(n);
    }

    void display(){
        Node temp = head;
        while(temp!= null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class linkedList {
    public static void main(String[] args){
        LL list = new LL();
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        list.addLast(4);
        list.addLast(5);
        list.addLast(6);
        list.addFirst(7);
        // list.display();
        // list.delete(2);
        list.display();
        list.rev();
        list.display();
        list.deleteLast(3);
        list.display();
        // System.out.println(list.size());
        System.out.println(list.find(4));
    }
}
