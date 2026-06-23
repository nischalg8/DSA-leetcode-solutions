#include <iostream>

using namespace std;

class Solution {
    public:

    int maxNumberOfBalloons(string text)
    {
        int charFreq[5]={0};
        for(char c: text)
        {
            if(c=='a')
                 charFreq[0]++;
            else if(c=='b')
                 charFreq[1]++;
            else if(c=='n')
                 charFreq[2]++;
            else if(c=='l')
                charFreq[3]++;
            else if(c=='o')
                charFreq[4]++;
        }
        int min = charFreq[0];

        charFreq[3]/=2;
        charFreq[4]/=2;

        for(size_t i{}; i<5; ++i)
        {
            if(charFreq[i]< min)
                min = charFreq[i];

        }
        return min;


    }
};
int main()
{

    Solution sol;
    string s1="loonbalxballpoon";
    string s2="";

    cout<<sol.maxNumberOfBalloons(s1)<<endl;
    cout<<sol.maxNumberOfBalloons(s2)<<endl;
}