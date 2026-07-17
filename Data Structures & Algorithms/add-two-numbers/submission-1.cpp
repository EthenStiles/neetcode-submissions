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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;

        int carry = 0;
        while (l1 || l2 || carry > 0)
        {
           int v1 = (l1 != nullptr) ? l1->val : 0;
           int v2 = (l2 != nullptr) ? l2->val : 0;

           int val = v1 + v2 + carry;
           carry = val / 10;
           val %= 10;

           itr->next = new ListNode(val);
           itr = itr->next;

           l1 = (l1 == nullptr) ? nullptr : l1->next;
           l2 = (l2 == nullptr) ? nullptr : l2->next;
        }

        return dummy->next;
    }
};
