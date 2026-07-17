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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = head;
        int counter = 0;
        while(dummy)
        {
            counter++; 
            dummy = dummy->next;
        }

        int index = counter - n;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        if (index == 0) return head->next;

        while (index)
        {
            prev = curr;
            curr = curr->next;
            index--;
        }

        prev->next = curr->next;
        return head;
    }
};
