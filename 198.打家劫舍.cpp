/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int house_count = nums.size();

        if (house_count <= 0)
        {
            return 0;
        }

        //                    yes  no
        using ROBORNOT = pair<int, int>;
        vector<ROBORNOT> robber;
        robber.reserve(house_count);

        //                    yes      no
        robber[0] = make_pair(nums[0], 0);

        for (int i = 1; i < house_count; i++)
        {
            //yes
            robber[i].first = robber[i - 1].second + nums[i];

            //no
            robber[i].second = max(robber[i - 1].first, robber[i - 1].second);
        }

        return max(robber[house_count - 1].first, robber[house_count - 1].second);
    }
};
// @lc code=end

