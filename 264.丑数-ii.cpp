/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 1)
        {
            return 1;
        }

        auto min = [] (const int &a, const int &b) -> int {
            return a < b ? a : b;
        };

        int ans[n];
        ans[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++)
        {
            int ai2 = ans[i2] * 2;
            int ai3 = ans[i3] * 3;
            int ai5 = ans[i5] * 5;
            ans[i] = min(min(ai2, ai3), ai5);
            if (ans[i] == ai2) i2++;
            if (ans[i] == ai3) i3++;
            if (ans[i] == ai5) i5++;
        }

        return ans[n - 1];
    }
};
// @lc code=end

