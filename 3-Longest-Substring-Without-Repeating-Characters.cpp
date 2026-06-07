#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t left=0;
        unordered_set<int> st;
        int maxlen=0;
        for(size_t right{}; right< s.length(); ++right)
        {   
            while(st.find(s[right]) != st.end())
            {
                st.erase(s[left]);
                left++;
            }
            
            st.insert(s[right]);
            maxlen = max(maxlen, static_cast<int>(right-left)+1);
        }
        return maxlen;
    }
};
int main()
{
    Solution sol;

    string s = "abcabcbb";
    int output = sol.lengthOfLongestSubstring(s);

    cout << "Input String: " << s << endl;
    cout << "Length of Longest Substring Without Repeating Characters: " << output << endl;

    return 0;
}
