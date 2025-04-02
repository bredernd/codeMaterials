/*************************************************************************
** Author : Dak Bredernitz
** Program : hw1, q1
** Date Created : March 31st 2025
** Date Last Modified : April 2nd, 2025
** Usage : No command line arguments
**
** Problem:
Accept the following information from the user (keyboard):
- Hw1, hw2 and hw3 (out of 100)
- Midterm (out of 100)
- Final exam (out of 100)
Calculate the total grade out of 100 based on the following grading scale:
Hws --> 30% (10% each)
Midterm --> 30%
Final Exam --> 40%
*************************************************************************/

#include "Twitter.h"
#include "Instagram.h"
#include <cstdlib>

// Define a Profile struct to represent a user with a unique ID and username
struct Profile {
    int userId;      // Unique ID for the user
    string username; // Username of the user
};

// Overload the ostream operator to display Profile objects in a user-friendly format
ostream& operator<<(ostream& os, const Profile& profile) {
    os << profile.username << " (ID: " << profile.userId << ")";
    return os;
}

int main() {
    // Create instances of Twitter and Instagram accounts using both string and Profile types
    Twitter<string> TS("@exampleUser");  // Twitter account using a string as handler
    Twitter<Profile> TP({1, "User1"});  // Twitter account using Profile struct
    Instagram<string> IS("@instaUser"); // Instagram account using a string as handler
    Instagram<Profile> IP({2, "InstaUser1"}); // Instagram account using Profile struct

    // Add followers and followed accounts to test functionality
    TS.addFollower("@follower1");                // Add a follower to Twitter account with string handler
    TP.addFollower({3, "FollowerProfile"});      // Add a follower to Twitter account with Profile handler
    IS.addFollowed("@following1");               // Add a followed account to Instagram account with string handler
    IP.addFollowed({4, "FollowedProfile"});      // Add a followed account to Instagram account with Profile handler

    // Simulate user actions: retweet for Twitter and like for Instagram
    TS.RT();   // Increment retweet count for Twitter account
    IS.Like(); // Increment like count for Instagram account

    // Display the list of followers for Twitter and followed accounts for Instagram
    TS.displayFollowers();  // Display followers for the Twitter account
    IS.displayFollowed();   // Display followed accounts for the Instagram account

    // Output the retweet count and like count
    cout << "Retweets: " << TS.getRetweetCount() << endl;  // Show the total retweet count
    cout << "Likes: " << IS.getLikeCount() << endl;        // Show the total like count

    return 0;  // End of main function
}