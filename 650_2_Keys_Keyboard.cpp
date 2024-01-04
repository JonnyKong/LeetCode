class Solution {
    /**
     * Perform prime factorization, sum the primes up.
     */

public:
    vector<int> factorPrimes(int n) {
        int i = 2;
        vector<int> ret;

        while (n > 1) {
            if (n % i == 0) {
                n /= i;
                ret.push_back(i);
            } else {
                i += 1;
            }
        }
        return ret;
    }


    int minSteps(int n) {
        auto primes = factorPrimes(n);
        return accumulate(primes.begin(), primes.end(), 0);
    }
};
