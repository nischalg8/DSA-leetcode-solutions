#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        // the frequency of every number.
        for(int num: nums)
            mp[num]++;
        
        int longestSubset = 0;

       for(int num: nums)
        {
            int currentSubset = 0;

            // Special handling for 1 since all of its powers are 1.
            // We can only use an odd number of 1's.
            if(num == 1)
            {
                currentSubset = mp[1] % 2 ? mp[1] : mp[1] - 1;
                longestSubset = max(currentSubset, longestSubset);
                continue;
            }

            // Keep extending the sequence while the current value
            // appears at least twice (needed for symmetric placement).
            while(num <= 1000000000L && mp[num] > 1)
            {
                currentSubset += 2;

                // Stop if squaring would exceed the maximum possible value. that is 1e-9
                if(num > 1000000000L / num)
                {
                    // The current value becomes the last valid element.
                    currentSubset--;
                    break;
                }

                // Move to the next power: x -> x².
                num *= num;

                // Next power doesn't exist.
                // Previous value is the last element of the sequence.
                if(mp[num] == 0)
                {
                    currentSubset--;
                    break;
                }

                // Next power occurs only once, so it can only be
                // placed at the center of the sequence.
                else if(mp[num] == 1)
                {
                    currentSubset++;
                    break;
                }
            }

            // If no valid chain was formed, the number itself
            // forms a sequence of length 1.
            currentSubset = !currentSubset ? 1 : currentSubset;

            longestSubset = max(longestSubset, currentSubset);
        }

        return longestSubset;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> testCases ={
        {5,4,1,2,2},
        {1,3,2,4},
        {1,2,3},
        {1,1,1,1,1,1,1,1,1,1,2,4,8,16,32,64,128,256,512,1024},
        {2,2,2,4,3,6,9,3,2},
        {14,14,196,196,38416,38416},
    };

    for(auto &vec: testCases )
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Case : "<<endl<<sol.maximumLength(vec)<<endl;
    }
}