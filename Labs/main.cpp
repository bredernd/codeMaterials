#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    // Creating a Person object and displaying their name and birthdate
    Person p1("Tony", "Stark", 1, 21, 1950);
    cout << p1.getName() << " born on: " << p1.getBirthdate() << endl;

    // Creating an Employee object and displaying their company
    Employee e1("Sue", "Storm", 2, 19, 1972, "Wayne Enterprises");
    cout << e1.getName() << " works at: " << e1.getCompany() << endl;

    // Creating a Student object and displaying their credits
    Student s1("Peter", "Piper", 8, 10, 2001, 15);
    cout << s1.getName() << " has " << s1.getCredits() << " credits." << endl;

    // Creating a GradStudent object and checking if they can graduate
    GradStudent g1("Reed", "Booker", 5, 5, 1965, 40);
    cout << g1.getName() << " can graduate: " << (g1.canGraduate() ? "Yes" : "No") << endl;

    return 0;
}
