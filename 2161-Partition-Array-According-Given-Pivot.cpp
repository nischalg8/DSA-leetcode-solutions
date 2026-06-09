#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n= nums.size();
        vector<int> ans(n, 0);
        int greater_count{0}, equal_count{0}; 
        for(int x: nums)
        {
    
            if(x==pivot)
                equal_count++;
            else if(x>pivot)
                greater_count++;
        }
        // for pivot in middle 
        int end = (n-1) - greater_count;
        int start = end - equal_count;

        for(int i=end; i>start; i--)          
            ans[i] = pivot;
        
        // for greater and smaller values 
        // smaller start from left while greater from right index
        int left=0,right=end+1;
        for(int x: nums)
        {
            if(x<pivot)
                ans[left++]=x;
          
            else if(x>pivot)
                ans[right++]= x;

        } 
        return ans;
    }
};

class Solution2 {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n= nums.size();
        vector<int> ans(n, pivot);
        int greater_count{0};

        for (int x : nums) 
            if (x > pivot) greater_count++;
        

        int greater_start = n-greater_count;
        int left=0,right=greater_start;
        for(int x: nums)
        {
            if(x<pivot) ans[left++]=x;
            else if(x>pivot) ans[right++]= x; 
        } 
        return ans;
    }
};

int main()
{

    vector<int> nums={9,12,5,10,14,3,10};
    int pivot = 10;

    Solution sol;
    vector<int> ans = sol.pivotArray(nums, pivot);
    for(int x: ans)
    {
        cout<<x<<" ";
    }
}

