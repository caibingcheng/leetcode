/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            result += (n & 0x1);
            n = (n >> 1);
        }

        return result;
    }
};
// @lc code=end

