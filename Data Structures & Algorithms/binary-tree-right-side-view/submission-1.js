/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    /**
     * @param {TreeNode} root
     * @return {number[]}
     */

    rightSideCall(node, level, ans) {
        if(!node) return;
        if(!ans[level]) {
            ans[level] = node.val
        }
        this.rightSideCall(node.right, level+1, ans);
        this.rightSideCall(node.left, level+1, ans);
    }

    rightSideView(root) {
        let ans = [];
        this.rightSideCall(root, 0, ans);
        return ans;
    }
}
