

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Simple solution with O(n log n) time complexity
class SimpleAndBetterSolution {

public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = 1;
        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            // The current element can either remain unchanged or be
            // decremented to at most (previous element + 1). Choosing
            // the minimum ensures that the array remains valid while
            // maximizing the final answer.
            ans = min(arr[i], ans + 1);
        }

        return ans;
    }
};

// O(n) approach but more complex and takes more time in practice
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        unordered_map<int, int> mp;

        // Store the frequency of every element.
        for (int x : arr)
            mp[x]++;

        int maxValue = 1;
        int length = 0;

        /*
            noOfElementsToDecrease represents the number of missing values
            encountered so far that must be created by decrementing some
            larger duplicate elements.

            For example, if 4 and 5 are missing, then
            noOfElementsToDecrease = 2, meaning two larger duplicate
            elements must later be decreased to generate 4 and 5.
        */
        int noOfElementsToDecrease = 0;

        int n = arr.size();

        for (int i = 1; length < n; i++) {

            int count = mp.count(i) ? mp[i] : 0;

            // If the current value occurs once or is absent,
            // exactly one position in the final array corresponds to i.
            if (count <= 1) {

                length++;

                // If i is missing, it must be created later by
                // decrementing a larger duplicate element.
                if (count == 0)
                    noOfElementsToDecrease++;
            }
            else {

                /*
                    Case 1:
                    The current value has enough duplicates to fill all
                    previously missing values.

                    Example:
                    arr = [6,6,6,1,2,3,6]

                    By the time we reach i = 6,
                    values 4 and 5 are missing.

                    noOfElementsToDecrease = 2
                    count = 4

                    Two of the 6's can be decremented to create 4 and 5.
                    The remaining (count - noOfElementsToDecrease) copies
                    of 6 stay unchanged in the final array.
                */
                if (count > noOfElementsToDecrease) {

                    length += count - noOfElementsToDecrease;

                    // All missing values have now been generated.
                    noOfElementsToDecrease = 0;
                }
                else {

                    /*
                        Case 2:
                        The number of missing values is greater than or
                        equal to the duplicates available at the current value.

                        Example:
                        arr = [1,6,6,6,7,7,7,7]

                        Missing values before reaching 6:
                        2,3,4,5

                        noOfElementsToDecrease = 4
                        count = 3

                        One copy of 6 remains as 6.
                        The remaining (count - 1) copies are decremented
                        to generate two missing values.

                        Therefore, reduce
                        noOfElementsToDecrease by (count - 1).
                    */
                    length += 1;
                    noOfElementsToDecrease -= (count - 1);
                }
            }

            // Since we process values in increasing order,
            // the last processed value is always the maximum
            // value achievable in the rearranged array.
            maxValue = i;
        }

        return maxValue;
    }
};
int main()
{

    Solution sol;
    vector<vector<int>> tsetCases = {
        {2, 2, 1, 2, 1},
        {100, 1, 1000},
        {1, 1, 1, 1, 1, 1, 1, 10},
        {73, 98, 9},
        {1, 2, 2, 2, 2, 2, 1000, 2000},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}};
    for (auto &test : tsetCases)
    {
        cout << sol.maximumElementAfterDecrementingAndRearranging(test) << endl;
    }
}