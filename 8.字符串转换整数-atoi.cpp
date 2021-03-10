/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {

    }

private:
    bool m_hasloadsign = false;

    bool isFirstSign(const char& c)
    {
        if (!m_hasloadsign)
        {
            m_hasloadsign = (c == '+') || (c == '-') || isNumber(c);
        }
        return m_hasloadsign;
    }

    bool isNumber(const char& c)
    {
        return ((c >= '0') && (c <= '9'));
    }
};
// @lc code=end

