/*
 * @lc app=leetcode.cn id=1787 lang=cpp
 *
 * [1787] 使所有区间的异或结果为零
 */

// @lc code=start
// 参考题解:
/**
 * xor的结果总是0-1024, 所以状态方程是前i个数, xor结果是mask的最少次数, mask的值域是0-1024,
 * 所以第i+1次xor的结果[0-1024]是, 前i个数的结果与当前改变某个值的次数和的最小
 *
**/
class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        //xor值为0-NMAX的改变次数, 初始化为nums.size()
        int n = nums.size();
        vector<int> f(NMAX, n);
        f[0] = 0;

        for (int i = 0; i < k; i++)
        {
            unordered_map<int, int> cnts;
            int size = 0; // 一组的数量
            // mod k 分组
            for (int j = i; j < n; j += k)
            {
                int x = nums[j];
                if (cnts.find(x) == cnts.end())
                {
                    cnts[x] = 0;
                }
                // 统计一个组每个值的个数, 方便计算变换的次数
                cnts[x]++;
                size++;
            }

            // 上一次最少的
            int lastmin = *min_element(begin(f), end(f));

            //初始化本次mask为0-NMAX的最少次数都是lastmin
            //这里蕴含了不改变的情况
            vector<int> nf(NMAX, lastmin);
            for (int mask = 0; mask < NMAX; mask++)
            {
                //只需要改为某个相同的数字
                for (auto [x, cnt] : cnts)
                {
                    // cout << x << " " << cnt << endl;
                    //最新的, 等于 上一次为mask ^ x的加上这次改为x的数量
                    nf[mask] = min(nf[mask], f[mask ^ x] - cnt); //-size
                    //这里不要先加size, 因为会有初始化问题, 所以要后面加size
                }
            }
            for_each(begin(nf), end(nf), [&size](auto &v) { v += size; });

            f = move(nf);
        }

        return f[0];
    }

private:
    // nums[i]最大值, 也是状态方程的最大范围
    const int NMAX = 1 << 10;
};

// @lc code=end
