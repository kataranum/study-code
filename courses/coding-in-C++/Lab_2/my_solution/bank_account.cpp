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

void BankAccount::withdraw(double amount) {
    this->info.balance -= amount;
}

double BankAccount::getBalance() {
    return this->info.balance;
}

AccountInfo BankAccount::getAccountInfo() {
    return this->info;
}
