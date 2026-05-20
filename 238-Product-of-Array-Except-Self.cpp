#include <iostream>
#include <vector>
using namespace std;

// // O(m^2)
class SolutionBruteForce
{
public:
    vector<int> productExceptSelf(vector<int> nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int pro = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                pro *= nums[j];
            }
            ans[i] = pro;
        }

        return ans;
    }
};

// /*
// one major con in going with this method is when we have an element as 0 in our array.
// The problem is that, we can't perform a division by 0, as a result,
// we won't be able to get corresponding values in our final answer array
//  for the indices having 0 in our initial array at that position.

// The Time Complexity of this approach would be O(n).*/

class SolutionByDivision
{
public:
    vector<int> productExceptSelf(vector<int> nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);

        // To
        int productWithoutZeros = 1;
        int countZeros = 0, indexZero;
        for (int i = 0; i < n; i++)
        {
            if (nums[i]== 0)
            {
                countZeros++;
                indexZero = i;
            }
            else
            {
                productWithoutZeros *= nums[i];
            }
        }

        if (countZeros > 1)
            return ans;
    
        else if (countZeros == 1)
            ans[indexZero] = productWithoutZeros;
    
        else
        {
            for (int i = 0; i < n; i++)
                ans[i] = productWithoutZeros / nums[i];
        }
        return ans;
    }
};

// // Using Prefix and Suffix Multiplication O(n) time and space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> prefixProduct(n, 1);
        vector<int> suffixProduct(n, 1);
        vector<int> result(n);

        // prefixProduct
        for (int i = 1; i < n; i++)
        {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }
        // suffixProduct
        for (int i = n - 2; i >= 0; i--)
        {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++)

        {
            result[i] = prefixProduct[i] * suffixProduct[i];
        }
        return result;
    }
};
// time O(n) and extra space O(1) except the answer array
class OptimizedSolution
{

public:
    vector<int> productExceptSelf(vector<int> nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefProduct = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = prefProduct;
            prefProduct *= nums[i];
        }

        int suffProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= suffProduct;
            suffProduct *= nums[i];
        }
        return result;
    }
};

int main()
{
    OptimizedSolution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3, 4},      // Example 1
        {-1, 1, 0, -3, 3}, // Example 2
        {5},               // Single element
        {2, 3},            // Two elements
        {0, 1, 2, 3},      // One zero
        {0, 0, 2, 3},      // Two zeros
        {-1, -2, -3, -4},  // All negatives
        {1, -1, 1, -1},    // Mixed signs
        {10, 20, 30},      // Larger positives
        {1, 1, 1, 1}       // All same
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        vector<int> nums = testCases[i];
        vector<int> result = sol.productExceptSelf(nums);

        cout << "Test Case " << i + 1 << endl;

        cout << "Input: [";
        for (int j = 0; j < nums.size(); j++)
        {
            cout << nums[j];
            if (j != nums.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;

        cout << "Output: [";
        for (int j = 0; j < result.size(); j++)
        {
            cout << result[j];
            if (j != result.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;

        cout << "---------------------" << endl;
    }

    return 0;
}