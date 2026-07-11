/**
 * Definition for singly-linked list.
 * class ListNode {
 *     constructor(val = 0, next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

class Solution {
    /**
     * @param {ListNode} list1
     * @param {ListNode} list2
     * @return {ListNode}
     */
    mergeTwoLists(list1, list2) {

        let root = new ListNode(0);
        let ans = root;

        while(list1 && list2) {
            if(list1.val <= list2.val) {
                root.next = list1;
                list1 = list1.next;
            } else {
                root.next = list2;
                list2 = list2.next;
            }
            root = root.next;
        }

        if(list1) root.next = list1;
        if(list2) root.next = list2;

        return ans.next;
    }
}
