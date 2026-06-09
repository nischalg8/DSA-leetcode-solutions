#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// O((m+26)*n) m= s1.length and n=s2.length() time
class MySolution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int charMap[26] = {0};
        for (char c : s1)
            charMap[c - 'a']++;

        int left = 0, right = 0;

        while (left + s1.length() <= s2.length())
        {

            bool isPerm = true;
            if (charMap[s2[left] - 'a'] > 0)
            {
                right = left + s1.length();

                int charMap2[26];
                copy(begin(charMap), end(charMap), begin(charMap2));

                for (int i = left; i < right; i++)
                {
                    if (charMap2[s2[i] - 'a'] < 1)
                        break;
                    charMap2[s2[i] - 'a']--;
                }

                for (int count : charMap2)
                    if (count != 0)
                        isPerm = false;

                if (isPerm)
                    return true;
            }
            left++;
        }
        return false;
    }
};
// O(26 * n)
class Solution{

    public:
    bool checkInclusion(string s1, string s2)
    {
        int m= s1.size(), n=s2.size();
        int freqArr1[26]={0};
        int freqArr2[26]={0};
        if(m>n)
            return false;
        for(int i=0; i<m; i++)
        {
            freqArr1[s1[i]-'a']++;
            freqArr2[s2[i]-'a']++;
        }

        if(equal(begin(freqArr1), end(freqArr1), begin(freqArr2)))
            return true;
        int left =0; // window size = right - left = m 
        for(int right=m; right<s2.size(); right++){
            
            // decrease the freq of character leaving the window from left
            freqArr2[s2[left]-'a']--; 
            // increase the freq of character entering the window from right 
            freqArr2[s2[right]-'a']++; 

            if(equal(begin(freqArr1), end(freqArr1), begin(freqArr2)))
                return true;
            left++;
      }
      return false;
    }
};
//O(n)
class BestOptimizedSolution{

    public:
    bool checkInclusion(string s1, string s2)
    {
        int m= s1.size(), n=s2.size();
        int freqArr1[26]={0};
        int freqArr2[26]={0};
        if(m>n)
            return false;
        // initial window of size m
        for(int i=0; i<m; i++)
        {
            freqArr1[s1[i]-'a']++;
            freqArr2[s2[i]-'a']++;
        }

        int matches = 0;
        for(int i=0; i<26;i++)
            if(freqArr1[i]==freqArr2[i])
                matches++;

  
        int left = 0;
        for(int right=m; right<s2.size(); right++){
             
            if(matches==26) return true;

            int incoming = s2[right]-'a';
            int outgoing = s2[left]-'a';

            // increase the freq of character entering the window from right 
            freqArr2[incoming]++;

            if(freqArr2[incoming]==freqArr1[incoming])
                matches++;
                
            else if (freqArr2[incoming]-1 == freqArr1[incoming])
                matches--;

            // decrease the freq of character leaving the window from left
            freqArr2[outgoing]--; 
             if(freqArr2[outgoing]==freqArr1[outgoing])
                matches++;
                // if we break the match after removing character from window then decrement matches
            else if(freqArr2[outgoing]+1 == freqArr1[outgoing])
                matches--;
            
            left++;
            
      }
      return matches==26;
    }
};

int main()
{
    BestOptimizedSolution sol;
    string s1 = "adc", s2 = "dcda";
    cout << sol.checkInclusion(s1, s2) << endl;
}