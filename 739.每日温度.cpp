/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
//emperatures = [73, 74, 75, 71, 69, 72, 76, 73] [1, 1, 4, 2, 1, 1, 0, 0]。
// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        stack<int> t;
        int s = T.size();
        vector<int> d(s);

        for (int i = s - 1; i >= 0; i--)
        {
            while (!t.empty() && T[i] >= T[t.top()])
            {
                t.pop();
            }
            if (!t.empty())
            {
                d[i] = t.top() - i;
            }
            else
            {
                d[i] = 0;
            }
            t.push(i);
        }

        return d;
    }
};
// @lc code=end
