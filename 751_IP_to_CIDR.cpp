#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    /* https://algo.monster/liteproblems/751
     * 	The key part of the algorithm is that blocks are 2^i aligned. We find
     * 	the block size that:
     *
     *  1. Aligns with the current IP (cur). (alignment gives an upper limit on
     *  block size)
     *
	 *  2. Covers as many addresses as possible without exceeding range.
     */
    unsigned int strToInt(string ip) {
        unsigned int ret = 0;    
        size_t cursor = 0;
        for (int i = 0; i < 4; i++) {
            int endPos;
            if (i == 3) {
                endPos = ip.length(); 
            } else {
                endPos = ip.find(".", cursor);
            }
            ret = (ret << 8) + std::stoi(ip.substr(cursor, endPos - cursor));
            cursor = endPos + 1;
        }
        return ret;
    }

    string intToStr(unsigned int ip) {
        string ret;
        return std::to_string((ip & 0xff000000) >> 24)
            + "." + std::to_string((ip & 0x00ff0000) >> 16)
            + "." + std::to_string((ip & 0x0000ff00) >> 8)
            + "." + std::to_string(ip & 0x000000ff);
    }

public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> result;
        unsigned int cur = strToInt(ip);

        while (n > 0) {
            // If aligned by b'1010, max block size is b'0010 (find the last bit 1)
            int maxAlignedPower = __builtin_ctz(cur);

            // If n is b'1001, max non-exceeding block size is b'1000 (find the
            // first bit 1, set the remaining to zero)
            int maxNotExceedPower = 32 - __builtin_clz(n) - 1;

            int maxPower = min(maxAlignedPower, maxNotExceedPower);
            result.push_back(intToStr(cur) + "/" + std::to_string(32 - maxPower));
            cur += (1 << maxPower);
            n -= (1 << maxPower);
        }
        return result;
    }
};

int main() {
    auto ret = Solution().ipToCIDR("255.0.0.7", 10);
    for (auto e : ret) {
        printf("%s\n", e.c_str());
    }
}
