// 2025-02-16
class Solution {
    // Bellman ford O(V*E)
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<int> delay(n, INT_MAX);
        delay[k - 1] = 0;   // 1- to 0-indexed

        for (int i = 0; i < n; i++) {
            for (const auto &time : times) {
                int u = time[0] - 1;    // 1- to 0-indexed
                int v = time[1] - 1;    // 1- to 0-indexed
                int w = time[2];

                if (delay[u] < INT_MAX && delay[u] + w < delay[v]) {
                    delay[v] = delay[u] + w;
                }
            }
        }

        int max_delay = *max_element(delay.begin(), delay.end());
        return max_delay == INT_MAX ? -1 : max_delay;
    }
};

// 2025-02-16
class Solution2 {
    // Dijkstra (w/o heap, O(n^2))
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto &edge : times) {
            int u = edge[0] - 1;    // 1 to 0-indexed
            int v = edge[1] - 1;    // 1 to 0-indexed
            int w = edge[2];
            adjList[u].push_back(std::make_pair(v, w));
        }

        vector<int> dists(n, INT_MAX);
        vector<bool> visited(n, false);
        dists[k - 1] = 0;   // 1 to 0-indexed

        for (int i = 0 ; i < n; i++) {
            // Find the nearest unvisited node
            int minDist = INT_MAX;
            int nearestUnvisitedNode;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && dists[j] < minDist) {
                    minDist = dists[j];
                    nearestUnvisitedNode = j;
                }
            }

            // Relax
            for (auto neighbor : adjList[nearestUnvisitedNode]) {
                int neighborIdx = neighbor.first;
                int distToNeighbor = neighbor.second;
                if (dists[nearestUnvisitedNode] + distToNeighbor < dists[neighborIdx]) {
                    dists[neighborIdx] = dists[nearestUnvisitedNode] + distToNeighbor;
                }
            }

            visited[nearestUnvisitedNode] = true;
        }

        int maxDist = *max_element(dists.begin(), dists.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};

// 2025-02-16
class Solution3 {
    // Dijkstra (w/ heap, O(nlogn))
    // 
    // Key idea is for each node, on dist change, we insert a new PQ
    // element but don't take out the old element. The old element will be filtered
    // upon checking `visited`
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto &edge : times) {
            int u = edge[0] - 1;    // 1 to 0-indexed
            int v = edge[1] - 1;    // 1 to 0-indexed
            int w = edge[2];
            adjList[u].push_back({v, w});
        }

        vector<bool> visited(n, false);
        vector<int> dists(n, INT_MAX);

        std::priority_queue<pair<int, int>,
                            vector<pair<int, int>>,
                            greater<pair<int, int>>> pq;
        pq.push({0, k - 1});    // 1 to 0 indexed
        dists[k - 1] = 0;

        while (!pq.empty()) {
            auto [nearestCost, nearestIdx] = pq.top();
            pq.pop();
            
            if (visited[nearestIdx]) {
                // Already visited. It's a stale PQ element that we inserted repeatedly
                continue;
            }

            for (auto &[neighborIdx, distToNeighbor] : adjList[nearestIdx]) {
                if (dists[nearestIdx] + distToNeighbor < dists[neighborIdx]) {
                    dists[neighborIdx] = dists[nearestIdx] + distToNeighbor;
                    pq.push({dists[neighborIdx], neighborIdx});
                }
            }

            visited[nearestIdx] = true;
        }

        int maxDist = *max_element(dists.begin(), dists.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};
