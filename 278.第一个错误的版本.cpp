/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 1)
            return 1;
        int start = 0;
        int end = n;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            bool is_bad_mid = isBadVersion(mid);
            if (is_bad_mid)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }
};
// @lc code=end

