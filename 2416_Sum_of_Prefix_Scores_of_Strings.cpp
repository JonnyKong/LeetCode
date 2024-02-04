class TrieNode {
public:
    vector<TrieNode *> c;
    int numWords;

    TrieNode() : c(26, nullptr), numWords(0) {}
};

void insert(TrieNode *root, const string & w) {
    // Assumes w does not exist in the tree
    // Root's isEnd and numWords is not valid
    TrieNode *p = root;

    for (char c : w) {
        if (p->c[c - 'a'] == NULL) {
            p->c[c - 'a'] = new TrieNode();
        }
        p = p->c[c - 'a'];
        p->numWords++;
    }
}

int findScoreSum(TrieNode *root, const string & w) {
    TrieNode *p = root;
    int scoreSum = 0;

    for (char c : w) {
        p = p->c[c - 'a'];
        scoreSum += p->numWords;
    }
    return scoreSum;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *trie = new TrieNode();

        for (auto &w : words) {
            insert(trie, w);
        }

        vector<int> ret;
        for (auto &w : words) {
            ret.push_back(findScoreSum(trie, w));
        }
        return ret;
    }
};
