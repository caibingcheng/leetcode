/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int max = -1;
        size_t size = nums.size() - 1;
        for (size_t i = size; i > 0; i--)
        {
            if ((nums[i] - nums[i - 1]) > max)
            {
                max = (nums[i] - nums[i - 1]);
            }
        }

        return max;
    }
};
// @lc code=end

