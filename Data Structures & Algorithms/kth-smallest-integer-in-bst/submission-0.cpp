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
    int ans;
    int findSmallest(TreeNode* root, int k, int nodes) {
        if(!root) return nodes;

        nodes = findSmallest(root->left, k, nodes);
        
        if(k-1 == nodes) {
            ans = root->val;
        };
        nodes++;
        nodes = findSmallest(root->right, k, nodes);

        return nodes;
    }

    int kthSmallest(TreeNode* root, int k) {
        int hh = findSmallest(root, k, 0);
        return ans;
    }
};
