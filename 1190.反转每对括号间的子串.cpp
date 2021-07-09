/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        size_t pos = 0;
        size_t n = s.size();

        if (n <= 1)
        {
            return s;
        }

        stack<size_t> st;
        for (pos = 0; pos < n; pos++){
            auto& c = s[pos];
            if (c == '(')
            {
                st.push(pos);
            }
            else if (c == ')')
            {
                auto tp = st.top();
                st.pop();
                reverse(s, tp + 1, pos - 1);
            }
        }

        return remove(s);
    }

private:
    void reverse(string &s, size_t start, size_t end){
        while(start < end)
        {
            swap(s[start++], s[end--]);
        }
    }

    string remove(string &s)
    {
        string ret = "";
        for (auto &c : s)
        {
            if (c != '(' && c != ')')
            {
                ret += c;
            }
        }

        return move(ret);
    }
};
// @lc code=end

