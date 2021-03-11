/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1)
        {
            return true;
        }

        bool can = false;
        int gap = 1;
        for (int i = size - 2; i >= 0; i--)
        {
            if (nums[i] >= gap)
            {
                gap = 1;
                can = true;
            }
            else
            {
                gap++;
                can = false;
            }
        }

        return can;
    }
};
// @lc code=end

