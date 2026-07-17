/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> m; // old node -> new node

        Node* dummy = head;
        Node* newHead = nullptr;
        while(dummy)
        {
            m[dummy] = new Node(dummy->val);
            if (newHead == nullptr) newHead = m[dummy];
            dummy = dummy->next;
        }
        
        m[nullptr] = nullptr;
        for (pair p : m)
        {
            if (p.first == nullptr) continue;
            Node* oldNode = p.first;
            Node* newNode = p.second;

            //if (oldNode->next == nullptr) newNode->next = nullptr;
            newNode->next = m[oldNode->next];

            //if (oldNode->random == nullptr) newNode->random = nullptr;
            newNode->random = m[oldNode->random];
        }

        return newHead;
    }
};
