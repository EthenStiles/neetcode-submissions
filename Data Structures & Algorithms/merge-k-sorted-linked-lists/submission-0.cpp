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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* dummy = new ListNode();
        ListNode* itr = dummy;

        while(true)
        {
            int minElt = 1001;
            int minIdx = -1;

            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != nullptr && lists[i]->val < minElt)
                {
                    minElt = lists[i]->val;
                    minIdx = i;
                }
            }

            if (minElt == 1001) break;

            lists[minIdx] = lists[minIdx]->next;
            ListNode* newNode = new ListNode(minElt);
            itr->next = newNode;
            itr = itr->next;
        }
    
        return dummy->next;
        
    }
};
