#include<iostream>
//#include "./treeStructure.cpp"
#include<vector>
#include<queue>

using std::queue;
using std::vector;
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given root of a binary tree, return level order ttraversal of its nodes.
 *
 * Approach:
 * Initialize queue and push root to it
 * Repeat the steps while queue is not empty
 *      for n times, n being size of the queue
 *      store the front element of queue
 *      push its children to the queue
 *      push its value to the level nodes vector
 * push level nodes vector to the result vector
 * return result vector.
 */


class TraverseTree{
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> result;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                vector<int> levelNodes;
                for(int i = 0; i < n; i++){
                    TreeNode* currNode = q.front();
                    q.pop();
                    if(currNode->left) q.push(currNode->left);
                    if(currNode->right) q.push(currNode->right);
                    levelNodes.push_back(currNode->data);
                }
                result.push_back(levelNodes);
            }
            return result;
        }

        void printVec(vector<vector<int>> arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr[i].size(); j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
};
/*
int main(){
    Solution soln;
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    vector<vector<int>> res = soln.levelOrder(root);
    soln.printVec(res);
    return 0;
}
*/
