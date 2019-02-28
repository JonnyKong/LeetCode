/**
 * Union find.
 */

class Solution {
 private:
  int root(const vector<int> &id, int a) {
    while (a != id[a]) a = id[a];
    return a;
  }

  void makeUnion(vector<int> &id, int p, int q) {
    int i = root(id, p);
    int j = root(id, q);
    id[i] = j;
  }

 public:
  int findCircleNum(vector<vector<int>> &a) {
    int n = a.size();
    vector<int> id(n);
    for (int i = 0; i < n; ++i) id[i] = i;
    for (int i = 0; i < n; ++i) {
      for (int j = 1 + i; j < n; ++j) {
        if (a[i][j] == 1) {
          makeUnion(id, i, j);
        }
      }
    }
    set<int> id_unique;
    for (int i : id) {
      cout << root(id, i) << ", ";
      id_unique.insert(root(id, i));
    }
    return id_unique.size();
  }
};