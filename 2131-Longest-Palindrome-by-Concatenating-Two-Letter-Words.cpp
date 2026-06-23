#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> wordCount;
        for(const auto &word: words)
            wordCount[word]++;
        
        int longestPalindromeLen= 0;
        bool oddCenter = false;
        for(const auto& [word, freq]: wordCount)
        {
            string reversed(word.rbegin(), word.rend());

            if(reversed == word)
            {
                longestPalindromeLen += (freq /2) * 4;
                /* 
                    result is int so it registers int values 
                if freq  = 1  int(1/2 ) =0 so result = 0
                if feq =3     3/2 =1 in int so result = 14
                */
                if(freq % 2)
                    oddCenter = true;
            }
            // to avoid counting twice if em and me then we check in one order only me and em 
            else if(word > reversed)
            {
                if(wordCount.count(reversed))
                    longestPalindromeLen += 4 * min(freq, wordCount[reversed]);
            }
        }
        /* extra 2 if rev is equal and has odd number 
            FOR eg. if there are three ee's then 2 are registered and result += 4
            from upper if condition and remaning 1 from here
        */
        if(oddCenter) longestPalindromeLen+=2;
        return longestPalindromeLen;
    }
};
class Solution2 {
public:
    int longestPalindrome(vector<string>& words, int count = 0) {

        // mpp[a][b] = number of unmatched words "ab" seen so far.
        // If we later see "ba", we can immediately pair them.
        vector<vector<int>> mpp(26, vector<int>(26, 0));

        // Number of unmatched self-palindromic words (same char words):
        // "aa", "bb", "cc", ...
        // One of these can potentially sit in the center.
        int middle = 0;

        for (auto &s : words) {
            int x = s[0] - 'a';
            int y = s[1] - 'a';

            // Check if the reverse word is waiting.
            // Example: current = "ab", look for an unmatched "ba".
            if (mpp[y][x] > 0) {

                // Use one reverse word to form a symmetric pair.
                mpp[y][x]--;

                // Pair contributes:
                // "ab" + ... + "ba" => 4 characters.
                count += 4;

                // If we paired "aa" with another "aa",
                // one center candidate disappears.
                if (x == y) middle--;
            }
            else {
                // No reverse found yet, keep this word waiting.
                mpp[x][y]++;

                // Unmatched "aa", "bb", ... can potentially
                // become the middle of the palindrome.
                if (x == y) middle++;
            }
        }

        // After forming all possible pairs, if any unmatched
        // self-palindromic word remains, place exactly one
        // in the center and gain 2 more characters.
        if (middle > 0) count += 2;

        return count;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"lc", "cl", "gg"};
    cout << sol.longestPalindrome(words1) << endl;  // 6

    vector<string> words2 = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << sol.longestPalindrome(words2) << endl;  // 8

    vector<string> words3 = {"cc", "ll", "xx"};
    cout << sol.longestPalindrome(words3) << endl;  // 2

    return 0;
}

