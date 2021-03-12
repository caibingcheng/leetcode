/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (!z)
        {
            return true;
        }
        return !(z % gcd(x, y));
    }

private:
    int gcd(int x, int y)
    {
        return (x && y) ? gcd(y, x % y) : max(x, y);
    }
};
// @lc code=end
