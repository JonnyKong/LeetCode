class Solution {
 public:
  bool helper(const string& s, int i, int j) {
    // cout << "calling helper with " << i << ' ' << j << endl;
    for (int k = i; k <= (i + j) / 2; ++k) {
      if (s[k] != s[j - k + i]) return false;
    }
    // cout << "substring true" << endl;
    return true;
  }

  bool validPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
      if (s[left] == s[right]) {
        ++left;
        --right;
      } else {
        return (helper(s, left, right - 1) || helper(s, left + 1, right));
      }
    }
    return true;
  }
};


// 2024-01-07
class Solution2 {
public:
  // Two pointers from opposite directions. Once differ, only two choices:
  // remove one from either left or right
  bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    int deleted = false;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        return validPalindromeWithoutDeletion(s.substr(l, r - l)) ||
               validPalindromeWithoutDeletion(s.substr(l + 1, r - l));
      }
    }
    return true;
    }

    bool validPalindromeWithoutDeletion(string s) {
        string sRev = s;
        reverse(sRev.begin(), sRev.end());
        return s == sRev;
    }
};
