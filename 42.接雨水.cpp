/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> wall;
        int peak = 0;
        int water = 0;

        auto min = [](const int &a, const int &b){
            return a < b ? a : b;
        };

        auto wh = [&height] (const int &i) {
            return height[i];
        };

        auto wt = [&wall] () {
            return wall.top();
        };

        for (int i = 0; i < height.size(); i++)
        {
            int ch = height[i];
            while (!wall.empty() && ch > wh(wt()))
            {
                int sh = wh(wt());
                wall.pop();
                if (wall.empty())
                    break;

                int d = i - wt() - 1;
                water += d * (min(ch, wh(wt())) - sh);
            }
            wall.push(i);
        }

        return water;
    }
};
// @lc code=end

