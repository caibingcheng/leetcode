/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        if (n < 1){
            return result;
        }

        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (i % 3 == 0) {
                s = "Fizz";
            }
            if (i % 5 == 0) {
                s = "Buzz";
            }
            if (i % 15 == 0) {
                s = "FizzBuzz";
            }
            result.emplace_back(s);
        }

        return result;
    }
};
// @lc code=end

