#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        size_t n= nums.size();
        vector<int> leftSum(n,0), rightSum(n,0), answer(n,0);
    
        for(size_t i{1}; i<n; ++i)
        {
            leftSum[i]=leftSum[i-1] + nums[i-1];
            rightSum[n-i-1]=rightSum[n-i] + nums[n-i];

        }
        for(size_t i{}; i<n; ++i)
        {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }
        return answer;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> answer = sol.leftRightDifference(nums);
    for(auto x: answer)
    {
        cout<<x<<endl;
    }
}