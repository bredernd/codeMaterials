#include <iostream>
#include "search.h"

int main() {
    // Integer array
    int intArr[] = {4, 67, 234, 24, 95, 45, 35, 59, 60, 294};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int intKey = 95;
    std::cout << "Integer key " << intKey << " found at index: " << search(intArr, intSize, intKey) << std::endl;

    // Double array
    double doubleArr[] = {3.5, 34.6, 234.98, 4.6, 7.9, 2.3, 4.1, 5.6, 0.985, 4.009};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    double doubleKey = 7.9;
    std::cout << "Double key " << doubleKey << " found at index: " << search(doubleArr, doubleSize, doubleKey) << std::endl;

    // String array
    std::string strArr[] = {"Halil", "UM-flint", "third", "4th", "is", "are", "?", "88", "CSC275", "csep"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    std::string strKey = "CSC275";
    std::cout << "String key \"" << strKey << "\" found at index: " << search(strArr, strSize, strKey) << std::endl;

    // Profile array
    Profile list[10];
    std::string names[] = {"Adam", "Eve", "John", "Daniel", "Kate", "Sue", "Nicole", "Nick", "Chris", "Sam"};

    for (int i = 0; i < 10; i++) {
        list[i].id = i;
        list[i].name = names[i];
    }

    // Searching for a Profile object
    Profile keyProfile;
    keyProfile.name = "Nicole"; // Assign name manually
    int profileIndex = search(list, 10, keyProfile);

    if (profileIndex != -1) {
        std::cout << "Profile with name \"" << keyProfile.name << "\" found at index: " << profileIndex << " with ID: " << list[profileIndex].id << std::endl;
    } else {
        std::cout << "Profile with name \"" << keyProfile.name << "\" not found.\n";
    }

    return 0;
}


