/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
        {
            return nullptr;
        }

        ListNode *lastA = headA;
        while(lastA)
        {
            ListNode *lastB = headB;
            while(lastB)
            {
                if (lastB == lastA)
                {
                    return lastB;
                }
                lastB = lastB->next;
            }
            lastA = lastA->next;
        }
        return nullptr;
    }
};
// @lc code=end

