#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>

// Function template for linear search
template <typename T>
int search(const T arr[], int n, const T& key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Profile struct
struct Profile {
    int id;
    std::string name;

    // Overloaded equality operator for comparison
    bool operator==(const Profile& other) const {
        return name == other.name;
    }
};

#endif // SEARCH_H

