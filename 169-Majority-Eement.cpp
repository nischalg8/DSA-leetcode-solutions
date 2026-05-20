#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0, count = 0;
        for (int x : nums)
        {
            if (count == 0)
            {
                candidate = x;
            }
            if (x == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 2, 1, 1, 1, 2};

    cout << sol.majorityElement(nums) << endl;
}