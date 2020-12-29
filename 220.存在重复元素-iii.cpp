/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution
{
public:
    typedef long long int LLI;
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int size = nums.size();
        for (int i = 0; i < size - k; i++)
        {
            for (int j = i + 1; (j <= i + k) && (j < size); j++)
            {
                LLI d = abs(LLI(nums[i]) - LLI(nums[j]));
                if (d <= LLI(t))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
