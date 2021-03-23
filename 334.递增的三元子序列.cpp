/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();

        if (size < 3)
        {
            return false;
        }

        pair<int, int> minp = {INT_MAX, INT_MAX};
        for (auto &n : nums)
        {
            if (n <= minp.first)
            {
                minp.first = n;
            } else if (n <= minp.second) {
                minp.second = n;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

