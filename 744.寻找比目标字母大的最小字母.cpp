/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ret = 'z' + 1;
        bool is_ok = false;
        for (auto &c : letters)
        {
            if (c > target && c < ret)
            {
                ret = c;
                is_ok = true;
            }
        }

        return is_ok ? ret : letters[0];
    }
};
// @lc code=end

