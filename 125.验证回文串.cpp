/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int start = 0;
        int end = size - 1;

        auto lowChar = [](const char& c)
        {
            char nc = c;
            if ('A' <= c && c <= 'Z')
            {
                nc = (c - 'A' + 'a');
            }
            return nc;
        };

        auto isCharOK = [&lowChar](const char& c)
        {
            char nc = lowChar(c);
            return ('a' <= nc && nc <= 'z') ||
                   ('0' <= nc && nc <= '9');
        };

        auto isMatch = [&lowChar](const char& c1, const char& c2)
        {
            return lowChar(c1) == lowChar(c2);
        };

        while(end > start)
        {
            if (!isCharOK(s[start]))
            {
                start++;
                continue;
            }
            if(!isCharOK(s[end]))
            {
                end--;
                continue;
            }
            if (!isMatch(s[start], s[end]))
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end

