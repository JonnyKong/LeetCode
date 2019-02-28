class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) return vector<int>();
    unordered_map<int, int> a;
    for (int p : nums1) a[p] = 1;
    for (int p : nums2) {
      if (a[p] == 1) a[p] = 2;
    }
    vector<int> result;
    for (auto p = a.begin(); p != a.end(); ++p) {
      if (p->second == 2) result.push_back(p->first);
    }
    return result;
  }
};