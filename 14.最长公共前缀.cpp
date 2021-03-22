/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        if (strs.size() <= 0){
            return result;
        }

        int min_size = INT_MAX;
        for (auto& s : strs) {
            if (s.size() < min_size)
            {
                min_size = s.size();
            }
        }

        for (int i = 0; i < min_size; i++)
        {
            char c = strs[0][i];
            bool is_ok = true;
            for (auto& s : strs)
            {
                if (s[i] != c)
                {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok)
            {
                result += c;
            }
            else
            {
                break;
            }
        }

        return result;
    }
};
// @lc code=end

