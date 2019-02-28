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