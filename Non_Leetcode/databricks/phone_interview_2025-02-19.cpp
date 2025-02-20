#include <iostream>
#include <map>
#include <assert.h>
using namespace std;

/*
High level idea: moving window

Algorithm 1:
If the query string is short:
* for each window on the long string, sort this window, compare with the query string
    - (n - k) windows, each (k logk) -> O(n-k)(k logk)

Algorithm 2:
If query string is long:
* Keep an array of length 26, means the count of each char
* Move to the next window: decrement the old char, increment counter of the new char
* Compare counter array v.s. counter array of the counter string O(26)
* Overall complexity: (n - k) windows, O(26) -> O(n-k)

Algorithm 3:
If query string is long:
* Keep a ordered map of counts (key: char, value: count)
* Similar to algo 2, for each window, compare count map v.s. the counter map of query string
* Complexity: (n - k) windows, (2 * m) -> O((n-k) * m)
    * m is the number of unique chars that appear in substr of length k

Algorithm 4:
* for each window, compare count map v
  * diff: map<char, int>, key: char, value: positive: q has more of this char than s, negative
  * Initialziation:
    for c in q:
      diff[c] += 1
    for c in s[:len(q)]:
      diff[c] -= 1
      if diff[c] == 0:
        del diff[c]
  * If len(diff) == 0: found a match
  * Move window, at each step:
    * Remove the old char (diff[c]++)
    * Add new char: (diff[c]--) -> if reaches 0, del diff[c]
    * Check if len(diff) == 0: return window's index
  * Complexity: (n - k), const in each window -> O(n - k)
*/

bool countIsEqual(const map<char, int> &m1, const map<char, int> &m2) {
  if (m1.size() != m2.size()) {
    return false;
  }
  map<char, int>::const_iterator it1 = m1.begin();
  map<char, int>::const_iterator it2 = m2.begin();
  while (it1 != m1.end()) {
    if (it1->first != it2->first || it1->second != it2->second) {
      return false;
    }
    it1 = next(it1);
    it2 = next(it2);
  }
  return true;
}

int findAnagram(const string &s, const string &q) {
  if (q.size() == 0) {
    return 0;
  } else if (s.size() < q.size()) {
    return -1;
  }

  map<char, int> qCounts;
  map<char, int> sCounts;

  for (size_t i = 0; i < q.size(); i++) {
    qCounts[q[i]]++;
  }

  // Build sCounts of the leftmost window
  for (size_t i = 0; i < q.size(); i++) {
    sCounts[s[i]]++;
  }

  if (countIsEqual(qCounts, sCounts)) {
    return 0;
  }

  for (size_t i = 0; i < s.size() - q.size(); i++) {
    // Move the window: Remove old char and add new char
    sCounts[s[i]]--;
    if (sCounts[s[i]] == 0) {
      sCounts.erase(s[i]);
    }
    sCounts[s[i + q.size()]]++;

    if (countIsEqual(qCounts, sCounts)) {
      return i + 1;
    }
  }

  return -1;
}

// To execute C++, please define "int main()"
int main() {
  // cout << findAnagram("94237catdfiw", "act") << endl;

  assert(findAnagram("catdfiw", "act") == 0);
  assert(findAnagram("atdfiw", "act") == -1);
  assert(findAnagram("94237catdfiw", "act") == 5);
  assert(findAnagram("catcatw", "act") == 0);
  assert(findAnagram("cat", "act1sdf") == -1);
  assert(findAnagram("cat", "cat") == 0);
  assert(findAnagram("catDFUS&&*(@56", "cat") == 0);
  assert(findAnagram("catDFUS&&*(@56", "") == 0);
  assert(findAnagram("", "adsjifo") == -1);
  assert(findAnagram("", "") == 0);

  return 0;
}
