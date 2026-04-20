#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Article {
public:
    string name;
    double price;
    int stock;
    string* category;
    int id;

    Article(string name, double price, int stock, string category, int id) {
        name = name;
        price = price;
        stock = stock;
        this->id = id;
        this->category = new string;
        *this->category = category;
    }

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

    double getPrice() {
        return price;
    }

    bool isAvailable() {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.price = -100;
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}
