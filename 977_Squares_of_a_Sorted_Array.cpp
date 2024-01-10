class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;

        // Find first zero or positive
        int l, r;
        for (r = 0; r < nums.size(); r++) {
            if (nums[r] >= 0) {
                break;
            }
        }
        l = r - 1;

        while (l >= 0 && r < nums.size()) {
            if (-1 * nums[l] < nums[r]) {
                ret.push_back(nums[l] * nums[l]);
                l--;
            } else {
                ret.push_back(nums[r] * nums[r]);
                r++;
            }
        }

        while (l >= 0) {
            ret.push_back(nums[l] * nums[l]);
            l--;
        }
        while (r < nums.size()) {
            ret.push_back(nums[r] * nums[r]);
            r++;
        }
        return ret;
    }
};

/*
Brute force: square every number and sort, O(N^2)

O(N) solution?

Two pointers?
r points to first zero or positive
l points to r - 1
[-4, -1, 0, 3, 10]

[]: works

[-1]: initial r=1, l=0
[1]: initial r=0, l=-1
*/
