class ListCycleII{
	public ListNode intersection(ListNode head){
		ListNode slow = head, fast = head;
		while(fast != null && fast.next != null){
		    slow = slow.next;
		    fast = fast.next.next;
		    if(slow == fast) //cycle
			return slow;
		}
		return null; //no cycle
	}
    	public ListNode detectCycle(ListNode head) {
        	if (head == null || head.next == null) return null;
        	ListNode intersect = intersection(head);
        	if(intersect == null) return null;
        	ListNode currNode = head;
        	while(intersect != currNode){
            	currNode = currNode.next;
            	intersect = intersect.next;
        	}
        	return currNode;
	}
}
