//Delete a node from a linked list given the key
//Leet code 203

class RemoveListElements{
    static Node head;

    static class Node{
        int data;
        Node next;
        Node(int d){
            this.data = d;
            next = null;
        }
    }

    static Node deleteNode(Node head, int key){
        Node tempHead = head;
        Node iter = head;
        Node prev = head;
        
        while(iter != null){
            if(iter.data == key){
                //if key is head
                if(iter == tempHead){
                    tempHead = iter.next;
                    prev = tempHead;
                }else if(iter.next == null){
                    //if key is tail
                    prev.next = null;
                }else{
                    //if key is middle element
                    prev.next = iter.next;
                }
                iter = iter.next;
            }else{
                prev = iter;
                iter = iter.next;
            }
        }
        return tempHead;
    }

    void printList(Node head){
        while(head != null){
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args){
        RemoveListElements llist = new RemoveListElements();
        llist.head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(6);
        head.next.next.next = new Node(3);
        head.next.next.next.next = new Node(4);
        head.next.next.next.next.next = new Node(5);
        head.next.next.next.next.next.next = new Node(6);

        llist.printList(head);
        System.out.println("Remove 6");
        head = llist.deleteNode(head, 6);
        llist.printList(head);
    }
}












