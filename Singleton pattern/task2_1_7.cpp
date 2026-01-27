#include <iostream>

class DataThree {
private:
    // запрещаем создавать объекты непосредственно
    DataThree() = default;
    DataThree(const DataThree&) = default;
    // создаём переменную указателя, счётчик
    static DataThree* ptr;
    static int count;
public:
    // функция ,которая задаёт новый указатель, если счётчик меньше 3
    static DataThree* get_new_data() {
        if (count < 3 or ptr == nullptr) {
            ptr = new DataThree;
            ++count;
        }
        return ptr;
    }
    //обнуляем указатель, это нужно, чтобы не было двойного удаления
    ~DataThree() {
        ptr = nullptr;
    }
};

DataThree* DataThree::ptr = nullptr;
int DataThree::count = 0;

int main() {
//создём массив
    DataThree* ptr_dates[5];
    for (size_t i = 0; i < 5; ++i) {
        ptr_dates[i] = DataThree::get_new_data();
    }
    delete ptr_dates[];
}
