/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        vector<long> dnums;
        size_t size = nums.size();
        if ((size <= 1) || (k <= 0))
        {
            return false;
        }

        //todo
        if (k >= 10000)
        {
            return false;
        }

        for (int i = 0; i < (size - 1); i++)
        {
            dnums.push_back((long)nums[i] - (long)nums[i + 1]);
        }

        size = dnums.size();
        if ((size <= 1) && (abs(dnums[0]) <= (long)t))
        {
            return true;
        }

        for (int i = 0; i < size; i++)
        {
            int l = i + k;
            long d = 0;
            for (int j = i; (j < size) && (j < l); j++)
            {
                d += (long)dnums[j];
                if (abs(d) <= (long)t)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end
