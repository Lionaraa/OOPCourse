class Rectangle {
    int x0{ 0 }, y0{ 0 }, x1{ 0 }, y1{ 0 };
    // функции, которые проверяют максимальное или минимальное число
    int min(int a, int b) const {
        return (a < b) ? a : b;
    }
    int max(int a, int b) const {
        return (a > b) ? a : b;
    }

public:
    // конструктор по умолчанию
    Rectangle() = default;
 
    Rectangle(int a, int b, int c, int d) : x0(a), y0(b), x1(c), y1(d)
    {
    }
    void get_coords(int& x0, int& y0, int& x1, int& y1) const
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    // для x0 y0 возвращает минимальные значения , а для x1 y1 - максимальные
    Rectangle operator+ (const Rectangle& right) {
        return Rectangle(
            min(x0, right.x0),
            min(y0, right.y0),
            max(x1, right.x1),
            max(y1, right.y1));
    }
};

int main() {
    Rectangle rect_1(-5, 0, 10, 12);
    Rectangle rect_2(1, -2, 7, 14);
    Rectangle res = rect_1 + rect_2;

}
