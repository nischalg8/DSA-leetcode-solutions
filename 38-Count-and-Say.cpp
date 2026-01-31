#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> arrayPairs(string s)
    {

        int count = 0, letter = s[0];
       vector<vector<int>> v1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == letter)
                count++;
            else
            {
                letter = s[i];
                v1.push_back({count, s[i - 1] - '0'});
                count = 1;
            }
        }
        char last = s.back();
        v1.push_back({count, last - '0'});
        return v1;
    }
    string stringPair(vector<vector<int>> a)
    {
        string s;
        for (const auto &row : a)
        {
           s += to_string(row[0]);
            s += to_string(row[1]);

        }
        return s;
    }
    string countAndSay(int n)
    {
        vector<vector<int>> v1;
        string s{'1'};
        for (int i = 1; i < n; i++)
        {

            v1 = arrayPairs(s);
            s = stringPair(v1);
            cout<< s<<endl;
        }
        return s;
    }
};

int main()
{       

        Solution s;
        string result = s.countAndSay(4);

        cout << result << endl;
}