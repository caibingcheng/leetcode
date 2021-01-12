/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int ans;
        int **mp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            mp[i] = new int[n]();
        }

        mp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                int up = 0, left = 0;
                if ((i - 1) >= 0)
                {
                    up = mp[i - 1][j];
                }
                if ((j - 1) >= 0)
                {
                    left = mp[i][j - 1];
                }
                mp[i][j] = up + left;
            }
        }

        ans = mp[m - 1][n - 1];
        for (int i = 0; i < m; i++)
        {
            delete[] mp[i];
        }
        delete[] mp;

        return ans;
    }
};
// @lc code=end
