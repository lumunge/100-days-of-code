// Leetcode #107 - binary tree level order traversal

class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            queue<TreeNode*> q; // bfs queue
            vector<vector<int>> res; // result vector
            if(!root) return res;

            q.push(root); // push for processing
            q.push(nullptr);
            
            vector<int> counter;
            res.push_back({root->val});

            while(!q.empty()){ // process queue nodes
                TreeNode* curr = q.front(); // process first node
                q.pop();
                if(!curr){
                    if(!q.empty()){
                        res.push_back(counter);
                        counter.clear(); // reset
                        q.push(nullptr);
                    }
                    continue;
                }
                
                if(curr->left){ // process left subtree
                counter.push_back(curr->left->val);
                q.push(curr->left);
                }

                if(curr->right){ // process right subtree
                    counter.push_back(curr->right->val);
                    q.push(curr->right);
                }

            }
            
            // swap
            for(int i = 0; i < res.size() / 2; i++)
                swap(res[i], res[res.size() - i - 1]);

            return res;
        }
};
