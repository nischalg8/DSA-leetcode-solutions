#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    long myAtoi(string s)
    {
        long num = 0, sign = 1;
        size_t i=0;
        while (i < s.length() && s[i] == ' ')
        {
            i++;
        }

        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            sign = s[i] == '-' ? sign * -1 : sign * 1;
            i++;
        }

        while (i < s.length() && (s[i] >= '0' && s[i] <= '9'))
        {
            num = num * 10 + (s[i] - '0');
            if (sign * num < INT_MIN)
                return INT_MIN;
            if (sign * num > INT_MAX)
                return INT_MAX;
            i++;
        }

        return num * sign;
    }
};

int main()
{
    Solution s;
    s.myAtoi("42");
    cout<<s.myAtoi("42")<<endl;

}