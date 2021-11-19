//Merging two sorted linked lists
//Leetcode 21

class MergeSortedLists{
    static Node l1;
    static Node l2;

    static class Node{
        int data;
        Node next;
        Node(int key){
            data = key;
            next = null;
        }
    }

    static Node mergeLists(Node l1, Node l2){
        //either of lists null
        if(l1 == null)
            return l2;
        if(l2 == null)
            return l1;
        //start with lesser list head
        if(l1.data > l2.data){
            Node temp;
            temp = l1;
            l1 = l2;
            l2 = temp;
        }
        //if either list has one item
        if(l1.next == null){
            l1.next = l2;
            return l1;
        }

        Node l1Curr = l1, l1Next = l1.next;
        Node l2Curr = l2, l2Next = l2.next;
        while(l1Next != null && l2Curr != null){
            //if node of 2nd list between two nodes of first list, insert and shift pointers
            if(l2Curr.data >= l1Curr.data && l2Curr.data <= l1Next.data){
                l2Next = l2Curr.next;
                l1Curr.next = l2Curr;
                l2Curr.next = l1Next;

                //point to next pointers
                l1Curr = l2Curr;
                l2Curr = l2Next;
            }else{
                //remainder nodes 1st list
                if(l1Next.next != null){
                    l1Next = l1Next.next;
                    l1Curr = l1Curr.next;
                }else{
                    //remainder nodes 2nd list
                    l1Next.next = l2Curr;
                    return l1;
                }
            }
        }
        return l1;
    }

    void printList(Node head){
        while(head != null){
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args){
        MergeSortedLists llist = new MergeSortedLists();
        llist.l1 = new Node(1);
        l1.next = new Node(2);
        l1.next.next = new Node(4);
        
        llist.l2 = new Node(1);
        l2.next = new Node(3);
        l2.next.next = new Node(4);

        llist.printList(l1);
        llist.printList(l2);

        l1 = mergeLists(l1, l2);

        llist.printList(l1);
    }
}
