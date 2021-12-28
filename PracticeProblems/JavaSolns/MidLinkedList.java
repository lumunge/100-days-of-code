/* 
 * PROBLEM SATTEMENT:
 * Given the head of a linked list, return the middle node, if there are two return the
 * second middle node.
 *
 * Sample:
 * Input: head = [1,2,3,4,5]
 * Output: [3,4,5]
 *
 * Approach(fast, slow pointer)
 * Fast pointer goes two steps forward, therefore if its next is null,
 * the slow pointer will be at the middle of the list.
 */

class MidLinkedList{
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
