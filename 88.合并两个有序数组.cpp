/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start1 = m - 1;
        int start2 = n - 1;
        int start = m + n - 1;

        while(start1 >= 0 || start2 >= 0)
        {
            if (start1 >= 0 && start2 >= 0)
            {
                if (nums1[start1] > nums2[start2])
                {
                    nums1[start--] = nums1[start1--];
                }
                else
                {
                    nums1[start--] = nums2[start2--];
                }
            }
            else if(start1 >= 0)
            {
                nums1[start--] = nums1[start1--];
            }
            else if(start2 >= 0)
            {
                nums1[start--] = nums2[start2--];
            }
        }
    }
};
// @lc code=end

