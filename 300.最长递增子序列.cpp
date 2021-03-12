/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
        {
            return 1;
        }

        vector<int> lisof;
        lisof.reserve(size);
        lisof.push_back(1);

        for (int i = 1; i < size; i++)
        {
            int max = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if ((nums[i] > nums[j]) && (lisof[j] > max))
                {
                    max = lisof[j];
                }
            }
            lisof.push_back(max + 1);
        }

        int max = 0;
        for (int lisn : lisof)
        {
            cout << lisn << endl;
            if (lisn > max)
            {
                max = lisn;
            }
        }

        return max;
    }
};
// @lc code=end

