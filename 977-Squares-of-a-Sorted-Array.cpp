#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n= nums.size();
        int leftPtr=0;
        int rightPtr = n-1;
        int i=n-1;
        vector<int> result(n);
        while(leftPtr <= rightPtr)
        {
            int leftSq = nums[leftPtr] * nums[leftPtr];
            int rightSq = nums[rightPtr] * nums[rightPtr];

            if(leftSq > rightSq)
            {
                result[i] = leftSq;
                leftPtr++;
            }
            
            else
            {
                result[i] = rightSq;
                rightPtr--;
            }
            i--;

        }
        return result;
    }

};

int main()
{
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> result = sol.sortedSquares(nums);

    for(int x: result){
        cout<<x<<" ";
    }

}