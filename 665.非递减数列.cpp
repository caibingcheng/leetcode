/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */



// 1, 3, 4, 5
// 1, 3, 2, 4
// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return true;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] <= nums[i + 1]) continue;
            cnt++;
            if (cnt > 1) return false;
            if (i > 0 && nums[i - 1] > nums[i + 1])
            {
                nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};
// @lc code=end
