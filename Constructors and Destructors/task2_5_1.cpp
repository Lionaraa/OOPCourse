#include <iostream>

class Operator {
// помещаем приватную секцию, чтобы можно было использовать конструктор внутри класса
    long a{0}, b{0}, c{0};
    Operator(const Operator& other) = default;
public:
    Operator() = default;
    // как мы видим, эта функция возвращает указатель на НОВУЮ область памяти, где наша копия!
    Operator* create_copy()
    {
        Operator * ptr_obj = new Operator(*this);
        return ptr_obj;
    }
};


int main() {

}
