class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st; // {temperature, index}

        for (int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];

            //if (st.empty()) st.emplace(t, i);
            
            while (!st.empty() && t > st.top().first)
            {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.emplace(t, i);
        }
 
        return res;
    }
};
