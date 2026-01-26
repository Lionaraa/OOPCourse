#include <iostream>

class Figure {
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
    Figure() = default;
    Figure(int a, int b, int c, int e) : x0(a), y0(b), x1(c), y1(e)
    {}
    Figure(const Figure& fig) = delete;
    const Figure& operator=(const Figure&) = delete;
    void get_data(int& x0, int& y0, int& x1, int& y1) {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
};
