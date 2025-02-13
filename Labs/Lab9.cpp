#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

#define N 5

class Profile {
public:
    // Default constructor
    Profile() : name("Jane"), lastName("Doe"), age(18) {}

    // Parameterized constructor
    Profile(string n, string l, int a) : name(n), lastName(l), age(a) {}

    // Getters & Setters
    void setName(string n) { name = n; }
    string getName() { return name; }

    void setLastName(string l) { lastName = l; }
    string getLastName() { return lastName; }

    void setAge(int a) { age = a; }
    int getAge() { return age; }

    // Operator overloading for '>'
    bool operator>(const Profile& p) { return age > p.age; }

    // Operator overloading for '[]'
    int& operator[](int index) {
        if (index >= 0 && index < N) {
            return array[index];
        }
        throw out_of_range("Index out of range");
    }

    // Display array elements
    void displayArray() {
        for (int i = 0; i < N; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Friend function for output stream overloading
    friend ostream& operator<<(ostream& var, const Profile& p);

private:
    string name;
    string lastName;
    int age;
    int array[N];
};

// Overloaded output stream operator
ostream& operator<<(ostream& var, const Profile& p) {
    var << p.name << " " << p.lastName << " (Age: " << p.age << ")";
    return var;
}

int main() {
    srand(time(0)); // Seed the random number generator

    Profile p1("Halil", "Smith", 32), p2("Ali", "Jones", 30);

    cout << "Array members for " << p1 << " are: " << endl;

    // Fill p1's array with random numbers from 1 through 6
    for (int i = 0; i < N; i++) {
        p1[i] = 1 + rand() % 6;
    }

    // Check if p1 is older than p2 and display array
    if (p1 > p2) {
        p1.displayArray();
    }

    return 0;
}

