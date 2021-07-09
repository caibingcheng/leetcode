/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        int gc[] = {2, 3, 5};
        for (auto &c : gc){
            while(n % c == 0)
            {
                n /= c;
            }
        }
        return n == 1;
    }
};
// @lc code=end

