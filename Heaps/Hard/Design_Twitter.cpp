#include <bits/stdc++.h>
using namespace std;
// tweets = n, ids=m
class User
{
public:
    int userId;
    vector<pair<int, int>> tweets; // SC:O(n)
    unordered_set<int> following; // SC:O(m)

    User(){}

    User(int id)
    {
        this->userId = id;
        following.insert(id);
    }
};
// twitter has a list of users, preferably stored in an unordered_map, each user has
// a list of following which includes himself so that he can see his own posts,
// also a list of tweets he has made, following is an unordered_map, so that we can see
// the following's post faster
// *postTweets* whenever a tweet is posted, make the user if not exists
// add the tweets in his list of tweets, 
// *follow* whenever a user follows some one, add the id of the followee in his following list
// *unfollow* a user can't unfollow himself, remove the id of the followee from his list of following
// *getNewsFeed* get the list of following, traverse it, add each of ther tweet in a maxheap
// the get the top 10 posts from the maxheap or all if less than 10
class Twitter
{
    unordered_map<int, User> userMap; // O(m)
    int timestamp;

public:
    Twitter()
    {
        this->timestamp = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        if (userMap.find(userId) == userMap.end())
        {
            userMap[userId] = User(userId);
        }

        userMap[userId].tweets.push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        // TC:O(m*n*log(m*n)+log(m*n)), SC:O(m*n+n)
        vector<int> res; // SC:O(n)
        if (userMap.find(userId) == userMap.end())
        {
            return res;
        }

        priority_queue<pair<int, int>> maxHeap; // SC:O(m*n)

        for (int followeeId : userMap[userId].following) // TC:O(m)
        {
            if (userMap.find(followeeId) == userMap.end())
            {
                continue;
            }

            for (auto &tweet : userMap[followeeId].tweets) // TC:O(n)
            {
                maxHeap.push(tweet); // O(log(m*n))
            }
        }

        int count = 0;
        while (!maxHeap.empty() && count < 10) // TC:O(10)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop(); // TC:O(log(m*n))
            count++;
        }

        return res;
    }

    void follow(int followerId, int followeeId)
    {
        if (userMap.find(followerId) == userMap.end())
        {
            userMap[followerId] = User(followerId);
        }

        if (userMap.find(followeeId) == userMap.end())
        {
            userMap[followeeId] = User(followeeId);
        }

        userMap[followerId].following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
        {
            return;
        }

        if (userMap.find(followerId) != userMap.end())
        {
            userMap[followerId].following.erase(followeeId);
        }
    }
};

int main()
{
    Twitter twt;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;

        if (command == "postTweet")
        {
            int userId, tweetId;
            cin >> userId >> tweetId;
            twt.postTweet(userId, tweetId);
        }
        else if (command == "getNewsFeed")
        {
            int userId;
            cin >> userId;
            vector<int> feed = twt.getNewsFeed(userId);
            for (int id : feed)
            {
                cout << id << " ";
            }
            cout << endl;
        }
        else if (command == "follow")
        {
            int followerId, followeeId;
            cin >> followerId >> followeeId;
            twt.follow(followerId, followeeId);
        }
        else if (command == "unfollow")
        {
            int followerId, followeeId;
            cin >> followerId >> followeeId;
            twt.unfollow(followerId, followeeId);
        }
    }

    return 0;
}
