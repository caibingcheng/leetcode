/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> counts{nums[0], 0};
        for (auto& n : nums)
        {
            if (n == counts.first)
            {
                counts.second++;
            }
            else
            {
                counts.second--;
            }

            if (counts.second < 0)
            {
                counts = {n, 1};
            }
        }

        return counts.first;
    }
};
// @lc code=end

