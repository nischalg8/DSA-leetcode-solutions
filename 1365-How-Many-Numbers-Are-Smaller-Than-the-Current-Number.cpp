#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> sorted =nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> indices;
        for(size_t i{}; i<sorted.size(); ++i)
        {
          if (indices.find(sorted[i]) ==  indices.end())
                indices[sorted[i]]=i;
        }
        vector<int> result;
        for(int x: nums)
            result.push_back(indices[x]);
        
        return result;
    }
};
int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {8, 1, 2, 2, 3};
    vector<int> result1 = sol.smallerNumbersThanCurrent(nums1);

    cout << "Test 1: ";
    for (int x : result1)
        cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {6, 5, 4, 8};
    vector<int> result2 = sol.smallerNumbersThanCurrent(nums2);

    cout << "Test 2: ";
    for (int x : result2)
        cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {7, 7, 7, 7};
    vector<int> result3 = sol.smallerNumbersThanCurrent(nums3);

    cout << "Test 3: ";
    for (int x : result3)
        cout << x << " ";
    cout << endl;

    // Test Case 4
    vector<int> nums4 = {1};
    vector<int> result4 = sol.smallerNumbersThanCurrent(nums4);

    cout << "Test 4: ";
    for (int x : result4)
        cout << x << " ";
    cout << endl;

    // Test Case 5
    vector<int> nums5 = {5, 0, 10, 0, 10, 6};
    vector<int> result5 = sol.smallerNumbersThanCurrent(nums5);

    cout << "Test 5: ";
    for (int x : result5)
        cout << x << " ";
    cout << endl;

    return 0;
}