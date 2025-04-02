#ifndef TWITTER_H
#define TWITTER_H

#include "SocialMediaAccount.h"

// Twitter class inheriting from SocialMediaAccount
template <typename T>
class Twitter : public SocialMediaAccount<T> {
private:
    int retweetCount; // Tracks the total number of retweets by the user

public:
    // Constructor to initialize the account with the given user handler
    Twitter(T userHandler) : SocialMediaAccount<T>(userHandler), retweetCount(0) {}

    // Setter for retweet count
    void setRetweetCount(int count) { retweetCount = count; }

    // Getter for retweet count
    int getRetweetCount() { return retweetCount; }

    // Function to increment retweet count when the user retweets a post
    void RT() { retweetCount++; }
};

#endif // End of TWITTER_H header guard
