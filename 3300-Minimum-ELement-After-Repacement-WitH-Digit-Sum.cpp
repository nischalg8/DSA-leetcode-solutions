#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sumOfDigits(int n)
    {
        int sum=0;
        while(n>0){
            sum+= n% 10; 
            n/=10;

        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        
        int minElement = sumOfDigits(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            minElement = min(minElement, sumOfDigits(nums[i]));
        }
        return minElement;

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {44, 2,3,30, 10};
    cout<<sol.minElement(nums)<<endl;
}