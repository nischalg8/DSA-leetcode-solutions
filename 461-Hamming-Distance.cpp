#include <iostream>
using namespace std;

// we can use Brian Kernighan’s Algorithm  to count the number of set bits as well
class Solution {
public:
    int hammingDistance(int x, int y) {
        // builtin_popcount expectes unsigned integer only
        return __builtin_popcount(x^y);
    }
};

int main()
{   
    Solution sol;
    cout<<sol.hammingDistance(1, 4);

}