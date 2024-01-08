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

// 2024-01-07
class Solution2 {
public:
    vector<int> findLongestPath(int n, const vector<vector<int>> & adjList, int sourceNode) {
        vector<bool> visited(n, false);
        vector<int> depth(n, 0);
        vector<int> from(n, 0);
        stack<int> stk;
        int maxDepth = 0;
        int maxDepthNode = sourceNode;

        stk.push(sourceNode);

        while (stk.size() > 0) {
            int node = stk.top();
            stk.pop();
            visited[node] = true;

            for (int e : adjList[node]) {
                if (!visited[e]) {
                    from[e] = node;
                    depth[e] = depth[node] + 1;
                    
                    if (depth[e] > maxDepth) {
                        maxDepth = depth[e];
                        maxDepthNode = e;
                    }

                    stk.push(e);
                }
            }
        }

        vector<int> ret;
        for (int node = maxDepthNode; node != sourceNode; node = from[node]) {
            ret.push_back(node);
        }
        ret.push_back(sourceNode);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    vector<vector<int>> buildAdjList(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        auto adjList = buildAdjList(n, edges);
        
        int randomSourceNode = 0;
        auto longestPath1 = findLongestPath(n, adjList, randomSourceNode);
        auto longestPath2 = findLongestPath(n, adjList, longestPath1.back());

        if (longestPath2.size() % 2 == 1) {
            return {longestPath2[(longestPath2.size() - 1) / 2]};
        } else {
            return {
                longestPath2[longestPath2.size() / 2],
                longestPath2[longestPath2.size() / 2 - 1]
            };
        }
        return {};
    }
};

/*
Idea 1:
1. Find the farthest leaf from any node
2. Find the farthest leaf from the node found above, which yields a maximum
path, on which the center one or two nodes are the center

Idea 2:
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
