
#include <iostream>
#include <vector>

using namespace std;

/*
    Not Optimal Approaches: 

    Approach  1: We can use brute force -- O(m^2) time 
    Approach 2:  Instead of linear-searching if every element in range [1, n]
    is present in nums or not, we could instead sort nums and then apply binary-search e
     very time. If the element is not found in nums, we include it in ans.

     O(nlogn), we iterate over the range [1, n] which takes O(n) and for each iteration,
      we check if that element occurs in nums using binary search which takes another O(logn) giving a total time of O(nlogn)

    We will be using O(n) time approach below.
*/

// A hashset (unoredered_set) can also be used for this problem O(n) time but it would take O(n) space complexity

// Solution with O(n) time and O(1) extra space (space taken apart from ans is constant)
class Solution
{   
    public:
    vector<int> findDisappearedNumbers(vector<int> nums)
    {
        int i=0;
        // keeping the numbers in the right index in sorted order--- O(n)
       while(i<nums.size())
       {    
         int correctIndex = nums[i] -1;
         // swapping if number is not in correctIndex or if correctIndex doesnt have the correct number 
         // the second check is necessary to avoid the infinity loop due to duplicates 
         if((i !=  correctIndex) && (nums[i] != nums[correctIndex]))
         {
            swap(nums[i], nums[correctIndex]);

         }
         else{
            i++;
         }
       }
       vector<int> result;
       for(int i=0; i<nums.size(); i++)
       {
            if(nums[i] != i+1){
                result.push_back(i+1);
            }
       }
       return result;
    }

};
int main()
{
    Solution sol;
    vector<int> nums={4, 1, 2, 3, 6, 6, 8, 4};
    vector<int> result = sol.findDisappearedNumbers(nums);
    for(int x: result){
        cout<<x<<endl;
    }
}