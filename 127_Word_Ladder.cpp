class Solution {
/*
 * Use BFS to look for shortest path.
 */
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordSet;    // holds words not visited
        for (auto & w : wordList) {
            wordSet.insert(w);
        }

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        // BFS
        queue<string> q;
        q.push(beginWord);

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            
            for (int i = 0; i < sz; i++) {
                string w = q.front();
                printf("dist=%d, w=%s\n", dist, w.c_str());
                q.pop();

                // Look for neighboring node
                for (int cursor = 0; cursor < w.length(); cursor++) {
                    string w_ = w;
                    for (char c = 'a'; c <= 'z'; c++) {
                        w_[cursor] = c;
                        if (w == endWord) {
                            return dist;
                        } else if (wordSet.find(w_) != wordSet.end()) {
                            printf("push word %s\n", w_.c_str());
                            q.push(w_);
                            wordSet.erase(w_);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
