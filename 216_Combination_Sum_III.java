class Solution {

    public List<List<Integer>> combinationSum3(int k, int n) {
        ArrayList<List<Integer>> result = new ArrayList<>();
        ArrayList<Integer> current = new ArrayList<>();

        dfs(result, current, n, k, 1);
        return result;
    }

    private void dfs(List<List<Integer>> result, List<Integer> current, int target, int k, int pos) {

        /* Termination */
        if(target == 0 && k == 0) { /* A valid combination is found */
            result.add(new ArrayList<Integer>(current));
            return;
        }
        else if(target == 0) {      /* Not valid number of numbers used */
            return;
        }
        else if(pos > 9) {        /* Out of bound */
            return;
        }

        dfs(result, current, target, k, pos + 1);
        current.add(Integer.valueOf(pos));
        dfs(result, current, target - pos, k - 1, pos + 1);
        current.remove(current.size() - 1);

    }
}

// 2023-12-27
class Solution2 {
public:
    void dfs(int k, int n, vector<int> current, vector<vector<int>> & results, int next) {
        if (k == 0 && n == 0) {
            results.push_back(current);
            return;
        } else if (k == 0 || n == 0) {
            return;
        }

        for (int i = next; i <= 9; i++) {
            current.push_back(i);
            dfs(k - 1, n - i, current, results, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        dfs(k, n, vector<int>(), results, 1);
        return results;
    }
};