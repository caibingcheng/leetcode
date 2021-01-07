/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string rs = "";
        int size = s.size();

        for (int i = 0; i < size; i++)
        {
            if (rs.find(s[i]) != string::npos)
            {
                continue;
            }

            while(!rs.empty() && (rs.back() > s[i]) && (s.find(rs.back(), i) != string::npos))
            {
                rs.pop_back();
            }

            rs.push_back(s[i]);
        }

        return rs;
    }
};
// @lc code=end
