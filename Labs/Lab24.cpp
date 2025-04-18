#include<iostream>
#include<set>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::set;

int main()
{
    set<string> setOfNames;

    // (a) Insert initial names
    setOfNames.insert("John");
    setOfNames.insert("Jane");
    setOfNames.insert("Nick");
    setOfNames.insert("Steve");

    string mynames[] = {"Adam", "Sue"};

    // (a) Insert the values in mynames array into the set
    setOfNames.insert(mynames, mynames + 2);

    // (b) Try to insert "Adam" again and check the result using the returned pair
    std::pair<set<string>::iterator, bool> ret;
    ret = setOfNames.insert("Adam");

    if (!ret.second)
        cout << "\"Adam\" already exists in the set." << endl;
    else
        cout << "\"Adam\" was inserted successfully." << endl;

    // (c) Use iterator to print current values
    cout << "setOfNames contains:";
    for (set<string>::iterator it = setOfNames.begin(); it != setOfNames.end(); ++it)
        cout << " " << *it;
    cout << endl;

    // (d) Search for element "Adam" using find
    set<string>::iterator it = setOfNames.find("Adam");
    if (it != setOfNames.end())
        cout << "'Adam' found" << endl;
    else
        cout << "'Adam' not found" << endl;

    // (e) Search for "adam" (lowercase 'a')
    it = setOfNames.find("adam");
    if (it != setOfNames.end())
        cout << "'adam' found" << endl;
    else
        cout << "'adam' not found" << endl;

    // (f) Erase "Adam" and print updated set
    setOfNames.erase("Adam");
    cout << "After erasing \"Adam\", setOfNames contains:";
    for (set<string>::iterator it = setOfNames.begin(); it != setOfNames.end(); ++it)
        cout << " " << *it;
    cout << endl;

    return 0;
}
