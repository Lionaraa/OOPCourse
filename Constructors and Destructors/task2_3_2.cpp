#include <iostream>

class StringBuffer {
// Константа
    enum {max_size = 1024};
 // Указатель на массив символов
    char *buffer {nullptr};
// размер
    int size {0};
public:
// Отправляем переданную строку в буффер, заметим что
// временно созданная строка - это массив из символов
// И нужно брать по указателю массив
    StringBuffer(const char* str)
    {
// заносим данные
// Алгоримт следующий:
/*
* Пока мы не наткнёмся на нулевой символ, увеличиваем размер
* или пока не достигнем максимального размера
* Далее добавляем символы до size-1
* В конец добавляем \0
*/
        size = 0;
        while (str[size] != '\0' && size < max_size - 1)
            size++;

        buffer = new char[size + 1];
        for (int i = 0; i < size; ++i) buffer[i] = str[i];
        buffer[size] = '\0';
    }
// Если в качестве передаваемых данных, мы хотим передать объект,
// В данном случае реализация через делегирующий конструктор
    StringBuffer(const StringBuffer& other) : StringBuffer(other.buffer)
    {}
// без делегирущего конструктора просто бы передали other и считали бы массив также как и в 1-ом
// потому что мы не можем использовать указатель, иначе всё это будет относиться к 1 участку памяти
    const char* get_data() {return buffer;}
    int get_size() {return size;}
// удаляем массив
    ~StringBuffer() {
        delete[] buffer;
    }

};
