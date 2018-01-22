class Twitter {
private:
    struct Post {
    public:
        int id;
        int num;
        Post(int id_, int num_) : id(id_), num(num_) {}
    };
    struct User {
    public:
        std::set<int> follow;
        std::vector<Post> posts;
        User() = default;
    };
    std::vector<User> users;
    std::unordered_map<int, int> pos;
    int userCount, postCount;
    
public:
    Twitter() : userCount(0), postCount(0) {}
    void postTweet(int userId, int tweetId) {
        if(pos.find(userId) == pos.end()) {
            pos[userId] = userCount++;
            users.push_back(User());
        }
        int userPos = pos[userId];
        users[userPos].posts.push_back(Post(tweetId, postCount++));
    }
    std::vector<int> getNewsFeed(int userId) {
        if(pos.find(userId) == pos.end()) {
            pos[userId] = userCount++;
            users.push_back(User());
        }
        int userPos = pos[userId];
        std::vector<Post> temp;
        for(int target : users[userPos].follow) {
            int targetPos = pos[target];
            for(int i = users[targetPos].posts.size() - 1, j = 0; j != 10 && i != -1; --i, ++j) {
                temp.push_back(users[targetPos].posts[i]);
            }
        }
        for(int i = users[userPos].posts.size() - 1, j = 0; j != 10 && i != -1; --i, ++j) {
            temp.push_back(users[userPos].posts[i]);
        }
        std::vector<int> result;
        if(temp.size() <= 10) {
            sort(temp.begin(), temp.end(), [](const Post & a, const Post & b) -> bool { return a.num > b.num; });
            for(const Post & p : temp) result.push_back(p.id);
        }
        else {
            for(int i = 0; i < 10; ++i) {
                int maxValue = INT_MIN;
                int maxPos = 0;
                for(int i = 0; i < temp.size(); ++i) {
                    if(temp[i].num > maxValue) {
                        maxValue = temp[i].num;
                        maxPos = i;
                    }
                }
                result.push_back(temp[maxPos].id);
                temp[maxPos].num = INT_MIN;
            }
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        if(pos.find(followerId) == pos.end()) {
            pos[followerId] = userCount++;
            users.push_back(User());
        }
        if(pos.find(followeeId) == pos.end()) {
            pos[followeeId] = userCount++;
            users.push_back(User());
        }
        if(followerId == followeeId) return;
        int userPos = pos[followerId];
        users[userPos].follow.insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if(pos.find(followerId) == pos.end()) {
            pos[followerId] = userCount++;
            users.push_back(User());
        }
        if(pos.find(followeeId) == pos.end()) {
            pos[followeeId] = userCount++;
            users.push_back(User());
        }
        if(followeeId == followerId) return;
        int userPos = pos[followerId];
        users[userPos].follow.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */