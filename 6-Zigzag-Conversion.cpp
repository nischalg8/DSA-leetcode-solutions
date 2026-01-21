#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1 || s.length() <= numRows)
        {
            return s;
        }
        vector<string> str(numRows, "");
        int i = 0;
        bool direction = false;
        for (char c : s)
        {
            str[i] += c;
            if (i == numRows - 1 || i == 0)
            {
                direction = !direction;
            }

            i += direction ? 1 : -1;
        }

        string ans;
        for (string line : str)
        {
            ans += line;
        }
        return ans;
    }
};
int main()
{
    Solution sol;

    string s = "PAYPALISHIRING";
    int numRows = 3;

    string output = sol.convert(s, numRows);

    cout << "Input String: " << s << endl;
    cout << "Number of Rows: " << numRows << endl;
    cout << "ZigZag Output: " << output << endl;

    return 0;
}
