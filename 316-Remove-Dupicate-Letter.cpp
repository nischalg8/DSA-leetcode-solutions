#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
// Solution I came up with..
class Solution1
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> st;

        // frequency of remaining characters
        int freq[26] = {0};

        // tracks if character already exists in stack
        bool inStack[26] = {false};

        string result;

        // count frequency
        for(char c : s)
        {
            freq[c - 'a']++;
        }

        for(char c : s)
        {
            // current character processed,
            // so decrease remaining frequency
            freq[c - 'a']--;

            // if already inside stack skip it
            if(inStack[c - 'a'])
                continue;

            // maintain lexicographically smallest order
            while(!st.empty() &&
                  st.top() > c &&
                  freq[st.top() - 'a'] > 0)
            {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        // build answer
        while(!st.empty())
        {
            result= st.top()+result;
            st.pop();
        }


        return result;
    }
};
// another solution with lastIndex instead of freqMap
class Solution1
{
public:
    string removeDuplicateLetters(string s)
    {
      stack<char> st;
      unsigned short int lastIndex[26] = {0};
      bool inStack[26]={false};
      string result;
      for(int i=0; i<s.length(); i++)
      {
        lastIndex[s[i]-'a']= i;
      }

      for(int i=0 ; i< s.length(); i++)
      {
        if(inStack[s[i] - 'a']) continue; // if the alphabet is in stack then skip it 

        while(!st.empty() && st.top() > s[i] && i < lastIndex[st.top()-'a'])
        {
            inStack[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(s[i]);
         inStack[st.top() - 'a'] = true;

      }
      while(!st.empty())
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

    Solution1 sol;

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