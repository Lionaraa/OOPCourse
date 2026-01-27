#include <iostream>

class DeskTop {
private:
    int width{ 0 }, height{ 0 };
// указатель
    static DeskTop* ptr;
// конструкторы
    DeskTop() = default;
    DeskTop(int a, int b) {
        width = a;
        height = b;
    }
    DeskTop(const DeskTop&) = default;
public:
// метод, создающий объект
    static DeskTop* get_instance(int a, int b) {
        if (ptr == nullptr) {
            ptr = new DeskTop(a, b);
        }
        return ptr;
    }
// получение данных
    int get_width() { return width; }
    int get_height() { return height; }
// деструктор
    ~DeskTop() {
        ptr = nullptr;
    }
};
// инициализация
DeskTop* DeskTop::ptr{ nullptr };


int main() {
    DeskTop* ptr_desk = DeskTop::get_instance(500, 200);
    std::cout << ptr_desk << std::endl;
    
    delete ptr_desk;
}
