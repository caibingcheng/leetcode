/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((nums[j] <= nums[i]) && ((i - j) > result))
                {
                    result = i - j;
                }
            }
        }

        return result;
    }
};
// @lc code=end

