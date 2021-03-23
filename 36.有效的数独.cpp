/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<10> bits;
        bits.reset();
        auto test = [&bits](const char& c){
            int pos = c - '0';
            cout << pos << " " << c << endl;
            if (bits.test(pos))
            {
                return false;
            }
            bits.set(pos);
            return true;
        };

        for (int i = 0; i < 9; i++)
        {
            bits.reset();
            for (int j = 0; j < 9; j++)
            {
                char& c = board[i][j];
                if ((c != '.') && !test(c))
                {
                    return false;
                }
            }
            bits.reset();
            for (int j = 0; j < 9; j++)
            {
                char& c = board[j][i];
                if ((c != '.') && !test(c))
                {
                    return false;
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                bits.reset();
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        char& c = board[i * 3 + k][j * 3 + l];
                        if ((c != '.') && !test(c))
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

