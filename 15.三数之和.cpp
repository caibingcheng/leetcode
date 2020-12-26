/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> less_zero;
        vector<int> zero;
        vector<int> great_zero;

        for (int &a : nums)
        {
            if (a > 0)
            {
                great_zero.push_back(a);
            }
            else if (a == 0)
            {
                zero.push_back(a);
            }
            else if (a < 0)
            {
                less_zero.push_back(a);
            }
        }

        vector<int> single_ans;
        vector<vector<int>> result;

        if (zero.size() >= 3)
        {
            single_ans = vector<int>(0, 0, 0);
            result.push_back(single_ans);
        }



        return result;
    }
};
// @lc code=end
