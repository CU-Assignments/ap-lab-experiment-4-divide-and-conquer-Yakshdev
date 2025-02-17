#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        if (n < 2) return "";

        for (int i = 0; i < n; i++) {
            unordered_set<char> charSet(s.begin(), s.end());
            if (charSet.count(tolower(s[i])) && charSet.count(toupper(s[i]))) {
                continue;
            }
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return left.size() >= right.size() ? left : right;
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    
    string s1 = "YazaAay";
    cout << "Output: " << sol.longestNiceSubstring(s1) << endl;

    string s2 = "Bb";
    cout << "Output: " << sol.longestNiceSubstring(s2) << endl;

    string s3 = "c";
    cout << "Output: " << sol.longestNiceSubstring(s3) << endl;

    return 0;
}
