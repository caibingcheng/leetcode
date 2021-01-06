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
            return 1;

        int m = 1, s = 1;
        int mp = cm(s++);
        while((m + mp) < n)
        {
            m += mp;
            mp = cm(s++);
        }
        s--;

        auto max = [](const int &a, const int &b) -> int{
            return (a > b) ? a : b;
        };

        int mn = n - m;
        int i = max(s - mn + 1, 0);
        int k = max(mn - s - 1, 0);
        int j = max(mn - 1, 0);

        cout << mn << " " << m << " " << s << " " << i << " " << j << " " << k << endl;

        return pow(2, i) * pow(3, j) * pow(5, k);
    }

private:
    int cm(const int &m)
    {
        return ((m + 1) * (m + 2)) >> 1;
    }
};
// @lc code=end

