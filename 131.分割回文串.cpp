/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> line;
        part(result, line, s, 0, 1, false);
        return result;
    }

private:
    void part(vector<vector<string>>& result, vector<string> line, const string& s, int start, int end, bool ok)
    {
        if (end > s.size())
        {
            if (!line.empty() && ok)
            {
                result.push_back(line);
            }
            return;
        }
        if (isOK(s, start, end))
        {
            string str = "";
            for (int i = start; i < end; i++)
            {
                str += s[i];
            }
            vector<string> nl(line);
            nl.emplace_back(str);
            part(result, nl, s, end, end + 1, end >= s.size());
        }
        else if (end >= s.size())
        {
            return;
        }
        part(result, line, s, start, end + 1, false);
    }

    bool isOK(const string& s, int start, int end)
    {
        bool isok = true;
        while (start < end)
        {
            if (s[start++] != s[--end])
            {
                isok = false;
                break;
            }
        }

        return isok;
    }
};
// @lc code=end

