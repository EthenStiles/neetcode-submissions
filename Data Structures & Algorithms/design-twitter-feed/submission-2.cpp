class Twitter {
public:
    
    unordered_map<int, unordered_map<int, int>> tweets; //userId -> time -> tweetId
    unordered_map<int, unordered_set<int>> following; // userId -> list of followers
    int time = 0;

    Twitter() 
    {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId][time] = tweetId;
        time++;
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> res;
        priority_queue<pair<int, int>> heap;

        //get own tweets
        for (auto p : tweets[userId])
        {
            heap.push({p.first, p.second});
            //if (heap.size() > 10) heap.pop();
        }

        //get tweets of those followed
        for (int accId : following[userId])
        {
            for (auto p : tweets[accId])
            {
                heap.push({p.first, p.second});
                //if (heap.size() > 10) heap.pop();
            }
        }

        while (!heap.empty() && res.size() < 10)
        {
            res.push_back(heap.top().second);
            heap.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        following[followerId].erase(followeeId);
    }
};
