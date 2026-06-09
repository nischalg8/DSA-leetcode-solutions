#include <iostream>
#include <vector>

using namespace std;

class BruteForceSolution
{
public:
    /* here we consider each possible substring that is

       AABABBA

       so for i=0  substrings are  A, AA, AAB, AABA, AABAB, ..., ...., ....
                                               |4th|
        for i=1 substrings are     A, AB, ABA, ABAB, .......

        and so on here we look at a substring lenght j-i+1 and look at max freq of character
        for the 4th substring in i=0 (first row) max freq is 3 of A and lenght is j-i+1 that is 3-0+1 =4 so we do
        changes = length - maxfreq so we need to make only 1 change to get all characters of the same maxfreq character

        so if changes is less than allowed (k) then we compare it with
        maxlen of substring if it is greater then make it max else not
    */
    int characterReplacement(string s, int k)
    {

        int maxlen = 0;
        for (size_t i{}; i < s.length(); ++i)
        {
            int freqArr[26] = {0}, maxFreq{0};
            for (size_t j = i; j < s.length(); ++j)
            {
                freqArr[s[j] - 'A']++;
                maxFreq = max(maxFreq, freqArr[s[j] - 'A']);

                int change = (j - i + 1) - maxFreq;

                if (change <= k)
                {
                    maxlen = max(maxlen, (int)(j - i + 1));
                }
                else
                {
                    break;
                }
            }
        }
        return maxlen;
    }
};

class Solution
{

public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0, freqArr[26] = {0};

        while (r < s.length())
        {
            freqArr[s[r] - 'A']++;
            maxFreq = max(maxFreq, freqArr[s[r] - 'A']);

            while (((r - l + 1) - maxFreq) > k)
            {
                 /*  now that the changes to be made are greater than allowed changes k so we move left ptr
                 window lenght = r-l+1 

                 to make the entire window consist of one repeating character 

                maxFreq is not decreased when moving left ptr, a stale maxFreq 
                value still wont produce maxLen greater than it previously was 
                this is enough for correctness and keeps the solution O(n).
                */
                freqArr[s[l] - 'A']--;             
                l++;
            }
            
            int changes = (r - l + 1) - maxFreq;
            maxLen = changes <= k ? max(maxLen, r - l + 1) : maxLen;
            r++;
        }
        return maxLen;
    }
};

int main()
{
    Solution bf;

    cout << bf.characterReplacement("AAAABABBA", 2) << endl;
}