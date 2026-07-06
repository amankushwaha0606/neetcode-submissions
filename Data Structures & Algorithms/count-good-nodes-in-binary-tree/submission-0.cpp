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

    int getNodes(TreeNode* root, int maxVal) {

        if(!root) return 0;
        int ans = 0;
        if(root->val >= maxVal) ans++;

        ans += getNodes(root->left, max(maxVal, root->val));
        ans += getNodes(root->right, max(maxVal, root->val));

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return getNodes(root, -101);
    }
};
