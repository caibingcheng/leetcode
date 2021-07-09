/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 */

// @lc code=start
/**
 *
 * 小于一个数m的丑数个数是 m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
 *
 *
 * **/
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long ab = lcm<long>(a, b);
        long ac = lcm<long>(a, c);
        long bc = lcm<long>(b, c);
        long abc = lcm<long>(ab, c);

        long l = min({a, b, c});
        long h = min(n * l, MAX);

        while(l <= h)
        {
            int m = (l + h) / 2;
            long nn = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
            // n == nn 的范围很大, 所以还需要一直缩小, 取到最小边界, 最小边界是刚好满足整除的.
            if (nn < n)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }

        return l;
    }

private:
    const long MAX = 2000000000;
};
// @lc code=end

