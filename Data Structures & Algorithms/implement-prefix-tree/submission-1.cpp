class PrefixTree {
public:
    unordered_set<string> words;
    unordered_set<string> prefixes;
    PrefixTree() {
        
    }
    
    void insert(string word) 
    {
        for (int i = 0; i < word.length(); i++)
        {
            cout << word.substr(0, i + 1) << endl;
            prefixes.insert(word.substr(0, i + 1));
        }
       
        words.insert(word);
    }
    
    bool search(string word) 
    {
        return words.contains(word);
    }
    
    bool startsWith(string prefix) 
    {
        return prefixes.contains(prefix);
    }
};
