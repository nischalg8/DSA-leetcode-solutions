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

int main()
{
    BruteForceSolution bf;

    cout << bf.characterReplacement("AABABBA", 1) << endl;
}