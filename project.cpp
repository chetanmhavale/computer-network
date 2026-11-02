#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accNo;
    string name;
    double balance;

public:
    BankAccount(int n, string s, double b) {
        accNo = n;
        name = s;
        balance = b;
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void display() {
        cout << "\nAccount Number: " << accNo;
        cout << "\nAccount Holder: " << name;
        cout << "\nBalance: Rs. " << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int n, string s, double b)
        : BankAccount(n, s, b) {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance - 500) {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Maintain minimum balance of Rs. 500!\n";
        }
    }
};

int main() {
    int n, choice;
    string name;
    double balance, amount;

    cout << "Enter Account Number: ";
    cin >> n;

    cout << "Enter Account Holder Name: ";
    cin >> name;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    SavingsAccount account(n, name, balance);
    BankAccount* ptr = &account;

    do {
        cout << "\n--- BANKING SYSTEM ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                ptr->deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                ptr->withdraw(amount);
                break;

            case 3:
                ptr->display();
                break;

            case 4:
                cout << "Thank you for using our bank!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
