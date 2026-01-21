#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxLen = 0;
        unordered_set<char> seen;

        for (int right = 0; right < s.length(); right++) {
         
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s = "abcabcbb";
    int output = sol.lengthOfLongestSubstring(s);

    cout << "Input String: " << s << endl;
    cout << "Length of Longest Substring Without Repeating Characters: " << output << endl;

    return 0;
}
