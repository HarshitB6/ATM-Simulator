#include <iostream>
#include <string>
using namespace std;

// Function to validate integer input
int getValidInteger() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid integer: ";
        } else {
            return value;
        }
    }
}

// Function to validate double input
double getValidDouble() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid amount: ";
        } else {
            return value;
        }
    }
}

// Class representing a bank account
class BankAccount {
private:
    string accountHolder;
    double balance;
    int pin; // PIN for account security

public:
    // Constructor
    BankAccount(string name, double initialBalance, int accountPin)
        : accountHolder(name), balance(initialBalance), pin(accountPin) {}

    // Authenticate the user with a PIN
    bool authenticate(int enteredPin) {
        return pin == enteredPin;
    }

    // Display account details
    void displayDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << "." << endl;
        } else {
            cout << "Invalid deposit amount. Please try again." << endl;
        }
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << "." << endl;
            return true;
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        } else {
            cout << "Invalid withdrawal amount. Please try again." << endl;
        }
        return false;
    }

    // Transfer funds to another account
    bool transfer(BankAccount& recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.deposit(amount);
            cout << "Successfully transferred $" << amount << " to " << recipient.accountHolder << "." << endl;
            return true;
        } else if (amount > balance) {
            cout << "Insufficient balance. Transfer failed." << endl;
        } else {
            cout << "Invalid transfer amount. Please try again." << endl;
        }
        return false;
    }

    // Get the account holder name
    string getAccountHolder() const {
        return accountHolder;
    }
};

// Function to authenticate the user and return the authenticated account
BankAccount& authenticateUser(BankAccount& account1, BankAccount& account2) {
    while (true) {
        cout << "\nSelect Account (1 or 2): ";
        int accountChoice = getValidInteger();

        if (accountChoice == 1) {
            cout << "Enter PIN for Account 1: ";
            int enteredPin = getValidInteger();
            if (account1.authenticate(enteredPin)) {
                cout << "Authentication successful!\n";
                return account1;
            } else {
                cout << "Incorrect PIN. Try again.\n";
            }
        } else if (accountChoice == 2) {
            cout << "Enter PIN for Account 2: ";
            int enteredPin = getValidInteger();
            if (account2.authenticate(enteredPin)) {
                cout << "Authentication successful!\n";
                return account2;
            } else {
                cout << "Incorrect PIN. Try again.\n";
            }
        } else {
            cout << "Invalid choice. Please select 1 or 2.\n";
        }
    }
}

int main() {
    // Create two bank accounts with unique PINs
    BankAccount account1("Alice", 5000.0, 1234); // PIN: 1234
    BankAccount account2("Bob", 3000.0, 5678);   // PIN: 5678

    int choice;

    do {
        // Authenticate user and get the selected account
        BankAccount& currentAccount = authenticateUser(account1, account2);

        // Display menu
        cout << "\n=== ATM Simulator ===\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        choice = getValidInteger();

        switch (choice) {
        case 1: // Check Balance
            currentAccount.displayDetails();
            break;

        case 2: // Deposit Money
            cout << "Enter amount to deposit: $";
            double depositAmount;
            depositAmount = getValidDouble();
            currentAccount.deposit(depositAmount);
            break;

        case 3: // Withdraw Money
            cout << "Enter amount to withdraw: $";
            double withdrawAmount;
            withdrawAmount = getValidDouble();
            currentAccount.withdraw(withdrawAmount);
            break;

        case 4: // Transfer Funds
            cout << "Enter amount to transfer: $";
            double transferAmount;
            transferAmount = getValidDouble();
            if (&currentAccount == &account1) {
                currentAccount.transfer(account2, transferAmount);
            } else {
                currentAccount.transfer(account1, transferAmount);
            }
            break;

        case 5: // Exit
            cout << "Thank you for using the ATM Simulator. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
