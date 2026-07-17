class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        m[key].emplace_back(value, timestamp);   
    }
    
    string get(string key, int timestamp) 
    {
        //if (m[key].empty()) return "";
        vector<pair<string, int>>& vec = m[key];
        
        
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (vec[mid].second > timestamp) right = mid - 1;
            else left = mid + 1;
        }

        return right >= 0 ? vec[right].first : "";
    }
};
