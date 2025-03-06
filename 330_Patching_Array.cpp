class Solution {
/*
Intuition:
* Traverse array, maintain the rolling max cover range
* If nums[i] <= max_cover_range:
    max_cover_range += nums[i]
    i += 1
* Else:
    (here, if no patch, cover range becomes non-continuous)
    Add a number `max_cover_range`, which doubles cover range

=====

[1, 5, 10]:

[1]: cover range is [1]

[1, 5]: cover range becomes non-continuous, need to add a number in between
Patch to [1, 1] -> cover range becomes 2
Patch to [1, 1, 2] -> cover range becomes 2*2 = 4
Patch to [1, 1, 2, 4] -> cover range becomes 4*2 = 8

[1, 1, 2, 4, 5] -> cover range becomes 8+5 = 13

=====

[1], n=4

[1]: cover range is 1
Patch to [1, 1]: cover range becomes 2
Patch to [1, 1, 2]: cover range becomes 4

=====

[1, 12, 15], n=43

[1]: cover range is 1
Patch to [1, 1]: cover range is 2
Patch to [1, 1, 2]: cover range is 4
Patch to [1, 1, 2, 4]: cover range is 8
Patch to [1, 1, 2, 4, 8]: cover range is 16
Include 12: [1, 1, 2, 4, 8, 12]: cover range is 28
Include 15: [1, 1, 2, 4, 8, 12, 15]: cover range is 43

======
[1, 3], n=6
Include [1]: cover range is 1
Patch to [1, 2]: cover range is 2
Include [1, 1, 3]: cover range is 5
*/
public:
    int minPatches(vector<int>& nums, int n) {
        int coverRange = 0;
        int i = 0;
        int numPatches = 0;

        while (coverRange < n) {
            if (i < nums.size() && nums[i] <= coverRange + 1) {
                // Include current number
                coverRange += nums[i];
                // printf("included %d, %d\n", nums[i], coverRange);
                i++;
            } else {
                // Insert a number after nums[i] 
                // printf("patched %d\n", coverRange);
                numPatches += 1;
                coverRange = coverRange * 2 + 1;
            }
        }

        return numPatches;
    }
};
