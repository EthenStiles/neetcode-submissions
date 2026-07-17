class Node
{
    public:

        int key;
        Node* prev;
        Node* next;

        Node(int key):
            key(key),
            prev(nullptr),
            next(nullptr)
        {}    
};

class LRUCache {
public:

    unordered_map<int, pair<int, Node*>> m;
    int capacity;
    Node* left;
    Node* right;
    
    LRUCache(int capacity) : capacity(capacity)
    {
        left = new Node(-1);
        right = new Node(-1);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) 
    {
        if (!m.contains(key)) return -1;

        //update item to be most recently used if not already
        if (m[key].second->prev != left)
        {
            removeNode(m[key].second);
            m[key].second = insertNode(key);
        }
        
        return m[key].first;
    }
    
    void put(int key, int value) 
    {
        if (m.contains(key))
        {
            removeNode(m[key].second);
            m.erase(key);
        }

        m[key] = {value, insertNode(key)};

        //check if we have exceeded capacity 
        if (m.size() > capacity)
        {
            //delete the LRU item from both the linked list and map
            m.erase(right->prev->key);
            removeNode(right->prev);
        }
    }

    Node* insertNode(int key)
    {
        Node* newNode = new Node(key);
        newNode->prev = left;
        newNode->next = left->next;
        left->next->prev = newNode;
        left->next = newNode;
        return newNode;
    }

    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};
