/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        auto r2n = [](const char& c){
            switch (c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };

        int ret = 0;
        char pre = 'M';
        for (auto& c : s) {
            int num_pre = r2n(pre);
            int num_c = r2n(c);

            if (num_pre < num_c)
            {
                ret -= num_pre * 2;
            }
            ret += num_c;
            pre = c;
        }

        return ret;
    }
};
// @lc code=end

