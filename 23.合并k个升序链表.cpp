/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        vector<ListNode *> ktop;
        ktop.reserve(k);

        auto cmp = [](const auto& p1, const auto& p2) {
            bool sign = false;
            if (p1->val < p2->val)
                return sign;
            else
                return !sign;
        };

        auto mv = [&ktop, &cmp]() {
            ktop[0] = ktop[0]->next;
            pop_heap(begin(ktop), end(ktop), cmp);
            if (ktop.back() == nullptr)
            {
                ktop.pop_back();
            }
            else
            {
                push_heap(begin(ktop), end(ktop), cmp);
            }

        };

        for (auto &l : lists)
        {
            if (l != nullptr)
                ktop.push_back(l);
        }
        if (ktop.empty())
            return nullptr;

        make_heap(begin(ktop), end(ktop), cmp);
        ListNode *p = ktop.front();
        mv();
        ListNode *head = p;
        while (!ktop.empty())
        {
            p->next = ktop.front();
            p = p->next;
            mv();
        }

        return head;
    }
};
// @lc code=end
