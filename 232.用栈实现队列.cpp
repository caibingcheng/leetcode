/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        swap(m_b_sk, m_f_sk);
        m_f_sk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        swap(m_f_sk, m_b_sk);

        int top = m_b_sk.top();
        m_b_sk.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        swap(m_f_sk, m_b_sk);
        return m_b_sk.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return m_f_sk.empty() && m_b_sk.empty();
    }

private:
    stack<int> m_f_sk;
    stack<int> m_b_sk;

    void swap(stack<int> &f, stack<int> &b){
        while(!f.empty())
        {
            b.push(f.top());
            f.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

