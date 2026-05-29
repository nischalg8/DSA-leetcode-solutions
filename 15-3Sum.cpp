
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

class SolutionBruteForce
{

public:
    // O(n^3) * O(logk) k--> no. of unique triplets that are actually sorted
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        // O(1) for sort because always three eleements are begin sorted
                        sort(temp.begin(), temp.end());
                        // O(logK) for K is the no. of unique triplets in the array which is variable
                        // set is used by sorting to make sure the same triplet are not used used twice in the result
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
// using two loops and for third element using hashing

// entire array cannot be taken into hashset or hashmap
// because there might me multiple elements in the array eg. -1 at index 0 and index 3
// to solve this we use a set and store in set  only as we move forward
// two loops to find two elements and for third we look into hashset so O(1)
// time: O(n^2 )
class SolutionSlightlyBetter
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        { // unordered set to make sure the third loop not required
            unordered_set<int> un_set;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(nums[i] + nums[j]);
                if (un_set.count(third))
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // sorting and storing vector in template so we do not conside the same triplet again
                }
                un_set.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
class Solution
{
    // helper not used in this implementation but kept for compatibility

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // to make sure unique triplets is taken
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                long sum = (long)nums[i] + nums[l] + nums[r];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r++;
                }
                else if (sum < 0)
                {
                    l++;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                }
                else
                {
                    r--;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            };
        }
        return result;
    }
}; // BUt still using set which requires extra time complexity

int main()
{
    SolutionBruteForce sol;
    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, 4},
        {-2, 2, 0, 1, 3, -1, -2},
        {0, -1, 1},
        {0, 0, 0},
        {1, 2, 3},
    };
    for (vector<int> &testArr : testCases)
    {
        vector<vector<int>> answers = sol.threeSum(testArr);

        for (vector<int> &elems : answers)
        {
                for(int elem: elems)
                {
                    cout<<elem<<" ";
                }
                cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }
}
