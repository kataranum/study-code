#include <string>

class User {
protected:
    std::string name;
    int id;

public:
    User(std::string name, int id);
    void printInfo();
};
