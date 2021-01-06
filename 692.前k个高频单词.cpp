/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        using UMSI = unordered_map<string, int>;
        using UMSIT = UMSI::iterator;

        UMSI smap;
        for (auto &s : words){
            if (smap.find(s) == smap.end())
            {
                smap.emplace(s, 0);
            }
            else
            {
                smap[s]++;
            }
        }

        auto cmp = [](UMSIT ita, UMSIT itb){
            bool is_sum_greater = (ita->second) > (itb->second);
            bool is_sum_equal = (ita->second) == (itb->second);
            bool is_string_less = strcmp((ita->first).c_str(), (itb->first).c_str()) < 0;
            return is_sum_greater ? is_sum_greater : (is_sum_equal ? is_string_less : false);
        };

        auto cmp2 = [](UMSIT ita, UMSIT itb){
            bool is_sum_greater = (ita->second) < (itb->second);
            bool is_sum_equal = (ita->second) == (itb->second);
            bool is_string_greater = strcmp((ita->first).c_str(), (itb->first).c_str()) > 0;
            return is_sum_greater ? is_sum_greater : (is_sum_equal ? is_string_greater : false);
        };

        UMSIT topK[k + 2];
        int initK = 0;
        for (UMSIT it = smap.begin(); it != smap.end(); it++)
        {
            if (initK < k)
            {
                topK[initK] = it;
            }
            else
            {
                if (initK == k)
                {
                    make_heap(topK, &topK[k], cmp);
                }

                if (cmp(it, topK[0]))
                {
                    topK[k] = it;
                    pop_heap(topK, &topK[k + 1], cmp);
                }
            }
            initK++;
        }

        vector<string> ret(k);
        make_heap(topK, &topK[k], cmp2);
        for (int i = 0; i < k; i++)
        {
            int j = k + 1 - i;
            ret[i] = topK[0]->first;
            pop_heap(topK, &topK[j - 1], cmp2);
        }

        return ret;
    }
};
// @lc code=end

