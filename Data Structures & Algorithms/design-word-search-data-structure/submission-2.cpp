struct TrieNode
{
    TrieNode()
    {
        this->c = '?';
        this->isEnd = false;
    }

    TrieNode(char c, bool isEnd)
    {
        this->c = c;
        this->isEnd = isEnd;
    }

    char c;
    bool isEnd;
    unordered_map<char, TrieNode*> children;
};


class WordDictionary {
public:
    TrieNode* head = new TrieNode();
    
    WordDictionary() {
        
    }
    
    void addWord(string word) 
    {
        TrieNode* currNode = head;

        for (int i = 0; i < word.length(); i++)
        {
            bool isEnd = (i + 1 == word.length()) ? true : false;
            
            if (!currNode->children.contains(word[i]))
            {
                currNode->children[word[i]] = new TrieNode(word[i], isEnd);
            }

            if (isEnd) currNode->children[word[i]]->isEnd = true;
            
            currNode = currNode->children[word[i]];
        }
    }
    
    bool search(string word) 
    {
        return dfs(word, head, 0);
    }

    bool dfs(string& word, TrieNode* currNode, int i)
    {
        if (i == word.length()) return currNode->isEnd;
        
        if (word[i] == '.')
        {
            //recurse for each child of the currNode
            bool res = false;
            for (auto p : currNode->children)
            {
                if (dfs(word, p.second, i + 1)) return true;
            }

            return false;
        }

        if (!currNode->children.contains(word[i])) return false;
        
        return dfs(word, currNode->children[word[i]], i + 1);  
    }
};
