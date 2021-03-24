/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
        {
            return 0;
        }

        vector<bool> bits;
        bits.reserve(n + 1);
        for (int i = 0; i < n; i++)
        {
            bits[i] = false;
        }

        bits[0] = true;
        bits[1] = true;
        bits[2] = false;

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (bits[i] == false)
            {
                result++;
                int j = i + i;
                while (j < n)
                {
                    bits[j] = true;
                    j += i;
                }
            }
        }

        return result;
    }
};
// @lc code=end

