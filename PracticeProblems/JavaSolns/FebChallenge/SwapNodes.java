// Leetcode #24 - Swap node in pairs

class SwapNodes{
    static ListNode swapPairs(ListNode head){
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode currNode = temp;
        
        while(currNode.next != null && currNode.next.next != null){
            // first and second nodes
            ListNode first = currNode.next;
            ListNode second = currNode.next.next;
            // swap nodes
            first.next = second.next;
            currNode.next = second;
            second.next = first;
            currNode.next.next = first;
            // place curr 2 positions ahead after swapping
            currNode = currNode.next.next;
        }
        // head
        return temp.next;
    }
}
