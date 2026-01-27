#include <iostream>
// класс массива
class Array {
    // приватные поля
    double* data{ nullptr };
    size_t size{ 0 };

    Array() = default;
    Array(const Array&) = default;
public:
    // статические функции создания объекта
    static Array* create(size_t a);
    static Array* create(const double* data, size_t length);
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
// можно объявлять также внутри класса!
Array* Array::create(size_t s) {
    Array* ar = new Array();
    ar->data = new double[s];
    ar->size = s;
    return ar;
}

Array* Array::create(const double* data, size_t s) {
    Array* ar = new Array();
    ar->data = new double[s];
    for (size_t i = 0; i < s; ++i) {
        ar->data[i] = data[i];
        return ar;
    }

}

int main() {
    double data[4] = { 1.0, 2.0, 3.0, 4.0 };
    // создание объектов
    Array* ar = Array::create(100);
    Array* ar2 = Array::create(data, 4);

    delete ar;
    delete ar2;
}
