/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *head1 = head;
        ListNode *head2 = head->next;

        ListNode *p1 = head1;
        ListNode *p2 = head2;
        ListNode *p12 = nullptr;

        while (p1 || p2)
        {
            if (p1)
            {
                p12 = p1;
            }
            if (p1 && p1->next)
            {
                ListNode *p1_next = p1->next->next;
                p1->next = p1_next;
                p1 = p1_next;
            }
            else
            {
                p1 = nullptr;
            }
            if (p2 && p2->next)
            {
                ListNode *p2_next = p2->next->next;
                p2->next = p2_next;
                p2 = p2_next;
            }
            else
            {
                p2 = nullptr;
            }
        }
        p12->next = head2;

        return head1;
    }
};
// @lc code=end
