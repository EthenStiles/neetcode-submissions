class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int time = 0;
        unordered_map<char, int> m;
        queue<pair<int, int>> waitList; //count, nextAvailableTime

        for (char c : tasks) m[c]++;

        priority_queue<int> pq;

        for (auto p : m)
        {
            pq.push(p.second);
        }

        while (!pq.empty() || !waitList.empty())
        {
            int curr = 0;
            time++;
            if (!pq.empty())
            {
                curr = pq.top() - 1;
                pq.pop();
            }
            
            if (curr > 0) waitList.push({curr, time + n});
            if (!waitList.empty() && waitList.front().second <= time)
            {
                pq.push(waitList.front().first);
                waitList.pop();
            }
        }

        return time;
    }
};
