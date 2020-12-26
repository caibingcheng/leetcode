/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int end = height.size() - 1;
        int start = 0;
        int ans = 0;
        int ans_tmp = 0;

        while (start < end)
        {
            if (height[start] > height[end])
            {
                ans_tmp = height[end] * (end - start);
                if (ans_tmp > ans)
                {
                    ans = ans_tmp;
                }
                end--;
            }
            else
            {
                ans_tmp = height[start] * (end - start);
                if (ans_tmp > ans)
                {
                    ans = ans_tmp;
                }
                start++;
            }
        }

        return ans;
    }
};
// @lc code=end
