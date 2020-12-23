/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        string dir;
        for (auto &c : path)
        {
            if (isValid(c))
            {
                dir += c;
            }
            else
            {
                check(dir, dirs);
            }
        }
        check(dir, dirs);

        while(!dirs.empty()){
            dir = ("/" + dirs.top()) + dir;
            dirs.pop();
        }

        if (dir.empty())
        {
            dir = "/";
        }

        return dir;
    }

private:
    bool isBack(const string &dir)
    {
        return (".." == dir);
    }

    bool isCurrent(const string &dir)
    {
        return ("." == dir);
    }

    bool isValid(const char &c)
    {
        return ('/' != c);
    }

    void check(string &dir, stack<string> &dirs)
    {
        if (!dir.empty())
        {
            if (isBack(dir))
            {
                if (!dirs.empty())
                {
                    dirs.pop();
                }
            }
            else
            {
                if (!isCurrent(dir))
                {
                    dirs.push(dir);
                }
            }
            dir = "";
        }
    }
};
// @lc code=end

