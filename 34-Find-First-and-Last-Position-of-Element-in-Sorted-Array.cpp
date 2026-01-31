#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int s = 0;
        int e = static_cast<int>(nums.size()) - 1;

        int ans1 = -1, ans2 = -1;

        // first occurrence
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans1 = mid;
                e = mid - 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        // last occurrence
        s = 0;
        e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans2 = mid;
                s = mid + 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return {ans1, ans2};
    }
};

int main() {
    vector<int> sortedArray = {3, 7, 8, 9, 10, 11};
    Solution sol;

    auto res = sol.searchRange(sortedArray, 8);
    cout << "[" << res[0] << ", " << res[1] << "]\n";
}
