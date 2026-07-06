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
    int maxD = 0;

    int markNodes(TreeNode* root) {
        if(!root) return 0;
        int left = markNodes(root->left);
        int right = markNodes(root->right);
        maxD = max(maxD, left+right+1);
        return max(left, right)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        return max(markNodes(root), maxD)-1;
    }
};
