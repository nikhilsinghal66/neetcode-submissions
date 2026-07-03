class Twitter {
public:
    int count = 0;

    unordered_map<int, vector<pair<int, int>>> map_tweet;
    unordered_map<int, unordered_set<int>> map_follow;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        map_tweet[userId].push_back({count++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        auto &st = map_follow[userId];

        for (auto user : st) {
            auto &temp = map_tweet[user];
            int ind = 0;
            for (auto tweets : temp) {
                pq.push({tweets.first, tweets.second, user, ind++});
            }
        }

        int ind = 0;
        for (auto tweets : map_tweet[userId]) {
            pq.push({tweets.first, tweets.second, userId, ind++});
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp[1]);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        map_follow[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        map_follow[followerId].erase(followeeId);
    }
};