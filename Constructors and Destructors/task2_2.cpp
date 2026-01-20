#include <iostream>

class TriangleChecker {
private:
    int a, b, c;
// конструктор по умолчанию
public:
    TriangleChecker(int x = 0, int y = 0, int z = 0) : a(x), b(y), c(z)
    {}
// условия для тругольника
    int is_triangle() {
        if(a <= 0 or b <= 0 or c <= 0){
            return 1;
/*Треугольник существует только тогда когда сумма двух его любых сторон больше третьей.*/
        } else if (a + b <= c || b + c <= a || a + c < b) {
            return 2;
        } else {
            return 3;
        }
    }
};

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    // Конструктор вызывается автоматически, когда создаём
    // динамический объект, передаём значения сразу
    TriangleChecker* ptr_tr = new TriangleChecker(a, b, c);
    std::cout << ptr_tr->is_triangle();
}
