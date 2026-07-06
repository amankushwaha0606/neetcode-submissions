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
    vector<int> rightView(TreeNode* root, vector<int>& v, int depth) {
        
        if(!root) return v;

        if(depth >= v.size()) {
            v.push_back(root->val);
        }
        if(root->right) rightView(root->right, v, depth+1);
        if(root->left) rightView(root->left, v, depth+1);

        return v;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rightView(root, v, 0);
        return v;
    }
};
