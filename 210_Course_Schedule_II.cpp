class Digraph {
 private:
  int size;
  struct edgeElement {
    int a;
    edgeElement* next;
    edgeElement(int a_) : a(a_) {}
  };
  vector<edgeElement*> adjList;
  vector<int> adj(int v) const {
    vector<int> result;
    edgeElement* temp = adjList[v];
    while (temp) {
      result.push_back(temp->a);
      temp = temp->next;
    }
    return result;
  }
  void dfs_topoSort(vector<bool>& checked, vector<int>& result,
                    vector<int>& state, int v) throw(int) {
    checked[v] = 1;
    state[v] = -1;
    vector<int> e = adj(v);
    for (int p : e) {
      if (state[p] == -1) {
        throw 0;
      }
      if (!checked[p]) {
        dfs_topoSort(checked, result, state, p);
      }
    }
    state[v] = 1;
    result.push_back(v);
  }

 public:
  Digraph(int n) : size(n) {
    adjList.resize(n);
    fill(adjList.begin(), adjList.end(), nullptr);
  }
  void addEdge(int v, int w) {  // add edge v -> w
    edgeElement* temp = adjList[v];
    adjList[v] = new edgeElement(w);
    adjList[v]->next = temp;
  }
  vector<int> topoSort() {
    vector<int> state(size);
    vector<bool> checked(size);
    vector<int> result;
    for (int i = 0; i < size; ++i) {
      if (!checked[i]) {
        try {
          dfs_topoSort(checked, result, state, i);
        } catch (int a) {
          return vector<int>();
        }
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
    Digraph a(numCourses);
    for (const pair<int, int> p : prerequisites) a.addEdge(p.second, p.first);
    return a.topoSort();
  }
};

// 2023-12-27
class Solution2 {
public:
    bool dfs(unordered_map<int, vector<int>> & graph, vector<int> & visited, vector<int> & result, int i) {
        if (visited[i] == 2) {
            return true;
        } else if (visited[i] == 1) {
            return false;
        }

        visited[i] = 1;
        for (int neighbor : graph[i]) {
            if (!dfs(graph, visited, result, neighbor)) {
                return false;
            }
        }
        visited[i] = 2;
        result.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0); // 0 not visited, 1 visiting, 2 visited    
        vector<int> result;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, visited, result, i)) {
                return vector<int>();
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
        
    }
};

// 2025-02-16
class Solution3 {
    // Idea: toposort by post-order DFS traversal
    vector<vector<int>> adjList;
    vector<int> visited;   // 0 means not visited, 1 means visiting, 2 means visited
    vector<int> postOrderDFS;

    bool dfs(int numCourses, int src, const vector<vector<int>> &adjList) {
        visited[src] = 1;
        for (int neighbor : adjList[src]) {
            if (visited[neighbor] == 0) {
                if (!dfs(numCourses, neighbor, adjList)) {
                    return false;
                }
            } else if (visited[neighbor] == 1) {
                return false;
            }
        }
        visited[src] = 2;
        postOrderDFS.push_back(src);
        
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjList = vector<vector<int>>(numCourses);
        for (const auto &edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        visited = vector<int>(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(numCourses, i, adjList)) {
                    return {};
                }
            }
        }
        
        return postOrderDFS;
    }
};