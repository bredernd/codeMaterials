#include "Person.h"
#include <sstream>
using namespace std;

Person::Person()
{
    Fname = "";
    Lname = "";
    birthDay = 1;
    birthMonth = 1;
    birthYear = 1;
}

Person::Person(string first, string last, int day, int month, int year){
    Fname = first;
    Lname = last;
    birthDay = day;
    birthMonth = month;
    birthYear = year;
}

string Person::getName(){
    return Fname + " " + Lname;
}

string Person::getBirthdate(){
    ostringstream bday;
    bday << birthDay << "/" << birthMonth << "/" << birthYear;
    return bday.str();
}

// Constructor for Employee
Employee::Employee(string first, string last, int day, int month, int year, string company) : Person(first, last, day, month, year), company(company) {}

// Returns the company name of the employee
string Employee::getCompany() {
    return company;
}

// Constructor for Student
Student::Student(string first, string last, int day, int month, int year, int credits) : Person(first, last, day, month, year), numCredits(credits) {}

// Returns the number of credits the student has
int Student::getCredits() {
    return numCredits;
}

// Adds credits to the student’s total
void Student::addCredits(int credits) {
    numCredits += credits;
}

// Constructor for GradStudent
GradStudent::GradStudent(string first, string last, int day, int month, int year, int credits) : Student(first, last, day, month, year, credits) {}

// Determines if a graduate student can graduate (requires at least 30 credits)
bool GradStudent::canGraduate() {
    return getCredits() >= 30;
}