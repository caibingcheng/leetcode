/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int result = 0;
        int pos = 0;
        int size = chars.size();

        char pre = chars[0];
        int count = 0;
        while(pos < size) {
            if (chars[pos] == pre)
            {
                count++;
            }

            if (chars[pos] != pre)
            {
                chars[result++] = pre;
                if (count > 1)
                {
                    string nums = to_string(count);
                    for (char& c : nums)
                    {
                        chars[result++] = c;
                    }
                }
                pre = chars[pos];
                count = 1;
            }

            pos++;
        }
        chars[result++] = pre;
        if (count > 1)
        {
            string nums = to_string(count);
            for (char& c : nums)
            {
                chars[result++] = c;
            }
        }

        return result;
    }
};
// @lc code=end

