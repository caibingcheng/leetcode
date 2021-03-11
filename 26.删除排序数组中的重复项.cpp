/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int size = nums.size();
        if (size < 1)
        {
            return 0;
        }

        int pre = move(nums[0]);
        int ret = 1;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] != pre)
            {
                pre = nums[i];
                ret++;
            }
        }

        return ret;
    }
};
// @lc code=end

