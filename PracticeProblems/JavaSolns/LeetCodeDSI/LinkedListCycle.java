//Return true is there exists a cycle in the linked list
//Leet code 141

class LinkedListCycle{
    static Node head;

    static class Node{
        int data;
        Node next;
        Node(int key){
            data = key;
            next = null;
        }
    }

    static boolean isCycle(Node head){
        if(head == null)
            return false;
        Node fast = head, slow = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow)
                return true;
        }
        return false;
    }

    public static void main(String[] args){
        LinkedListCycle llist = new LinkedListCycle();
        llist.head = new Node(3);
        head.next = new Node(2);
        head.next.next = new Node(0);
        head.next.next.next = new Node(-4);
        head.next.next.next = head.next;
        System.out.println(isCycle(head));
    }
}
