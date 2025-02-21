#include <iostream>
#include <vector>

using namespace std;

int countFancyNumbers(int n) {
    int fancy_upper_bound = 0;
    int base = 1;

    // Convert n to base-4, replacing 2 and 3 with 1
    bool isFancy = true;
    while (n > 0) {
        int digit = n % 4;
        if (digit >= 2) {
            digit = 1; // Replace 2 or 3 with 1
            isFancy = false;
        }
        fancy_upper_bound += digit * base;
        base *= 2; // This constructs the binary interpretation
        n /= 4;
    }

    return fancy_upper_bound - (isFancy ? 1 : 0);
}

// Driver function
int main() {
    cout << countFancyNumbers(10) << endl;
    cout << countFancyNumbers(21) << endl;
    cout << countFancyNumbers(20) << endl;
    return 0;
}
