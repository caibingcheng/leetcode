/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() < 1)
            return {-1, -1};

        int end = nums.size() - 1;
        int start = 0;

        while (start <= end)
        {
            if (nums[start] != target)
            {
                if (start < nums.size() - 1)
                  start++;
            }
            if (nums[end] != target)
            {
                if (end > 0)
                    end--;
            }
            if (nums[start] == nums[end])
                break;
        }

        return (nums[start] == target) ? vector<int>{start, end} : vector<int>{-1, -1};
    }
};
// @lc code=end
