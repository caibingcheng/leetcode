/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1 || n == 2)
        {
            return false;
        }

        while(n > 3)
        {
            if (n % 3 != 0)
            {
                return false;
            }
            n /= 3;
            if (n == 2)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

