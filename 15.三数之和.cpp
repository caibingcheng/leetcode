/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        int sign_pos = 0;
        for(int& n : nums)
        {
            if(n >= 0)
            {
                sign_pos = n;
            }
        }
        int start = sign_pos;
        int end = nums.size();
    }
};
// @lc code=end
