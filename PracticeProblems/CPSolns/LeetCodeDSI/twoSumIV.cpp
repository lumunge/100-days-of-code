/*
 * PROBLEM STATEMENT:
 * Given root of bst and target, return true is there exists two elements in bst such that
 * their sum is equal to the given target
 *
 * Sample:
 * Input: [5, 3, 6, 2, 4], target = 9
 * Output: true -> 6 + 3, 4 + 5
 *
 * Approach:
 * Do a level order traversal of the tree and store node values in vector
 * Traverse the vector using two pointers from front and back
 * Compare sum of the pointers with target, increment and decrement as needed.
 * If loop terminates return false.
 */

#include<iostream>
#include "./treeStructure.cpp"
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class TwoSum{
    private:
        void inOrder(TreeNode* root, vector<int>& arr){
            if(!root) return;
            inOrder(root->left, arr);
            arr.push_back(root->data);
            inOrder(root->right, arr);
        }
    public:
        bool isTarget(TreeNode* root, int target){
            if(!root) return false;
            vector<int> nodes;
            inOrder(root, nodes);
            int i = 0, j = nodes.size() - 1;
            while(i < j){
                if(nodes[i] + nodes[j] == target)
                    return true;
                if(nodes[i] + nodes[j] < target)
                    i++;
                if(nodes[i] + nodes[j] > target)
                    j--;
            }
            return false;
        }
};

int main(){
    TwoSum ts;
    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);
    cout << ts.isTarget(root, 9) << endl;
    cout << ts.isTarget(root, 2) << endl;
    return 0;
}
