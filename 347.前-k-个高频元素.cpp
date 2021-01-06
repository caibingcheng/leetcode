/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using MKV = unordered_map<int, int>;
        using MKVIT = MKV::iterator;
        MKV sum;

        for (auto &n : nums){
            if (sum.find(n) != sum.end())
            {
                sum[n]++;
            }
            else
            {
                sum.emplace(n, 1);
            }
        }

        MKVIT topK[k + 2];
        auto cmp = [](MKVIT ita, MKVIT itb) {
            return (ita->second) > (itb->second);
        };

        int initK = k;
        for (MKVIT it = sum.begin(); it != sum.end(); it++)
        {
            if (initK > 0)
            {
                topK[k - initK] = it;
                initK--;
            }
            else
            {
                if (initK == 0)
                {
                    make_heap(topK, &topK[k], cmp);
                }
                if (cmp(it, topK[0]))
                {
                    topK[k] = it;
                    pop_heap(topK, &topK[k + 1], cmp);
                }
            }

        }

        vector<int> ret(k);
        for (int i = 0; i < k; i++)
        {
            ret[i] = topK[i]->first;
        }

        return ret;
    }
};
// @lc code=end

