/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w, l;
        w = l = sqrt(area);

        int n_area = w * l;
        while(n_area != area)
        {
            if (n_area < area)
            {
                l++;
                n_area += w;
            }
            else
            {
                w--;
                n_area -= l;
            }
        }
        return {l, w};
    }
};
// @lc code=end

