/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        ListNode* h = l1;
        while(h)
        {
            s1.push(h->val);
            h = h->next;
        }
        h = l2;
        while(h)
        {
            s2.push(h->val);
            h = h->next;
        }
        int size = max(s1.size(), s2.size());

        stack<int> s3;
        int cn = 0;
        while(!s1.empty() || !s2.empty())
        {
            int n1 = 0, n2 = 0;
            if (!s1.empty())
            {
                n1 = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                n2 = s2.top();
                s2.pop();
            }

            int n = n1 + n2 + cn;
            s3.push(n % 10);
            cn = n / 10;
        }
        if (cn > 0)
        {
            s3.push(cn);
        }

        ListNode* ret;
        ListNode* retHead;

        int sn = s3.top();
        s3.pop();
        retHead = new ListNode(sn);
        ret = retHead;

        while(!s3.empty())
        {
            sn = s3.top();
            s3.pop();
            ret->next = new ListNode(sn);
            ret = ret->next;
        }
        ret->next = nullptr;

        // ret = retHead;
        // while(ret)
        // {
        //     cout << ret->val << endl;
        //     ret = ret->next;
        // }

        return retHead;
    }
};
// @lc code=end

