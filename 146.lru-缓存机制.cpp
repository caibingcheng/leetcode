/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        int result = -1;
        auto start = begin(m_lru);
        auto endlru = end(m_lru);
        while(start != endlru)
        {
            if (start->first == key)
            {
                result = start->second;
                VAL val = *start;
                m_lru.erase(start);
                m_lru.push_front(val);
                break;
            }
            start = next(start);
        }
        return result;
    }

    void put(int key, int value) {
        auto start = begin(m_lru);
        auto endlru = end(m_lru);
        while(start != endlru)
        {
            if (start->first == key)
            {
                start->second = value;
                VAL val = *start;
                m_lru.erase(start);
                m_lru.push_front(val);
                return;
            }
            start = next(start);
        }

        if (m_lru.size() >= m_capacity)
        {
            m_lru.pop_back();
        }
        m_lru.push_front({key, value});
    }

private:
    using VAL = pair<int, int>;
    int m_capacity;
    list<VAL> m_lru;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

