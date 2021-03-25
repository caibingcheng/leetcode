/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 1)
        {
            return -1;
        }

        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if (check(nums, i - 1, i , i + 1))
            {
                return i;
            }
        }

        return -1;
    }

private:
    bool check(vector<int>& nums, const int& posl, const int& pos, const int& posr) {
        bool is_okl = (posl < 0) || (nums[posl] < nums[pos]);
        bool is_okr = (posr >= nums.size()) || (nums[posr] < nums[pos]);

        return is_okl && is_okr;
    }
};
// @lc code=end

