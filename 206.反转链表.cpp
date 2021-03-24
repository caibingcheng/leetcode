/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        if (!p){
            return head;
        }
        ListNode* next = p->next;
        ListNode* next_next = nullptr;
        p->next = nullptr;

        while(next) {
            next_next = next->next;
            next->next = p;
            p = next;
            next = next_next;
        }

        return p;
    }
};
// @lc code=end

