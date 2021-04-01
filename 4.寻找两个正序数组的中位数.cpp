/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        int cleft = (m + n - 1) / 2;
        int cright = (((m + n) % 2) == 0) ? (m + n) / 2 : cleft;

        auto pnum1 = begin(nums1), enum1 = end(nums1);
        auto pnum2 = begin(nums2), enum2 = end(nums2);
        int sum = 0;
        int pos = 0;

        auto fillsum = [&sum, &pos, &cleft, &cright](const int &n) {
            if (pos == cright)
            {
                sum += n;
            }
            if (pos == cleft)
            {
                sum += n;
            }
        };

        int target = 0;
        while (pos <= cright)
        {
            if (pnum1 != enum1 && pnum2 != enum2)
            {
                if (*pnum1 < *pnum2)
                {
                    target = *pnum1;
                    pnum1++;
                }
                else
                {
                    target = *pnum2;
                    pnum2++;
                }
            }
            else if (pnum1 != enum1)
            {
                target = *pnum1;
                pnum1++;
            }
            else if (pnum2 != enum2)
            {
                target = *pnum2;
                pnum2++;
            }
            fillsum(target);
            pos++;
        }

        double result = (double)sum / 2;

        return result;
    }
};
// @lc code=end
