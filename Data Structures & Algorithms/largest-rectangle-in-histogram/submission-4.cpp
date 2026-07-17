class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int res = 0;
        stack<pair<int, int>> st; //{index, height}
        
        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!st.empty() && heights[i] < st.top().second)
            {
                int index = st.top().first;
                int height = st.top().second;
                int area = height * (i - index);
                res = max(res, area);
                st.pop();
                start = index;
            }

            st.emplace(start, heights[i]);
        }

        while (!st.empty())
        {
            int index = st.top().first;
            int height = st.top().second;
            int area = height * (heights.size() - index);
            res = max(res, area);
            st.pop();
        }

        return res;
    }
};
