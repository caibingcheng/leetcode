/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        size_t size = intervals.size();
        if (size < 2){
            return intervals;
        }

        sort(intervals);
        vector<vector<int>> ret;
        int single[2];
        bool init = true,
             reset = false;
        for (int i = 0; i < size; i++)
        {
            if (init)
            {
                single[0] = intervals[i][0];
                single[1] = intervals[i][1];
                init = false;
            }
            else
            {
                if (single[1] < intervals[i][0])
                {
                    vector<int> s;
                    s.push_back(single[0]);
                    s.push_back(single[1]);
                    ret.push_back(s);

                    i--;
                    init = true;
                }
                else
                {
                    if (single[1] < intervals[i][1])
                        single[1] = intervals[i][1];
                }
            }
        }
        vector<int> s;
        s.push_back(single[0]);
        s.push_back(single[1]);
        ret.push_back(s);
        reset = true;

        return ret;
    }

private:
    void sort(vector<vector<int>>& intervals)
    {
        size_t size = intervals.size();
        for (int i = 0; i < (size - 1); i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (intervals[j][0] < intervals[i][0])
                {
                    swap(intervals[j], intervals[i]);
                }
            }
        }
    }
};
// @lc code=end

