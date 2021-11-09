#include<iostream>
#include<vector>
#include<stack>
#include "./treeStructure.cpp"

using std::stack;
using std::vector;
using std::cout;
using std::endl;

class Solution {
    public:
        void printVec(vector<int> arr){
            for(int i = 0; i < arr.size(); i++)
                cout << arr[i] << " ";
            cout << endl;
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
        //bool isSymmetric(TreeNode* root){
        //}

};

int main(){
    Solution soln;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    vector<int> res = soln.inOrder(root);
    soln.printVec(res);
    return 0;
}




