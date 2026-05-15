#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> st;
        unordered_map<char, size_t> lastIndex;
        unordered_map<char, bool> seenMap;
        string result;
        for (size_t i = 0; i < s.length(); i++)
        {
            lastIndex[s[i]] = i;
        }

        for (size_t i = 0; i < s.length(); i++)

        {
            if (seenMap[s[i]])
                continue;

            while (!st.empty() && st.top() > s[i] && i < lastIndex[st.top()])
            {
                seenMap[st.top()] = false;
                st.pop();
            }

            st.push(s[i]);

            seenMap[s[i]] = true;
        }
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};

#include <iostream>
using namespace std;

int main()
{

    Solution sol;

    cout << sol.removeDuplicateLetters("abacb") << endl;
    //  1. basic example

    cout << sol.removeDuplicateLetters("bcabc") << endl;
    // // expected: abc

    // 2. given example
    cout << sol.removeDuplicateLetters("cbacdcbc") << endl;
    // expected: acdb

    // // 3. all same characters
    cout << sol.removeDuplicateLetters("aaaaa") << endl;
    // // expected: a

    // // 4. already sorted unique
    cout << sol.removeDuplicateLetters("abcde") << endl;
    // // expected: abcde

    // // 5. reverse order
    // cout << sol.removeDuplicateLetters("edcba") << endl;
    // // expected: edcba

    // // 6. alternating duplicates
    // cout << sol.removeDuplicateLetters("abacb") << endl;
    // // expected: abc

    // // 7. tricky ordering
    cout << sol.removeDuplicateLetters("cbac") << endl;
    // // expected: bac

    // // 8. repeated blocks
    cout << sol.removeDuplicateLetters("bbcaac") << endl;
    // // expected: bac

    // // 9. complex pattern
    cout << sol.removeDuplicateLetters("thesqtitxyetpxloeevdeqifkz") << endl;
    // // expected: txyetpxloevdqi f k z → (final expected: "thesqtitxyepxloevdqifkz") // common test

    // // 10. single character
    cout << sol.removeDuplicateLetters("z") << endl;
    // expected: z

    return 0;
}