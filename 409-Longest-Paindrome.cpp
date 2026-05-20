#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {

        unordered_map<char, int> mp;
        if (s.empty())
            return 0;
        for (char c : s)
        {
            mp[c]++;
        }
        int count = 0;
        for (auto &it : mp)
        {
            if (it.second % 2 == 0)
                count += it.second;
            else
                count += (it.second - 1);
        }
        // we can add one element in the middle and still the string will be palindrome;
        count = count + 1 > s.length() ? count : count + 1;
        return count;
    }
};
// using freqArr instead of hashmap
class OptimizedBetterSolution
{

public:
    int longestPalindrome(string s)
    {
        // Uppercase and lowercase letter = 26*2 = 52
        int freqArr[52] = {0};
        for (char c : s)
        {

            if (c >= 'a' && c <= 'z')
                freqArr[c - 'a']++;

            else
                freqArr[c - 'A' + 26]++;
        }
        int length = 0;
        bool oddFound = false;

        for (int count : freqArr)
        {
            length += (count / 2) * 2; // to make sure if count is odd then even number which is one less than odd number is added
            if (count % 2)
            {
                oddFound = true;
            }
        }
        return oddFound ? length + 1 : length;
    }
};

int main()
{
    Solution sol;
    OptimizedBetterSolution sol2;

    vector<string> stringVec = {
        "abccccdd",
        "a",
        "",
        "vvccasde",
        "bbsade",
        "Azja"};
    for (string s : stringVec)
    {
        cout << sol.longestPalindrome(s) << endl;
    }
    for (string s : stringVec)
    {
        cout << sol2.longestPalindrome(s) << endl;
    }
}