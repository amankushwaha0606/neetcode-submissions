/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* root = head;
        unordered_map<Node*, Node*> mp;

        while(head) {
            mp[head] = new Node(head->val);
            head = head->next;
        }

        head = root;
        while(head) {
            mp[head]->next = mp[head->next];
            mp[head]->random = mp[head->random];
            head = head->next;
        }

        return mp[root];

    }
};
