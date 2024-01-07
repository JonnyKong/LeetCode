class Solution {
public:
    vector<int> getNode2degree(int n, const vector<vector<int>>& edges) {
        vector<int> ret(n, 0);
        for (auto edge : edges) {
            for (auto e : edge) {
                ret[e]++;
            } 
        }
        return ret;
    }

    unordered_map<int, vector<int>> getAdjList(const vector<vector<int>> & edges) {
        unordered_map<int, vector<int>> ret;
        for (auto edge : edges) {
            if (ret.find(edge[0]) == ret.end()) {
                ret[edge[0]] = vector<int>();
            }
            if (ret.find(edge[1]) == ret.end()) {
                ret[edge[1]] = vector<int>();
            }
            ret[edge[0]].push_back(edge[1]);
            ret[edge[1]].push_back(edge[0]);
        }
        return ret;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return vector<int>{0};
        }

        auto node2degree = getNode2degree(n, edges);
        auto adjList = getAdjList(edges);

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (node2degree[i] == 1) {
                q.push(i);
            }
        }
        
        vector<int> ret;
        while (!q.empty()) {
            ret.clear();
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                int n = q.front();
                q.pop();
                ret.push_back(n);
                node2degree[n]--;

                for (int other : adjList[n]) {
                    // Cut tree
                    node2degree[other]--;
                    if (node2degree[other] == 1) {
                        q.push(other);
                    }
                }
            }
        }
        return ret;
    }
};

/*
BFS from leaves. When visiting each leaf, remove it from the tree, so some other
nodes become leaves, then BFS on the new leaves. This is different from BFS
simply based on the neighbor. Return the nodes used in the

Corollary: the number of min height roots are at most 2. Proof:

1. Assume the contradiction, assume there are 3 min height roots A B C

2. Assume A is now root. W/o loss of generality, assume B and C are respectively
in the left and right subtree

3. Since B is also min root, that means rotating the tree to the right (B now is
the root) will results in a tree of the same height. That means the A-rooted
tree's left height is one more than right height

4. Vice versa for C (right height one more than left height) -> contradiction
*/
