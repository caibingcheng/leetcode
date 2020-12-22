/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        size_t vlen = nums.size();

        typedef pair<size_t, size_t> PA;
        map<int, vector<PA>> tadd, tdes;

        for (size_t i = 0; i < (vlen - 1); i++)
        {
            for (size_t j = i; j < vlen; j++)
            {
                int itadd = nums[i] + nums[j];
                int itdes = target - itadd;
            }
        }
    }
};
// @lc code=end

