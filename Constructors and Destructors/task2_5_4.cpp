#include <iostream>
#include <cstring>

class Flower {
    char name[100];
    int price {0};
public:
    // запрещаем использовать
    // конструктор по умолчанию и конструктор копирования
    Flower() = delete;
    Flower(const Flower& other) = delete;
    // передаём C-строки через strcpy
    Flower(const char* str, int pricing) 
    {
        strcpy(name, str);
        price = pricing;
    }
    // передаём C-строки через strcpy
    void get_data(char* name, int& price) {
        strcpy(name, this->name);
        price = this->price;
    }

};

int main() {
    Flower flower("Тюльпан", 120);
}
