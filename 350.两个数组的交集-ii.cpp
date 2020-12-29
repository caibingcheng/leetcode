/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (!nums1.empty() && !nums2.empty())
        {
            if (nums1.back() > nums2.back())
            {
                nums1.pop_back();
            }
            else if (nums1.back() < nums2.back())
            {
                nums2.pop_back();
            }
            else
            {
                ret.push_back(nums1.back());
                nums1.pop_back();
                nums2.pop_back();
            }
        }

        return ret;
    }
};
// @lc code=end
