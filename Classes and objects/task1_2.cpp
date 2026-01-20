#include <iostream>

class Vector3D {
    // объявление переменных в одну строку
    int x, y, z;
    // проверка на диапазон, если не выполняется будут 0
    bool check(int a) {
        return a <= 100 && -100 <= a;
    }

public:
    // установка координат
    void set_coords(int a, int b, int c) {
        if(check(a) && check(b) && check(c)) {
            this-> x = a;
            this -> y = b;
            this -> z = c;
        }            
    }

    // получение коорд через переменные и ссылки
        void get_coords(int& x, int& y, int& z) {
            x = this->x;
            y = this->y;
            z = this->z;
        }

};

int main() {
    // Создание объекта через выделение памяти
    Vector3D* ptr_v1 = new Vector3D;
    Vector3D* ptr_v2 = new Vector3D;
    // обращение к методам объектам через этот способ
    ptr_v1->set_coords(10, -5, 7);
    ptr_v2->set_coords(0, 12, -56);

    int x1, y1, z1;

    ptr_v1->get_coords(x1, y1, z1);
    std::cout << x1 << " " << y1 << " " << z1;
    delete ptr_v1;
    delete ptr_v2;
}
