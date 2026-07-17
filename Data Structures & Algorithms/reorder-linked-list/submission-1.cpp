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
    void reorderList(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }


        bool isFirst = true;
        ListNode* prev = slow; 

        while (slow)
        {
            ListNode* slowNext = slow->next;
            if (isFirst)
            {
                slow->next = nullptr;
                isFirst = false;
            }
            
            else slow->next = prev;
            
            prev = slow; 
            slow = slowNext; 
        }

        ListNode* right = prev;
        ListNode* rightNext = right->next;
        ListNode* left = head;
        ListNode* leftNext = left->next;
        int i = 0;

        while (left != right)
        {
            if (i % 2 == 0)
            {
                left->next = right;
                left = leftNext;
                leftNext = left->next;
            }
            
            else
            {
                right->next = left;
                right = rightNext;
                rightNext = right->next;
            }

            i++;
        }
    }
};