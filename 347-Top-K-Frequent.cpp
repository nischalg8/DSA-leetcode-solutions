#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;


// set approach sice only count is needed 
class Solution1 {
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

class Solution2{
    public: 
    vector<int> topKFrequent(vector<int>&nums, int k)
    {
        unordered_map<int, int> freqMap;
        for(int n:nums)
        {
            freqMap[n]++;
        }

        auto comp = [&freqMap](int a, int b)
        {
            return freqMap[a] > freqMap[b];
        };
        //decltype gives type of the comparator object and heap is initialized with the actual comparator object 
        priority_queue<int, vector<int>, decltype(comp)> heap(comp); 
        
        //O(N logK ) where N is the size of map and k is heap size  
        for(auto& it: freqMap)
        {
            //pushing O(logk) as size si reduced to K 
            heap.push(it.first);
            // popping to make sure the heap size is k instead of N 
            if(heap.size() > k) heap.pop(); // O(logk)
        }

        vector<int> topK(k);
        for(int i=k-1; i>=0; i--)
        {
            topK[i]=(heap.top());
            heap.pop();
        }
        return topK;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;

    vector<int> nums = {2,7, 7, 11,7,15, 15};
    vector<int> result1 = sol1.topKFrequent(nums, 2);
    vector<int> result2 = sol2.topKFrequent(nums, 2);
    for(int x: result1)
    {
        cout<<x<<endl;
    }
    for(int x: result2)
    {
        cout<<x<<endl;
    }
}
