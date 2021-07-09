/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    struct ROMA
    {
        char c;
        int val;
        int div;

        ROMA() : c(0), val(0), div(0) {}
        ROMA(const char &p1, const int &p2, const int &p3) : c(p1), val(p2), div(p3) {}
    };

    string intToRoman(int num)
    {
        ROMA roma[13] = {
            ROMA('I', 1, 0),
            ROMA('Q', 4, 0),
            ROMA('V', 5, 0),
            ROMA('W', 9, 0),
            ROMA('X', 10, 0),
            ROMA('E', 40, 0),
            ROMA('L', 50, 0),
            ROMA('R', 90, 0),
            ROMA('C', 100, 0),
            ROMA('T', 400, 0),
            ROMA('D', 500, 0),
            ROMA('Y', 900, 0),
            ROMA('M', 1000, 0),
        };

        int num_tmp = num;
        for (int i = 12; i >= 0; i--)
        {
            roma[i].div = num_tmp / roma[i].val;
            num_tmp = num_tmp % roma[i].val;
        }

        string result = "";
        auto update = [&result] (auto s, int cnt)
        {
            while(cnt-- > 0)
            {
                result += s;
            }
        };
        for (int i = 12; i >= 0; i--)
        {
            switch(roma[i].c)
            {
                case 'Q':
                    update("IV", roma[i].div);
                    break;
                case 'W':
                    update("IX", roma[i].div);
                    break;
                case 'E':
                    update("XL", roma[i].div);
                    break;
                case 'R':
                    update("XC", roma[i].div);
                    break;
                case 'T':
                    update("CD", roma[i].div);
                    break;
                case 'Y':
                    update("CM", roma[i].div);
                    break;
                default:
                    update(roma[i].c, roma[i].div);
                    break;
            }
        }

        return result;
    }
};
// @lc code=end
