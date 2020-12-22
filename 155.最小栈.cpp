/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        m_index = 0;
        m_size = 10;
        m_empty = true;
        m_min = INT_MAX;
        mp_mem = new int[m_size];
    }

    ~MinStack() {
        deleteMem();
    }

    void push(int x) {
        if (m_index >= m_size)
        {
            resize();
        }
        mp_mem[m_index] = x;
        m_empty = false;
        m_index++;
    }

    void pop() {
        if (m_empty){
            return;
        }

        m_index--;
        if (m_index <= 0)
        {
            m_empty = true;
        }
    }

    int top() {
        int index = m_empty ? 0 : (m_index - 1);
        return mp_mem[index];
    }

    int getMin() {
        m_min = INT_MAX;
        for (int i = 0; i < m_index; ++i)
        {
            if (mp_mem[i] < m_min)
            {
                m_min = mp_mem[i];
            }
        }
        return m_min;
    }

    bool empty() {
        return m_empty;
    }

private:
    int *mp_mem = nullptr;
    int m_size = 0;
    int m_index = 0;
    int m_min = INT_MAX;
    bool m_empty = true;

    void resize(){
        int size_tmp = m_size * 1.5;
        int *mem_tmp = new int[size_tmp];
        memcpy(mem_tmp, mp_mem, m_size * sizeof(int));

        deleteMem();

        m_size = size_tmp;
        mp_mem = mem_tmp;
    }

    void deleteMem(){
        delete []mp_mem;
        mp_mem = nullptr;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

