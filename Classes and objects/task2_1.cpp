#include <iostream>
#include <string>
class Goods {
// публичные методы
public:
    std::string name;
    double weight;
    int price;
    // Благодаря тому, что мы возвращаем ссылку, мы не возвращаем копию
    const std::string& get_name(){
        return name;
    }
    double get_weight() {
        return weight;
    }
    int get_price() {
        return price;
    }
};


int main() {
    Goods book;
    book.name = "Основы ООП";
    book.weight = 234.5;
    book.price = 2000;

    Goods toy;
    toy.name = "Oculus Quest 3";
    toy.weight = 204.6;
    toy.price = 80000;
    std::cout << toy.get_name();

}
