#include <iostream>
#include <string>
using namespace std;

class ATM {
public:
    float balance;

    ATM(float initial_balance) {
        balance = initial_balance;
    }

    void showBalance() {
        cout << "Your current balance is $" << balance << endl;
    }

    void deposit(float amount) {
        if(amount > 0) {
            balance += amount;
            cout << "You have successfully deposited $" << amount << endl;
        } else {
            cout << "invalid deposit amount." << endl;
        }
    }

    bool withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "You have successfully withdrawn $" << amount << endl;
            return true;
        } else {
            cout << "Could not withdrawn $" << amount << "insufficient funds please try again later" << endl;
            return false;
        }
    }
};

int main() {
    ATM atm_obj (250);

    atm_obj.showBalance();

    atm_obj.deposit(250);

    atm_obj.showBalance();

    atm_obj.balance += 250;
    
    atm_obj.showBalance();

    atm_obj.withdraw(100);

    atm_obj.showBalance();

    return 0;
};
