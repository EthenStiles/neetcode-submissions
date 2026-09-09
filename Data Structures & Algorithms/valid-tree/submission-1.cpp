class Solution {
public:
    unordered_map<int, vector<int>> childMap;
    unordered_set<int> visited;
    unordered_set<int> prevChecked;
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        for (const vector<int>& edge : edges)
        {
            int first = edge[0];
            int second = edge[1];
            childMap[first].push_back(second);
            childMap[second].push_back(first);
        }

        return dfs(0, -1) && visited.size() == n;
    }

    bool dfs(int n, int prev)
    {
        if (visited.contains(n)) return false;
        visited.insert(n);

        for (const int child : childMap[n])
        {
            if (child == prev) continue;
            if (!dfs(child, n)) return false;
        }

        return true;
    }
};
