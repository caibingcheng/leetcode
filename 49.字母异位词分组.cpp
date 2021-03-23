/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mps;

        for (auto& str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            mps[s].emplace_back(str);
        }

        vector<vector<string>> result;
        for (auto& mp:mps) {
            result.emplace_back(mp.second);
        }

        return result;
    }
};
// @lc code=end

