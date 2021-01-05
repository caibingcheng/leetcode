/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        size_t size = citations.size() - 1;
        int h = 0;

        for (int i = size; i >= 0; i--)
        {
            if (((size - i + 1) >= h) && (citations[i] >= ((size - i) + 1)))
            {
                h = (size - i) + 1;
            }
            else
            {
                break;
            }
        }

        return h;
    }
};
// @lc code=end

