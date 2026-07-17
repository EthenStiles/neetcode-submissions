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
        vector<ListNode*> vec;
        
        ListNode* dummy = head;
        while(dummy)
        {
            vec.push_back(dummy);
            dummy = dummy->next;
        }

        dummy = head;
        int left = 1;
        int right = vec.size() - 1;
        int itr = 1;
        
       while (left <= right)
        {
            if (itr % 2 == 0)
            {
                dummy->next = vec[left];
                left++;
            }

            else
            {
                dummy->next = vec[right];
                right--;
            }
            
            dummy = dummy->next;
            itr++;
        }

        dummy->next = nullptr;
    }
};