/**
 * O(NlogN) greedy + stack.
 * 
 * We traverse nums[] from back to front, and keep a stack of decreasing order.
 * 
 * Greedy step: If i<j and nums[i]>nums[j], then nums[i] "shadows" nums[j]. So 
 * we remove nums[j].
 * 
 * Because we need to traverse the stack, so use vector.
 */

/** 
 * Optimized solution: O(NlogN) stack.
 * 
 * We traverse nums[] from front to back, and keep a stack of decreasing order.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> s;
        unordered_map<int, int> dict;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (s.empty())
                dict[nums[i]] = -1;
            else {
                int j;
                for (j = s.size() - 1; j >= 0; --j) {
                    if (s[j] > nums[i]) {
                        dict[nums[i]] = s[j];
                        break;
                    }
                }
                if (j < 0)
                    dict[nums[i]] = -1;
            }

            while (!s.empty() && nums[i] > s.back())
                s.pop_back();
            s.push_back(nums[i]);
        }

        vector<int> result;
        for(int i : findNums)
            result.push_back(dict[i]);
        return result;
    }

};


class Solution2 {
public:

    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int num : nums) {
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        
        vector<int> result;
        for(int num : findNums)
            result.push_back(m[num]);
        return result;
    }

};


int main() {
    vector<int> a = {4, 1, 2};
    vector<int> b = {1, 3, 4, 2};
    vector<int> c = Solution().nextGreaterElement(a, b);
    for (int i : c)
        cout << i << " ";
    cout << endl;
    return 0;
}