#include <iostream>
#include <string>
class Thing {
    std::string name;
    double weight;
    int price;
public:
    Thing() : name(""), weight(0), price(0)
    {
        std::cout << "default constructor" << std::endl;
    }

    Thing(const std::string& name) : name(name), weight(0), price(0)
    {
        std::cout << "constructor 1" << std::endl;
    }

    Thing(const std::string& name, double weight, int price) : Thing(name)
    {
        this->weight = weight;
        this->price = price;
        std::cout << "constructor 3" << std::endl;
    }

    std::string get_name() {
        return name;
    }
    double get_weight() {
        return weight;
    }
    int get_price() {
        return price;
    }
};

int main(void)
{
    Thing* ptr_th = new Thing("HP Omen", 2.3, 120000);

    delete ptr_th;
    ptr_th = nullptr;
    return 0;
}
