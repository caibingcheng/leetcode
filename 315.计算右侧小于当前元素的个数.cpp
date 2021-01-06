/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> ls(nums.size());
        size_t size = nums.size() - 1;

        MyStack left(nums.size()), right(nums.size());
        for (int i = size; i >= 0; i--)
        {
            if (ls.empty())
            {
                ls[i] = 0;
                left.push(nums[i]);
            }
            else
            {
                while (!left.empty() && nums[i] <= left.top())
                {
                    right.push(left.pop());
                }
                while (!right.empty() && nums[i] > right.top())
                {
                    left.push(right.pop());
                }
                ls[i] = left.size();
                left.push(nums[i]);
            }
        }
        return ls;
    }

private:
    class MyStack
    {
    public:
        /** Initialize your data structure here. */
        MyStack(const int &size)
        {
            m_size = size;
            m_mem = new int[m_size];
            m_top = 0;
        }

        ~MyStack()
        {
            delete[] m_mem;
            m_mem = nullptr;
        }

        /** Push element x onto stack. */
        void push(int x)
        {
            if (m_top >= m_size)
            {
                resize();
            }

            m_mem[m_top] = x;
            m_top++;
        }

        /** Removes the element on top of the stack and returns that element. */
        int pop()
        {
            if (m_top > 0)
            {
                m_top--;
            }
            return m_mem[m_top];
        }

        /** Get the top element. */
        int top()
        {
            int top = m_top;
            if (top > 0)
            {
                top--;
            }
            return m_mem[top];
        }

        int size() { return m_top; }

        /** Returns whether the stack is empty. */
        bool empty() { return (m_top == 0); }

    private:
        int *m_mem = nullptr;
        int m_size = 0;
        int m_top = 0;

        void resize()
        {
            int new_size = m_size * 1.5;
            int *new_mem = new int[new_size];
            memcpy(new_mem, m_mem, m_size * sizeof(int));

            delete[] m_mem;
            m_mem = new_mem;
            m_size = new_size;
        }
    };
};
// @lc code=end
