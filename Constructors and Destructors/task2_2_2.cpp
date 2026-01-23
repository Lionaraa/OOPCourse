#include <iostream>
#include <string>
#include <sstream>
class Vector3D {
    int x, y, z;
public:
    // через поток
    Vector3D(const char* s) {
        std::stringstream data(s);
        // создаём массивы
        char a[100], b[100], c[100];
        // переводим в числа
        data >> a >> b >> c;
        x = atoi(a);
        y = atoi(b);
        z = atoi(c);
    }
    //через список координат можно было бы присвоить перечислением
    Vector3D(const int* coords) {
        x = coords[0];
        y = coords[1];
        z = coords[2];

    }

    void get_coords(int& a, int& b, int& c)
    {
        a = x; b = y; c = z;
    }
};

int main() {
    Vector3D f = "1,4 3 4";
    int coords_1[] = { 4, 5, 2 };
    Vector3D g = coords_1;

}
