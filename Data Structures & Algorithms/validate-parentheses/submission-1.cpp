class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else
            {
                switch (c)
                {
                    case ')':
                        if (st.empty() || st.top() != '(') return false;
                        else st.pop();
                        break;
                    case '}':
                        if (st.empty() || st.top() != '{') return false;
                        else st.pop();
                        break;
                    case ']':
                        if (st.empty() || st.top() != '[') return false;
                        else st.pop();
                        break;
                    default:
                    cout << "Problem" << endl;
                }

            }
        }

        return st.empty();
    }
};
