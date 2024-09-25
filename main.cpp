//
//  main.cpp
//  BankScenario
//
//  Created by Nicholas Powell on 9/25/24.
//

#include <iostream>

using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

// These variables show the amount of money in the account of customer 1, customer 2, and customer 3.
double customer1Bal = 12500;
double customer2Bal = 500;
double customer3Bal = 6000;

const string customer1Name = "John Stevens";
const string customer2Name = "Victoria Simmons";
const string customer3Name = "Lewis Berry";

const int customer1Acc = 10298374;
const int customer2Acc = 73619034;
const int customer3Acc = 40192348;

class bankAccount {
public:
    void deposit(double &balance);
    void withdraw(double &balance);
};

// Function to deposit money into account
void bankAccount::deposit(double &balance) {
    double depositAmount;
    cout << "How much would you like to deposit? " << endl;
    cin >> depositAmount;

    if (depositAmount < 0) {
        cout << "Invalid deposit amount" << endl;
    } else {
        balance += depositAmount;
        cout << depositAmount << " XCD was deposited into your account." << endl;
        cout << "Updated balance is: " << balance << " XCD" << endl;
    }
}

// Function to withdraw money from account
void bankAccount::withdraw(double &balance) {
    double withdrawAmount;
    cout << "How much would you like to withdraw? " << endl;
    cin >> withdrawAmount;

    if (withdrawAmount > balance) {
        cout << "Insufficient balance!" << endl;
    } else if (withdrawAmount < 0) {
        cout << "Invalid withdrawal amount" << endl;
    } else {
        balance -= withdrawAmount;
        cout << withdrawAmount << " XCD was withdrawn from your account." << endl;
        cout << "Updated balance is: " << balance << " XCD" << endl;
    }
}

int main() {
    bankAccount account;
    int customerreply;
    int customerAccNumber;
    double *selectedBalance = nullptr;
    string customernamereply;

    do {
        // Welcome message and options
        cout << "======================================================" << endl;
        cout << "Hello! Welcome to The Best Bank of St. Kitts and Nevis!" << endl;
        cout << "======================================================" << endl;

        cout << "Kindly select your choice (1-4): " << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cin >> customerreply;

        if (customerreply == 4) {
            cout << "Thank you for visiting The Best Bank! " << endl;
            break;
        }
        
        cout << "Enter name on the account: ";
        getline(cin >> ws, customernamereply);
        cout << customernamereply << endl;

        // Enter the 8-Digit Account ID
        cout << "Enter the 8-Digit Account ID: ";
        cin >> customerAccNumber;

        // Select the correct customer balance based on account number
        if (customerAccNumber == customer1Acc and customernamereply == customer1Name) {
            selectedBalance = &customer1Bal;
        } else if (customerAccNumber == customer2Acc and customernamereply == customer2Name) {
            selectedBalance = &customer2Bal;
        } else if (customerAccNumber == customer3Acc and customernamereply == customer3Name) {
            selectedBalance = &customer3Bal;
        } else {
            cout << "Invalid account information!" << endl;
            continue;
        }

        // Perform operations based on choice
        switch (customerreply) {
            case 1:
                account.deposit(*selectedBalance);
                break;
            case 2:
                account.withdraw(*selectedBalance);
                break;
            case 3:
                cout << "Current balance is: " << *selectedBalance << " XCD" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Thanks for using The Best Bank of St. Kitts and Nevis!" << endl;
    } while (customerreply != 4);

    return 0;
}
