#include <iostream>
// класс массива
class Array {
    // приватные поля
    double* data{ nullptr };
    size_t size{ 0 };
    Array() = default;
    // Конструктор, который принимает число
    Array(int a) : size(a) {
        data = new double[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }
    // Конструктор, который принимает массив и число
    Array(const double* arr, int a) {
        data = new double[a];
        size = a;
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }
    // констркутор копирования, не разрешён
    Array(const Array&) = delete;

public:
// статические функции создания объекта
    static Array* create(int a);
    static Array* create(const double* data, int length);
// меняем данные
    void set_data(double* d, size_t length) {
        //удаление предыдущего, выделение памяти, копирование в data
        delete[] data;
        size = length;
        data = new double[size];

        for (size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }
    // возвращаем данные
    double* get_data() { return data; }
    size_t get_size() { return size; }
// деструктор
    ~Array() {
        delete[] data;
    }
};

// реализация функций, просто возвращаем указатель
Array* Array::create(int a) {
    return new Array(a);
}

Array* Array::create(const double* data, int length) {
    return new Array(data, length);
}

int main() {
    double data[4] = { 1.0, 2.0, 3.0, 4.0 };
    // создание объектов
    Array* ar = Array::create(100);
    Array* ar2 = Array::create(data, 4);

    delete ar;
    delete ar2;
}
