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
        const static char brackets_table[][2] = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}};
        auto is_match = [=](const char &a, const char &b) -> bool {
            bool match = false;
            for (int i = 0; i < 3; i++)
            {
                match = ((a == brackets_table[i][0]) && (b == brackets_table[i][1]));
                if (match)
                {
                    return match;
                }
            }
            return match;
        };
        auto is_left = [=](const char &a) -> bool {
            for (int i = 0; i < 3; i++)
            {
                if (a == brackets_table[i][0])
                {
                    return true;
                }
            }
            return false;
        };
        auto is_right = [=](const char &a) -> bool {
            for (int i = 0; i < 3; i++)
            {
                if (a == brackets_table[i][1])
                {
                    return true;
                }
            }
            return false;
        };

        stack<char> ss;
        for (const char &c : s)
        {
            if (ss.empty())
            {
                if (is_left(c))
                {
                    ss.push(c);
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (is_left(c))
                {
                    ss.push(c);
                    continue;
                }
                if (is_right(c))
                {
                    if (is_match(ss.top(), c))
                    {
                        ss.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return ss.empty();
    }
};
// @lc code=end
