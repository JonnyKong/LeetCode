//
//  274. H-Index.h
//
//
//  Created by Jonny Kong on 2/29/16.
//
//

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    if (citations.empty()) return 0;

    sort(citations.begin(), citations.end(), greater<int>());

    int i = 0;

    while (citations[i] >= (i + 1) && i < citations.size()) ++i;

    return i;
  }
};