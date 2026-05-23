#include <iostream>
#include <vector>
using namespace std;

class MySolution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while (start < end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (start == end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else
            {
                return nums[mid] > target ? mid : mid + 1;
            }
        }
    }
};

class BetterSolution{
    public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end= nums.size()-1;
        int mid= start+ (end-start)/2;

        while(start<=end)
        {
           mid= start+ (end-start)/2;
           if(nums[mid]==target) return mid;
           else if(nums[mid] > target) end =mid-1;
           else start = mid+1;

        }
        return start;

    }
};
int main()
{
    BetterSolution sol;

    vector<vector<int>> testNums = {
        {1, 3, 5, 6},     // target exists
        {1, 3, 5, 6},     // insert middle
        {1, 3, 5, 6},     // insert end
        {1, 3, 5, 6},     // insert beginning
        {1},              // single element found
        {1},              // single element smaller
        {1},              // single element larger
        {},               // empty array
        {1, 2, 4, 6, 8},  // insert between
        {1, 2, 4, 6, 8},  // found first
        {1, 2, 4, 6, 8},  // found last
        {10, 20, 30, 40}, // insert before all
        {10, 20, 30, 40}, // insert after all
        {-10, -5, 0, 5},  // negative values found
        {-10, -5, 0, 5}   // negative insert
    };

    vector<int> targets = {
        5,
        2,
        7,
        0,
        1,
        0,
        2,
        1,
        5,
        1,
        8,
        5,
        50,
        -5,
        -7};

    vector<int> expected = {
        2, // [1,3,5,6], 5
        1, // [1,3,5,6], 2
        4, // [1,3,5,6], 7
        0, // [1,3,5,6], 0
        0, // [1], 1
        0, // [1], 0
        1, // [1], 2
        0, // [], 1
        3, // [1,2,4,6,8], 5
        0, // [1,2,4,6,8], 1
        4, // [1,2,4,6,8], 8
        0, // [10,20,30,40], 5
        4, // [10,20,30,40], 50
        1, // [-10,-5,0,5], -5
        1  // [-10,-5,0,5], -7
    };
    for (int i = 0; i < testNums.size(); i++)
    {
        int ans = sol.searchInsert(testNums[i], targets[i]);
        cout << "Test " << i + 1
             << ": got = " << ans
             << ", expected = " << expected[i] << endl;
    }
}