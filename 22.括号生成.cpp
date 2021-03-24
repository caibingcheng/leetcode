/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        for (int i = 0; i < n; i++)
        {
            str += "()";
        }

        vector<string> result;
        prim(result, str, 0, 2 * n);

        return result;
    }

private:
    void prim(vector<string>& result, string &str, const int &s, const int &e){
        if (!isOK(str))
        {
            return;
        }
        if (s >= e)
        {
            result.emplace_back(str);
        }

        for (int i = s; i < e; i++)
        {
            if (isRepeat(str, s, i))
                continue;
            swap(str[i], str[s]);
            prim(result, str, s + 1, e);
            swap(str[i], str[s]);
        }
    }

    bool isOK(string &str)
    {
        int l = 0;
        int r = 0;
        for (char& c : str)
        {
            if (c == '(')
            {
                l++;
            }
            else
            {
                r++;
            }
            if (r > l)
            {
                return false;
            }
        }
        return true;
    }

    bool isRepeat(string &str, const int &s, const int &e){
        for (int i = s; i < e; i++)
        {
            if (str[i] == str[e])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

