#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
public:
    // Default constructor
    Person();
    // Parameterized constructor
    Person(std::string first, std::string last, int day, int month, int year);
    // Returns the full name of the person
    std::string getName();
    // Returns the birthdate as a formatted string
    std::string getBirthdate();

private:
    std::string Fname;  // First name
    std::string Lname;  // Last name
    int birthDay;       // Day of birth
    int birthMonth;     // Month of birth
    int birthYear;      // Year of birth

protected:
    /*You may move private members to protected if needed*/
};

class Employee : public Person {
public:
    // Constructor to initialize Employee with company name
    Employee(std::string first, std::string last, int day, int month, int year, std::string company);
    // Returns the company name
    std::string getCompany();
private:
    std::string company; // Company name
};

class Student : public Person {
public:
    // Constructor to initialize Student with credit hours
    Student(std::string first, std::string last, int day, int month, int year, int credits);
    // Returns the number of credits the student has
    int getCredits();
    // Adds credits to the student's total
    void addCredits(int credits);
private:
    int numCredits; // Number of credits
};

class GradStudent : public Student {
public:
    // Constructor to initialize GradStudent
    GradStudent(std::string first, std::string last, int day, int month, int year, int credits);
    // Checks if the student can graduate (requires at least 30 credits)
    bool canGraduate();
};

#endif // PERSON_H