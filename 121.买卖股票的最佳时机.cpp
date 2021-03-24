/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max_result = 0;
        for (auto & p : prices) {
            if (p < min)
            {
                min = p;
            }
            else
            {
                int ans = p - min;
                if (ans > max_result)
                    max_result = ans;
            }
        }

        return max_result;
    }
};
// @lc code=end

