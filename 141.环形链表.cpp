/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        set<ListNode *> nodes;

        while(p)
        {
            auto stats = nodes.insert(p);
            if (!stats.second)
            {
                return true;
            }
            p = p->next;
        }
        return false;
    }
};
// @lc code=end

