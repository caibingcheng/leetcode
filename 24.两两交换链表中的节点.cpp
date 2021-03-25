/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next))
        {
            return head;
        }

        ListNode* p = head;
        ListNode* pn = p->next->next;
        ListNode* nh = p->next;

        while(p && p->next)
        {
            p->next->next = p;
            p->next = pn ? pn->next ? pn->next : pn : nullptr;
            p = pn;
            if (p && p->next)
            {
                pn = p->next->next;
            }
        }
        return nh;
    }
};
// @lc code=end

