#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26] = {0};
    bool valid;     // Whether a word exists at this node
    TrieNode() : valid(false) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int cursor = 0;
        TrieNode *p = root;
        while (1) {
            if (p->children[word[cursor] - 'a'] == nullptr)
                p->children[word[cursor] - 'a'] = new TrieNode(); // Create new node
            p = p->children[word[cursor] - 'a'];                  // Keep traversing tree
            
            if (++cursor == word.length()) {
                p->valid = true;
                return;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int cursor = 0;
        TrieNode *p = root;
        while (1) {
            if (p->children[word[cursor] - 'a'] == nullptr)
                return false;
            p = p->children[word[cursor] - 'a'];
            
            if (++cursor == word.length())
                break;
        }
        return p->valid;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int cursor = 0;
        TrieNode *p = root;
        while (1) {
            if (p->children[word[cursor] - 'a'] == nullptr)
                return false;
            p = p->children[word[cursor] - 'a'];
            
            if (++cursor == word.length())
                break;
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("apple");
    cout <<  trie.search("apple") << endl;
    cout <<  trie.startsWith("app") << endl;
}