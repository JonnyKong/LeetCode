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
  void dfs(vector<int>& state, int v) throw(int) {
    state[v] = -1;
    vector<int> e = adj(v);
    for (int p : e) {
      if (state[p] == 0)
        dfs(state, p);
      else if (state[p] == -1)
        throw 0x7fff;
      else
        continue;
    }
    state[v] = 1;
  }

 public:
  Digraph(int n) : size(n) {
    adjList.resize(n);
    // fill(adjList.begin(), adjList.end(), nullptr);
  }
  ~Digraph() {
    for (edgeElement* p : adjList) {
      edgeElement* temp1 = p;
      while (temp1) {
        edgeElement* temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
      }
    }
  }
  void addEdge(int v, int w) {  // add edge v -> w
    edgeElement* temp = adjList[v];
    adjList[v] = new edgeElement(w);
    adjList[v]->next = temp;
  }
  bool hasCycle() {
    vector<int> state(size);
    /*
     state 0: has not been visited.
     state -1: executing dfs on its descendents.
     state 1: has been visited.
    */
    for (int i = 0; i < size; ++i) {
      if (state[i] == 0) try {
          dfs(state, i);
        } catch (int a) {
          return 1;
        }
      else if (state[i] == -1)
        return 1;
      else
        continue;
    }
    return 0;
  }
};

class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (numCourses == 1) return 1;
    Digraph a(numCourses);
    for (const pair<int, int>& p : prerequisites) {
      a.addEdge(p.second, p.first);
    }
    return !a.hasCycle();
  }
};


// 2023-12-27
class Solution2 {
public:
    bool dfs(unordered_map<int, vector<int>> & graph, vector<int> & visited, int i) {
        if (visited[i] == 2) {
            return true;
        } else if (visited[i] == 1) {
            return false;
        }

        visited[i] = 1;
        for (int neighbor : graph[i]) {
            if (!dfs(graph, visited, neighbor)) {
                return false;
            }
        }
        visited[i] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0); // 0 not visited, 1 visiting, 2 visited    

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, visited, i)) {
                return false;
            }
        }
        return true;
    }
};