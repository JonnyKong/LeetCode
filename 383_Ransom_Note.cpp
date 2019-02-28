class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26);
    for (int i = 0; i < magazine.length(); ++i) ++count[magazine[i] - 'a'];
    for (int i = 0; i < ransomNote.length(); ++i) {
      if (count[ransomNote[i] - 'a'])
        --count[ransomNote[i] - 'a'];
      else
        return 0;
    }
    return 1;
  }
};