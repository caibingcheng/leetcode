/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int cleft = (m + n - 1) / 2;
        int cright = (m + n) / 2;

        auto pnum1 = begin(nums1), enum1 = end(nums1);
        auto pnum2 = begin(nums2), enum2 = end(nums2);
        int sum = 0;
        int pos = 0;
        while(pos <= cright)
        {
            if(pnum1 != enum1)
            {
                pnum1++;
            }
            if(pnum2 != enum2)
            {
                pnum2++;
            }

            pos++
        }
    }
};
// @lc code=end

