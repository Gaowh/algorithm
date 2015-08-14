class TrieNode {
public:
    TrieNode *ptr[26] = {nullptr};
    bool isEnd;
    TrieNode():isEnd(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *r = root;
        for(auto c: word){
            int index = c-'a';
            if(r->ptr[index] == nullptr){
                TrieNode *node = new TrieNode;
                r->ptr[index] = node;
            }
            r = r->ptr[index];
        }
        r->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *r = root;
        for(auto c: word){
            int index = c-'a';
            if(r->ptr[index] == nullptr) return false;
            r = r->ptr[index];
        }
        if(!r->isEnd) return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *r = root;
        for(auto c: prefix){
            int index = c-'a';
            if(r->ptr[index] == nullptr) return false;
            r = r->ptr[index];
        }
        return true;
    }
private:
    TrieNode* root;
};
