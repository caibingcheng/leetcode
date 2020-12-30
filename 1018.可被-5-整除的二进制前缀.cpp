 /*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int is_five = 0;
        for (auto &a : A)
        {
            is_five = ((is_five << 1) + a) % 10;
            ret.push_back((is_five % 5) == 0);
        }
        return ret;
    }
};
// @lc code=end

