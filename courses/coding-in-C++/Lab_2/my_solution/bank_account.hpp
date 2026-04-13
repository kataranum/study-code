#ifndef H_BANKACCOUNT
#define H_BANKACCOUNT

#include <string>

struct AccountInfo {
    std::string owner;
    // balance is left unitialized when new class is created, the constructor
    // should set this to a default value (e.g. 0.0)
    double balance;
};

class BankAccount {
private:
    AccountInfo info;

public:
    void setOwner(const std::string& name);
    std::string getOwner();

    bool deposit(double amount);
    bool withdraw(double amount);

    double getBalance();
    AccountInfo getAccountInfo();
};

#endif
