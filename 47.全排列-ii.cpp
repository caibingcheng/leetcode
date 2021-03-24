/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        perm(result, nums, 0, nums.size());

        return result;
    }

private:
    void perm(vector<vector<int>> &result, vector<int> &nums, const int &s, const int &e)
    {
        if (s >= e)
        {
            result.emplace_back(nums);
        }
        for (int i = s; i < e; i++)
        {
            if (isRepeat(nums, s, i))
                continue;
            swap(nums[i], nums[s]);
            perm(result, nums, s + 1, e);
            swap(nums[i], nums[s]);
        }
    }

    bool isRepeat(vector<int>& nums, const int& s, const int &e)
    {
        for (int i = s; i < e; i++)
        {
            if (nums[i] == nums[e])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

