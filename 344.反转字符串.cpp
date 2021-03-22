/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int start = 0;
        int end = size - 1;
        while(start < end)
        {
            swap(s[start++], s[end--]);
        }
    }
};
// @lc code=end

