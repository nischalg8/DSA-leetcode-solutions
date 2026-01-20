#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (size_t i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = static_cast<int>(i);
        }

        for (size_t i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != static_cast<int>(i)) {
                return {static_cast<int>(i), numMap[complement]};
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
