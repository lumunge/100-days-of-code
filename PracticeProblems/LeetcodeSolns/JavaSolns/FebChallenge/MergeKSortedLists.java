// Leetcode 23 - merge k sorted lists

class MergeKSortedLists{
    // brute force
    static ListNode mergeKLists(ListNode[] lists){
        List<Integer> lst = new ArrayList<>();        
        
        // Add list elements to array
        for(ListNode ln : lists){
            while(ln != null){
                lst.add(ln.val);
                ln = ln.next;
            }
        }
        
        // Sort list elements
        Collections.sort(lst);
        
        ListNode head = new ListNode(0);
        ListNode hd = head;
        // add sorted elements to linked list
        for(int i : lst){
            ListNode n = new ListNode(i);
            hd.next = n;
            hd = hd.next;
        }
        // make next node null - end of list
        hd.next = null;
        // skip 0 - head
        return head.next;
    }
}
