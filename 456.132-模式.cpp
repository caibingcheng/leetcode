/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> a12;
        stack<int> a13;
        stack<int> a32;

        for (int &a : nums)
        {
INIT:
            if (a12.empty() && a13.empty())
            {
                a12.push(a);
                a13.push(a);
            }
            else
            {
                if (a12.size() == 1)
                {
                    a32.push(a);
                }
                pushmM(a, a12);


                if (a12.size() < 2){
                    a12.clear();
                    a13.clear();
                    a32.clear();
                    goto INIT;
                }

                if (a12.size() == 2)
                {
                    pushmM(a, a13);
                    pushMm(a, a32);
                }
            }

        }
    }

private:
    void pushmM(const int &a, stack<int> &b)
    {
        if (a > b.top())
        {
            b.push(a);
        }
    }
    void pushMm(const int &a, stack<int> &b)
    {
        if (a < b.top())
        {
            b.push(a);
        }
    }
};
// @lc code=end

