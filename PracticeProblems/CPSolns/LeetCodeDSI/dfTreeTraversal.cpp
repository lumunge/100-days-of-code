#include<iostream>
#include<stack>
#include<vector>

using std::stack;
using std::vector;
using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Tree traversals using depth first search
 * Preorder (root, left, right)
 * Inorder(left, root, right)
 * PostOrder(left, right, root)
 *
 * Sample:
 * Input: root = [1, 2, 3, 4, 5, null, null]
 * Output: preOrder = [1, 2, 4, 5, 3]
 *         inOrder = [4, 2, 5, 1, 3]
 *         postOrder = [4, 5, 2, 3, 1]
 *
 * Approach: preOrder(root, left, right)
 * Initialize result vector to hold result
 * Initialize a stack that can hold a tree node
 * Push root node to stack
 * Initialize currNode to root
 * Traverse the tree while stack is not empty doing the following
 * if the currNode is not null
 *      push currNode data to vector
 *      If currNode has a right child, push it to stack
 *      Traverse left subtree of currNode
 * Otherwise
 *      assign currNode to first element in stack
 *      Remove first element from stack
 * Repeat this until stack becomes empty.
 * Return result vector
 *
 * Approach: inOrder(left, right, root)
 * Initialize result vector to hold result
 * Initialize stack to hold tree nodes
 * Initialize currNode to root
 * Repeat the following while stack and currNode are not null
 * If currNode is not null
 *      push currNode to stack
 *      traverse left of currNode
 * Otherwise
 *      push data of top element in stack to result vector
 *      pop top element in stack
 *      traverse right of currNode
 * Return result vector
 *
 *
 * Approach: postOrder(left, right, root)
 * Initialize result vector to hold result
 * Initialize stack1 to hold nodes stack2 to hold order of traversed nodes
 * Push root to stack1
 * Repeat steps while stack1 is not empty
 *      Initialize currNode to first element in stack1
 *      Remove first node from stack1
 *      push data of currNode to stack2
 *      push left and right child of currNode to stack1 respectively
 * Finally push elements from stack2 to result vector in order.
 * return result vector
 */

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        left, right = NULL;
    }
};

class TraverseTree{
    public:
        vector<int> preOrder(TreeNode* root){
            if(!root)
                return {};
            vector<int> result;
            stack<TreeNode*> counter;
            counter.push(root);
            TreeNode* currNode = root;

            while(!counter.empty()){
                if(currNode){
                    result.push_back(currNode->data);
                    if(currNode->right)
                        counter.push(currNode->right);
                    currNode = currNode->left;
                }else{
                    currNode = counter.top();
                    counter.pop();
                }
            }
            return result;
        }

        vector<int> inOrder(TreeNode* root){
            if(root == nullptr)
                return {};

            vector<int> result;
            stack<TreeNode*> counter;
            TreeNode* currNode = root;
            
            while(!counter.empty() || currNode){
                if(currNode){
                    counter.push(currNode);
                    currNode = currNode->left;
                }else{
                    currNode = counter.top();
                    result.push_back(currNode->data);
                    counter.pop();
                    currNode = currNode->right;
                }
            }
            return result;
        }
        
        vector<int> postOrder(TreeNode* root){
            if(root == nullptr)
                return {};

            vector<int> result;
            stack<TreeNode*> counter1;
            stack<int> counter2;
            counter1.push(root);

            while(!counter1.empty()){
                TreeNode* currNode = counter1.top();
                counter1.pop();
                counter2.push(currNode->data);
                if(currNode->left) counter1.push(currNode->left);
                if(currNode->right) counter1.push(currNode->right);
            }

            while(!counter2.empty()){
                result.push_back(counter2.top());
                counter2.pop();
            }
            return result;
        }
        void printArr(vector<int> arr){
            for(int i = 0; i < arr.size(); i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void run(){
            TraverseTree traverse;
            TreeNode* root = new TreeNode(1);
            root->left = new TreeNode(2);
            root->right = new TreeNode(3);
            root->left->left = new TreeNode(4);
            root->left->right = new TreeNode(5);
            vector<int> preOrder = traverse.preOrder(root);
            vector<int> inOrder = traverse.inOrder(root);
            vector<int> postOrder = traverse.postOrder(root);
            cout << "preorder traversal" << endl;
            traverse.printArr(preOrder);
            cout << "inorder traversal" << endl;
            traverse.printArr(inOrder);
            cout << "postorder traversal" << endl;
            traverse.printArr(postOrder);
        }
};

int main(){
    TraverseTree traverse;
    traverse.run();
    return 0;
}
