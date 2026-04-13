#include "bank_account.hpp"

void BankAccount::setOwner(const std::string& name) {
    this->info.owner = name;
}

std::string BankAccount::getOwner() {
    return this->info.owner;
}

bool BankAccount::deposit(double amount) {
    if (amount < 0.0) {
        return false;
    }

    this->info.balance += amount;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount < 0.0) {
        return false;
    }

    double new_balance = this->info.balance - amount;
    if (new_balance < 0.0) {
        return false;
    }

    this->info.balance = new_balance;
    return true;
}

double BankAccount::getBalance() {
    return this->info.balance;
}

AccountInfo BankAccount::getAccountInfo() {
    return this->info;
}
