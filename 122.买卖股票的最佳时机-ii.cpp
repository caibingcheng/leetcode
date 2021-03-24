/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min = INT_MAX;
        for (auto& n : prices)
        {
            if (n <= min)
            {
                min = n;
            }
            else
            {
                result += (n - min);
                min = n;
            }
        }

        return result;
    }
};
// @lc code=end

