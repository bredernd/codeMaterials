/*************************************************************************
** Author : Dak Bredernitz
** Program : hw2, q2
** Date Created : [February 10, 2025]
** Date Last Modified : [February 13, 2025]
** Usage : No command line arguments
**
** Problem:
Accept the following information from the user (keyboard):
- Hw1, hw2 and hw3 (out of 100)
- Midterm (out of 100)
- Final exam (out of 100)
Calculate the total grade out of 100 based on the following grading scale:
Hws --> 30% (10% each)
Midterm --> 30%
Final Exam --> 40%
*************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Check {
    int CheckNum;
    string CheckMemo;
    float CheckAmount;

    // Overloaded comparison operator
    bool operator>(float amount) const {
        return CheckAmount > amount;
    }

    // Overloaded output stream operator
    friend ostream& operator<<(ostream& os, const Check& c) {
        os << "Check# " << c.CheckNum << " | Memo: " << c.CheckMemo << " | Amount: $" << c.CheckAmount;
        return os;
    }
};

class CheckBook {
private:
    float balance;
    Check* chkPtr;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;

public:
    // Default constructor
    CheckBook() : balance(0), lastDeposit(0), numOfChecks(0), checkBookSize(4) {
        chkPtr = new Check[checkBookSize];
    }

    // Parameterized constructor
    CheckBook(float initialBalance) : balance(initialBalance), lastDeposit(0), numOfChecks(0), checkBookSize(2) {
        chkPtr = new Check[checkBookSize];
    }

    // Destructor
    ~CheckBook() {
        delete[] chkPtr;
    }

    // Copy constructor
    CheckBook(const CheckBook& other) {
        balance = other.balance;
        lastDeposit = other.lastDeposit;
        numOfChecks = other.numOfChecks;
        checkBookSize = other.checkBookSize;
        chkPtr = new Check[checkBookSize];
        for (int i = 0; i < numOfChecks; i++) {
            chkPtr[i] = other.chkPtr[i];
        }
    }

    // Overloaded assignment operator
    CheckBook& operator=(const CheckBook& other) {
        if (this != &other) {
            delete[] chkPtr;
            balance = other.balance;
            lastDeposit = other.lastDeposit;
            numOfChecks = other.numOfChecks;
            checkBookSize = other.checkBookSize;
            chkPtr = new Check[checkBookSize];
            for (int i = 0; i < numOfChecks; i++) {
                chkPtr[i] = other.chkPtr[i];
            }
        }
        return *this;
    }

    // Deposit function
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    // Write check function
    bool writeCheck(Check c_amount) {
        if (!(c_amount > balance)) {
            static const string memos[] = {"hardware store", "fanatics", "federal government", "hospital", "loctician", "pest control", "barnes & nobles", "playstation"};
            c_amount.CheckNum = numOfChecks + 1;
            c_amount.CheckMemo = memos[rand() % 8];
            balance -= c_amount.CheckAmount;
            chkPtr[numOfChecks] = c_amount;
            numOfChecks++;

            if (numOfChecks >= checkBookSize / 2) {
                checkBookSize *= 2;
                Check* newChkPtr = new Check[checkBookSize];
                for (int i = 0; i < numOfChecks; i++) {
                    newChkPtr[i] = chkPtr[i];
                }
                delete[] chkPtr;
                chkPtr = newChkPtr;
                cout << "Warning: New checkbook has been ordered!" << endl;
            }
            return true;
        }
        return false;
    }

    // Display checks
    void displayChecks() const {
        for (int i = numOfChecks - 1; i >= 0; i--) {
            cout << chkPtr[i] << endl;
        }
    }

    float getBalance() const { return balance; }
};

// Function to test check writing until balance is exhausted
void checkTest(CheckBook& cb, float initialAmount) {
    while (cb.getBalance() > 0) {
        Check newCheck;
        newCheck.CheckAmount = (rand() % 20) + 1; // Random check amount between 1 and 20
        if (!cb.writeCheck(newCheck)) {
            break;
        }
    }
    cb.displayChecks();
}

// Function to calculate total grade
void calculateGrade() {
    float hw1, hw2, hw3, midterm, finalExam;
    cout << "Enter Homework 1 score (out of 100): ";
    cin >> hw1;
    cout << "Enter Homework 2 score (out of 100): ";
    cin >> hw2;
    cout << "Enter Homework 3 score (out of 100): ";
    cin >> hw3;
    cout << "Enter Midterm score (out of 100): ";
    cin >> midterm;
    cout << "Enter Final Exam score (out of 100): ";
    cin >> finalExam;

    float totalGrade = (hw1 * 0.1) + (hw2 * 0.1) + (hw3 * 0.1) + (midterm * 0.3) + (finalExam * 0.4);
    cout << "Total Grade: " << totalGrade << "/100" << endl;
}

int main() {
    srand(time(0)); // Seed random number generator
    CheckBook myCheckBook(100); // Start with high balance
    checkTest(myCheckBook, 100);

    // Accept and calculate student grades
    calculateGrade();

    return 0;
}