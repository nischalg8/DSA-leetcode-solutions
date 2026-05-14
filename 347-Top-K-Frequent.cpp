#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// set approach sice only count is needed 
class Solution {
    public: 
    vector<int> topKFrequent(vector<int>& nums, int k )
    {
        unordered_map<int, int> freqMap;

        for(int n: nums)
        {
            freqMap[n]++;
        }

        // as unordered_map doesnt support sort
        vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());

        sort(freqVec.begin(), freqVec.end(), [](auto a, auto b)
        {
            return a.second> b.second;
        });

        vector<int> topKFreq;

         for (size_t i = 0; i < k; i++) {
            topKFreq.push_back(freqVec[i].first);
        }
        return topKFreq;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7, 7, 11,7,15, 15};
    vector<int> result = sol.topKFrequent(nums, 2);
    for(int x: result)
    {
        cout<<x<<endl;
    }
}
