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
    bool hasCycle(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = nullptr;
        if (head) fast = head->next;

        while (fast)
        {
            if (slow->val == fast->val) return true;
            slow = slow->next;

            if (!fast->next) return false;
            fast = fast->next->next;
        }

        return false;
    }
};
