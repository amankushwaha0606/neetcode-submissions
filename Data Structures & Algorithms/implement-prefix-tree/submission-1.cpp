class TrieNode {
public:

        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
        }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            int idx = word[i] - 'a';
            if(temp->children[idx]) {
                temp = temp->children[idx];
                if(i == word.size()-1) {
                    temp->isEnd = true;
                    return;
                };
            } else {
                TrieNode* node = new TrieNode();
                if(i == word.size()-1) node->isEnd = true;
                temp->children[idx] = node;
                temp = temp->children[idx];
            }
        }
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            int idx = word[i] - 'a';
            if(temp->children[idx]) {
                temp = temp->children[idx];
                if(i == word.size()-1 && temp->isEnd) return true;
            } else return false;
        }    
        return temp->isEnd;    
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0; i<prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(temp->children[idx]) {
                temp = temp->children[idx];
                if(i == prefix.size()-1) return true;
            } else return false;
        }     
        return temp->isEnd;       
    }
};
