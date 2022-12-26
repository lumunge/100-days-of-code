/* PROBLEM STATEMENT
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same
 * probability of being selected.
 *
 * Sample:
 * Input: ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
 *        [[[1, 2, 3]], [], [], [], [], []]
 * Output: [null, 1, 3, 2, 2, 3]
 *
 * Approach:(using an array list)
 * Add list elements to array list and using choose a random node
 *
 * AppraochII (reservoir sampling)
 */

import java.util.ArrayList;

class RandomNode{
    static ArrayList<Integer> list = new ArrayList<>();

    public static int addToList(ListNode head){
        while(head != null){
            list.add(head.val);
            head = head.next;
        }
    }

    public static int getRandomI(ListNode head){
        return list.get((int)(Math.random() * list.size()));
    }
    
    //reservoir sampling
    public static int getRandom(ListNode head){
        ListNode currNode = head;
        int i = 1, randomNode = 0;
        while(currNode != null){
            if(Math.random() < 1 / i)
                randomNode = currNode.val;
            i++;
            currNode = currNode.next;
        }
        return randomNode;
    }
}
