/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();

        if (size1 > size2) return false;

        int ss1 = 0, e1 = size1;
        int ss2 = 0, e2 = size2 - e1 + 1;

        unordered_map<char, int>mps, mps_tmp;
        for (auto &c : s1)
        {
            if(mps.find(c) == mps.end())
            {
                mps[c] = 1;
            }
            else
            {
                mps[c]++;
            }
        }

        for (int i = ss2; i < e2; i++)
        {
            mps_tmp = mps;
            bool is_ok = true;
            for (int j = ss1; j < e1; j++)
            {
                char c = s2[i + j];
                if(mps_tmp.find(c) != mps_tmp.end())
                {
                    mps_tmp[c]--;
                }
                else
                {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok)
            {
                for(auto& mp : mps_tmp)
                {
                    if(mp.second != 0)
                    {
                        is_ok = false;
                        break;
                    }
                }
            }
            if (is_ok)
                return true;
        }

        return false;
    }
};
// @lc code=end

