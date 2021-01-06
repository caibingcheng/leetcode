/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        char cs[128] = {0};
        for (auto &c : s)
        {
            cs[c]++;
        }

        string rs = "";
        for (int i = 0; i < 128; i++)
        {
            if (cs[i] > 0)
            {
                for
            }
        }
    }
};
// @lc code=end

