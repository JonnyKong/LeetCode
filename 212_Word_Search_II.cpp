class TrieNode{
public:
    int is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end=false;
        children=vector<TrieNode*>(26, NULL);
    }   
};

class Trie {
public:
    TrieNode *root = NULL;;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string & word) {
        TrieNode *p = root;

        for (char c : word) {
            if (p->children[c - 'a'] == NULL) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->is_end = true;
    }
};

class Solution {
    vector<pair<int, int>> pos = {
        pair<int, int>(-1, 0),
        pair<int, int>(1, 0),
        pair<int, int>(0, -1),
        pair<int, int>(0, 1)
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        for (auto w : words) {
            trie->addWord(w);
        }

        vector<string> ret;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                auto wordsFound = dfs(board, trie->root, i, j);
                for (auto w : wordsFound) {
                    ret.push_back(w);
                }
            }
        }
        return ret;
    }

    vector<string> dfs(const vector<vector<char>>& board, TrieNode *trie, int i, int j) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        vector<string> result;
        string current;
        char c = board[i][j];
        if (trie->children[c - 'a']) {
            current.push_back(c);
            dfs_helper(board, trie->children[c - 'a'], i, j, visited, current, result);
        }
        return result;
    };

    void dfs_helper(const vector<vector<char>>& board, TrieNode *trie, int i, int j, vector<vector<int>> & visited, string &current, vector<string> & result) {
        // Assumes trie is not NULL

        visited[i][j] = 1;

        if (trie->is_end) {
            // Found word
            trie->is_end = false;
            result.push_back(current);
        }

        for (auto p : pos) {
            int i_ = i + p.first;
            int j_ = j + p.second;

            if (i_ < 0 || i_ >= board.size() || j_ < 0 || j_ >= board[0].size()) {
                // Out of bound
                continue;
            }
            if (visited[i_][j_]) {
                continue;
            }

            char c = board[i_][j_];
            if (!trie->children[c - 'a']) {
                // Word not found, prune
                continue;
            }

            current.push_back(c);
            dfs_helper(board,
                trie->children[c - 'a'],
                i_,
                j_,
                visited,
                current,
                result);
            current.pop_back();
        }
        visited[i][j] = 0;
    }
};
