/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // vector<int> sum_cnt(nums.size() + 1, 0);
        int *sum_cnt = new int[nums.size() + 1]();
        sum_cnt[0] = 1;
        int result = 0, sum = 0;
        for(auto& n : nums)
        {
            sum += n;
            int check = sum - goal;
            if (check >= 0)
            {
                result += sum_cnt[check];
            }
            sum_cnt[sum]++;
        }

        delete []sum_cnt;
        return result;
    }
};
// @lc code=end

