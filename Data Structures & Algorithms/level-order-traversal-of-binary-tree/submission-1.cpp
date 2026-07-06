/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ans;

        if(root) que.push(root);

        while(!que.empty()) {
            int size = que.size();
            vector<int> v;

            while(size>0) {
                size--;

                TreeNode* front = que.front();
                que.pop();
                v.push_back(front->val);
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }

            ans.push_back(v);
        }

        return ans;
    }
};
