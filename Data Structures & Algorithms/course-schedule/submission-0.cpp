class Solution 
{
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
        {
            for (int i = 0; i < numCourses; i++)
            {
                preMap[i] = {};
            }

            for (const auto& prereq : prerequisites)
            {
                preMap[prereq[0]].push_back(prereq[1]);
            }

            for (int c = 0; c < numCourses; c++)
            {
                if (!dfs(c)) return false;
            }

            return true;
        }

        bool dfs(int course)
        {
            if (visited.contains(course)) return false;
            if (preMap[course].empty()) return true;

            visited.insert(course);

            for (int pre : preMap[course])
            {
                if (!dfs(pre)) return false;
            }

            visited.erase(course);
            preMap[course].clear();

            return true;
        }
};
