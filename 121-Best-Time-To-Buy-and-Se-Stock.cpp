
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MySolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int begin = 0, maxProfit = 0, minBuy = INT_MAX;
        while (begin < prices.size() - 1)
        {
            int end = begin + 1;
            while (end < prices.size())
            {
                int profit = prices[end] - prices[begin];

                if(profit < 0 || prices[begin] > minBuy){
                    break;
                }
                if (profit > maxProfit)
                {
                    maxProfit = profit;
                }
                cout << "Begin: " << begin
                     << " End: " << end
                     << " Profit: " << profit << endl;

                end++;
            }

            begin++;
        }
        return maxProfit;
    }
};
class Solution
{ // kadane algorithm
public:
    int maxProfit(vector<int> &prices)
    {
        int begin = 0, maxProfit = 0, minBuy = prices[0];
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] < minBuy)
            {
                minBuy = prices[i];
            }
            else if((prices[i] - minBuy) > maxProfit) {
                maxProfit = prices[i] - minBuy;
        }
        }
        return maxProfit;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    cout << sol.maxProfit(nums) << endl;
}