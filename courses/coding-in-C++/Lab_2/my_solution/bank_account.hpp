#ifndef H_BANKACCOUNT
#define H_BANKACCOUNT

#include <string>

class BankAccount {
private:
    std::string owner;
    // balance is left unitialized when new class is created, the constructor
    // should set this to a default value (e.g. 0.0)
    double balance;

public:
    void setOwner(const std::string& name);
    std::string getOwner();

    bool deposit(double amount);
    bool withdraw(double amount);

    double getBalance();
    void getAccountInfo();
};

#endif
