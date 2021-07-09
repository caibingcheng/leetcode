/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution
{
public:
    //ax + by = z ?
    bool canMeasureWater(int x, int y, int z)
    {
        if ((x + y) < z) return false;
        long long mx = max(x, y);
        long long my = min(x, y);

        //int a = 0;  //a >= 0
        long long b = 0;  //b <= 0

        //a = (z - by) / x;
        for (b = 0; b > -mx; b--)
        {
            if ((z - b * y) % x == 0)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
