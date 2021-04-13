/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            result += (n-- - nums[i]);
        }

        return result;
    }
};
// @lc code=end

