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
        string ret = "";
        int start = 0;
        int end = s.size();

        for (; start < end; ++start)
        {
            const char &c = s[start];

            if (ret.empty())
            {
                const char &topC = c;
                ifPush(ret, start, end, c, topC, true);
                continue;
            }

            if (hasS(ret, c))
            {
                continue;
            }

            const char &topC = topS(ret);
            if (!ifPush(ret, start, end, c, topC))
            {
                pushS(ret, c);
            }
        }

        return ret;
    }

private:
    bool ifPush(string &s, const int &start, const int &end, const char &c, const char &topC, bool m=false)
    {
        bool is_same = false;
        bool is_less = true;
        bool is_push = false;
        if (c <= topC)
        {
            int i = start + 1;
            while (i < end)
            {
                if (topC == s[i])
                {
                    is_same = true;
                }
                if (topC > s[i])
                {
                    is_less = false;
                }
                if ((!m || is_less) && is_same)
                {
                    is_push = true;
                    break;
                }
                i++;
            }

            if (is_push)
            {
                popS(s);
                pushS(s, c);
            }
        }
        return is_push;
    }

    const char &topS(const string &s)
    {
        return s.back();
    }

    void popS(string &s)
    {
        if (s.size() > 0)
            s.pop_back();
    }

    void pushS(string &s, const char &c)
    {
        s += c;
    }

    bool hasS(string &s, const char &c)
    {
        bool ret = false;
        for (char &_c : s)
        {
            if (c == _c)
            {
                ret = true;
            }
        }
        return ret;
    }
};
// @lc code=end
