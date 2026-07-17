class Node 
{
    public:
        Node()
        {
            this->c = '?';
            this->isEnd = false;
        }
        
        Node(char c, bool isEnd)
        {
            this->c = c;
            this->isEnd = isEnd;
        }

        char c;
        bool isEnd;
        unordered_map<char, Node*> m;

};


class PrefixTree {
public:

    Node* head = new Node();

    PrefixTree() {
        
    }
    
    void insert(string word) 
    {
        Node* currNode = head;
        
        for (int i = 0; i < word.length(); i++)
        {
            char currChar = word[i];
            bool isEnd = (i + 1 == word.length()) ? true : false;

            if (currNode->m.contains(currChar))
            {
                currNode = currNode->m[currChar];
                if (isEnd) currNode->isEnd = isEnd; // incase we need to add a word inside a larger already added word (e.g app -> apple) 
            } 

            else
            {
                currNode->m[currChar] = new Node(currChar, isEnd);
                currNode = currNode->m[currChar];
            }
        }
    }
    
    bool search(string word) 
    {
        Node* currNode = head;

        for (int i = 0; i < word.length(); i++)
        {
            char currChar = word[i];
            if (currNode->m.contains(currChar))
            {
                currNode = currNode->m[currChar];
                
                if (i + 1 == word.length())
                {
                    return currNode->isEnd;
                }    
            }

            else return false;
        }
        
        //should never make it here
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        Node* currNode = head;

        for (int i = 0; i < prefix.length(); i++)
        {
            char currChar = prefix[i];
            if (currNode->m.contains(currChar))
            {
                currNode = currNode->m[currChar];     
            } 

            else return false;
        }
        

        return true;
    }
};
