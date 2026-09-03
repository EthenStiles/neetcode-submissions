class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
    unordered_set<int> inRes;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        res = {};
        
        for (int i = 0; i < numCourses; i++)
        {
            preMap[i] = {};
        }

        for (vector<int> prereq : prerequisites)
        {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i)) return {};
        }

        return res;
    }

    bool dfs(int n)
    {
        if (inRes.contains(n)) return true;
        if (visited.contains(n)) return false; //cycle

        visited.insert(n);
        for (const int& i : preMap[n])
        {
            if (!dfs(i)) return false;
        }

        visited.erase(n);
        
        res.push_back(n);
        inRes.insert(n);
        return true;
    }

    void printMap()
    {   
        for (const auto& [num, prereqs] : preMap)
        {
            cout << num;
            cout << " : {";

            for (int i : prereqs)
            {
                cout << i << ",";
            }

            cout << "}";
            cout << endl;
        }
    }
};
