/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        int count[size][2];
        for (int i = 0; i < size; i++)
        {
            count[i][0] = 0;
            count[i][1] = 0;
        }

        if (s[0] != '0')
        {
            count[0][0] = 1;
        }
        if (size <= 1)
        {
            return count[0][0];
        }

        for (int i = 1; i < size; i++)
        {
            if (s[i] == '0')
            {
                count[i][1] = 0;
            }
            else
            {
                count[i][0] += count[i - 1][1] + count[i - 1][0];
            }

            if (s[i - 1] == '0')
            {
                count[i][1] = 0;
            }
            else if (((s[i - 1] == '1') && (s[i] <= '9')) || ((s[i - 1] == '2') && (s[i] <= '6')))
            {
                count[i][1] = count[i - 1][0];
            }
            else
            {
                count[i][1] = 0;
            }
        }

        return count[size - 1][0] + count[size - 1][1];
    }
};
// @lc code=end

