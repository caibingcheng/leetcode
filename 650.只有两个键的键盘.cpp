/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        if (n <= 1)
        {
            return 0;
        }

        vector<int> dp;
        dp.reserve(n + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            for (int j = i / 2; j > 0; j--)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + 1 + (i - j) / j;
                    break;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

