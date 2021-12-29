/* 
 * PROBLEM STATEMENT:
 * Given a perfect binary tree where leaves are all on the same level and every parent has
 * two children.
 * Polpulate each next poonter to point to its next right node, the next pointer should
 * be set to null.
 *
 * Sample:
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 *
 * Approach(level by level traversal of tree)
 * Create current node and set it to root
 * While left subtree of current is not null:
 *      create a node used for level order traversal
 *      While current node is not null:
 *          make current's left node point to its right node
 *          if(current's next is null) //this means its on the rightmost node of tree
 *              make its right point to null
 *          otherwise its still inside the tree
 *              make its right point to the left of the corresponding left node of left subtree
 *          make current be its next, if now its on the rightmost side, loop terminates
 * move curr to the next level of the tree
 */

class PolpulatingNrPointer{
    public static Node connect(Node root){
        if(root == null) return null;
        Node curr = root;
        while(curr.left != null){
            //start with left
            Node nextNode = curr.left;
            while(curr != null){
                curr.left.next = curr.right;
                //right most side of tree
                if(curr.next == null)
                    curr.right.next = null;
                //still inside of tree
                else
                    curr.right.next = curr.next.left;
                //determine if loop breaks(right most) or continues(still inside)
                curr = curr.next;
            }
            //proceed to next level
            curr = nextNode;
        }
        return root;
    }
    public static void main(String[] args){
    }
}
