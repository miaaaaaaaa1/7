#include <iostream>
#include <string>
using namespace std;

class Overcoat {
private:
    string type; 
    double price;

public:
    Overcoat(string t = "", double p = 0.0) : type(t), price(p) {}

    Overcoat(const Overcoat& other) : type(other.type), price(other.price) {}

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) { 
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    bool operator>(const Overcoat& other) const {
        if (type != other.type) {
            throw invalid_argument("Cannot compare prices of different types of clothing");
        }
        return price > other.price;
    }

    friend ostream& operator<<(ostream& os, const Overcoat& o) {
        os << "Type: " << o.type << ", Price: " << o.price;
        return os;
    }

    friend istream& operator>>(istream& is, Overcoat& o) {
        cout << "Enter type: ";
        is >> o.type;
        cout << "Enter price: ";
        is >> o.price;
        return is;
    }
};

int main() {
    try {
        Overcoat coat1("Coat", 150.0);
        Overcoat coat2("Coat", 200.0);
        Overcoat jacket("Jacket", 100.0);

        cout << "coat1: " << coat1 << "\n";
        cout << "coat2: " << coat2 << "\n";
        cout << "jacket: " << jacket << "\n";

        cout << "coat1 == coat2: " << (coat1 == coat2 ? "Yes" : "No") << "\n";
        cout << "coat1 == jacket: " << (coat1 == jacket ? "Yes" : "No") << "\n";

        Overcoat coat3;
        coat3 = coat1;
        cout << "coat3 (after assignment): " << coat3 << "\n";

        cout << "coat2 > coat1: " << (coat2 > coat1 ? "Yes" : "No") << "\n";

        cout << "coat1 > jacket: ";
        cout << (coat1 > jacket ? "Yes" : "No") << "\n";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

}
