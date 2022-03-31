#include<iostream>
#include "./treeStructure.cpp"
#include<unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
    public:
        bool findTarget(TreeNode* root, int k){
            vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> result;
            queue<TreeNode*> q;
            q.push(root);
            vector<int> levelNodes;
            while(!q.empty()){
                for(int i = 0; i < n; i++){
                    TreeNode* currNode = q.front();
                    q.pop();
                    if(currNode->left) q.push(currNode->left);
                    if(currNode->right) q.push(currNode->right);
                    levelNodes.push_back(currNode->data);
                }
            }
        }
};

int main(){
    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right = newNode(6);
    root->right->right = newNode(7);
    return 0;
}
