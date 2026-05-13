#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
     unordered_map<int, int> map;
 
     for(size_t i=0; i<nums.size(); i++)
     {
        int complement = target - nums[i];

        if(map.count(complement)){
            return {static_cast<int>(i), map[complement]};
        }
        map[nums[i]] = static_cast<int>(i);
     }
    return {};
     
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 5};

    Solution s;
    vector<int> result = s.twoSum(nums,6);

    for (int x : result) {
        cout << x << " ";
    }

  
}