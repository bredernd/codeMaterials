#include<iostream>
#include<string>
using namespace std;

class Profile {
private:
    string name, lastName;
    int age;

public:
    Profile() : name("Mac"), lastName("Miller"), age(26) {}

    string getName() const { return name; }
    string getLastName() const { return lastName; }
    int getAge() const { return age; }

    void setName(const string& pname) { name = pname; }
    void setLastName(const string& plastName) { lastName = plastName; }
    void setAge(int page) { age = page; }
};

class Twitter {
private:
    Profile TwProfile;
    int NumFollowers;

public:
    Twitter(const Profile& profile) : TwProfile(profile), NumFollowers(0) {}

    Profile getProfile() const { return TwProfile; }

    void addFollowers() { NumFollowers++; }

    int getNumFollowers() const { return NumFollowers; }

    void ChangeProfile(string pname = "", string plastName = "", string page = "") {
        if (!pname.empty()) TwProfile.setName(pname);
        if (!plastName.empty()) TwProfile.setLastName(plastName);
        if (!page.empty()) TwProfile.setAge(stoi(page));
    }
};

int main() {
    Profile persona1;
    Twitter Account1(persona1);

    for (int i = 1; i <= 10; i++) {
        Account1.addFollowers();
        cout << "Someone random has just started following you your follower count is " << Account1.getNumFollowers() << endl;
    }

    Profile currentProfile = Account1.getProfile();
    cout << "\nProfile Details:" << endl;
    cout << "Name: " << currentProfile.getName() << endl;
    cout << "Last Name: " << currentProfile.getLastName() << endl;
    cout << "Age: " << currentProfile.getAge() << endl;
    cout << "Number of Followers: " << Account1.getNumFollowers() << endl;

    Account1.ChangeProfile("Trae", "Young");

    currentProfile = Account1.getProfile();
    cout << "\nUpdated Profile Details:" << endl;
    cout << "Name: " << currentProfile.getName() << endl;
    cout << "Last Name: " << currentProfile.getLastName() << endl;
    cout << "Age: " << currentProfile.getAge() << endl;
    cout << "Number of Followers: " << Account1.getNumFollowers() << endl;

    return 0;
}