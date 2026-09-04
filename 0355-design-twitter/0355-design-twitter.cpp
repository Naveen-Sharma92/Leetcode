class Twitter {
public:

    int time = 0;

    // follower -> users they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> ans;

        // {time, {userId, index}}
        priority_queue<pair<int,pair<int,int>>> pq;

        // user himself
        vector<int> users;
        users.push_back(userId);

        // users he follows
        for(auto x : following[userId])
            users.push_back(x);

        // latest tweet of every relevant user
        for(auto u : users){
            if(!tweets[u].empty()){
                int index = tweets[u].size()-1;

                pq.push({
                    tweets[u][index].first,
                    {u,index}
                });
            }
        }

        // get 10 most recent tweets
        while(!pq.empty() && ans.size() < 10){

            auto curr = pq.top();
            pq.pop();

            int u = curr.second.first;
            int index = curr.second.second;

            ans.push_back(tweets[u][index].second);

            // previous tweet of same user
            if(index > 0){
                pq.push({
                    tweets[u][index-1].first,
                    {u,index-1}
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};