#include <iostream>
#include <string>
#include <iomanip>

// using namespaces is considered bad practice because it may silently shadow
// variables or functions.
//using namespace std;

// issue 9: no header file

// issue 10: no documentation

// issue 11: no validation of input parameters (e.g. setPrice)

// issue 12: wrong usage of restock() in main

// issue 13: wrong usage of setPrice() in main

class Article {
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;

public:
    Article(
        std::string name,
        double price,
        int stock,
        std::string category,
        int id
    ) : name(name), price(price), stock(stock), category(category), id(id) { }

    void setPrice(double price) {
        price = price;
    }

    void sell(int amount) {
        stock = stock - amount;
    }

    void restock(int amount) {
        this->stock += amount;
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() const {
        return price;
    }

    bool isAvailable() const {
        return stock > 0;
    }

    void printInfo() const {
        std::cout << "Article: " << name << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.setPrice(-100);
    a.applyDiscount(150);

    if (a.isAvailable()) {
        std::cout << "Article available" << std::endl;
    }

    a.printInfo();
}
