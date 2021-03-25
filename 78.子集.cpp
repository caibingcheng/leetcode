/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> line;

        check(result, line, nums, 0);

        return result;
    }

private:
    void check(vector<vector<int>>& result, vector<int> line, vector<int>& nums, const int& pos) {
        if (pos >= nums.size())
        {
            result.emplace_back(line);
            return;
        }
        check(result, line, nums, pos + 1);
        line.emplace_back(nums[pos]);
        check(result, line, nums, pos + 1);
    }
};
// @lc code=end

