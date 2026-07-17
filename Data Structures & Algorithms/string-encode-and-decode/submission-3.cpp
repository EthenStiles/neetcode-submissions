class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string res = "";

        for (string s : strs)
        {
            res += s; 
            res += "ethen";  
        }

        return res;
    }

    vector<string> decode(string s) 
    {
        vector<string> res;
        string curr = "";
        
        for (int i = 0; i < s.length(); i++)
        {
            if (isDelimiter(s[i], s[i+1], s[i+2], s[i+3], s[i+4]))
            {
                res.push_back(curr);
                curr = "";
                i += 4;
            } 

            else curr.push_back(s[i]);
        }

        return res;
    }

    bool isDelimiter(char first, char second, char third, char fourth, char fifth)
    {
        return first == 'e' && second == 't' && third == 'h' && fourth == 'e' && fifth == 'n';
    }
};
