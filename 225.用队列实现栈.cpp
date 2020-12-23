/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        m_size = 32;
        m_mem = new int[m_size];
        m_top = 0;
    }

    ~MyStack() {
        delete[] m_mem;
        m_mem = nullptr;
    }

    /** Push element x onto stack. */
    void push(int x) {
        if (m_top >= m_size)
        {
            resize();
        }

        m_mem[m_top] = x;
        m_top++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (m_top > 0)
        {
            m_top--;
        }
        return m_mem[m_top];
    }

    /** Get the top element. */
    int top() {
        int top = m_top;
        if (top > 0)
        {
            top--;
        }
        return m_mem[top];
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return (m_top == 0);
    }

private:
    int *m_mem = nullptr;
    int m_size = 0;
    int m_top = 0;

    void resize(){
        int new_size = m_size * 1.5;
        int *new_mem = new int[new_size];
        memcpy(new_mem, m_mem, m_size * sizeof(int));

        delete[] m_mem;
        m_mem = new_mem;
        m_size = new_size;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

