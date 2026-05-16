#include <iostream>
#include <unordered_set>
#include <vector>

#include <cassert>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        bool isPresent[201] = {false};
        size_t x = 0;
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!isPresent[(size_t)nums[i] + 100])
            {
                nums[x] = nums[i];
                isPresent[nums[i] + 100] = true;
                x++;
               
            }
        }
        return (int)x;
    }
};

void test(vector<int> nums, vector<int> expectedNums, Solution &sol)
{
    int k = sol.removeDuplicates(nums);

    assert(k == expectedNums.size());

    for (int i = 0; i < k; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    cout << "Test Passed\n";
}

int main()
{
    Solution sol;

    test({1, 1, 2}, {1, 2}, sol);

    test({0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
         {0, 1, 2, 3, 4}, sol);

    test({1, 2, 3, 4, 5},
         {1, 2, 3, 4, 5}, sol);

    test({1, 1, 1, 1, 1},
         {1}, sol);

    test({-3, -3, -2, -2, -1, -1, 0, 0},
         {-3, -2, -1, 0}, sol);

    test({1},
         {1}, sol);

    test({1, 1},
         {1}, sol);

    test({1, 2},
         {1, 2}, sol);

    test({1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
         {1, 2, 3, 4, 5}, sol);

    test({0, 0, 0, 0, 0, 1},
         {0, 1}, sol);

    test({-10, -10, -5, -5, 0, 1, 1, 2, 2, 100},
         {-10, -5, 0, 1, 2, 100}, sol);

    cout << "All tests passed successfully\n";
}