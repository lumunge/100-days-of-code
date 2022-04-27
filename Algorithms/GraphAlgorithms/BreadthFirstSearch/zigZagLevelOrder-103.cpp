// Leetcode #103 - Binary tree zigzag level order traversal

class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(!root) return {};

            // bfs level order traversal
            queue<TreeNode*> q;
            q.push(root);

            vector<vector<int>> res;
            bool flag = true;

            while(!q.empty()){
                int s = q.size();
                vector<int> temp;

                while(s--){
                    TreeNode* curr = q.front(); q.pop();

                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);

                    temp.push_back(curr->val);
                }

                // create zigzag
                if(flag) res.push_back(temp);
                else{
                    reverse(temp.begin(), temp.end());
                    res.push_back(temp);
                }
                flag = !flag; // return back
            }
            return res;
    }
};
