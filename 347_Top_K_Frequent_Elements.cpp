class Solution {
 private:
  class myBind {
   public:
    int num;
    int frequency;
    myBind(int num_, int frequency_) : num(num_), frequency(frequency_) {}
  };

 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> a;
    for (int p : nums) {
      auto i = a.find(p);
      if (i == a.end())
        a[p] = 1;
      else
        ++i->second;
    }
    vector<myBind> b;
    for (auto p = a.begin(); p != a.end(); ++p)
      b.push_back(myBind(p->first, p->second));
    sort(b.begin(), b.end(), [](const myBind& a, const myBind& b) -> bool {
      return a.frequency > b.frequency;
    });
    vector<int> result;
    for (int i = 0; i < b.size(); ++i) result.push_back(b[i].num);
    return vector<int>(result.begin(), result.begin() + k);
  }
};


// 2024-01-10
bool comparator(const pair<int, int> & p1, const pair<int, int> p2) {
    return p1.second > p2.second;
}

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqTable;
        for (int n : nums) {
            if (freqTable.find(n) == freqTable.end()) {
                freqTable[n] = 1;
            } else {
                freqTable[n]++;
            }
        }        

        vector<pair<int, int>> freqVec;
        for (auto it = freqTable.begin(); it != freqTable.end(); it++) {
            freqVec.push_back(make_pair(it->first, it->second));
        }
        sort(freqVec.begin(), freqVec.end(), comparator);

        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(freqVec[i].first);
        }
        return ret;
    }
};

// 2025-02-18
class Solution3 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (auto n : nums) {
            freqs[n] += 1;
        }

        // Pairs of <freq, num>
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        for (auto &[num, freq] : freqs) {
            if (pq.size() == k && pq.top().first < freq) {
                pq.pop();
            }
            if (pq.size() < k) {
                pq.push({freq, num});
            }
        }

        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};