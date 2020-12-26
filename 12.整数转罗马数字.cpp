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
        ROMA roma[7] = {
            ROMA('I', 1, 0),
            ROMA('V', 5, 0),
            ROMA('X', 10, 0),
            ROMA('L', 50, 0),
            ROMA('C', 100, 0),
            ROMA('D', 500, 0),
            ROMA('M', 1000, 0)
        };

        int num_tmp = num;
        for (int i = 6; i >= 0; i--)
        {
            roma[i].div = num_tmp / roma[i].val;
            num_tmp = num_tmp % roma[i].val;
        }

        //每个div一定小于5
        string result = "";
        for (int i = 6; i >= 0; i--)
        {
            int div = roma[i].div;
            if ((div > 0) && (div < 4))
            {
                for (int j = 0; j < div; j++)
                {
                    result += roma[i].c;
                }
            }
            else if (div > 3)
            {
                result += roma[i].c;
                result += roma[i + 1].c;
            }
        }

        return result;
    }
};
// @lc code=end
