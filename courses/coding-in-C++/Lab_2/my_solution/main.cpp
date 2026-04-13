#include <iostream>

struct AccountInfo {
    std::string owner;
    double balance;
};

class BankAccount {
private:
    AccountInfo info;

public:
    void setOwner(const std::string& name);
    std::string get_owner();

    void deposit(double amount);
    void withdraw(double amount);

    double getBalance();
    AccountInfo getAccountInfo();
};

int main(void) {
    std::cout << "hello" << std::endl;

    return 0;
}
