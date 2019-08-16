#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, cur, n, 2);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> &cur, int n, int start) {
        for (int i = start; i * i <= n; ++i) {
            if (n % i == 0) {
                // Trivial solution: divide n into two numbers
                cur.push_back(i);
                cur.push_back(n / i);
                result.push_back(cur);

                // Recurse for non-trivial solutions
                cur.pop_back();
                dfs(result, cur, n / i, i);
                cur.pop_back();
            }
        }
    }
};

int main() {
    auto result = Solution().getFactors(12);
    cout << result.size() << endl;
}