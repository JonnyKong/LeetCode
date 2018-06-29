/* Data structure: Monotonic queue
 * Time complexity: O(n)
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> window;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            while(window.empty() == false && window.front().second < nums[i]) {
                window.pop_front();
            }
            window.push_front(make_pair(i, nums[i]));
            while(window.back().first < i - k + 1) {
                window.pop_back();
            }
            if(i + 2 > k) {
                result.push_back(window.back().second);
            }
        }
        return result;
    }
};