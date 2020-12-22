/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (isPalin(s))
        {
            return s;
        }

        size_t len = s.size();
        string left = s.substr(0, len - 1);
        string right = s.substr(1, len - 1);
        string result_left = longestPalindrome(left);
        string result_right = longestPalindrome(right);

        return (result_left.size() >= result_right.size()) ? result_left : result_right;
    }

private:
    bool isPalin(string s)
    {
        bool ret = true;
        size_t len = s.size();
        if (len <= 1)
            return ret;

        len -= 1;
        for (size_t begin = 0; begin <= len; begin++)
        {
            if (s[begin] != s[len])
            {
                ret = false;
                break;
            }
            len--;
        }

        return ret;
    }
};
// @lc code=end
