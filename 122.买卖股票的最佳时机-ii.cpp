/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int sum = 0;
        for (int i = 0; i < size; i++){
            for (int j = i + 1; j < size; j++)
            {
                if (prices[j] > prices[i])
                {
                    sum += (prices[j] - prices[i]);
                    i++;
                    break;
                }
            }
        }
        return sum;
    }
};
// @lc code=end

