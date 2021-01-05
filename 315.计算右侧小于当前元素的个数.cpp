/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ls;
        size_t size = nums.size() - 1;

        stack<int> left, right;
        for (int i = size; i >= 0; i--)
        {
            if (ls.empty())
            {
                ls.push_back(0);
                left.push(nums[i]);
            }
            else
            {
                while (nums[i] < left.top())
                {
                    right.push(left.top());
                    left.pop();
                }
                left.push(nums[i]);
            }
        }
        reverse(ls.begin(), ls.end());

        return ls;
    }
};
// @lc code=end

