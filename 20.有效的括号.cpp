/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty() || (s.size() & 1))
        {
            return false;
        }

        bool ret = true;
        stack<char> cs;
        for (char &c : s)
        {
            if (isLeft(c))
            {
                cs.push(c);
            }
            else if (isRight(c))
            {
                if (!cs.empty())
                {
                    if (!isMatch(cs.top(), c))
                    {
                        ret = false;
                    }
                    cs.pop();
                }
                else
                {
                    ret = false;
                }
                if (!ret)
                {
                    break;
                }
            }
        }

        if (!cs.empty())
        {
            ret = false;
        }

        return ret;
    }

private:
    bool isLeft(const char &c)
    {
        return (c == '(') || (c == '[') || (c == '{');
    }
    bool isRight(const char &c)
    {
        return (c == ')') || (c == ']') || (c == '}');
    }
    bool isMatch(const char &a, const char &b)
    {
        return ((a == '(') && (b == ')')) ||
               ((a == '[') && (b == ']')) ||
               ((a == '{') && (b == '}'));
    }
};
// @lc code=end
