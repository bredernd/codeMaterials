#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    map<string, string> presidentStates;

    // (a) Create a string pair with your name and state
    pair<string, string> myPair("Alex Johnson", "California");

    string name, state, line;
    ifstream file("presidentsWstates.txt");

    // (b) Fill your presidentStates with the names and states as you read from the file
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, '\t');
            getline(ss, state, '\t');
            presidentStates.insert(pair<string, string>(name, state));
        }
        file.close();
    }

    // (c) Use a map iterator to print the values
    // (d) iterator->first is the key, iterator->second is the value
    cout << "President to State mapping:\n";
    for (map<string, string>::iterator it = presidentStates.begin(); it != presidentStates.end(); ++it)
    {
        cout << setw(25) << left << it->first << " => " << it->second << endl;
    }

    cout << "***************************" << endl;

    // (e) Print the state for Thomas Jefferson
    cout << "State for Thomas Jefferson: " << presidentStates["Thomas Jefferson"] << endl;

    // (f) Insert your name and state using the pair created
    presidentStates.insert(myPair);

    // (g) Print your values
    cout << "My name and state: " << myPair.first << " => " << presidentStates[myPair.first] << endl;

    // (h) Try to insert again and store return value
    pair<map<string, string>::iterator, bool> ret;
    ret = presidentStates.insert(myPair);

    // (i) Check if key exists using return value
    if (!ret.second)
    {
        cout << "\"" << myPair.first << "\" already exists in the map." << endl;

        // (j) Print current value for this key
        cout << "Current state: " << ret.first->second << endl;
    }
    else
    {
        cout << "\"" << myPair.first << "\" was inserted successfully." << endl;
    }

    return 0;
}
