class Solution {
public:
    bool isDigitLog(const string & s) {
        char c = s[s.find(' ') + 1];
        if (c >= '0' and c <= '9') {
            return true;
        } else {
            return false;
        }

    }

    static bool letterLogComparator(const string &s1, const string &s2) {
        string s11 = s1.substr(0, s1.find(' '));
        string s21 = s2.substr(0, s2.find(' '));
        string s12 = s1.substr(s1.find(' ') + 1);
        string s22 = s2.substr(s2.find(' ') + 1);

        if (s12 == s22) {
            return s11 < s21;
        } else {
            return s12 < s22;
        }
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        // First pass: collect letter logs
        vector<string> result;
        for (int i = 0; i < logs.size(); i++)  {
            if (!isDigitLog(logs[i])) {
                result.push_back(logs[i]);
            }
        }
        sort(result.begin(), result.end(), letterLogComparator);

        // Second pass: add digit logs
        for (int i = 0; i < logs.size(); i++) {
            if (isDigitLog(logs[i])) {
                result.push_back(logs[i]);
            }
        }
        return result;
    }
};
