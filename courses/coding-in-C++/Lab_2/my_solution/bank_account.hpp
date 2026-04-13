#ifndef H_BANKACCOUNT
#define H_BANKACCOUNT

#include <string>

struct AccountInfo {
    std::string owner;
    double balance;
};

class BankAccount {
private:
    AccountInfo info;

public:
    void setOwner(const std::string& name);
    std::string getOwner();

    void deposit(double amount);
    void withdraw(double amount);

    double getBalance();
    AccountInfo getAccountInfo();
};

#endif
