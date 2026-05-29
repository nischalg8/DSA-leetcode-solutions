#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// O(n^3) time
class SolutionBruteForce
{

private:
    bool hasNextConsecutiveElement(vector<int> &nums, int target)
    {
        // if there is at least one element equal to target then return true else false
        for (int x : nums)
        {
            if (x == target)
                return true;
        }
        return false;
    }

public:
    int longestConsecutive(vector<int> &nums)
    {

        int longestConsecutiveSequence = 0;
        int current, currSequence;
        for (int i = 0; i < nums.size(); i++)
        {
            current = nums[i];
            currSequence = 1;

            while (hasNextConsecutiveElement(nums, current + 1))
            {
                current++;
                currSequence++;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currSequence);
        }
        return longestConsecutiveSequence;
    }
};

// O(nlogn)
class SolutionBySorting
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());
        int longestConsecutiveSequence = 1;
        int currentNumber = nums[0];
        int currentSequence = 1;
        for (int i = 1; i < nums.size(); i++)
        {

            if (nums[i] == currentNumber)
            {
                continue;
            }

            else if (nums[i] == currentNumber + 1)
            {
                currentSequence++;
                currentNumber++;
            }
            else
            {
                currentNumber = nums[i];
                currentSequence = 1;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentSequence);
        }
        return longestConsecutiveSequence;
    }
};

// O(n)
class SolutionHashTable
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longestConsecutiveSequence = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for (int num : st)
        {
            // if the number is the smallest in the sequence then only run loop
            if (st.count(num - 1) == 0)
            {
                int currentNumber = num;
                int currentSequence = 1;
                // Since we only start from the smallest element, each sequence
                // is explored exactly once, keeping the solution O(n).
                while (st.count(currentNumber + 1))
                {
                    currentNumber++;
                    currentSequence++;
                }
                longestConsecutiveSequence = max(currentSequence, longestConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};
int main()
{
    
    SolutionBruteForce sol1;
    SolutionBySorting sol2;
    SolutionHashTable sol3;
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> nums3 = {1, 0, 1, 2};

    cout << sol1.longestConsecutive(nums1) << endl;
    cout << sol1.longestConsecutive(nums2) << endl;
    cout << sol1.longestConsecutive(nums3) << endl;
    cout << sol2.longestConsecutive(nums1) << endl;
    cout << sol2.longestConsecutive(nums2) << endl;
    cout << sol2.longestConsecutive(nums3) << endl;
    cout << sol3.longestConsecutive(nums1) << endl;
    cout << sol3.longestConsecutive(nums2) << endl;
    cout << sol3.longestConsecutive(nums3) << endl;
}