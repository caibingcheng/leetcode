/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int sum = 0;
        for (auto &c : costs)
        {
            if (coins >= c)
            {
                coins -= c;
                sum++;
            }
            else
            {
                break;
            }
        }
        return sum;
    }
};
// @lc code=end

