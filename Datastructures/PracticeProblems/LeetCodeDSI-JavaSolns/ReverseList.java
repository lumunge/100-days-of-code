// Linked list reversal
//Leet code 206

class ReverseList{
    static Node head;

    static class Node{
        int data;
        Node next;
        Node(int d){
            this.data = d;
            next = null;
        }
    }
    
    public static Node reverseList(Node head){
        Node prevNode = null, next = null;
        Node currNode = head;
        while(currNode != null){
            next = currNode.next;
            currNode.next = prevNode;
            prevNode = currNode;
            currNode = next;
        }
        return prevNode;
    }
    
    void printList(Node head){
        while(head != null){
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args){
        ReverseList llist = new ReverseList();
        llist.head = new Node(1);
        llist.head.next = new Node(2);
        llist.head.next.next = new Node(3);
        llist.head.next.next.next = new Node(4);
        llist.head.next.next.next.next = new Node(5);

        llist.printList(head);
        head = llist.reverseList(head);
        llist.printList(head);
    }
}
