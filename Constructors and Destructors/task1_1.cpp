#include <iostream>

class Wallet {
private:
    long volume;
public:
//Конструктор по умолчанию (не передаём значений)
    Wallet() : volume(0)
    {}
// Конструктор, в который мы передаём значения, (обычный??)
    Wallet(int a) : volume(a)
    {}
// методы
    void set_volume(long volume) {
        this->volume = volume;
    }
    long get_volume(){
        return volume;
    }
};


int main() {
    Wallet wt1(1000);
    Wallet wt2;
}
