/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();

        int pre = 0;
        for (int i = 0; i < k; i++)
        {
            pre += nums[i];
        }
        int max = pre;
        for (int i = k; i < n; i++)
        {
            pre = pre + nums[i] - nums[i - k];
            if (pre > max)
                max = pre;
        }

        return double(max) / k;
    }
};
// @lc code=end
