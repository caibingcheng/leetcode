/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        end = coins.size();
        sort(coins.begin(), coins.end(), greater<int>());

        return nCoinChange(coins, 0, amount, 0);
    }

private:
    int min = INT_MAX;
    int start = -1;
    int end = -1;

    int nCoinChange(vector<int> &coins, const int &start, const int &amount, const int &count)
    {
        if ((min > count) && (start < end))
        {
            for (int i = start; i < end; i++)
            {
                int c = coins[i];
                int ac = amount / c;
                for (int j = ac; j >= 0; j--)
                {
                    int nc = j + count;
                    if (min < nc)
                    {
                        return min;
                    }
                    int am = amount - j * c;
                    if (am == 0)
                    {
                        if (min > nc)
                        {
                            min = nc;
                        }
                        return min;
                    }
                    nCoinChange(coins, i + 1, am, nc);
                }
            }
        }
        return (min == INT_MAX) ? -1 : min;
    }
};
// @lc code=end
