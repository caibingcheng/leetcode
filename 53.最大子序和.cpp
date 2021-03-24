/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last_result = nums[0];
        int max_result = last_result;
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            int cand_cur_result = nums[i] + last_result;
            if (cand_cur_result > nums[i])
            {
                last_result = cand_cur_result;
            }
            else
            {
                last_result = nums[i];
            }
            if (last_result > max_result)
            {
                max_result = last_result;
            }
        }

        return max_result;
    }
};
// @lc code=end

