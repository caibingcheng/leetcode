/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> s;
        int k = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int a = nums[i];

            if (a < k)
                return true;

            while (!s.empty() && a > s.top())
            {
                k = s.top();
                s.pop();
            }
            s.push(a);
        }

        return false;
    }
};
// @lc code=end
