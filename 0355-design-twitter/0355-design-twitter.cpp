class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> utweets;

public:
    Twitter() { this->time = 0; }

    void postTweet(int userId, int tweetId) {
        auto& v = utweets[userId];
        v.push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        auto& ut = utweets[userId];
        int cnt = 0;
        for (int i = ut.size() - 1; i >= 0; i--) {
            if (cnt >= 10)
                break;
            auto& it = ut[i];
            pq.push({it.first, it.second});
            cnt += 1;
        }
        auto& st = following[userId];
        for (auto& sst : st) {
            cnt=0;
            auto& utt = utweets[sst];
            for (int i = utt.size() - 1; i >= 0; i--) {
                if (cnt >= 10)
                    break;
                auto& it = utt[i];
                pq.push({it.first, it.second});
                cnt += 1;
            }
        }
        vector<int> ans;
        for(int i=0;i<10;i++){
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else break;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto& st = following[followerId];
        st.erase(followeeId);
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