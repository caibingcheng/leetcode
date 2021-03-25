/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    using POS = pair<int, int>;
    int numIslands(vector<vector<char>> &grid)
    {
        map<POS, int> mps;

        int result = 0;
        int row = grid.size();
        if (row < 1)
        {
            return result;
        }
        int col = grid[0].size();
        if (row < 1)
        {
            return result;
        }

        set<POS> islands;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == '1')
                {
                    islands.insert({r, c});
                }
            }
        }

        while(!islands.empty())
        {
            result++;
            POS pos = *begin(islands);
            check(islands, pos);
        }

        return result;
    }

private:
    void check(set<POS>& islands, const POS& pos)
    {
        if(islands.find(pos) != islands.end())
        {
            islands.erase(pos);
            check(islands, {pos.first - 1, pos.second});
            check(islands, {pos.first, pos.second - 1});
            check(islands, {pos.first + 1, pos.second});
            check(islands, {pos.first, pos.second + 1});
        }
    }
};
// @lc code=end
