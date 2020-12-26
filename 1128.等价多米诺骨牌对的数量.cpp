/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int pack[10][10] = {0};
        for (vector<int> &vb : dominoes)
        {
            int m = min(vb[0], vb[1]);
            int n = max(vb[0], vb[1]);
            pack[m][n]++;
        }

        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                int p = pack[i][j];
                if (p > 1)
                {
                    sum += ((p * (p - 1)) / 2);
                }
            }
        }

        return sum;
    }
};
// @lc code=end

