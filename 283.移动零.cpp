/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                for(int j = i + 1; j < size; j++)
                {
                    if (nums[j] != 0)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};
// @lc code=end

