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
        if(!root) return {};

        queue<TreeNode*> q1, q2;
        vector<vector<int>> ans;
        q2.push(root);

        while(!q2.empty()) {
            q1 = q2;
            q2 = {};
            vector<int> v;
            while(!q1.empty()) {
                TreeNode* temp = q1.front();
                q1.pop();
                v.push_back(temp->val);
                if(temp->left) q2.push(temp->left);
                if(temp->right) q2.push(temp->right);
            }
            ans.push_back(v);
        }

        return ans;
    }
};
