class Solution {
public:
    void swap(string & numStr, int i, int j) {
        if (i != j) {
            char c = numStr[i];
            numStr[i] = numStr[j];
            numStr[j] = c;
        }
    }

    int maximumSwap(int num) {
        string numStr = to_string(num);
        int largestSeenPos = numStr.length() - 1;
        int largestSeen = numStr[largestSeenPos];
        int bestSwapi = largestSeenPos;
        int bestSwapj = largestSeenPos;

        for (int i = numStr.length() - 2; i >= 0; i--) {
            if (numStr[i] < largestSeen) {
                bestSwapi = i;
                bestSwapj = largestSeenPos;
            }

            if (largestSeen < numStr[i]) {
                largestSeen = numStr[i];
                largestSeenPos = i;
            }
        }

        swap(numStr, bestSwapi, bestSwapj);
        cout << bestSwapi << ", " << bestSwapj << endl;
        return stoi(numStr);
    }
};

/*
Worst case: O(n^2), where n is up to 10.

// Find the largest digit, swap with first digit?
// If first digit is already the largest:
// do it recursively for the rest

Scan backwards:
record largest digit seen
if current smaller than largest, record best swap

98368
largestSeen=8, largestSeenPos = 4, bestSwapi = 4, bestSwapj = 4
largestSeen=8, largestSeenPos = 4, bestSwapi = 3, bestSwapj = 4
largestSeen=8, largestSeenPos = 4, bestSwapi = 2, bestSwapj = 4
*/
