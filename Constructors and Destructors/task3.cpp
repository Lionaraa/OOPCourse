#include <iostream>
// Дана структура точки
struct Point
{
    short x, y;
};
// Класс линии
class Line {
private:
    short x0, y0, x1, y1;
public:
    Line(int a = 0, int b = 0, int c = 0 , int d = 0) : 
x0(a), y0(b), x1(c), y1(d)
    {}
    Line(const Point& es, const Point& ep) :
x0(es.x), y0(es.y), x1(ep.x), y1(ep.y)
    {}
// Если хотим поменять координаты
    void set_coords(short a, short b, short c, short d) {
        x0 = a;
        y0 = b;
        x1 = c;
        y1 = d;
    }

    void set_coords(Point sp, Point ep) {
        x0 = sp.x;
        y0 = sp.y;
        x1 = ep.x;
        y1 = ep.y;
    }
/*БЫЛО:  Point obj;
        obj.x = x0;
        obj.y = y0;
        return obj;*/

        // Получаем конец или начало в виде объекта точки
    Point get_start() {
        Point pt {x0, y0};
        return pt;
    }

    Point get_end() {
        Point pt {x1, y1};
        return pt;
    }

};

int main(void)
{
    Point sp, ep;  
    short a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;


    Line* ptr_ln1 = new Line(a, b, c, d);
    Line* ptr_ln2 = new Line(sp, ep);


    Point obj1 = ptr_ln1->get_start();
    Point obj2 = ptr_ln1->get_end();

    Point obj3 = ptr_ln2->get_start();
    Point obj4 = ptr_ln2->get_end();

    std::cout << obj1.x << " " << obj1.y <<" "<< obj2.x <<" "<< obj2.y << " ";
    std::cout << obj3.x << " " << obj3.y <<" "<< obj4.x <<" "<< obj4.y << " ";


    delete ptr_ln1;
    delete ptr_ln2;
    ptr_ln1 = ptr_ln2 = nullptr;
    return 0;
}
