#include <iostream>
using namespace std;
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int leftPtr = 0;
        int rightPtr = s.size() -1;
        
        while(leftPtr < rightPtr)
        {
            char left=s[leftPtr], right = s[rightPtr];
        
            while(!isalnum(left) && leftPtr <rightPtr)
            {
                left = s[++leftPtr];
            }     
            while(!isalnum(right) && leftPtr<rightPtr)
            {
                right = s[--rightPtr];
            }
            right = tolower(right);
            left = tolower(left);

            if(left!= right)
                return false;
             
             
            ++leftPtr;
            --rightPtr;
            
        }
        return true;
    }
};

#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<string> testCases = {
        "Aba",
        "abba",
        "abcba",
        "A man, a plan, a canal: Panama",
        "race a car",
        " ",
        ".,",
        "0P",
        "Madam",
        "madam",
        "Was it a car or a cat I saw?"
        "ab@a",
        "a#b#a",
        "abc",
        "aa",
        "a",
        "12321",
        "12@321",
        "1a2",
        "ab2a"
    };

    Solution sol;

    for (string s : testCases) {
        cout << "Input: \"" << s << "\"" << endl;
        cout << "Output: " << sol.isPalindrome(s) << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}