#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include "SocialMediaAccount.h"

// Instagram class inheriting from SocialMediaAccount
template <typename T>
class Instagram : public SocialMediaAccount<T> {
private:
    int likeCount; // Tracks the total number of posts liked by the user

public:
    // Constructor to initialize the account with the given user handler
    Instagram(T userHandler) : SocialMediaAccount<T>(userHandler), likeCount(0) {}

    // Setter for like count
    void setLikeCount(int count) { likeCount = count; }

    // Getter for like count
    int getLikeCount() { return likeCount; }

    // Function to increment like count when the user likes a post
    void Like() { likeCount++; }
};

#endif // End of INSTAGRAM_H header guard
