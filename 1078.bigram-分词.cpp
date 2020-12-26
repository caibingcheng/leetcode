/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string fs = first + " " + second + " ";
        vector<string> ret;
        string s = "";
        int size = text.size();
        int fsize = fs.size();
        if (size <= fsize)
        {
            return ret;
        }

        for (int i = 0; i < size; i++)
        {
            if ((((i > 0) && (text[i - 1] == ' ')) ||
                (i == 0)) &&
                match(text, fs, i, (i + fsize)) &&
                next(text, s, (i + fsize), size))
            {
                ret.emplace_back(s);
                s = "";
            }
        }

        return ret;
    }

private:
    bool match(string &text, string &fs, const int &s, const int &e)
    {
        for (int i = s, j = 0; i < e; i++, j++)
        {
            if (text[i] != fs[j]){
                return false;
            }
        }
        return true;
    }
    bool next(string &text, string &t, const int &s, const int &e)
    {
        for (int i = s; (text[i] != ' ') && (i < e); i++)
        {
            t += text[i];
        }
        return !t.empty();
    }
};
// @lc code=end

