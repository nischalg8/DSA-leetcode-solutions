// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {

        if(x <= 1)
            return x;

        int start = 1, end = x / 2+1;
        int ans = 0;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            long long square = 1LL * mid * mid;
            cout<<"mid"<<mid<<"end"<<end<<"start"<<start<<endl;
            if(square == x)
            {
                return mid;
            }
            else if(square < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};
int main() {
    // Write C++ code here

    Solution sol;
cout << sol.mySqrt(4) << endl;      // 1000
cout << sol.mySqrt(123456789) << endl;    // 11111
cout << sol.mySqrt(2147395599) << endl;   // 46339
cout << sol.mySqrt(2147395600) << endl;   // 46340
cout << sol.mySqrt(2147483647) << endl;   // 46340
    return 0;
}