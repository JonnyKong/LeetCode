/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
 private:
  void dfsConstruct(const vector<NestedInteger> &nestedList) {
    for (const auto &p : nestedList) {
      if (p.isInteger())
        result_.push_back(p.getInteger());
      else
        dfsConstruct(p.getList());
    }
  }

  vector<int> result_;
  int index;

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    result_.clear();
    dfsConstruct(nestedList);
    index = 0;
  }

  int next() { return result_[index++]; }

  bool hasNext() { return index < result_.size(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// 2024-01-16
class NestedIterator {
/*
    DFS w/ stack.

    Note that need to push vector to stack in reverse order.

    Note that need to make sure to expand stack top to integer, otherwise
    no way to know whether list is empty in hasNext().
*/

    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            s.push(nestedList[i]);
        }
    }

    // Make sure the 
    void expandTopToInteger() {
        while (!s.empty() && !s.top().isInteger()) {
            NestedInteger n = s.top();
            s.pop();
            auto list = n.getList();
            for (int i = list.size() - 1; i >= 0; i--) {
                s.push(list[i]);
            }
        }
    }
    
    int next() {
        expandTopToInteger();
        int ret = s.top().getInteger();
        s.pop();
        return ret;
    }
    
    bool hasNext() {
        expandTopToInteger();
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */