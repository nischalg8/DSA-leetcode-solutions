#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size()-1;
        int mid = start + (end - start) /2;
        while(start <= end)
        {
            mid = start + (end - start) /2;
            if(nums[mid] == target)
            {
                return mid ;
            }
            if(nums[mid] > target)
            {
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
 
    cout<<sol.search(nums, 9)<<endl;
    cout<<sol.search(nums, 4);
}