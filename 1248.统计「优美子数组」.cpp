/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int *cnt = new int[nums.size() + 1]();
        cnt[0] = 1;
        int result = 0, sum = 0;
        for (auto &n : nums){
            sum += n & 1;
            int check = sum - k;
            if (check >= 0)
            {
                result += cnt[check];
            }
            cnt[sum]++;
        }

        delete[] cnt;
        return result;
    }
};
// @lc code=end

