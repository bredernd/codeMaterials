#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MyList.h"

using namespace std;

// Profile struct
struct Profile {
    string fullname;
    string state;

    bool operator==(Profile rhs) {
        return fullname == rhs.fullname;
    }

    bool operator!=(Profile rhs) {
        return fullname != rhs.fullname;
    }
};

// Overload the << operator for Profile
ostream& operator<<(ostream& out, Profile& user) {
    out << user.fullname << " -- " << user.state;
    return out;
}

int main() {
    MyList<Profile> pMyList;
    ifstream file("presidentsWstates.txt");
    string line;
    Profile temp;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            temp.fullname.clear();
            string word;
            vector<string> words;

            // Break the line into words
            while (ss >> word) {
                words.push_back(word);
            }

            if (!words.empty()) {
                temp.state = words.back();  // Last word is state
                temp.fullname = words[0];
                for (size_t i = 1; i < words.size() - 1; ++i) {
                    temp.fullname += " " + words[i];
                }
                pMyList.insertHead(temp);
            }
        }
        file.close();
    } else {
        cerr << "Could not open file." << endl;
        return 1;
    }

    // Display all presidents
    cout << "\nList of Presidents:\n--------------------\n";
    pMyList.display();

    // Example search
    Profile searchProfile;
    searchProfile.fullname = "Abraham Lincoln";
    if (pMyList.search(searchProfile)) {
        cout << "\n" << searchProfile.fullname << " found in the list!" << endl;
    } else {
        cout << "\n" << searchProfile.fullname << " not found." << endl;
    }

    return 0;
}

