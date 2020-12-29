/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        for (auto &n : nums1)
        {
            s1.insert(n);
        }
        for (auto &n : nums2)
        {
            s2.insert(n);
        }

        vector<int> ret;
        for (auto &n : s2)
        {
            auto b = s1.insert(n);
            if (!b.second)
            {
                ret.emplace_back(n);
            }
        }
        return ret;
    }
};
// @lc code=end

