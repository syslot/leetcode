#include "../common.h"

struct TrieNode {
    TrieNode(){
        memset(chds, 0, sizeof(chds));
        isEnd = false;
    }

    bool isEnd;
    TrieNode * chds[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = root;
        char ch;
        for(int i=0;i<word.length();i++){
            ch = word[i];
            if(cur->chds[ch-'a'] == nullptr){
                cur->chds[ch-'a'] = new TrieNode();
            }
            cur = cur->chds[ch - 'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur  = root;
        char ch;
        for(int i=0;i<word.length();i++){
            ch = word[i];
            if(cur->chds[ch-'a'] == nullptr)
                return false;
            cur = cur->chds[ch-'a'];
        }
        if(cur->isEnd)
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur  = root;
        char ch;
        for(int i=0;i<prefix.length();i++){
            ch = prefix[i];
            if(cur->chds[ch-'a'] == nullptr)
                return false;
            cur = cur->chds[ch-'a'];
        }
        return true;

        
    }

    TrieNode * root;
};


int main(){
    Trie *trie = new Trie();
    trie->insert("app");
    trie->insert("apple");
    trie->insert("beer");
    cout << trie->search("app")     <<endl;
    cout << trie->startsWith("app")  <<endl;

    return 0;
}
