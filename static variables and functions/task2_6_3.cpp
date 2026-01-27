#include <iostream>

class Operator {
    int type{ 0 };
    short operation{ -1 };
 // запрещаем образование объекта непосредственно
    Operator() = default;
public:
// можно перенести в private
    Operator(const Operator& other) = delete;
// метод, который создаёт объект
    static Operator* create();
    void set_state(int t, short o) { type = t; operation = o; }
    void get_state(int& t, short& o) { t = type; o = operation; }
};
// возвращает указатель
Operator* Operator::create() {
    return new Operator;
}
