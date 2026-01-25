#include <iostream>
#include <cmath>
class Complex {
    short re{0}, im{0};

public:
    Complex()
    {}
    Complex(int a) : re(a), im(0)
    {}
    explicit Complex(int a, int b) : re(a), im(b)
    {}
    Complex(const Complex& obj) {
        re = std::abs(obj.re);
        im = std::abs(obj.im);
    }
    short real() {
        return re;
    }
    short imag() {
        return im;
    }
};


int main() {
    Complex d; // re=0, im=0
    Complex d1 = 5; // re=5, im=0
    Complex d2(1, -6); // re=1, im=-6
    Complex d3 = d2;
}
