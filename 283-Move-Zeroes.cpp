#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int replaceableSlot=0;
        int countZeros = 0;
        bool toReplace=false;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0 && toReplace)
            {
                nums[replaceableSlot] = nums[i];
                replaceableSlot++;
               
            }
            else if(nums[i] ==0)
            {
                // if zero is encountered then it is to be replaced with next non-zero element so toReplace is trye
                countZeros++;
                toReplace=true;
            }
            else{
               
                // non-zero element but toReplace is false so no need to replace
                replaceableSlot++;
            }
        }
        int n= nums.size()-1;
        for(int i=n;i>n-countZeros; i--)
        {
            nums[i]=0;
        }

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums1 = {{0,1,0,3,2},{0},{1,2,3,0, 5, 0, 7,0},{0,0,0,1,2}};
  

    sol.moveZeroes(nums1[0]);
    sol.moveZeroes(nums1[1]);
    sol.moveZeroes(nums1[2]);
    sol.moveZeroes(nums1[3]);

    for(vector<int> vec: nums1)
    {
        for(int x: vec)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
