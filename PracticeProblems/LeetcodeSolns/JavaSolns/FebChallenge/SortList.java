// Leetcode #148 - sort list

class SortList{
    private ListNode mergeList(ListNode l1, ListNode l2){
        ListNode temp = new ListNode();
        ListNode currNode = temp;
        
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                currNode.next = l1;
                l1 = l1.next;
            }else{
                currNode.next = l2;
                l2 = l2.next;
            }
            currNode = currNode.next;
        }
        // remainders.
        if(l1 != null){
            currNode.next = l1;
            l1 = l1.next;
        }
        
        if(l2 != null){
            currNode.next = l2;
            l2 = l2.next;
        }
        
        return temp.next;
    }
    
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        
        ListNode temp = null;
        ListNode slow = head, fast = head;
        
        while(fast != null && fast.next != null){
            // move pointers
            temp = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        temp.next = null;
        
        ListNode l1 = sortList(head), l2 = sortList(slow);
        
        return mergeList(l1, l2);
    }
}
