/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        ListNode *p = head;
        while(p)
        {
            vals.emplace_back(p->val);
            p = p->next;
        }

        int size = vals.size();
        int start = 0;
        int end = size - 1;
        while(start < end)
        {
            if(vals[start++] != vals[end--])
                return  false;
        }

        return true;
    }
};
// @lc code=end

