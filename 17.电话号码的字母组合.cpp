/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
        {
            return result;
        }

        int size = digits.size();
        string line = "";
        check(result, line, digits, 0, size);

        return result;
    }

private:
    map<char, string> mps{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    void check(vector<string>& result, string line, string& digits, const int& pos, const int& size)
    {
        if (pos >= size)
        {
            result.emplace_back(line);
            return;
        }

        auto s = mps[digits[pos]];
        for (auto &c : s)
        {
            check(result, line + c, digits, pos + 1, size);
        }
    }
};
// @lc code=end

