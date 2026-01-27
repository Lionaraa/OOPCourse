#include <iostream>
class Point
{
private:
    static int MIN_COORD; //левая граница (статическая, то есть не зависит от конкретного объекта
    static int MAX_COORD; // правая граница (статическая, то есть не зависит от конкретного объекта)
    int x{0}, y{0}; // координаты (у каждого объекта свои координаты
    bool check_coord(int coord); // проверка координаты на границу
public:
    // констркутор по умполчанию
    Point() = default;
    Point(int a, int b)
    {
        if (check_coord(a) && check_coord(b)) {
            x = a;
            y = b;
        }
    }
    // установка границ (тоже статические, так как границы не индивидуальны для каждого класса)
    static void set_bounds(int left, int right);
    // получение границ
    static void get_bounds(int& left, int& right);
    void set_coords(int x, int y);
    int get_x();
    int get_y();
};

// инициализация статических переменных
int Point::MAX_COORD{10};
int Point::MIN_COORD{0};
//реализация функций
bool Point::check_coord(int coord) {return coord >= MIN_COORD && coord <= MAX_COORD;}
void Point::set_bounds(int left, int right) {MIN_COORD = left; MAX_COORD = right;}
void Point::get_bounds(int& left, int& right) {left=MIN_COORD; right=MAX_COORD;}
void Point::set_coords(int x, int y) {
    if (check_coord(x) && check_coord(y)) {
        this->x = x;
        this->y = y;
    }
}
int Point::get_x() {return x;}
int Point::get_y() {return y;}


int main() {
    Point::set_bounds(-5,5);
    Point pt(-5, 7);
}
