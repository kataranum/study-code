#include "bank_account.hpp"

void BankAccount::setOwner(const std::string& name) {
    this->info.owner = name;
}

std::string BankAccount::getOwner() {
    return this->info.owner;
}

void BankAccount::deposit(double amount) {
    this->info.balance += amount;
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
