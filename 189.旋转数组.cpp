/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = nums.size();
        int size = count;
        int pos = 0;
        int start_pos = pos;
        int tmp = nums[pos];
        while((count--) > 0)
        {
            pos = (pos + k) % size;
            swap(tmp, nums[pos]);
            if (start_pos == pos)
            {
                pos++;
                pos = pos % size;
                start_pos = pos;
                tmp = nums[pos];
            }
        }
    }
};
// @lc code=end

