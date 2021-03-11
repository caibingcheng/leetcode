/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int pos = 0;
        pos = clearBlank(s, pos);
        if (pos < 0)
        {
            return 0;
        }

        bool sign = getSign(s[pos]);
        pos = moveToFirstNumber(s, pos);
        if (pos < 0)
        {
            return 0;
        }

        long long int ret = 0;
        int num = nextNumber(s, pos);
        while (num >= 0)
        {
            cout << num << endl;
            ret = ret * 10 + num;
            num = nextNumber(s, pos);

            if (ret > INT_MAX)
            {
                return sign ? INT_MIN : INT_MAX;
            }
        }

        return sign ? -ret : ret;
    }

private:
    int clearBlank(const string &s, int &pos)
    {
        pos = 0;
        for (auto &c : s)
        {
            if (c == ' ')
            {
                pos++;
            }
            else if (isNumber(c) || isSignChar(c))
            {
                return pos;
            }
            else
            {
                break;
            }
        }
        return -1;
    }

    bool isSignChar(const char& c)
    {
        return c == '+' || c == '-';
    }

    bool getSign(const char &c)
    {
        return (c == '-');
    }

    int moveToFirstNumber(const string &s, int &pos)
    {
        const int size = s.size();
        if (isNumber(s[pos]) || ((++pos < size) && isNumber(s[pos])))
        {
            return pos;
        }
        return -1;
    }

    bool isNumber(const char &c)
    {
        return ('0' <= c) && (c <= '9');
    }

    int nextNumber(const string &s, int &pos)
    {
        const int size = s.size();
        if ((pos < size) && isNumber(s[pos]))
        {
            return s[pos++] - '0';
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
