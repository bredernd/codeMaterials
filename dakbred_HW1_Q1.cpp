#include <iostream>
#include <string>
using namespace std;

const int N = 5;  // Checkbook capacity

// Define Check struct
struct Check {
    int checkNum;
    string checkMemo;
    float checkAmount;
};

// Define CheckBook class
class CheckBook {
private:
    float balance;
    Check checks[N];
    float lastDeposit;
    int numOfChecks;
    const int checkLimit;

public:
    // Default constructor
    CheckBook() : balance(0.0f), lastDeposit(0.0f), numOfChecks(0), checkLimit(N) {}

    // Constructor with initial balance
    CheckBook(float initialBalance) : balance(initialBalance), lastDeposit(0.0f), numOfChecks(0), checkLimit(N) {}

    // Deposit function
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
        cout << "Deposited: $" << amount << ", New Balance: $" << balance << endl;
    }

    // Display checks in chronological order
    void displayChecks() const {
        cout << "Checks (Most Recent First):\n";
        for (int i = numOfChecks - 1; i >= 0; --i) {
            cout << "Check Number: " << checks[i].checkNum
                 << ", Amount: $" << checks[i].checkAmount
                 << ", Memo: " << checks[i].checkMemo << endl;
        }
    }

    // Write a check
    bool writeCheck(float amount) {
        if (numOfChecks >= checkLimit || amount > balance) {
            cout << "Unable to write check: Insufficient balance or checkbook full." << endl;
            return false;
        }

        cout << "Enter check memo: ";
        string memo;
        cin.ignore();
        getline(cin, memo);

        checks[numOfChecks].checkNum = numOfChecks + 1;
        checks[numOfChecks].checkMemo = memo;
        checks[numOfChecks].checkAmount = amount;

        balance -= amount;
        numOfChecks++;

        cout << "Check written successfully. Remaining Balance: $" << balance << endl;
        return true;
    }
};

int main() {
    // Create two CheckBook instances
    CheckBook cb1(500.0f);  // First checkbook with initial balance
    CheckBook cb2(1000.0f); // Second checkbook with initial balance

    // Write multiple checks for cb1
    cb1.writeCheck(150.0f); // memo? a
    cb1.writeCheck(150.0f); // memo? c
    cb1.writeCheck(150.0f); // memo? e
    cb1.writeCheck(150.0f); // memo? g
    cb1.writeCheck(150.0f); // memo? h

    // Write multiple checks for cb2
    cb2.writeCheck(130.0f); // memo? b
    cb2.writeCheck(130.0f); // memo? d
    cb2.writeCheck(130.0f); // memo? f

    // Display check details for cb1
    cout << "cb1 check details" << endl;
    cb1.displayChecks();

    // Display check details for cb2
    cout << "cb2 check details" << endl;
    cb2.displayChecks();

    cout << cb1.writeCheck(150.0f) << endl; // Additional check writing success check
    cout << cb2.writeCheck(130.0f) << endl; // Additional check writing success check

    return 0;
}

