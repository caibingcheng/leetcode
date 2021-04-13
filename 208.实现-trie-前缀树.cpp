/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        m_head = new T;
    }

    ~Trie() {
        list<T *> dels;
        list<T *> visited;
        T *head = m_head;
        dels.emplace_back(head);
        while(!dels.empty())
        {
            for (auto &t : dels)
            {
                for (auto &n : t->next)
                {
                    if (n != nullptr)
                    {
                        visited.emplace_back(n);
                    }
                }
                delete t;
            }
            dels = visited;
            visited.clear();
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        T* head = m_head;
        for (auto& c : word)
        {
            if (head->next[c] == nullptr)
            {
                head->next[c] = new T;
            }
            head = head->next[c];
        }
        head->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        bool result = true;
        T* head = m_head;
        for (auto& c : word)
        {
            if (head->next[c] == nullptr)
            {
                result = false;
                break;
            }
            head = head->next[c];
        }
        if (!head->end)
        {
            result = false;
        }

        return result;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        bool result = true;
        T* head = m_head;
        for (auto& c : prefix)
        {
            if (head->next[c] == nullptr)
            {
                result = false;
                break;
            }
            head = head->next[c];
        }

        return result;
    }

private:
    struct T {
        bool end;
        T* next[256];

        T() {
            for (auto &n : next)
            {
                n = nullptr;
            }
            end = false;
        }
    };

    T *m_head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

