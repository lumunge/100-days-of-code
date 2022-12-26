/* 
 * PROBLEM STATEMENT:
 * Given the head of a singly linked list represented as l0 -> l1 -> ...ln-1 -> ln
 * Reorder the list in the following form
 * l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2
 *
 * Sample:
 * Input: 1 -> 2 -> 3 -> 4 -> 5
 * Output: 1 -> 5 -> 2 -> 4 -> 3
 *
 * Approach: (using stack)
 * Push linked list elements to stack
 * Initialize currNode to head of list
 * We pop the stack stackSize() / 2 times (n)
 * Traverse the linked list n times
 * Initialize nextNode to next of currNode
 * Make next of currNode top element of the stack and pop stack
 * Move currNode pointer by one step(its next)
 * Make next of currNode nextNode
 * Move currNode pointer by one step(its next)
 * Finally currNode will be pointing to its prevNode therefore make it null.
 */

import java.util.Stack;

class ReorderList{
    //using stack
    static void reorder(ListNode head){
        Stack<ListNode> stk = new Stack<>(); 
        while(head != null){
            stk.push(head);
            head = head.next;
        }
        ListNode currNode = head;
        // pop the stack stackSize/2 times
        int n = stk.size()/2;
        for(int i = 0; i < n; i++){
            ListNode nextNode = currNode.next;
            currNode.next = stk.pop();
            currNode = currNode.next;
            currNode.next = nextNode;
            currNode = currNode.next;
        }
        // currNode pointing to prev before last, make it null
        currNode.next = null;
    }
    public static void main(String args[]){
    }
};
