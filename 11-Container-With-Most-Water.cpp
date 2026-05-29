#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size()-1;
        int n = height.size() - 1;
        int largestArea = 0;
        while (left < right)
        {
            int area = (right-left)* min(height[left], height[right]);
            largestArea = max(area, largestArea);
            
            if(height[left] < height[right]) 
                left++;
            else 
                right--;
        }
        return largestArea;
    }
};

int main()
{
    Solution sol;
#include <vector>
    using namespace std;

    vector<vector<int>> testHeights = {
        {1, 8, 6, 2, 5, 4, 8, 3, 7}, // Leetcode example
        {1, 1},                      // minimum size
        {4, 3, 2, 1, 4},             // equal tall ends
        {1, 2, 1},                   // small symmetric
        {1, 2, 4, 3},                // increasing then drop
        {1, 2, 3, 4, 5},             // strictly increasing
        {5, 4, 3, 2, 1},             // strictly decreasing
        {2, 2, 2, 2},                // all equal
        {1, 100, 1, 100, 1},         // tall middle walls
        {1, 3, 2, 5, 25, 24, 5}, // max near right
       {10, 1, 10},                 // equal tall ends
          {0, 0, 0, 0},                // all zero
          {0, 2, 0, 4, 0},             // with zeros
        {6, 9, 3, 4, 5, 8},          // mixed heights
          {1, 1000, 1000, 1}           // huge equal middle

    };

    vector<int>
        expected = {
            49,  // min(8,7)*7
            1,   // min(1,1)*1
            16,  // min(4,4)*4
             2,   // min(1,1)*2
            4, // min(2,3)*2
            6, // min(2,5)*3
            6, // min(5,2)*3
            6,   // min(2,2)*3
            200, // min(100,100)*2
            24, // min(25,24)*1
            20,  // min(10,10)*2
            0,   // no height
            4,   // min(2,4)*2
            32,  // min(9,8)*4
            1000 // min(1000,1000)*1
        };

    for (int i = 0; i < testHeights.size(); i++)
    {
        int ans = sol.maxArea(testHeights[i]);

        cout << "Test " << i + 1
             << ": got = " << ans
             << ", expected = " << expected[i] << endl;
    }
}     