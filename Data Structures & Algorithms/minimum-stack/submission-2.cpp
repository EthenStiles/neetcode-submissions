class MinStack {
public:
    
    vector<int> st;
    vector<int> st_prefix;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        st.push_back(val);
        
        if (st_prefix.empty()) st_prefix.push_back(val);
        else st_prefix.push_back(min(st_prefix.back(), val));
        
    }
    
    void pop() 
    {
        st.pop_back();
        st_prefix.pop_back();

    }
    
    int top() 
    {
        return st.back();
    }
    
    int getMin() 
    {
        return st_prefix.back();
    }
};
