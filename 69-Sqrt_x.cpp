#include <iostream>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {

        if (x < 2) return x;
        int start = 1, end = x / 2;
        int mid = start + (end - start) / 2, root = 0, largestRoot = 0;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            root = x / mid;
            /* if square = mid * mid is used to compare with x instead of mid with root 
                then 1L is to be used 
                square = (long long)mid * mid 
                or 
                square = 1LL * mid * mid 
                as mid * mid will be considered int and if it exceeds int range that would cause problems
                
                then .
                if(square == x) return mid 
                if(square < x) .....
                can be done 
            */

         
            if (mid <= root)
            {
                largestRoot = mid;
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
          
        }
        return largestRoot;
    }
};

int main()

{
    Solution sol;
   cout << sol.mySqrt(0) << endl;           // 0
cout << sol.mySqrt(1) << endl;           // 1
cout << sol.mySqrt(4) << endl;           // 2
cout << sol.mySqrt(9) << endl;           // 3
cout << sol.mySqrt(16) << endl;          // 4
cout << sol.mySqrt(25) << endl;          // 5
cout << sol.mySqrt(36) << endl;          // 6
cout << sol.mySqrt(49) << endl;          // 7
cout << sol.mySqrt(64) << endl;          // 8
cout << sol.mySqrt(81) << endl;          // 9

cout << sol.mySqrt(2) << endl;           // 1
cout << sol.mySqrt(3) << endl;           // 1
cout << sol.mySqrt(5) << endl;           // 2
cout << sol.mySqrt(8) << endl;           // 2
cout << sol.mySqrt(10) << endl;          // 3
cout << sol.mySqrt(15) << endl;          // 3
cout << sol.mySqrt(24) << endl;          // 4
cout << sol.mySqrt(27) << endl;          // 5
cout << sol.mySqrt(50) << endl;          // 7
cout << sol.mySqrt(99) << endl;          // 9

cout << sol.mySqrt(2147395599) << endl;  // 46339
cout << sol.mySqrt(2147483647) << endl;  // 46340
cout << sol.mySqrt(1000000) << endl;     // 1000
cout << sol.mySqrt(99999999) << endl;    // 9999
cout << sol.mySqrt(123456789) << endl;   // 11111
cout << sol.mySqrt(1000000000) << endl;  // 31622
}