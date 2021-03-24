/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        perm(result, nums, 0, nums.size());
        return result;
    }

private:
    void perm(vector<vector<int>>& result, vector<int> &nums, const int &start, const int &end) {
        if(start >= end){
            result.emplace_back(nums);
        }
        for (int i = start; i < end; i++) {
            swap(nums[start], nums[i]);
            perm(result, nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
};
// @lc code=end

