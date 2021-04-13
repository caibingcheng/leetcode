/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() < 2)
            return points.size();

        sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {
            return p1[0] < p2[0];
        });

        using RANGE = pair<int, int>;
        RANGE curange{INT_MIN, INT_MAX};
        int result = 1;
        for (auto &p : points) {
            if ((curange.first <= p[0] && p[0] <= curange.second) || (curange.first <= p[1] && p[1] <= curange.second))
            {
                curange.first = max(curange.first, p[0]);
                curange.second = min(curange.second, p[1]);
            }
            else
            {
                result++;
                curange = {p[0], p[1]};
            }
        }

        return result;
    }
};
// @lc code=end

