#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution1{
    private:
    vector<int> countAndSumDigits(int x)
    {
        int count=0,sum=0,n=x;
        while(x>0)
        {
            int rem=x%10;
            sum+=rem*rem;
            x/=10;
            count++;
        }
        return {count, sum};
    }
    public:
     bool isHappy(int n)
    {
        unordered_set<int> set;
        vector<int> sumCount ={0,n};
        while (sumCount[0]!=1)
        {
            if(sumCount[1]==7 || sumCount[1]==1) return true;
            sumCount = countAndSumDigits(sumCount[1]);
        }
       // cout<<endl<<sumCount[0]<<" "<<sumCount[1]<<endl;
        
        return false;
    }
};
class Solution {
private:
    int sumDigits(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            int rem = x % 10;
            sum += rem * rem;
            x /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (!set.count(n))
        {
            if (n == 1) return true;

            set.insert(n);
            n = sumDigits(n);
        }
        return false;
    }
};

int main()
{
    Solution1 sol;
    vector<int> nums = {1,7,19,49,577,2,4,123,44,1000};

    for (int x : nums)
    {
        cout << x << " -> " << sol.isHappy(x) << endl;
    }
}