#include <iostream>
using namespace std;

class ATM {
private:
    float balance;
    int numOfTransactions;

public:
    ATM(float initialBalance = 0.0) : balance(initialBalance), numOfTransactions(0) {}

    void initBalance(float amount) {
        balance = amount;
        numOfTransactions = 0;
    }

    void showBalance() const {
        cout << "Your current balance is: $" << balance << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            numOfTransactions++;
            cout << "You have deposited : $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    bool withdraw(float amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            numOfTransactions++;
            return true;
        }
        return false;
    }

    int getTransactions() const {
        return numOfTransactions;
    }
};

int main() {
    ATM atm_obj;
    atm_obj.initBalance(250);

    atm_obj.showBalance();

    atm_obj.deposit(250);

    atm_obj.showBalance();

    if (atm_obj.withdraw(100)) {
        cout << "Your withdrawl was successful" << endl;
        atm_obj.showBalance();
    } else {
        cout << "Not enough money in your account please try again later." << endl;
        atm_obj.showBalance();
    }

    cout << "Total number of transactions processed: " << atm_obj.getTransactions() << endl;

    return 0;
}