class RandomizedSet {
  unordered_set<int> a;

 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (a.find(val) != a.end())
      return 0;
    else {
      a.insert(val);
      return 1;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (a.find(val) == a.end())
      return 0;
    else {
      a.erase(val);
      return 1;
    }
  }

  /** Get a random element from the set. */
  int getRandom() {
    auto p = a.begin();
    advance(p, rand() % a.size());
    return *p;
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */