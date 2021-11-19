//Remove duplicates from linked list
//Leet code 83

class RemoveDuplicates{
    static Node head;

    static class Node{
        int data;
        Node next;
        Node(int d){
            this.data = d;
            next = null;
        }
    }
    
    public static Node removeDuplicates(Node head){
        Node currNode = head, next = null;
        while(currNode != null && currNode.next != null){
            if(currNode.data == currNode.next.data)
                currNode.next = currNode.next.next;
            else
                currNode = currNode.next;
        }
        return head;
    }

    void printList(Node head){
        while(head != null){
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args){
        RemoveDuplicates llist = new RemoveDuplicates();
        llist.head = new Node(1);
        head.next = new Node(1);
        head.next.next = new Node(2);
        head.next.next.next = new Node(3);
        head.next.next.next.next = new Node(3);

        llist.printList(head);
        head = llist.removeDuplicates(head);
        llist.printList(head);
    }

}



