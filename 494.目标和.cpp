/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        s = nums.size();
        sums = new int[s + 1];
        zsums = new int[s + 1];
        zsums[s] = 1;
        sums[s] = 0;
        for (int i = s - 1; i >= 0; i--)
        {
            sums[i] = nums[i] + sums[i + 1];
            if (nums[i] == 0)
            {
                zsums[i] = 2 * zsums[i + 1];
            }
            else
            {
                zsums[i] = zsums[i + 1];
            }
        }

        findTargetSumWays(nums, 0, S);
        delete []sums;
        delete []zsums;

        return count;
    }

private:
    int count = 0;
    int s = 0;
    int *sums;
    int *zsums;
    void findTargetSumWays(vector<int>& nums, const int &start, const int &S)
    {
        if (start >= s)
        {
            return;
        }
        if (abs(S) > sums[start])
        {
            return;
        }
        if (abs(S) == sums[start])
        {
            count += zsums[start];
            return;
        }
        findTargetSumWays(nums, start + 1, S - nums[start]);
        findTargetSumWays(nums, start + 1, S + nums[start]);
    }
};
// @lc code=end

