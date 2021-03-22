/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        int size = nums.size();
        if (size < 3)
        {
            return ret;
        }

        sort(begin(nums), end(nums));
        // for_each(begin(nums), end(nums), [](const int& n){
        //     cout << n << " ";
        // });
        // cout << endl;

        // auto is_repeat = [&ret](const vector<int>& each){
        //     return end(ret) != find_if(begin(ret), end(ret), [&each](const vector<int>& ret_each){
        //         return ret_each[0] == each[0] && ret_each[1] == each[1];
        //     });
        // };

        if (nums[0] == 0 && nums[0] == nums[size-1])
        {
            vector<int> each;
            each.emplace_back(0);
            each.emplace_back(0);
            each.emplace_back(0);

            ret.emplace_back(each);
            return ret;
        }

        int pos1_end = size - 3;
        for (int pos1 = 0; pos1 <= pos1_end; pos1++){
            int num1 = -nums[pos1];
            int pos2 = pos1 + 1;
            int pos3 = size - 1;
            while(pos2 < pos3){
                int add23 = nums[pos2] + nums[pos3];
                if (add23 > num1)
                {
                    pos3--;
                }
                else if (add23 < num1)
                {
                    pos2++;
                }
                else
                {
                    // cout << pos1 << " " << pos2 << " " << pos3 << endl;

                    vector<int> each;
                    each.emplace_back(nums[pos1]);
                    each.emplace_back(nums[pos2]);
                    each.emplace_back(nums[pos3]);

                    // if (!is_repeat(each))
                    // {
                    //     ret.emplace_back(each);
                    // }

                    ret.emplace_back(each);

                    // break;
                    pos2++;
                    pos3--;
                }
            }
        }

        set<vector<int>> st(ret.begin(), ret.end());
        ret.assign(st.begin(), st.end());

        return ret;
    }
};
// @lc code=end
