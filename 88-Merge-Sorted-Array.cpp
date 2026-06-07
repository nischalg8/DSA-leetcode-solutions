#include <iostream>
#include <vector>

using namespace std;
/*
    from problems like insert into sorted arrays by preserving order, merging sorted arrays by preserving order
    it is best to start from rear end of array as no need to move the next element after adding the new element
    and no need to overwrite as starting from last we need to worry for next element which is at second last only.
*/
class Solution
{

    public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {

            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }\
        while(j>=0)
            nums1[k--]  = nums2[j--];
    }
};
int main()
{
    Solution sol;
    vector<int> nums1={1,2,3,0,0,0};

    vector<int> nums2={2,5,6};

    sol.merge(nums1,3, nums2,3);
    for(int x: nums1)
    {
        cout<<x<<" ";
    }

}