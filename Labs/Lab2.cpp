#include <iostream>
#include <string>
using namespace std;

struct Date {
    int month;
    int day;
    int year;
};

struct Department {
    string name;
    int ID;
};

struct Employee {
    string name;
    string lastname;
    Date DOB;
    Date startDate;
    Department dept;
};

void displayEmployee(const Employee& e) {
    cout << "Employee Name: " << e.name << " " << e.lastname << endl;
    cout << "Date of Birth: " << e.DOB.month << "/" << e.DOB.day << "/" << e.DOB.year << endl;
    cout << "Start Date: " << e.startDate.month << "/" << e.startDate.day << "/" << e.startDate.year << endl;
    cout << "Department Name: " << e.dept.name << endl;
    cout << "Department ID: " << e.dept.ID << endl;
}

int main() {

    Employee e1;
    e1.name = "Dak";
    e1.lastname = "Prescott";
    e1.DOB = {07, 29, 1993};
    e1.startDate = {1, 15, 2016};
    e1.dept = {"Football", 101};

    cout << "Employee 1 details:" << endl;
    displayEmployee(e1);

    Employee e2;
    cout << "\nEnter Employee 2 details:" << endl;

    cout << "Enter first name: ";
    cin >> e2.name;

    cout << "Enter last name: ";
    cin >> e2.lastname;
    cout << "Enter date of birth (month): ";
    cin >> e2.DOB.month;

    cout << "Enter date of birth (day): ";
    cin >> e2.DOB.day;

    cout << "Enter date of birth (year): ";
    cin >> e2.DOB.year;

    cout << "Enter start date (month): ";
    cin >> e2.startDate.month;

    cout << "Enter start date (day ): ";
    cin >> e2.startDate.day;

    cout << "Enter start date (year): ";
    cin >> e2.startDate.year;

    cout << "Enter department name: ";
    cin >> e2.dept.name;

    cout << "Enter department ID: ";
    cin >> e2.dept.ID;

    cout << "\nEmployee 2 details:" << endl;
    displayEmployee(e2);
}
