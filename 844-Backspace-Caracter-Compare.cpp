
#include <iostream>
#include <string>
using namespace std;


// worst case O(n^2)
class SolutionTimeConsuming
{
public:
    bool backspaceCompare(string s, string t)
    {
        // for s

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                int j = 1;
                while (i - j >= 0 && s[i - j] == '#')
                    j++;
                if (i - j >= 0)
                    s[i - j] = '#';
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#')
            {

                int j = 1;
                while (i - j >= 0 && t[i - j] == '#')
                    j++;
                if (i - j >= 0)
                    t[i - j] = '#';
            }
        }

        int sPtr = 0;
        int tPtr = 0;
        while (sPtr < s.length() && tPtr < t.length())
        {

            while (sPtr < s.length() && s[sPtr] == '#')
                sPtr++;
            while (tPtr < t.length() && t[tPtr] == '#')
                tPtr++;

            if (s[sPtr] != t[tPtr])
                return false;

            sPtr++;
            tPtr++;
        }
        while (sPtr < s.length())
        {
            if (s[sPtr] != '#')
                return false;
            sPtr++;
        }

        while (tPtr < t.length())
        {
            if (t[tPtr] != '#')
                return false;
            tPtr++;
        }
        return true;
    }
};
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int sPtr = s.length() - 1;
        int tPtr = t.length() - 1;
        int backspCount = 0;
        while (sPtr >= 0)
        {
            if (s[sPtr] == '#')
                backspCount++;

            else if (backspCount > 0)
            {
                s[sPtr] = '#';
                backspCount--;
            }

            sPtr--;
        }

        backspCount = 0;
        while (tPtr >= 0)
        {
            if (t[tPtr] == '#')
                backspCount++;

            else if (backspCount > 0)
            {
                t[tPtr] = '#';
                backspCount--;
            }

            tPtr--;
        }

        sPtr = 0;
        tPtr = 0;
        while (sPtr < s.length() && tPtr < t.length())
        {

            while (sPtr < s.length() && s[sPtr] == '#')
                sPtr++;
            while (tPtr < t.length() && t[tPtr] == '#')
                tPtr++;

            if (s[sPtr] != t[tPtr])
                return false;

            sPtr++;
            tPtr++;
        }
        while (sPtr < s.length())
        {
            if (s[sPtr] != '#')
                return false;
            sPtr++;
        }

        while (tPtr < t.length())
        {
            if (t[tPtr] != '#')
                return false;
            tPtr++;
        }
        return true;
    }
};
int main()
{
    Solution sol;

    string s1 = "ab#cc#";
    string t1 = "ad#c";

    string s2 = "bxj##tw";
    string t2 = "bxo#j##tw";

    string s3 = "xywrrmp";
    string t3 = "xywrrmu#p";

    cout << sol.backspaceCompare(s1, t1) << endl;
    cout << sol.backspaceCompare(s2, t2) << endl;
    cout << sol.backspaceCompare(s3, t3) << endl;
}