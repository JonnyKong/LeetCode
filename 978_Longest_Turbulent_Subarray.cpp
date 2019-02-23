#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        // Sanity check
        if (A.size() <= 1)
            return A.size();
        else if (A.size() <= 2)
            return (A[0] == A[1]) ? 1 : 2;

        int dp[A.size() + 1];
        int result = 0;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = (A[0] == A[1]) ? 1 : 2;
        for (int i = 3; i < A.size() + 1; ++i) {
            if (A[i - 3] < A[i - 2] && A[i - 2] > A[i - 1] || A[i - 3] > A[i - 2] && A[i - 2] < A[i - 1])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = (A[i - 1] == A[i - 2]) ? 1 : 2;
            result = (result > dp[i]) ? result : dp[i];
        }

        return result;
    }
};

int main() {
    vector<int> input {37,199,60,296,257,248,115,31,273,176};
    int output = Solution().maxTurbulenceSize(input);
    cout << output << endl;
}
