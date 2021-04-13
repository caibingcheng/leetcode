/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        vector<int> l2r(size, 1);
        vector<int> r2l(size, 1);

        for (int i = 1; i < size; i++)
        {
            l2r[i] = nums[i - 1] * l2r[i - 1];
        }
        for (int i = size - 2; i >= 0; i--)
        {
            r2l[i] = nums[i + 1] * r2l[i + 1];
        }
        for(int i = 0; i < size; i++)
        {
            result[i] = l2r[i] * r2l[i];
        }

        return result;
    }
};
// @lc code=end

