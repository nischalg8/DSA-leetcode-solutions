#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* My approach (solution that I though of )
class Solution {
public:
    bool constainsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (size_t i = 0; i < nums.size(); i++) {
            numMap[nums[i]]++;
            if(numMap[nums[i]] > 1){
                return true;
                
            }
            numMap[nums[i]]++;
    
        }
        
        return false;
       
    }
};
*/

// set approach sice only count is needed 
class Solution {
    public: 
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> seen;

        for(int num : nums)
        {
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7, 7, 11,7,15};
  

    bool result = sol.containsDuplicate(nums);
    cout<<result<<endl;
    
}
