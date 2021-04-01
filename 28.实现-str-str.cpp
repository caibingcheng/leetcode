/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int sh = haystack.size();
        int sn = needle.size();
        if (sh < sn)
            return -1;

        for (int i = 0; i <= (sh - sn); i++)
        {
            bool is_ok = true;
            for (int j = 0; j < sn; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

