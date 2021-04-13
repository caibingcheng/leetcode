/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        int sh = haystack.size();
        int sn = needle.size();
        if (sh < sn)
            return -1;

        unordered_map<char, int> badmps;
        // cout << "badmps" << endl;
        badChar(badmps, needle);
        // cout << "badChar" << endl;
        vector<int> sufix;
        vector<bool> prefix;
        goodMatch(sufix, prefix, needle);
        // cout << "goodMatch" << endl;

        int i = 0;
        while (i <= (sh - sn))
        {
            int j = sn - 1;
            int mlen = 0;
            char bad_char = 0;
            while (j >= 0)
            {
                if (haystack[i + j] != needle[j])
                {
                    bad_char = haystack[i + j];
                    break;
                }
                mlen++;
                j--;
            }
            if (mlen >= sn)
            {
                return i;
            }

            int pos = sn - mlen - 1;
            int bad_step = badMove(badmps, bad_char, pos);
            int good_step = goodMove(sufix, prefix, mlen, pos);
            int step = max(bad_step, good_step);
            if (step < 0) step = sn;
            i += (step > 0 ? step : 1);
        }

        return -1;
    }

private:
    void badChar(unordered_map<char, int> &badmps, const string &pstr)
    {
        int size = pstr.size();
        for (int i = 0; i < size; i++)
        {
            //badmps代表的是模式串的字符的最右位置
            badmps[pstr[i]] = i;
        }
    }

    int badMove(unordered_map<char, int> &badmps, const char &badc, const int &pos)
    {
        //尽管可能是负数, 但是我们并不是很当心
        //1. 负数可以用右移一位代替
        //2. 增加复杂度, 不匹配模式串最右匹配, 而是匹配模式串以坏字符为界的右子串的最右匹配
        return badmps.find(badc) != badmps.end() ? pos - badmps[badc] : -1;
    }

    void goodMatch(vector<int> &sufix, vector<bool> &prefix, const string &pstr)
    {
        int size = pstr.size();
        sufix.reserve(size);
        prefix.reserve(size);
        for (int i = 0; i < size; ++i)
        {
            //sufix[i]表示长度为i的子串的位置, 需要注意, 长度为i的子串是唯一的.
            //-1则时不存在这个子串
            sufix[i] = -1;
            //prefix[i]表示这个子串是不是在头部
            prefix[i] = false;
        }

        int pstr_max_index = size - 1;
        //不需要遍历整个模式串, 因为长度满的时候, 必定没有其他子串
        for (int i = 0; i < pstr_max_index; i++)
        {
            //是遍历的初始位置, 从右向左
            int j = i;
            //k用来记录子串的长度
            int k = 0;

            //这样我们拿到的sufix总是最右的
            while ((j >= 0) && (pstr[j] == pstr[pstr_max_index - k]))
            {
                sufix[++k] = j--;
            }

            if (j < 0)
            {
                prefix[k] = true;
            }
        }
    }

    int goodMove(const vector<int> &sufix, const vector<bool> &prefix, const int &mlen, const int &pos)
    {
        if (mlen < 1)
            return -1;
        int move_len = 0;
        int size = sufix.size();
        move_len = sufix[mlen];
        if (move_len < 0)
        {
            for (int i = mlen - 1; i > 0; i--)
            {
                if (prefix[i] == true)
                {
                    move_len = sufix[i];
                    break;
                }
            }
        }

        return pos - move_len;
    }
};
// @lc code=end
