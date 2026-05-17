#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumTillN = nums.size() * (nums.size() + 1 ) / 2; 
        int sumOfArray = 0;
        for(int n: nums){
            sumOfArray += n;
        }
        return sumTillN - sumOfArray;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2,3, 0, 4, 6, 7};

    int n = sol.missingNumber(nums);

    cout<<n;
}