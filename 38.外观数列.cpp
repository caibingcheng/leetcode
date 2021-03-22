/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        string last = "1";

        for (int i = 1; i < n; i++){
            int count = 0;
            char pre_c = pre[0];
            last = "";
            for (auto& c : pre)
            {
                if (c == pre_c)
                {
                    count++;
                }
                else
                {
                    last += (to_string(count) + pre_c);
                    pre_c = c;
                    count = 1;
                }
            }
            if (count > 0)
            {
                last += (to_string(count) + pre_c);
            }
            pre = last;
            cout << pre << endl;
        }

        return last;
    }
};
// @lc code=end

