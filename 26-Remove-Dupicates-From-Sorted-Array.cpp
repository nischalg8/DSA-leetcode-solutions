#include <iostream>
#include <unordered_set>
#include <vector>

#include <cassert>
using namespace std;

// O(n) time and O(201) Space for 201 size array
class SolutionSpaceConsuming
{
public:
     int removeDuplicates(vector<int> &nums)
     {
          bool isPresent[201] = {false};
          int x = 0;

          for (int i = 0; i < nums.size(); i++)
          {
               if (!isPresent[(size_t)nums[i] + 100])
               {
                    nums[x] = nums[i];
                    isPresent[nums[i] + 100] = true;
                    x++;
               }
          }
          return x;
     }
};

// O(n) time and O(1) Space
class SolutionSpaceOptimized
{
public:
     int removeDuplicates(vector<int> &nums)
     {
          int x = 0;
          for (int i = 1; i < nums.size(); i++)
          {
               if (nums[i] == nums[x]) continue;
               else nums[++x] = nums[i];
               
          }
      
          return x + 1;
     }
};

void test(vector<int> nums, vector<int> expectedNums, SolutionSpaceOptimized &sol)
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
     SolutionSpaceOptimized sol;
     vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
     int x = sol.removeDuplicates(nums);
     cout << "X" << x << endl;
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