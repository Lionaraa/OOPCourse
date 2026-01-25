#include <iostream>

class Graph 
{

    double* data {nullptr};
    int length {0};
public:
    Graph () 
    {}
// Передача массива точек
    Graph(const double* ar, int size) 
    {
        length = size;
        data = new double[length];
        for (size_t i = 0; i < length; ++i) {
            data[i] = ar[i];
        }
    }
    void set_data(const double* ar, int size) {
    // Освобождение памяти
        delete[] data;
        length = size;
        data = new double[length];
        for (size_t i = 0; i < length; ++i) {
                data[i] = ar[i];
        }
    }
    double* get_data() {
        return data;
    }
    int get_length() {
        return length;
    }
// освобождение памяти, деструктор
    ~Graph() {
        delete[] data;
    }
};

int main() {
    double coords[] = { 5, 0.4, 2.7, -3.2 };
    Graph gr(coords, sizeof(coords)/sizeof(coords[0]));
}
