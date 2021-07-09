/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n == 1) || (n && !(m_mask & n));
    }

private:
    int m_mask = 0xaaaaaaab;
};
// @lc code=end

