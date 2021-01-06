/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        size_t size = nums.size();
        const size_t max_k = k > size ? size : k;

        int heap[max_k + 2];
        for (int i = 0; i < max_k; i++)
        {
            heap[i] = nums[i];
        }
        auto cmp = [] (int &a, int &b){
            return a > b;
        };
        make_heap(&heap[0], &heap[max_k], cmp);

        // auto ct = [&](){
        //     for (auto &a : heap)
        //     {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // };

        // ct();

        if (max_k == size)
        {
            return heap[0];
        }

        for (int i = max_k; i < size; i++)
        {
            if (nums[i] >= heap[0])
            {
                heap[max_k] = nums[i];
                pop_heap(&heap[0], &heap[max_k + 1], cmp);
                // ct();
            }
        }

        return heap[0];
    }
};
// @lc code=end

