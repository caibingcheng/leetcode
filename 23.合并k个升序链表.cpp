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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool is_all_empty = true;
        for (ListNode* l : lists){
            is_all_empty &= (l == nullptr);
        }
        if (is_all_empty)
        {
            return nullptr;
        }

        ListNode* p = nullptr;
        ListNode** first = nullptr;
        for (ListNode* l : lists)
        {
            if (!p && l)
            {
                p = l;
                first = &l;
            }
            else if (l && l->val <= p->val)
            {
                p = l;
                first = &l;
            }
        }
        (*first) = (*first)->next;

        ListNode* head = p;
        while(!p)
        {
            ListNode** pre = &p;
            for (ListNode* l : lists)
            {
                if (l && l->val <= (*pre)->val)
                {
                    pre = &l;
                }
            }
            if (pre != &p)
            {
                p->next = *pre;
                *pre = (*pre)->next;
            }
            else
            {
                p->next = nullptr;
            }
            p = p->next;
        }

        return head;
    }
};
// @lc code=end

