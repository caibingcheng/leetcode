/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string ret = "";

        if (zero(nums))
        {
            ret = "0";
            return ret;
        }

        vector<string> nums_str;
        toStr(nums_str, nums);
        sort(nums_str.begin(), nums_str.end(), isGreater());

        for (string &s : nums_str)
        {
            ret += s;
        }
        return ret;
    }

private:
    bool zero(vector<int> &nums)
    {
        for (int &a : nums)
        {
            if (a != 0)
            {
                return false;
            }
        }
        return true;
    }

    void toStr(vector<string> &nums_str, vector<int> &nums)
    {
        for (int &a : nums)
        {
            string b = to_string(a);
            nums_str.push_back(b);
        }
    }

    class isGreater
    {
    public:
        bool operator()(string &a, string &b)
        {
            string ab = a + b;
            string ba = b + a;

            int size = ab.size();

            for (int i = 0; i < size; i++)
            {
                if (ab[i] > ba[i])
                {
                    return true;
                }
                else if (ab[i] < ba[i])
                {
                    return false;
                }
            }
            return true;
        }
    };
};
// @lc code=end
