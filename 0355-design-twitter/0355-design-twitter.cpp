class Twitter {
    map<int, queue<int>> posts;
    map<int, vector<int>> f;
    vector<vector<int>> tweet;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts[userId].push(tweetId);
        tweet.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int n = tweet.size();
        for (int i = 0; i < n && ans.size() < 10; i++) {
            if (tweet[n - i - 1][0] == userId)
                ans.push_back(tweet[n - i - 1][1]);
            else {
                int fid = tweet[n - i - 1][0];
                for (int j = 0; j < f[userId].size(); j++) {
                    if (fid == f[userId][j]) {
                        ans.push_back(tweet[n - i - 1][1]);
                        break;
                    }
                }
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        f[followerId].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        int n = f[followerId].size();
        for (int i = 0; i < n; i++) {
            if (f[followerId][i] == followeeId) {
                f[followerId][i] = f[followerId][n - 1];
                f[followerId].pop_back();
                return;
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */