#include <iostream>
#include <climits>

using namespace std;

class Solution
{
// constraints   -2^31 <= x <= 2^31 - 1
public:
    int reverse(int x)
    {   
        
        int rem=0, num=0;
        while(x !=0)
        {
            rem = x % 10;
            x/=10;
            if((num > INT_MAX / 10) || ((num == INT_MAX /10) && (rem > 7)))
                 return 0;
            if((num < INT_MIN / 10) || ((num == INT_MIN /10)  && (rem < -8)))
                 return 0;
            num = num * 10 + rem ; 
           
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout<<s.reverse(10134)<<endl;

}
