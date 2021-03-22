/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        if (!(p1 && p2)){
            return p1 ? p1 : p2;
        }

        ListNode* p = nullptr;

        if (p1->val < p2->val){
            p = p1;
            p1 = p1->next;
        }
        else {
            p = p2;
            p2 = p2->next;
        }

        ListNode* head = p;
        while(p1 && p2)
        {
            if (p1->val <= p2->val){
                p->next = p1;
                p = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        };
        p->next = p1 ? p1 : p2;

        return head;
    }
};
// @lc code=end

