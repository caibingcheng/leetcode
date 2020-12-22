/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string max_str = "";
        unsigned int max_counts = 0;
        for (char &c : s){
            unsigned int len = 0;
            for (char &mc : max_str){
                len ++;
                if (mc == c){
                    max_str.erase(0, len);
                    break;
                }
            }
            max_str += c;
            if (max_str.size() > max_counts)
            {
                max_counts = max_str.size();
            }
        }
        return max_counts;
    }
private:   
};
// @lc code=end

