class Twitter {
public:
    int timer;

    // user -> {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // follower -> followees
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // {time, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        // Push latest tweet of self
        if(!tweets[userId].empty()){
            int idx = tweets[userId].size()-1;
            pq.push({
                tweets[userId][idx].first,
                tweets[userId][idx].second,
                userId,
                idx
            });
        }

        // Push latest tweet of every followed user
        for(int user : followMap[userId]){
            if(!tweets[user].empty()){
                int idx = tweets[user].size()-1;
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            // Push previous tweet of same user
            if(idx > 0){
                pq.push({
                    tweets[user][idx-1].first,
                    tweets[user][idx-1].second,
                    user,
                    idx-1
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};