#ifndef SOCIALMEDIAACCOUNT_H
#define SOCIALMEDIAACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// Define constants for maximum followers and followed accounts
const int maxFollowers = 100;
const int maxFollowed = 100;

// Template class for a generic Social Media Account
template <typename T>
class SocialMediaAccount {
protected:
    T handler;  // Represents the account owner
    T followers[maxFollowers];  // Array to store followers
    T followed[maxFollowed];  // Array to store followed accounts
    int followerCount;  // Keeps track of the number of followers
    int followedCount;  // Keeps track of the number of followed accounts
    bool privateAccount;  // Indicates if the account is private (default: true)

public:
    // Constructor to initialize the account with default privacy settings
    SocialMediaAccount(T userHandler) : handler(userHandler), followerCount(0), followedCount(0), privateAccount(true) {}

    // Setter for handler (account owner)
    void setHandler(T userHandler) { handler = userHandler; }

    // Getter for handler (account owner)
    T getHandler() { return handler; }

    // Setter for account privacy status
    void setPrivacy(bool privacy) { privateAccount = privacy; }

    // Getter for account privacy status
    bool getPrivacy() { return privateAccount; }

    // Getter for follower count
    int getFollowerCount() { return followerCount; }

    // Getter for followed count
    int getFollowedCount() { return followedCount; }

    // Adds a follower to the followers list if there is space
    void addFollower(T user) {
        if (followerCount < maxFollowers) {
            followers[followerCount++] = user;
        }
    }

    // Adds an account to the followed list if there is space
    void addFollowed(T user) {
        if (followedCount < maxFollowed) {
            followed[followedCount++] = user;
        }
    }

    // Displays followers if the account is public
    void displayFollowers() {
        if (privateAccount) {
            cout << "Account is protected. Cannot display followers.\n";
        } else {
            for (int i = 0; i < followerCount; i++) {
                cout << followers[i] << " ";
            }
            cout << endl;
        }
    }

    // Displays followed accounts if the account is public
    void displayFollowed() {
        if (privateAccount) {
            cout << "Account is protected. Cannot display followed accounts.\n";
        } else {
            for (int i = 0; i < followedCount; i++) {
                cout << followed[i] << " ";
            }
            cout << endl;
        }
    }
};

#endif // End of SOCIALMEDIAACCOUNT_H header guard