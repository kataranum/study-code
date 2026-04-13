#include "bank_account.hpp"
#include <iostream>

void BankAccount::setOwner(const std::string& name) {
    this->owner = name;
}

std::string BankAccount::getOwner() {
    return this->owner;
}

bool BankAccount::deposit(double amount) {
    if (amount < 0.0) {
        return false;
    }

    this->balance += amount;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount < 0.0) {
        return false;
    }

    double new_balance = this->balance - amount;
    if (new_balance < 0.0) {
        return false;
    }

    this->balance = new_balance;
    return true;
}

double BankAccount::getBalance() {
    return this->balance;
}

void BankAccount::getAccountInfo() {
    std::cout << "Name: " << this->owner << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
}
