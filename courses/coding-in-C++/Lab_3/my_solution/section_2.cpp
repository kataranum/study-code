#include <string>
#include <iostream>

class User {
protected:
    // protected is used so that these are available in derived classes
    std::string name;
    int id;

public:
    User(std::string name, int id)
        : name(name), id(id) {}

    void printInfo() {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "ID: " << this->id << std::endl;
    }
};

// without the `public` the compiler defaults to `private` and we get
// compiler errors because we can't access the User fields.
class Student : public User {
protected:
    unsigned int courses_taken;

public:
    // it's important to call the base class constructor so the derived
    // fields also get initialized properly
    Student(std::string name, int id)
        : User(name, id), courses_taken(0) {}

    void printRole() {
        std::cout
            << "Student ("
            << this->id
            << ", '"
            << this->name
            << "') took "
            << this->courses_taken
            << " courses."
            << std::endl;
    }
};

class Instructor : public User {
protected:
    unsigned int courses_instructed;

public:
    Instructor(std::string name, int id)
        : User(name, id), courses_instructed(0) {}

    void printRole() {
        std::cout
            << "Instructor ("
            << this->id
            << ", '"
            << this->name
            << "') has instructed "
            << this->courses_instructed
            << " courses."
            << std::endl;
    }
};

int main(void) {
    Student student = Student("stud", 123);
    Instructor instructor = Instructor("inst", 456);

    student.printInfo();
    instructor.printInfo();

    student.printRole();
    instructor.printRole();

    return 0;
}
